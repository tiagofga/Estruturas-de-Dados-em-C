#include "grafo.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int grafo_criar(Grafo *grafo, size_t vertices) {
    return grafo_criar_direcionado(grafo, vertices, 0);
}

int grafo_criar_direcionado(Grafo *grafo, size_t vertices, int direcionado) {
    if (grafo == NULL || vertices == 0U) {
        return 0;
    }

    grafo->vertices = vertices;
    grafo->direcionado = direcionado ? 1 : 0;
    grafo->matriz = calloc(vertices, sizeof(int *));
    if (grafo->matriz == NULL) {
        return 0;
    }

    for (size_t i = 0; i < vertices; ++i) {
        grafo->matriz[i] = calloc(vertices, sizeof(int));
        if (grafo->matriz[i] == NULL) {
            for (size_t j = 0; j < i; ++j) {
                free(grafo->matriz[j]);
            }
            free(grafo->matriz);
            grafo->matriz = NULL;
            return 0;
        }
    }

    return 1;
}

void grafo_destruir(Grafo *grafo) {
    if (grafo == NULL || grafo->matriz == NULL) {
        return;
    }

    for (size_t i = 0; i < grafo->vertices; ++i) {
        free(grafo->matriz[i]);
    }

    free(grafo->matriz);
    grafo->matriz = NULL;
    grafo->vertices = 0;
    grafo->direcionado = 0;
}

int grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }

    grafo->matriz[origem][destino] = 1;
    if (!grafo->direcionado) {
        grafo->matriz[destino][origem] = 1;
    }
    return 1;
}

int grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }

    grafo->matriz[origem][destino] = 0;
    if (!grafo->direcionado) {
        grafo->matriz[destino][origem] = 0;
    }
    return 1;
}

int grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }

    return grafo->matriz[origem][destino];
}

int grafo_bfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados) {
    if (grafo == NULL || grafo->matriz == NULL || inicio >= grafo->vertices || ordem == NULL || visitados == NULL ||
        capacidade < grafo->vertices) {
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

        for (size_t vizinho = 0; vizinho < grafo->vertices; ++vizinho) {
            if (grafo->matriz[atual][vizinho] != 0 && !visitado[vizinho]) {
                visitado[vizinho] = 1;
                fila[tras++] = vizinho;
            }
        }
    }

    *visitados = total;
    free(visitado);
    free(fila);
    return 1;
}

static void dfs_visitar(const Grafo *grafo, size_t atual, int *visitado, size_t *ordem, size_t *total) {
    visitado[atual] = 1;
    ordem[(*total)++] = atual;

    for (size_t vizinho = 0; vizinho < grafo->vertices; ++vizinho) {
        if (grafo->matriz[atual][vizinho] != 0 && !visitado[vizinho]) {
            dfs_visitar(grafo, vizinho, visitado, ordem, total);
        }
    }
}

int grafo_dfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados) {
    if (grafo == NULL || grafo->matriz == NULL || inicio >= grafo->vertices || ordem == NULL || visitados == NULL ||
        capacidade < grafo->vertices) {
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

int grafo_dijkstra(const Grafo *grafo, size_t origem, int *distancias, size_t capacidade) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || distancias == NULL ||
        capacidade < grafo->vertices) {
        return 0;
    }

    int *visitado = calloc(grafo->vertices, sizeof(int));
    if (visitado == NULL) {
        return 0;
    }

    for (size_t i = 0; i < grafo->vertices; ++i) {
        distancias[i] = INT_MAX;
    }
    distancias[origem] = 0;

    for (size_t i = 0; i < grafo->vertices; ++i) {
        size_t atual = grafo->vertices;
        int menor = INT_MAX;

        for (size_t v = 0; v < grafo->vertices; ++v) {
            if (!visitado[v] && distancias[v] < menor) {
                menor = distancias[v];
                atual = v;
            }
        }

        if (atual == grafo->vertices) {
            break;
        }

        visitado[atual] = 1;

        for (size_t vizinho = 0; vizinho < grafo->vertices; ++vizinho) {
            int peso = grafo->matriz[atual][vizinho];
            if (peso > 0 && !visitado[vizinho] && distancias[atual] != INT_MAX && distancias[atual] <= INT_MAX - peso &&
                distancias[atual] + peso < distancias[vizinho]) {
                distancias[vizinho] = distancias[atual] + peso;
            }
        }
    }

    free(visitado);
    return 1;
}

int grafo_ordenacao_topologica(const Grafo *grafo, size_t *ordem, size_t capacidade, size_t *tamanho_ordem) {
    if (grafo == NULL || grafo->matriz == NULL || ordem == NULL || tamanho_ordem == NULL || capacidade < grafo->vertices ||
        !grafo->direcionado) {
        return 0;
    }

    size_t *grau_entrada = calloc(grafo->vertices, sizeof(size_t));
    size_t *fila = calloc(grafo->vertices, sizeof(size_t));
    if (grau_entrada == NULL || fila == NULL) {
        free(grau_entrada);
        free(fila);
        return 0;
    }

    for (size_t origem = 0; origem < grafo->vertices; ++origem) {
        for (size_t destino = 0; destino < grafo->vertices; ++destino) {
            if (grafo->matriz[origem][destino] != 0) {
                ++grau_entrada[destino];
            }
        }
    }

    size_t frente = 0U;
    size_t tras = 0U;
    for (size_t v = 0; v < grafo->vertices; ++v) {
        if (grau_entrada[v] == 0U) {
            fila[tras++] = v;
        }
    }

    size_t total = 0U;
    while (frente < tras) {
        size_t atual = fila[frente++];
        ordem[total++] = atual;

        for (size_t vizinho = 0; vizinho < grafo->vertices; ++vizinho) {
            if (grafo->matriz[atual][vizinho] != 0) {
                --grau_entrada[vizinho];
                if (grau_entrada[vizinho] == 0U) {
                    fila[tras++] = vizinho;
                }
            }
        }
    }

    *tamanho_ordem = total;
    free(grau_entrada);
    free(fila);
    return total == grafo->vertices;
}

void grafo_imprimir(const Grafo *grafo) {
    if (grafo == NULL || grafo->matriz == NULL) {
        return;
    }

    for (size_t i = 0; i < grafo->vertices; ++i) {
        for (size_t j = 0; j < grafo->vertices; ++j) {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}
