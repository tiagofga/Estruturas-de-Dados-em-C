#include "algoritmos_grafos.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_union_find(void) {
    UnionFind *uf = union_find_criar(5U);
    assert(uf != NULL);
    assert(union_find_unir(uf, 0U, 1U) == 1);
    assert(union_find_unir(uf, 1U, 2U) == 1);
    assert(union_find_mesmo_conjunto(uf, 0U, 2U) == 1);
    assert(union_find_mesmo_conjunto(uf, 0U, 3U) == 0);
    assert(union_find_unir(uf, 0U, 2U) == 0);
    union_find_destruir(uf);
    PASS("test_union_find");
}

static void test_kruskal(void) {
    ArestaPeso arestas[] = {
        {0U, 1U, 10}, {0U, 2U, 6}, {0U, 3U, 5}, {1U, 3U, 15}, {2U, 3U, 4}
    };
    ArestaPeso mst[3];
    size_t quantidade = 0U;
    int peso_total = 0;
    assert(kruskal(4U, arestas, sizeof(arestas) / sizeof(arestas[0]), mst, 3U, &quantidade, &peso_total) == 1);
    assert(quantidade == 3U);
    assert(peso_total == 19);
    PASS("test_kruskal");
}

static void test_prim_matriz(void) {
    int matriz[] = {
        0, 10, 6, 5,
        10, 0, 0, 15,
        6, 0, 0, 4,
        5, 15, 4, 0
    };
    ArestaPeso mst[3];
    size_t quantidade = 0U;
    int peso_total = 0;
    assert(prim_matriz(4U, matriz, mst, 3U, &quantidade, &peso_total) == 1);
    assert(quantidade == 3U);
    assert(peso_total == 19);
    PASS("test_prim_matriz");
}

static void test_bellman_ford(void) {
    ArestaPeso arestas[] = {
        {0U, 1U, 6}, {0U, 2U, 7}, {1U, 2U, 8}, {1U, 3U, 5}, {1U, 4U, -4},
        {2U, 3U, -3}, {2U, 4U, 9}, {3U, 1U, -2}, {4U, 0U, 2}, {4U, 3U, 7}
    };
    int distancias[5];
    assert(bellman_ford(5U, arestas, sizeof(arestas) / sizeof(arestas[0]), 0U, distancias) == 1);
    assert(distancias[0] == 0);
    assert(distancias[1] == 2);
    assert(distancias[2] == 7);
    assert(distancias[3] == 4);
    assert(distancias[4] == -2);
    PASS("test_bellman_ford");
}

static void test_bellman_ford_ciclo_negativo(void) {
    ArestaPeso arestas[] = {{0U, 1U, 1}, {1U, 2U, -2}, {2U, 0U, -2}};
    int distancias[3];
    assert(bellman_ford(3U, arestas, 3U, 0U, distancias) == -1);
    PASS("test_bellman_ford_ciclo_negativo");
}

static void test_floyd_warshall(void) {
    int matriz[] = {
        0, 5, 0, 10,
        0, 0, 3, 0,
        0, 0, 0, 1,
        0, 0, 0, 0
    };
    int distancias[16];
    assert(floyd_warshall(4U, matriz, distancias) == 1);
    assert(distancias[0 * 4 + 0] == 0);
    assert(distancias[0 * 4 + 1] == 5);
    assert(distancias[0 * 4 + 2] == 8);
    assert(distancias[0 * 4 + 3] == 9);
    PASS("test_floyd_warshall");
}

static void test_invalidos(void) {
    ArestaPeso arestas[1] = {{0U, 1U, 1}};
    ArestaPeso mst[1];
    size_t quantidade = 0U;
    int peso_total = 0;
    int distancias[2];
    assert(union_find_criar(0U) == NULL);
    assert(union_find_unir(NULL, 0U, 1U) == 0);
    assert(union_find_encontrar(NULL, 0U) == (size_t)-1);
    assert(kruskal(0U, arestas, 1U, mst, 1U, &quantidade, &peso_total) == 0);
    assert(prim_matriz(0U, NULL, mst, 1U, &quantidade, &peso_total) == 0);
    assert(bellman_ford(2U, arestas, 1U, 2U, distancias) == 0);
    assert(floyd_warshall(0U, NULL, distancias) == 0);
    PASS("test_invalidos");
}

static void test_complexidade(void) {
    assert(strcmp(algoritmos_grafos_complexidade(),
                  "Union-Find quase O(1); Kruskal O(E log E); Prim matriz O(V^2); Bellman-Ford O(VE); Floyd-Warshall O(V^3).") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: Algoritmos Avancados de Grafos ===\n");
    test_union_find();
    test_kruskal();
    test_prim_matriz();
    test_bellman_ford();
    test_bellman_ford_ciclo_negativo();
    test_floyd_warshall();
    test_invalidos();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
