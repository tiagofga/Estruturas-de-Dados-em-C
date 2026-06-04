#ifndef GRAFO_H
#define GRAFO_H

#include <stddef.h>

typedef struct {
    size_t vertices;
    int direcionado;
    int **matriz;
} Grafo;

int grafo_criar(Grafo *grafo, size_t vertices);
int grafo_criar_direcionado(Grafo *grafo, size_t vertices, int direcionado);
void grafo_destruir(Grafo *grafo);
int grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
int grafo_adicionar_aresta_ponderada(Grafo *grafo, size_t origem, size_t destino, int peso);
int grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
int grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino);
int grafo_bfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int grafo_dfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int grafo_dijkstra(const Grafo *grafo, size_t origem, int *distancias, size_t capacidade);
int grafo_ordenacao_topologica(const Grafo *grafo, size_t *ordem, size_t capacidade, size_t *tamanho_ordem);
void grafo_imprimir(const Grafo *grafo);

#endif
