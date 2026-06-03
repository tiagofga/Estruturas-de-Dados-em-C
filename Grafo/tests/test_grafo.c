#include "grafo.h"

#include <assert.h>
#include <stdio.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_e_destruir(void) {
    Grafo grafo;
    assert(grafo_criar(&grafo, 3U) == 1);
    assert(grafo.vertices == 3U);
    assert(grafo.matriz != NULL);
    grafo_destruir(&grafo);
    assert(grafo.matriz == NULL);
    assert(grafo.vertices == 0U);
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

int main(void) {
    printf("=== Testes: Grafo ===\n");
    test_criar_e_destruir();
    test_criar_invalido();
    test_adicionar_aresta();
    test_remover_aresta();
    test_aresta_invalida();
    test_grafo_sem_arestas();
    printf("Todos os testes passaram.\n");
    return 0;
}
