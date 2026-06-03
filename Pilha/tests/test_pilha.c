#include "pilha.h"
#include "pilha_estatica.h"

#include <assert.h>
#include <stdio.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_e_destruir(void) {
    Pilha pilha;
    assert(pilha_criar(&pilha, 4U) == 1);
    assert(pilha.tamanho == 0);
    assert(pilha.capacidade == 4U);
    pilha_destruir(&pilha);
    assert(pilha.dados == NULL);
    PASS("test_criar_e_destruir");
}

static void test_criar_invalido(void) {
    Pilha pilha;
    assert(pilha_criar(NULL, 4U) == 0);
    assert(pilha_criar(&pilha, 0U) == 0);
    PASS("test_criar_invalido");
}

static void test_vazia_e_cheia(void) {
    Pilha pilha;
    assert(pilha_criar(&pilha, 2U) == 1);
    assert(pilha_vazia(&pilha) == 1);
    assert(pilha_empilhar(&pilha, 1) == 1);
    assert(pilha_cheia(&pilha) == 0);
    assert(pilha_empilhar(&pilha, 2) == 1);
    assert(pilha_cheia(&pilha) == 1);
    pilha_destruir(&pilha);
    PASS("test_vazia_e_cheia");
}

static void test_empilhar_e_desempilhar(void) {
    Pilha pilha;
    int valor = 0;
    assert(pilha_criar(&pilha, 4U) == 1);

    assert(pilha_empilhar(&pilha, 10) == 1);
    assert(pilha_empilhar(&pilha, 20) == 1);
    assert(pilha_empilhar(&pilha, 30) == 1);

    assert(pilha_desempilhar(&pilha, &valor) == 1);
    assert(valor == 30);
    assert(pilha_desempilhar(&pilha, &valor) == 1);
    assert(valor == 20);
    assert(pilha_desempilhar(&pilha, &valor) == 1);
    assert(valor == 10);
    assert(pilha_vazia(&pilha) == 1);

    pilha_destruir(&pilha);
    PASS("test_empilhar_e_desempilhar");
}

static void test_topo(void) {
    Pilha pilha;
    int valor = 0;
    assert(pilha_criar(&pilha, 3U) == 1);

    assert(pilha_topo(&pilha, &valor) == 0);
    assert(pilha_empilhar(&pilha, 7) == 1);
    assert(pilha_empilhar(&pilha, 9) == 1);
    assert(pilha_topo(&pilha, &valor) == 1);
    assert(valor == 9);
    assert(pilha.tamanho == 2U);

    pilha_destruir(&pilha);
    PASS("test_topo");
}

static void test_limites(void) {
    Pilha pilha;
    int valor = 0;
    assert(pilha_criar(&pilha, 1U) == 1);

    assert(pilha_empilhar(&pilha, 42) == 1);
    assert(pilha_empilhar(&pilha, 99) == 0);
    assert(pilha_desempilhar(&pilha, &valor) == 1);
    assert(valor == 42);
    assert(pilha_desempilhar(&pilha, &valor) == 0);

    pilha_destruir(&pilha);
    PASS("test_limites");
}

static void test_estatica_criar_e_operacoes(void) {
    PilhaEstatica pilha;
    int valor = 0;

    assert(pilha_estatica_criar(&pilha, 3U) == 1);
    assert(pilha_estatica_vazia(&pilha) == 1);

    assert(pilha_estatica_empilhar(&pilha, 10) == 1);
    assert(pilha_estatica_empilhar(&pilha, 20) == 1);
    assert(pilha_estatica_topo(&pilha, &valor) == 1);
    assert(valor == 20);

    assert(pilha_estatica_desempilhar(&pilha, &valor) == 1);
    assert(valor == 20);

    pilha_estatica_destruir(&pilha);
    assert(pilha.capacidade == 0U);
    PASS("test_estatica_criar_e_operacoes");
}

static void test_estatica_limites(void) {
    PilhaEstatica pilha;

    assert(pilha_estatica_criar(&pilha, 0U) == 0);
    assert(pilha_estatica_criar(&pilha, PILHA_ESTATICA_CAPACIDADE_MAX + 1U) == 0);

    assert(pilha_estatica_criar(&pilha, 1U) == 1);
    assert(pilha_estatica_empilhar(&pilha, 1) == 1);
    assert(pilha_estatica_empilhar(&pilha, 2) == 0);
    assert(pilha_estatica_cheia(&pilha) == 1);

    pilha_estatica_destruir(&pilha);
    PASS("test_estatica_limites");
}

int main(void) {
    printf("=== Testes: Pilha ===\n");
    test_criar_e_destruir();
    test_criar_invalido();
    test_vazia_e_cheia();
    test_empilhar_e_desempilhar();
    test_topo();
    test_limites();
    test_estatica_criar_e_operacoes();
    test_estatica_limites();
    printf("Todos os testes passaram.\n");
    return 0;
}
