#include "grafo.h"

#include <stdio.h>
#include <stdlib.h>

int grafo_criar(Grafo *grafo, size_t vertices) {
    if (grafo == NULL || vertices == 0U) {
        return 0;
    }

    grafo->vertices = vertices;
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
}

int grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }

    grafo->matriz[origem][destino] = 1;
    grafo->matriz[destino][origem] = 1;
    return 1;
}

int grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }

    grafo->matriz[origem][destino] = 0;
    grafo->matriz[destino][origem] = 0;
    return 1;
}

int grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino) {
    if (grafo == NULL || grafo->matriz == NULL || origem >= grafo->vertices || destino >= grafo->vertices) {
        return 0;
    }

    return grafo->matriz[origem][destino];
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
