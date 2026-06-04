#include "grafo_lista.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static GrafoListaAresta *buscar_aresta(GrafoListaAresta *lista, size_t destino) {
    for (GrafoListaAresta *atual = lista; atual != NULL; atual = atual->proximo) {
        if (atual->destino == destino) {
            return atual;
        }
    }
    return NULL;
}

static int adicionar_aresta_dirigida(GrafoLista *grafo, size_t origem, size_t destino, int peso) {
    GrafoListaAresta *existente = buscar_aresta(grafo->adjacencias[origem], destino);
    if (existente != NULL) {
        existente->peso = peso;
        return 1;
    }
    GrafoListaAresta *nova = malloc(sizeof(*nova));
    if (nova == NULL) {
        return 0;
    }
    nova->destino = destino;
    nova->peso = peso;
    nova->proximo = grafo->adjacencias[origem];
    grafo->adjacencias[origem] = nova;
    return 1;
}

static int remover_aresta_dirigida(GrafoLista *grafo, size_t origem, size_t destino) {
    GrafoListaAresta *atual = grafo->adjacencias[origem];
    GrafoListaAresta *anterior = NULL;
    while (atual != NULL) {
        if (atual->destino == destino) {
            if (anterior == NULL) {
                grafo->adjacencias[origem] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}

int grafo_lista_criar(GrafoLista *grafo, size_t vertices, int direcionado) {
    if (grafo == NULL || vertices == 0U) {
        return 0;
    }
    grafo->adjacencias = calloc(vertices, sizeof(GrafoListaAresta *));
    if (grafo->adjacencias == NULL) {
        grafo->vertices = 0U;
        grafo->direcionado = 0;
        return 0;
    }
    grafo->vertices = vertices;
    grafo->direcionado = direcionado ? 1 : 0;
    return 1;
}

void grafo_lista_destruir(GrafoLista *grafo) {
    if (grafo == NULL || grafo->adjacencias == NULL) {
        return;
    }
    for (size_t i = 0U; i < grafo->vertices; ++i) {
        GrafoListaAresta *atual = grafo->adjacencias[i];
        while (atual != NULL) {
            GrafoListaAresta *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(grafo->adjacencias);
    grafo->adjacencias = NULL;
    grafo->vertices = 0U;
    grafo->direcionado = 0;
}

int grafo_lista_adicionar_aresta(GrafoLista *grafo, size_t origem, size_t destino) {
    return grafo_lista_adicionar_aresta_ponderada(grafo, origem, destino, 1);
}

int grafo_lista_adicionar_aresta_ponderada(GrafoLista *grafo, size_t origem, size_t destino, int peso) {
    if (grafo == NULL || grafo->adjacencias == NULL || origem >= grafo->vertices || destino >= grafo->vertices || peso <= 0) {
        return 0;
    }
    if (!adicionar_aresta_dirigida(grafo, origem, destino, peso)) {
        return 0;
    }
    if (!grafo->direcionado && origem != destino) {
        if (!adicionar_aresta_dirigida(grafo, destino, origem, peso)) {
            remover_aresta_dirigida(grafo, origem, destino);
            return 0;
        }
    }
    return 1;
}

int grafo_lista_remover_aresta(GrafoLista *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->adjacencias == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }
    int removeu = remover_aresta_dirigida(grafo, origem, destino);
    if (!grafo->direcionado && origem != destino) {
        removeu = remover_aresta_dirigida(grafo, destino, origem) || removeu;
    }
    return removeu;
}

int grafo_lista_tem_aresta(const GrafoLista *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->adjacencias == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }
    for (GrafoListaAresta *atual = grafo->adjacencias[origem]; atual != NULL; atual = atual->proximo) {
        if (atual->destino == destino) {
            return atual->peso;
        }
    }
    return 0;
}

int grafo_lista_bfs(const GrafoLista *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados) {
    if (grafo == NULL || grafo->adjacencias == NULL || inicio >= grafo->vertices || ordem == NULL || visitados == NULL || capacidade < grafo->vertices) {
        return 0;
    }
    int *visitado = calloc(grafo->vertices, sizeof(int));
    size_t *fila = calloc(grafo->vertices, sizeof(size_t));
    if (visitado == NULL || fila == NULL) {
        free(visitado);
        free(fila);
        return 0;
    }
    size_t frente = 0U;
    size_t tras = 0U;
    size_t total = 0U;
    fila[tras++] = inicio;
    visitado[inicio] = 1;
    while (frente < tras) {
        size_t atual = fila[frente++];
        ordem[total++] = atual;
        for (GrafoListaAresta *aresta = grafo->adjacencias[atual]; aresta != NULL; aresta = aresta->proximo) {
            if (!visitado[aresta->destino]) {
                visitado[aresta->destino] = 1;
                fila[tras++] = aresta->destino;
            }
        }
    }
    *visitados = total;
    free(visitado);
    free(fila);
    return 1;
}

static void dfs_visitar(const GrafoLista *grafo, size_t atual, int *visitado, size_t *ordem, size_t *total) {
    visitado[atual] = 1;
    ordem[(*total)++] = atual;
    for (GrafoListaAresta *aresta = grafo->adjacencias[atual]; aresta != NULL; aresta = aresta->proximo) {
        if (!visitado[aresta->destino]) {
            dfs_visitar(grafo, aresta->destino, visitado, ordem, total);
        }
    }
}

int grafo_lista_dfs(const GrafoLista *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados) {
    if (grafo == NULL || grafo->adjacencias == NULL || inicio >= grafo->vertices || ordem == NULL || visitados == NULL || capacidade < grafo->vertices) {
        return 0;
    }
    int *visitado = calloc(grafo->vertices, sizeof(int));
    if (visitado == NULL) {
        return 0;
    }
    size_t total = 0U;
    dfs_visitar(grafo, inicio, visitado, ordem, &total);
    *visitados = total;
    free(visitado);
    return 1;
}

int grafo_lista_dijkstra(const GrafoLista *grafo, size_t origem, int *distancias, size_t capacidade) {
    if (grafo == NULL || grafo->adjacencias == NULL || origem >= grafo->vertices || distancias == NULL || capacidade < grafo->vertices) {
        return 0;
    }
    int *visitado = calloc(grafo->vertices, sizeof(int));
    if (visitado == NULL) {
        return 0;
    }
    for (size_t i = 0U; i < grafo->vertices; ++i) {
        distancias[i] = INT_MAX;
    }
    distancias[origem] = 0;
    for (size_t i = 0U; i < grafo->vertices; ++i) {
        size_t atual = grafo->vertices;
        int menor = INT_MAX;
        for (size_t v = 0U; v < grafo->vertices; ++v) {
            if (!visitado[v] && distancias[v] < menor) {
                menor = distancias[v];
                atual = v;
            }
        }
        if (atual == grafo->vertices) {
            break;
        }
        visitado[atual] = 1;
        for (GrafoListaAresta *aresta = grafo->adjacencias[atual]; aresta != NULL; aresta = aresta->proximo) {
            int peso = aresta->peso;
            if (!visitado[aresta->destino] && distancias[atual] != INT_MAX && distancias[atual] <= INT_MAX - peso &&
                distancias[atual] + peso < distancias[aresta->destino]) {
                distancias[aresta->destino] = distancias[atual] + peso;
            }
        }
    }
    free(visitado);
    return 1;
}

void grafo_lista_imprimir(const GrafoLista *grafo) {
    if (grafo == NULL || grafo->adjacencias == NULL) {
        printf("Grafo invalido.\n");
        return;
    }
    for (size_t v = 0U; v < grafo->vertices; ++v) {
        printf("%zu:", v);
        for (GrafoListaAresta *aresta = grafo->adjacencias[v]; aresta != NULL; aresta = aresta->proximo) {
            printf(" -> %zu(%d)", aresta->destino, aresta->peso);
        }
        printf("\n");
    }
}

const char *grafo_lista_complexidade(void) {
    return "Grafo com lista de adjacencia: espaco O(V+E), BFS/DFS O(V+E), Dijkstra simples O(V^2+E).";
}
