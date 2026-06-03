#include "fila.h"
#include "fila_estatica.h"

#include <assert.h>
#include <stdio.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_e_destruir(void) {
    Fila fila;
    assert(fila_criar(&fila, 4U) == 1);
    assert(fila.tamanho == 0);
    assert(fila.capacidade == 4U);
    fila_destruir(&fila);
    assert(fila.dados == NULL);
    PASS("test_criar_e_destruir");
}

static void test_criar_invalido(void) {
    Fila fila;
    assert(fila_criar(NULL, 4U) == 0);
    assert(fila_criar(&fila, 0U) == 0);
    PASS("test_criar_invalido");
}

static void test_vazia(void) {
    Fila fila;
    assert(fila_criar(&fila, 4U) == 1);
    assert(fila_vazia(&fila) == 1);
    fila_destruir(&fila);
    PASS("test_vazia");
}

static void test_enfileirar_e_desenfileirar(void) {
    Fila fila;
    int valor = 0;
    assert(fila_criar(&fila, 4U) == 1);

    assert(fila_enfileirar(&fila, 10) == 1);
    assert(fila_enfileirar(&fila, 20) == 1);
    assert(fila_enfileirar(&fila, 30) == 1);
    assert(fila.tamanho == 3U);

    assert(fila_desenfileirar(&fila, &valor) == 1);
    assert(valor == 10);
    assert(fila_desenfileirar(&fila, &valor) == 1);
    assert(valor == 20);
    assert(fila.tamanho == 1U);

    fila_destruir(&fila);
    PASS("test_enfileirar_e_desenfileirar");
}

static void test_frente(void) {
    Fila fila;
    int valor = 0;
    assert(fila_criar(&fila, 4U) == 1);

    fila_enfileirar(&fila, 42);
    fila_enfileirar(&fila, 99);

    assert(fila_frente(&fila, &valor) == 1);
    assert(valor == 42);
    assert(fila.tamanho == 2U);

    fila_destruir(&fila);
    PASS("test_frente");
}

static void test_frente_vazia(void) {
    Fila fila;
    int valor = 0;
    assert(fila_criar(&fila, 4U) == 1);
    assert(fila_frente(&fila, &valor) == 0);
    fila_destruir(&fila);
    PASS("test_frente_vazia");
}

static void test_cheia(void) {
    Fila fila;
    assert(fila_criar(&fila, 2U) == 1);

    assert(fila_enfileirar(&fila, 1) == 1);
    assert(fila_enfileirar(&fila, 2) == 1);
    assert(fila_cheia(&fila) == 1);
    assert(fila_enfileirar(&fila, 3) == 0);

    fila_destruir(&fila);
    PASS("test_cheia");
}

static void test_fila_circular(void) {
    Fila fila;
    int valor = 0;
    assert(fila_criar(&fila, 3U) == 1);

    fila_enfileirar(&fila, 1);
    fila_enfileirar(&fila, 2);
    fila_enfileirar(&fila, 3);

    fila_desenfileirar(&fila, &valor);
    assert(valor == 1);
    fila_desenfileirar(&fila, &valor);
    assert(valor == 2);

    assert(fila_enfileirar(&fila, 4) == 1);
    assert(fila_enfileirar(&fila, 5) == 1);

    fila_desenfileirar(&fila, &valor);
    assert(valor == 3);
    fila_desenfileirar(&fila, &valor);
    assert(valor == 4);
    fila_desenfileirar(&fila, &valor);
    assert(valor == 5);

    assert(fila_vazia(&fila) == 1);

    fila_destruir(&fila);
    PASS("test_fila_circular");
}

static void test_estatica_criar_e_operacoes(void) {
    FilaEstatica fila;
    int valor = 0;

    assert(fila_estatica_criar(&fila, 3U) == 1);
    assert(fila_estatica_vazia(&fila) == 1);

    assert(fila_estatica_enfileirar(&fila, 1) == 1);
    assert(fila_estatica_enfileirar(&fila, 2) == 1);
    assert(fila_estatica_frente(&fila, &valor) == 1);
    assert(valor == 1);

    assert(fila_estatica_desenfileirar(&fila, &valor) == 1);
    assert(valor == 1);

    fila_estatica_destruir(&fila);
    assert(fila.capacidade == 0U);
    PASS("test_estatica_criar_e_operacoes");
}

static void test_estatica_circular_e_limites(void) {
    FilaEstatica fila;
    int valor = 0;

    assert(fila_estatica_criar(&fila, 0U) == 0);
    assert(fila_estatica_criar(&fila, FILA_ESTATICA_CAPACIDADE_MAX + 1U) == 0);

    assert(fila_estatica_criar(&fila, 2U) == 1);
    assert(fila_estatica_enfileirar(&fila, 10) == 1);
    assert(fila_estatica_enfileirar(&fila, 20) == 1);
    assert(fila_estatica_enfileirar(&fila, 30) == 0);

    assert(fila_estatica_desenfileirar(&fila, &valor) == 1);
    assert(valor == 10);
    assert(fila_estatica_enfileirar(&fila, 30) == 1);

    assert(fila_estatica_desenfileirar(&fila, &valor) == 1);
    assert(valor == 20);
    assert(fila_estatica_desenfileirar(&fila, &valor) == 1);
    assert(valor == 30);

    fila_estatica_destruir(&fila);
    PASS("test_estatica_circular_e_limites");
}

int main(void) {
    printf("=== Testes: Fila ===\n");
    test_criar_e_destruir();
    test_criar_invalido();
    test_vazia();
    test_enfileirar_e_desenfileirar();
    test_frente();
    test_frente_vazia();
    test_cheia();
    test_fila_circular();
    test_estatica_criar_e_operacoes();
    test_estatica_circular_e_limites();
    printf("Todos os testes passaram.\n");
    return 0;
}
