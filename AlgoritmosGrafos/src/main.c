#include "algoritmos_grafos.h"

#include <stdio.h>

static void imprimir_arestas(const ArestaPeso *arestas, size_t n) {
    for (size_t i = 0U; i < n; ++i) {
        printf("%zu -- %zu (peso %d)\n", arestas[i].origem, arestas[i].destino, arestas[i].peso);
    }
}

int main(void) {
    ArestaPeso arestas[] = {
        {0U, 1U, 10}, {0U, 2U, 6}, {0U, 3U, 5}, {1U, 3U, 15}, {2U, 3U, 4}
    };
    ArestaPeso mst[3];
    size_t qtd_mst = 0U;
    int peso_total = 0;

    if (kruskal(4U, arestas, sizeof(arestas) / sizeof(arestas[0]), mst, 3U, &qtd_mst, &peso_total)) {
        printf("Kruskal - peso total: %d\n", peso_total);
        imprimir_arestas(mst, qtd_mst);
    }

    int matriz[] = {
        0, 10, 6, 5,
        10, 0, 0, 15,
        6, 0, 0, 4,
        5, 15, 4, 0
    };

    if (prim_matriz(4U, matriz, mst, 3U, &qtd_mst, &peso_total)) {
        printf("Prim - peso total: %d\n", peso_total);
        imprimir_arestas(mst, qtd_mst);
    }

    ArestaPeso bf[] = {
        {0U, 1U, 6}, {0U, 2U, 7}, {1U, 2U, 8}, {1U, 3U, 5}, {1U, 4U, -4},
        {2U, 3U, -3}, {2U, 4U, 9}, {3U, 1U, -2}, {4U, 0U, 2}, {4U, 3U, 7}
    };
    int distancias[5];
    if (bellman_ford(5U, bf, sizeof(bf) / sizeof(bf[0]), 0U, distancias) == 1) {
        printf("Bellman-Ford distancias a partir de 0:\n");
        for (size_t i = 0U; i < 5U; ++i) {
            printf("dist[%zu] = %d\n", i, distancias[i]);
        }
    }

    printf("%s\n", algoritmos_grafos_complexidade());
    return 0;
}
