#include "grafo.h"

#include <stdio.h>

int main(void) {
    Grafo grafo;

    if (!grafo_criar(&grafo, 4U)) {
        fprintf(stderr, "Erro ao criar grafo.\n");
        return 1;
    }

    grafo_adicionar_aresta(&grafo, 0U, 1U);
    grafo_adicionar_aresta(&grafo, 0U, 2U);
    grafo_adicionar_aresta(&grafo, 2U, 3U);

    printf("Matriz de adjacência:\n");
    grafo_imprimir(&grafo);

    printf("Aresta 0-1: %s\n", grafo_tem_aresta(&grafo, 0U, 1U) ? "sim" : "não");
    printf("Aresta 1-3: %s\n", grafo_tem_aresta(&grafo, 1U, 3U) ? "sim" : "não");

    grafo_destruir(&grafo);
    return 0;
}
