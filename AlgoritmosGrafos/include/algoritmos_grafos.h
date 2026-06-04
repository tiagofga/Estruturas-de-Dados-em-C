#ifndef ALGORITMOS_GRAFOS_H
#define ALGORITMOS_GRAFOS_H

#include <limits.h>
#include <stddef.h>

#define ALG_GRAFOS_INF (INT_MAX / 4)

typedef struct {
    size_t origem;
    size_t destino;
    int peso;
} ArestaPeso;

typedef struct {
    size_t *pai;
    size_t *rank;
    size_t tamanho;
} UnionFind;

int union_find_criar(UnionFind *uf, size_t tamanho);
void union_find_destruir(UnionFind *uf);
size_t union_find_encontrar(UnionFind *uf, size_t elemento);
int union_find_unir(UnionFind *uf, size_t a, size_t b);
int union_find_mesmo_conjunto(UnionFind *uf, size_t a, size_t b);

int kruskal(size_t vertices,
            const ArestaPeso *arestas,
            size_t quantidade_arestas,
            ArestaPeso *arvore_geradora_minima,
            size_t capacidade_arvore,
            size_t *quantidade_arvore,
            int *peso_total);

int prim_matriz(size_t vertices,
                const int *matriz,
                ArestaPeso *arvore_geradora_minima,
                size_t capacidade_arvore,
                size_t *quantidade_arvore,
                int *peso_total);

int bellman_ford(size_t vertices,
                 const ArestaPeso *arestas,
                 size_t quantidade_arestas,
                 size_t origem,
                 int *distancias);

int floyd_warshall(size_t vertices, const int *matriz, int *distancias);

const char *algoritmos_grafos_complexidade(void);

#endif
