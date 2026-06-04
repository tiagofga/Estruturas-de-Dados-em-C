#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <stddef.h>

typedef struct GrafoListaAresta {
    size_t destino;
    int peso;
    struct GrafoListaAresta *proximo;
} GrafoListaAresta;

typedef struct {
    size_t vertices;
    int direcionado;
    GrafoListaAresta **adjacencias;
} GrafoLista;

int grafo_lista_criar(GrafoLista *grafo, size_t vertices, int direcionado);
void grafo_lista_destruir(GrafoLista *grafo);
int grafo_lista_adicionar_aresta(GrafoLista *grafo, size_t origem, size_t destino);
int grafo_lista_adicionar_aresta_ponderada(GrafoLista *grafo, size_t origem, size_t destino, int peso);
int grafo_lista_remover_aresta(GrafoLista *grafo, size_t origem, size_t destino);
int grafo_lista_tem_aresta(const GrafoLista *grafo, size_t origem, size_t destino);
int grafo_lista_bfs(const GrafoLista *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int grafo_lista_dfs(const GrafoLista *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int grafo_lista_dijkstra(const GrafoLista *grafo, size_t origem, int *distancias, size_t capacidade);
void grafo_lista_imprimir(const GrafoLista *grafo);
const char *grafo_lista_complexidade(void);

#endif
