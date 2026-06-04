#include "grafo_lista.h"

#include <stdio.h>

int main(void) {
    GrafoLista grafo;
    int distancias[5];

    if (!grafo_lista_criar(&grafo, 5U, 1)) {
        fprintf(stderr, "Falha ao criar grafo.\n");
        return 1;
    }

    grafo_lista_adicionar_aresta_ponderada(&grafo, 0U, 1U, 10);
    grafo_lista_adicionar_aresta_ponderada(&grafo, 0U, 2U, 3);
    grafo_lista_adicionar_aresta_ponderada(&grafo, 2U, 1U, 4);
    grafo_lista_adicionar_aresta_ponderada(&grafo, 1U, 3U, 2);
    grafo_lista_adicionar_aresta_ponderada(&grafo, 3U, 4U, 7);

    grafo_lista_imprimir(&grafo);

    if (grafo_lista_dijkstra(&grafo, 0U, distancias, 5U)) {
        for (size_t i = 0U; i < 5U; ++i) {
            printf("dist[0 -> %zu] = %d\n", i, distancias[i]);
        }
    }

    printf("%s\n", grafo_lista_complexidade());
    grafo_lista_destruir(&grafo);
    return 0;
}
