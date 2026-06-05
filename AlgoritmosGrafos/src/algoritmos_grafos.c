#include "algoritmos_grafos.h"

#include <stdlib.h>

static int aresta_valida(const ArestaPeso *aresta, size_t vertices) {
    return aresta != NULL && aresta->origem < vertices && aresta->destino < vertices;
}

int union_find_criar(UnionFind *uf, size_t tamanho) {
    if (uf == NULL || tamanho == 0U) {
        return 0;
    }
    uf->pai = malloc(tamanho * sizeof(*uf->pai));
    uf->rank = calloc(tamanho, sizeof(*uf->rank));
    if (uf->pai == NULL || uf->rank == NULL) {
        free(uf->pai);
        free(uf->rank);
        uf->pai = NULL;
        uf->rank = NULL;
        uf->tamanho = 0U;
        return 0;
    }
    uf->tamanho = tamanho;
    for (size_t i = 0U; i < tamanho; ++i) {
        uf->pai[i] = i;
    }
    return 1;
}

void union_find_destruir(UnionFind *uf) {
    if (uf == NULL) {
        return;
    }
    free(uf->pai);
    free(uf->rank);
    uf->pai = NULL;
    uf->rank = NULL;
    uf->tamanho = 0U;
}

size_t union_find_encontrar(UnionFind *uf, size_t elemento) {
    if (uf == NULL || uf->pai == NULL || elemento >= uf->tamanho) {
        return (size_t)-1;
    }
    if (uf->pai[elemento] != elemento) {
        uf->pai[elemento] = union_find_encontrar(uf, uf->pai[elemento]);
    }
    return uf->pai[elemento];
}

int union_find_unir(UnionFind *uf, size_t a, size_t b) {
    if (uf == NULL || uf->pai == NULL || uf->rank == NULL || a >= uf->tamanho || b >= uf->tamanho) {
        return 0;
    }
    size_t raiz_a = union_find_encontrar(uf, a);
    size_t raiz_b = union_find_encontrar(uf, b);
    if (raiz_a == raiz_b) {
        return 0;
    }
    if (uf->rank[raiz_a] < uf->rank[raiz_b]) {
        uf->pai[raiz_a] = raiz_b;
    } else if (uf->rank[raiz_a] > uf->rank[raiz_b]) {
        uf->pai[raiz_b] = raiz_a;
    } else {
        uf->pai[raiz_b] = raiz_a;
        ++uf->rank[raiz_a];
    }
    return 1;
}

int union_find_mesmo_conjunto(UnionFind *uf, size_t a, size_t b) {
    if (uf == NULL || a >= uf->tamanho || b >= uf->tamanho) {
        return 0;
    }
    return union_find_encontrar(uf, a) == union_find_encontrar(uf, b);
}

static int comparar_arestas(const void *a, const void *b) {
    const ArestaPeso *x = a;
    const ArestaPeso *y = b;
    return (x->peso > y->peso) - (x->peso < y->peso);
}

int kruskal(size_t vertices,
            const ArestaPeso *arestas,
            size_t quantidade_arestas,
            ArestaPeso *arvore_geradora_minima,
            size_t capacidade_arvore,
            size_t *quantidade_arvore,
            int *peso_total) {
    if (vertices == 0U || arestas == NULL || arvore_geradora_minima == NULL || quantidade_arvore == NULL || peso_total == NULL ||
        capacidade_arvore < vertices - 1U) {
        return 0;
    }

    ArestaPeso *ordenadas = malloc(quantidade_arestas * sizeof(*ordenadas));
    if (ordenadas == NULL) {
        return 0;
    }
    for (size_t i = 0U; i < quantidade_arestas; ++i) {
        if (!aresta_valida(&arestas[i], vertices)) {
            free(ordenadas);
            return 0;
        }
        ordenadas[i] = arestas[i];
    }
    qsort(ordenadas, quantidade_arestas, sizeof(*ordenadas), comparar_arestas);

    UnionFind uf;
    if (!union_find_criar(&uf, vertices)) {
        free(ordenadas);
        return 0;
    }

    *quantidade_arvore = 0U;
    *peso_total = 0;
    for (size_t i = 0U; i < quantidade_arestas && *quantidade_arvore < vertices - 1U; ++i) {
        if (union_find_unir(&uf, ordenadas[i].origem, ordenadas[i].destino)) {
            arvore_geradora_minima[*quantidade_arvore] = ordenadas[i];
            ++(*quantidade_arvore);
            *peso_total += ordenadas[i].peso;
        }
    }

    union_find_destruir(&uf);
    free(ordenadas);
    return *quantidade_arvore == vertices - 1U;
}

int prim_matriz(size_t vertices,
                const int *matriz,
                ArestaPeso *arvore_geradora_minima,
                size_t capacidade_arvore,
                size_t *quantidade_arvore,
                int *peso_total) {
    if (vertices == 0U || matriz == NULL || arvore_geradora_minima == NULL || quantidade_arvore == NULL || peso_total == NULL ||
        capacidade_arvore < vertices - 1U) {
        return 0;
    }

    int *chave = malloc(vertices * sizeof(*chave));
    size_t *pai = malloc(vertices * sizeof(*pai));
    int *incluido = calloc(vertices, sizeof(*incluido));
    if (chave == NULL || pai == NULL || incluido == NULL) {
        free(chave);
        free(pai);
        free(incluido);
        return 0;
    }

    for (size_t i = 0U; i < vertices; ++i) {
        chave[i] = ALG_GRAFOS_INF;
        pai[i] = vertices;
    }
    chave[0] = 0;

    for (size_t count = 0U; count < vertices; ++count) {
        size_t u = vertices;
        int menor = ALG_GRAFOS_INF;
        for (size_t v = 0U; v < vertices; ++v) {
            if (!incluido[v] && chave[v] < menor) {
                menor = chave[v];
                u = v;
            }
        }
        if (u == vertices) {
            free(chave);
            free(pai);
            free(incluido);
            return 0;
        }
        incluido[u] = 1;
        for (size_t v = 0U; v < vertices; ++v) {
            int peso = matriz[u * vertices + v];
            if (peso > 0 && !incluido[v] && peso < chave[v]) {
                chave[v] = peso;
                pai[v] = u;
            }
        }
    }

    *quantidade_arvore = 0U;
    *peso_total = 0;
    for (size_t v = 1U; v < vertices; ++v) {
        if (pai[v] == vertices) {
            free(chave);
            free(pai);
            free(incluido);
            return 0;
        }
        arvore_geradora_minima[*quantidade_arvore] = (ArestaPeso){pai[v], v, chave[v]};
        ++(*quantidade_arvore);
        *peso_total += chave[v];
    }

    free(chave);
    free(pai);
    free(incluido);
    return 1;
}

int bellman_ford(size_t vertices,
                 const ArestaPeso *arestas,
                 size_t quantidade_arestas,
                 size_t origem,
                 int *distancias) {
    if (vertices == 0U || arestas == NULL || origem >= vertices || distancias == NULL) {
        return 0;
    }
    for (size_t i = 0U; i < vertices; ++i) {
        distancias[i] = ALG_GRAFOS_INF;
    }
    distancias[origem] = 0;

    for (size_t i = 1U; i < vertices; ++i) {
        int alterou = 0;
        for (size_t j = 0U; j < quantidade_arestas; ++j) {
            if (!aresta_valida(&arestas[j], vertices)) {
                return 0;
            }
            size_t u = arestas[j].origem;
            size_t v = arestas[j].destino;
            int peso = arestas[j].peso;
            if (distancias[u] != ALG_GRAFOS_INF && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                alterou = 1;
            }
        }
        if (!alterou) {
            break;
        }
    }

    for (size_t j = 0U; j < quantidade_arestas; ++j) {
        size_t u = arestas[j].origem;
        size_t v = arestas[j].destino;
        int peso = arestas[j].peso;
        if (distancias[u] != ALG_GRAFOS_INF && distancias[u] + peso < distancias[v]) {
            return -1;
        }
    }
    return 1;
}

int floyd_warshall(size_t vertices, const int *matriz, int *distancias) {
    if (vertices == 0U || matriz == NULL || distancias == NULL) {
        return 0;
    }

    for (size_t i = 0U; i < vertices; ++i) {
        for (size_t j = 0U; j < vertices; ++j) {
            if (i == j) {
                distancias[i * vertices + j] = 0;
            } else if (matriz[i * vertices + j] != 0) {
                distancias[i * vertices + j] = matriz[i * vertices + j];
            } else {
                distancias[i * vertices + j] = ALG_GRAFOS_INF;
            }
        }
    }

    for (size_t k = 0U; k < vertices; ++k) {
        for (size_t i = 0U; i < vertices; ++i) {
            for (size_t j = 0U; j < vertices; ++j) {
                int ik = distancias[i * vertices + k];
                int kj = distancias[k * vertices + j];
                if (ik != ALG_GRAFOS_INF && kj != ALG_GRAFOS_INF && ik + kj < distancias[i * vertices + j]) {
                    distancias[i * vertices + j] = ik + kj;
                }
            }
        }
    }

    for (size_t i = 0U; i < vertices; ++i) {
        if (distancias[i * vertices + i] < 0) {
            return -1;
        }
    }
    return 1;
}

const char *algoritmos_grafos_complexidade(void) {
    return "Union-Find quase O(1); Kruskal O(E log E); Prim matriz O(V^2); Bellman-Ford O(VE); Floyd-Warshall O(V^3).";
}
