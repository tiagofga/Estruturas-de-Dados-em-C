#ifndef GRAFO_H
#define GRAFO_H

#include <stddef.h>

typedef struct {
    size_t vertices;
    int **matriz;
} Grafo;

int grafo_criar(Grafo *grafo, size_t vertices);
void grafo_destruir(Grafo *grafo);
int grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
int grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
int grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino);
void grafo_imprimir(const Grafo *grafo);

#endif
