#include "grafo_lista.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_arestas(void) {
    GrafoLista grafo;
    assert(grafo_lista_criar(&grafo, 4U, 0) == 1);
    assert(grafo_lista_adicionar_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 0U, 2U, 5) == 1);
    assert(grafo_lista_tem_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_lista_tem_aresta(&grafo, 1U, 0U) == 1);
    assert(grafo_lista_tem_aresta(&grafo, 0U, 2U) == 5);
    assert(grafo_lista_tem_aresta(&grafo, 2U, 0U) == 5);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 0U, 2U, 7) == 1);
    assert(grafo_lista_tem_aresta(&grafo, 0U, 2U) == 7);
    grafo_lista_destruir(&grafo);
    PASS("test_criar_arestas");
}

static void test_remover(void) {
    GrafoLista grafo;
    assert(grafo_lista_criar(&grafo, 3U, 0) == 1);
    assert(grafo_lista_adicionar_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_lista_remover_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_lista_tem_aresta(&grafo, 0U, 1U) == 0);
    assert(grafo_lista_tem_aresta(&grafo, 1U, 0U) == 0);
    assert(grafo_lista_remover_aresta(&grafo, 0U, 1U) == 0);
    grafo_lista_destruir(&grafo);
    PASS("test_remover");
}

static void test_bfs_dfs(void) {
    GrafoLista grafo;
    size_t ordem[4];
    size_t visitados = 0U;
    assert(grafo_lista_criar(&grafo, 4U, 1) == 1);
    assert(grafo_lista_adicionar_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_lista_adicionar_aresta(&grafo, 0U, 2U) == 1);
    assert(grafo_lista_adicionar_aresta(&grafo, 1U, 3U) == 1);
    assert(grafo_lista_bfs(&grafo, 0U, ordem, 4U, &visitados) == 1);
    assert(visitados == 4U);
    assert(ordem[0] == 0U);
    assert(grafo_lista_dfs(&grafo, 0U, ordem, 4U, &visitados) == 1);
    assert(visitados == 4U);
    assert(ordem[0] == 0U);
    grafo_lista_destruir(&grafo);
    PASS("test_bfs_dfs");
}

static void test_dijkstra(void) {
    GrafoLista grafo;
    int distancias[5];
    assert(grafo_lista_criar(&grafo, 5U, 1) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 0U, 1U, 10) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 0U, 2U, 3) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 2U, 1U, 4) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 1U, 3U, 2) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 2U, 3U, 8) == 1);
    assert(grafo_lista_adicionar_aresta_ponderada(&grafo, 3U, 4U, 7) == 1);
    assert(grafo_lista_dijkstra(&grafo, 0U, distancias, 5U) == 1);
    assert(distancias[0] == 0);
    assert(distancias[1] == 7);
    assert(distancias[2] == 3);
    assert(distancias[3] == 9);
    assert(distancias[4] == 16);
    grafo_lista_destruir(&grafo);
    PASS("test_dijkstra");
}

static void test_invalidos(void) {
    GrafoLista grafo;
    size_t ordem[2];
    size_t visitados = 0U;
    int distancias[2];
    assert(grafo_lista_criar(NULL, 2U, 0) == 0);
    assert(grafo_lista_criar(&grafo, 0U, 0) == 0);
    assert(grafo_lista_adicionar_aresta(NULL, 0U, 1U) == 0);
    assert(grafo_lista_bfs(NULL, 0U, ordem, 2U, &visitados) == 0);
    assert(grafo_lista_dijkstra(NULL, 0U, distancias, 2U) == 0);
    PASS("test_invalidos");
}

static void test_complexidade(void) {
    assert(strcmp(grafo_lista_complexidade(),
                  "Grafo com lista de adjacencia: espaco O(V+E), BFS/DFS O(V+E), Dijkstra simples O(V^2+E).") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: Grafo Lista de Adjacencia ===\n");
    test_criar_arestas();
    test_remover();
    test_bfs_dfs();
    test_dijkstra();
    test_invalidos();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
