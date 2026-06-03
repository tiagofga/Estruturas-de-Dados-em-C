#include "lista.h"
#include "lista_estatica.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_e_destruir(void) {
    Lista lista;
    assert(lista_criar(&lista, 4U) == 1);
    assert(lista.tamanho == 0);
    assert(lista.capacidade == 4U);
    lista_destruir(&lista);
    assert(lista.dados == NULL);
    PASS("test_criar_e_destruir");
}

static void test_criar_invalido(void) {
    Lista lista;
    assert(lista_criar(NULL, 4U) == 0);
    assert(lista_criar(&lista, 0U) == 0);
    PASS("test_criar_invalido");
}

static void test_vazia(void) {
    Lista lista;
    assert(lista_criar(&lista, 4U) == 1);
    assert(lista_vazia(&lista) == 1);
    lista_destruir(&lista);
    PASS("test_vazia");
}

static void test_inserir_fim(void) {
    Lista lista;
    assert(lista_criar(&lista, 2U) == 1);

    assert(lista_inserir_fim(&lista, 10) == 1);
    assert(lista_inserir_fim(&lista, 20) == 1);
    assert(lista.tamanho == 2U);
    assert(lista_vazia(&lista) == 0);

    assert(lista.dados[0] == 10);
    assert(lista.dados[1] == 20);

    lista_destruir(&lista);
    PASS("test_inserir_fim");
}

static void test_redimensionamento(void) {
    Lista lista;
    assert(lista_criar(&lista, 1U) == 1);

    for (int i = 0; i < 8; ++i) {
        assert(lista_inserir_fim(&lista, i * 10) == 1);
    }
    assert(lista.tamanho == 8U);
    assert(lista.dados[7] == 70);

    lista_destruir(&lista);
    PASS("test_redimensionamento");
}

static void test_inserir_posicao(void) {
    Lista lista;
    assert(lista_criar(&lista, 4U) == 1);

    lista_inserir_fim(&lista, 10);
    lista_inserir_fim(&lista, 30);
    assert(lista_inserir_posicao(&lista, 1U, 20) == 1);

    assert(lista.tamanho == 3U);
    assert(lista.dados[0] == 10);
    assert(lista.dados[1] == 20);
    assert(lista.dados[2] == 30);

    lista_destruir(&lista);
    PASS("test_inserir_posicao");
}

static void test_inserir_posicao_invalida(void) {
    Lista lista;
    assert(lista_criar(&lista, 4U) == 1);
    lista_inserir_fim(&lista, 10);

    assert(lista_inserir_posicao(&lista, 5U, 99) == 0);

    lista_destruir(&lista);
    PASS("test_inserir_posicao_invalida");
}

static void test_remover_posicao(void) {
    Lista lista;
    int removido = 0;
    assert(lista_criar(&lista, 4U) == 1);

    lista_inserir_fim(&lista, 10);
    lista_inserir_fim(&lista, 20);
    lista_inserir_fim(&lista, 30);

    assert(lista_remover_posicao(&lista, 1U, &removido) == 1);
    assert(removido == 20);
    assert(lista.tamanho == 2U);
    assert(lista.dados[0] == 10);
    assert(lista.dados[1] == 30);

    lista_destruir(&lista);
    PASS("test_remover_posicao");
}

static void test_remover_posicao_invalida(void) {
    Lista lista;
    assert(lista_criar(&lista, 4U) == 1);

    assert(lista_remover_posicao(&lista, 0U, NULL) == 0);

    lista_inserir_fim(&lista, 10);
    assert(lista_remover_posicao(&lista, 5U, NULL) == 0);

    lista_destruir(&lista);
    PASS("test_remover_posicao_invalida");
}

static void test_buscar(void) {
    Lista lista;
    size_t posicao = 999U;
    assert(lista_criar(&lista, 4U) == 1);

    lista_inserir_fim(&lista, 10);
    lista_inserir_fim(&lista, 20);
    lista_inserir_fim(&lista, 30);

    assert(lista_buscar(&lista, 20, &posicao) == 1);
    assert(posicao == 1U);

    assert(lista_buscar(&lista, 99, NULL) == 0);

    lista_destruir(&lista);
    PASS("test_buscar");
}

static void test_buscar_metodo(void) {
    Lista lista;
    size_t posicao = 999U;
    assert(lista_criar(&lista, 4U) == 1);

    lista_inserir_fim(&lista, 30);
    lista_inserir_fim(&lista, 10);
    lista_inserir_fim(&lista, 20);

    assert(lista_buscar_metodo(&lista, 20, &posicao, LISTA_BUSCA_LINEAR) == 1);
    assert(posicao == 2U);

    assert(lista_ordenar(&lista, LISTA_ORDENACAO_BUBBLE) == 1);
    assert(lista_buscar_metodo(&lista, 20, &posicao, LISTA_BUSCA_BINARIA) == 1);
    assert(posicao == 1U);

    assert(lista_buscar_metodo(&lista, 99, NULL, LISTA_BUSCA_BINARIA) == 0);
    assert(lista_buscar_metodo(&lista, 20, &posicao, (ListaMetodoBusca)99) == 0);

    lista_destruir(&lista);
    PASS("test_buscar_metodo");
}

static void test_ordenar_metodos(void) {
    Lista lista;
    assert(lista_criar(&lista, 4U) == 1);
    lista_inserir_fim(&lista, 4);
    lista_inserir_fim(&lista, 1);
    lista_inserir_fim(&lista, 3);
    lista_inserir_fim(&lista, 2);

    assert(lista_ordenar(&lista, LISTA_ORDENACAO_INSERTION) == 1);
    assert(lista.dados[0] == 1);
    assert(lista.dados[1] == 2);
    assert(lista.dados[2] == 3);
    assert(lista.dados[3] == 4);

    lista.dados[0] = 3;
    lista.dados[1] = 1;
    lista.dados[2] = 4;
    lista.dados[3] = 2;
    assert(lista_ordenar(&lista, LISTA_ORDENACAO_SELECTION) == 1);
    assert(lista.dados[0] == 1);
    assert(lista.dados[1] == 2);
    assert(lista.dados[2] == 3);
    assert(lista.dados[3] == 4);

    assert(lista_ordenar(&lista, (ListaMetodoOrdenacao)99) == 0);

    lista_destruir(&lista);
    PASS("test_ordenar_metodos");
}

static void test_complexidade_metodos(void) {
    assert(strcmp(lista_complexidade_busca(LISTA_BUSCA_LINEAR), "Busca linear: O(n) tempo, O(1) espaco.") == 0);
    assert(strcmp(lista_complexidade_busca(LISTA_BUSCA_BINARIA),
                  "Busca binaria: O(log n) tempo, O(1) espaco (requer lista ordenada).") == 0);
    assert(strcmp(lista_complexidade_busca((ListaMetodoBusca)99), "Metodo de busca invalido.") == 0);

    assert(strcmp(lista_complexidade_ordenacao(LISTA_ORDENACAO_BUBBLE),
                  "Bubble sort: O(n^2) medio/pior, O(1) espaco.") == 0);
    assert(strcmp(lista_complexidade_ordenacao(LISTA_ORDENACAO_INSERTION),
                  "Insertion sort: O(n) melhor, O(n^2) medio/pior, O(1) espaco.") == 0);
    assert(strcmp(lista_complexidade_ordenacao(LISTA_ORDENACAO_SELECTION),
                  "Selection sort: O(n^2) em todos os casos, O(1) espaco.") == 0);
    assert(strcmp(lista_complexidade_ordenacao((ListaMetodoOrdenacao)99), "Metodo de ordenacao invalido.") == 0);

    PASS("test_complexidade_metodos");
}

static void test_estatica_criar_e_operacoes(void) {
    ListaEstatica lista;
    int removido = 0;
    size_t posicao = 0;

    assert(lista_estatica_criar(&lista, 4U) == 1);
    assert(lista_estatica_vazia(&lista) == 1);

    assert(lista_estatica_inserir_fim(&lista, 10) == 1);
    assert(lista_estatica_inserir_fim(&lista, 30) == 1);
    assert(lista_estatica_inserir_posicao(&lista, 1U, 20) == 1);

    assert(lista_estatica_buscar(&lista, 20, &posicao) == 1);
    assert(posicao == 1U);
    assert(lista_estatica_remover_posicao(&lista, 1U, &removido) == 1);
    assert(removido == 20);

    lista_estatica_destruir(&lista);
    assert(lista.capacidade == 0U);
    PASS("test_estatica_criar_e_operacoes");
}

static void test_estatica_limites(void) {
    ListaEstatica lista;

    assert(lista_estatica_criar(&lista, 0U) == 0);
    assert(lista_estatica_criar(&lista, LISTA_ESTATICA_CAPACIDADE_MAX + 1U) == 0);

    assert(lista_estatica_criar(&lista, 2U) == 1);
    assert(lista_estatica_inserir_fim(&lista, 1) == 1);
    assert(lista_estatica_inserir_fim(&lista, 2) == 1);
    assert(lista_estatica_cheia(&lista) == 1);
    assert(lista_estatica_inserir_fim(&lista, 3) == 0);

    lista_estatica_destruir(&lista);
    PASS("test_estatica_limites");
}

int main(void) {
    printf("=== Testes: Lista ===\n");
    test_criar_e_destruir();
    test_criar_invalido();
    test_vazia();
    test_inserir_fim();
    test_redimensionamento();
    test_inserir_posicao();
    test_inserir_posicao_invalida();
    test_remover_posicao();
    test_remover_posicao_invalida();
    test_buscar();
    test_buscar_metodo();
    test_ordenar_metodos();
    test_complexidade_metodos();
    test_estatica_criar_e_operacoes();
    test_estatica_limites();
    printf("Todos os testes passaram.\n");
    return 0;
}
