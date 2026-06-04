#include "grafo.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_e_destruir(void) {
    Grafo grafo;
    assert(grafo_criar(&grafo, 3U) == 1);
    assert(grafo.vertices == 3U);
    assert(grafo.direcionado == 0);
    assert(grafo.matriz != NULL);
    grafo_destruir(&grafo);
    assert(grafo.matriz == NULL);
    assert(grafo.vertices == 0U);
    assert(grafo.direcionado == 0);
    PASS("test_criar_e_destruir");
}

static void test_criar_invalido(void) {
    Grafo grafo;
    assert(grafo_criar(NULL, 3U) == 0);
    assert(grafo_criar(&grafo, 0U) == 0);
    PASS("test_criar_invalido");
}

static void test_adicionar_aresta(void) {
    Grafo grafo;
    assert(grafo_criar(&grafo, 4U) == 1);

    assert(grafo_adicionar_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_adicionar_aresta(&grafo, 1U, 2U) == 1);

    assert(grafo_tem_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_tem_aresta(&grafo, 1U, 0U) == 1);
    assert(grafo_tem_aresta(&grafo, 1U, 2U) == 1);
    assert(grafo_tem_aresta(&grafo, 2U, 1U) == 1);
    assert(grafo_tem_aresta(&grafo, 0U, 2U) == 0);

    grafo_destruir(&grafo);
    PASS("test_adicionar_aresta");
}

static void test_remover_aresta(void) {
    Grafo grafo;
    assert(grafo_criar(&grafo, 3U) == 1);

    grafo_adicionar_aresta(&grafo, 0U, 2U);
    assert(grafo_tem_aresta(&grafo, 0U, 2U) == 1);

    assert(grafo_remover_aresta(&grafo, 0U, 2U) == 1);
    assert(grafo_tem_aresta(&grafo, 0U, 2U) == 0);
    assert(grafo_tem_aresta(&grafo, 2U, 0U) == 0);

    grafo_destruir(&grafo);
    PASS("test_remover_aresta");
}

static void test_aresta_invalida(void) {
    Grafo grafo;
    assert(grafo_criar(&grafo, 3U) == 1);

    assert(grafo_adicionar_aresta(&grafo, 0U, 5U) == 0);
    assert(grafo_remover_aresta(&grafo, 5U, 0U) == 0);
    assert(grafo_tem_aresta(&grafo, 5U, 0U) == 0);

    grafo_destruir(&grafo);
    PASS("test_aresta_invalida");
}

static void test_grafo_sem_arestas(void) {
    Grafo grafo;
    assert(grafo_criar(&grafo, 4U) == 1);

    for (size_t i = 0; i < grafo.vertices; ++i) {
        for (size_t j = 0; j < grafo.vertices; ++j) {
            assert(grafo_tem_aresta(&grafo, i, j) == 0);
        }
    }

    grafo_destruir(&grafo);
    PASS("test_grafo_sem_arestas");
}

static void test_grafo_direcionado(void) {
    Grafo grafo;
    assert(grafo_criar_direcionado(&grafo, 3U, 1) == 1);
    assert(grafo.direcionado == 1);

    assert(grafo_adicionar_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_tem_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_tem_aresta(&grafo, 1U, 0U) == 0);

    assert(grafo_remover_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_tem_aresta(&grafo, 0U, 1U) == 0);

    grafo_destruir(&grafo);
    PASS("test_grafo_direcionado");
}

static void montar_dag_exemplo(Grafo *grafo) {
    assert(grafo_criar_direcionado(grafo, 5U, 1) == 1);
    assert(grafo_adicionar_aresta(grafo, 0U, 1U) == 1);
    assert(grafo_adicionar_aresta(grafo, 0U, 2U) == 1);
    assert(grafo_adicionar_aresta(grafo, 1U, 3U) == 1);
    assert(grafo_adicionar_aresta(grafo, 2U, 3U) == 1);
    assert(grafo_adicionar_aresta(grafo, 3U, 4U) == 1);
}

static void test_bfs(void) {
    Grafo grafo;
    size_t ordem[5];
    size_t visitados = 0U;
    size_t esperado[] = {0U, 1U, 2U, 3U, 4U};

    montar_dag_exemplo(&grafo);

    assert(grafo_bfs(&grafo, 0U, ordem, 5U, &visitados) == 1);
    assert(visitados == 5U);
    for (size_t i = 0; i < visitados; ++i) {
        assert(ordem[i] == esperado[i]);
    }

    assert(grafo_bfs(&grafo, 0U, ordem, 4U, &visitados) == 0);
    grafo_destruir(&grafo);
    PASS("test_bfs");
}

static void test_dfs(void) {
    Grafo grafo;
    size_t ordem[5];
    size_t visitados = 0U;
    size_t esperado[] = {0U, 1U, 3U, 4U, 2U};

    montar_dag_exemplo(&grafo);

    assert(grafo_dfs(&grafo, 0U, ordem, 5U, &visitados) == 1);
    assert(visitados == 5U);
    for (size_t i = 0; i < visitados; ++i) {
        assert(ordem[i] == esperado[i]);
    }

    assert(grafo_dfs(&grafo, 8U, ordem, 5U, &visitados) == 0);
    grafo_destruir(&grafo);
    PASS("test_dfs");
}

static void test_dijkstra(void) {
    Grafo grafo;
    int distancias[5];

    montar_dag_exemplo(&grafo);

    assert(grafo_dijkstra(&grafo, 0U, distancias, 5U) == 1);
    assert(distancias[0] == 0);
    assert(distancias[1] == 1);
    assert(distancias[2] == 1);
    assert(distancias[3] == 2);
    assert(distancias[4] == 3);

    assert(grafo_dijkstra(&grafo, 5U, distancias, 5U) == 0);
    assert(grafo_dijkstra(&grafo, 0U, distancias, 4U) == 0);

    grafo_destruir(&grafo);
    PASS("test_dijkstra");
}

static void test_ordenacao_topologica(void) {
    Grafo grafo;
    size_t ordem[5];
    size_t total = 0U;
    size_t esperado[] = {0U, 1U, 2U, 3U, 4U};

    montar_dag_exemplo(&grafo);
    assert(grafo_ordenacao_topologica(&grafo, ordem, 5U, &total) == 1);
    assert(total == 5U);
    for (size_t i = 0; i < total; ++i) {
        assert(ordem[i] == esperado[i]);
    }
    grafo_destruir(&grafo);

    assert(grafo_criar_direcionado(&grafo, 3U, 1) == 1);
    assert(grafo_adicionar_aresta(&grafo, 0U, 1U) == 1);
    assert(grafo_adicionar_aresta(&grafo, 1U, 2U) == 1);
    assert(grafo_adicionar_aresta(&grafo, 2U, 0U) == 1);
    assert(grafo_ordenacao_topologica(&grafo, ordem, 5U, &total) == 0);
    grafo_destruir(&grafo);

    assert(grafo_criar(&grafo, 3U) == 1);
    assert(grafo_ordenacao_topologica(&grafo, ordem, 5U, &total) == 0);
    grafo_destruir(&grafo);

    PASS("test_ordenacao_topologica");
}

int main(void) {
    printf("=== Testes: Grafo ===\n");
    test_criar_e_destruir();
    test_criar_invalido();
    test_adicionar_aresta();
    test_remover_aresta();
    test_aresta_invalida();
    test_grafo_sem_arestas();
    test_grafo_direcionado();
    test_bfs();
    test_dfs();
    test_dijkstra();
    test_ordenacao_topologica();
    printf("Todos os testes passaram.\n");
    return 0;
}
