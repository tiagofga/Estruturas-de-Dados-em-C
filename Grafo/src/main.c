#include "grafo.h"

#include <limits.h>
#include <stdio.h>

int main(void) {
    Grafo grafo;
    size_t ordem[5];
    size_t visitados = 0U;
    int distancias[5];
    size_t ordem_topologica[5];
    size_t total_topologica = 0U;

    if (!grafo_criar_direcionado(&grafo, 5U, 1)) {
        fprintf(stderr, "Erro ao criar grafo.\n");
        return 1;
    }

    grafo_adicionar_aresta(&grafo, 0U, 1U);
    grafo_adicionar_aresta(&grafo, 0U, 2U);
    grafo_adicionar_aresta(&grafo, 1U, 3U);
    grafo_adicionar_aresta(&grafo, 2U, 3U);
    grafo_adicionar_aresta(&grafo, 3U, 4U);

    printf("Matriz de adjacência:\n");
    grafo_imprimir(&grafo);

    if (grafo_bfs(&grafo, 0U, ordem, 5U, &visitados)) {
        printf("\nBFS a partir do 0: ");
        for (size_t i = 0; i < visitados; ++i) {
            printf("%zu ", ordem[i]);
        }
        printf("\n");
    }

    if (grafo_dfs(&grafo, 0U, ordem, 5U, &visitados)) {
        printf("DFS a partir do 0: ");
        for (size_t i = 0; i < visitados; ++i) {
            printf("%zu ", ordem[i]);
        }
        printf("\n");
    }

    if (grafo_dijkstra(&grafo, 0U, distancias, 5U)) {
        printf("Distâncias mínimas (Dijkstra) a partir do 0: ");
        for (size_t i = 0; i < grafo.vertices; ++i) {
            if (distancias[i] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", distancias[i]);
            }
        }
        printf("\n");
    }

    if (grafo_ordenacao_topologica(&grafo, ordem_topologica, 5U, &total_topologica)) {
        printf("Ordenação topológica: ");
        for (size_t i = 0; i < total_topologica; ++i) {
            printf("%zu ", ordem_topologica[i]);
        }
        printf("\n");
    }

    grafo_destruir(&grafo);
    return 0;
}
