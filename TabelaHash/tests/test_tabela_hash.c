#include "tabela_hash.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_e_destruir(void) {
    TabelaHash tabela;
    assert(tabela_hash_criar(&tabela, 5U) == 1);
    assert(tabela.capacidade == 5U);
    assert(tabela.tamanho == 0U);
    assert(tabela.baldes != NULL);
    tabela_hash_destruir(&tabela);
    assert(tabela.baldes == NULL);
    assert(tabela.capacidade == 0U);
    assert(tabela.tamanho == 0U);
    PASS("test_criar_e_destruir");
}

static void test_inserir_buscar_atualizar(void) {
    TabelaHash tabela;
    int valor = 0;
    assert(tabela_hash_criar(&tabela, 3U) == 1);
    assert(tabela_hash_inserir(&tabela, 1, 10) == 1);
    assert(tabela_hash_inserir(&tabela, 4, 40) == 1);
    assert(tabela_hash_buscar(&tabela, 1, &valor) == 1);
    assert(valor == 10);
    assert(tabela_hash_buscar(&tabela, 4, &valor) == 1);
    assert(valor == 40);
    assert(tabela_hash_inserir(&tabela, 1, 11) == 1);
    assert(tabela_hash_tamanho(&tabela) == 2U);
    assert(tabela_hash_buscar(&tabela, 1, &valor) == 1);
    assert(valor == 11);
    tabela_hash_destruir(&tabela);
    PASS("test_inserir_buscar_atualizar");
}

static void test_remover(void) {
    TabelaHash tabela;
    int valor = 0;
    assert(tabela_hash_criar(&tabela, 2U) == 1);
    assert(tabela_hash_inserir(&tabela, 1, 10) == 1);
    assert(tabela_hash_inserir(&tabela, 3, 30) == 1);
    assert(tabela_hash_remover(&tabela, 1) == 1);
    assert(tabela_hash_buscar(&tabela, 1, &valor) == 0);
    assert(tabela_hash_tamanho(&tabela) == 1U);
    assert(tabela_hash_remover(&tabela, 99) == 0);
    tabela_hash_destruir(&tabela);
    PASS("test_remover");
}

static void test_invalidos(void) {
    TabelaHash tabela;
    int valor = 0;
    assert(tabela_hash_criar(NULL, 5U) == 0);
    assert(tabela_hash_criar(&tabela, 0U) == 0);
    assert(tabela_hash_inserir(NULL, 1, 1) == 0);
    assert(tabela_hash_buscar(NULL, 1, &valor) == 0);
    assert(tabela_hash_remover(NULL, 1) == 0);
    PASS("test_invalidos");
}

static void test_complexidade(void) {
    assert(strcmp(tabela_hash_complexidade(),
                  "Tabela hash com encadeamento separado: inserir/buscar/remover O(1) medio, O(n) pior caso.") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: Tabela Hash ===\n");
    test_criar_e_destruir();
    test_inserir_buscar_atualizar();
    test_remover();
    test_invalidos();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
