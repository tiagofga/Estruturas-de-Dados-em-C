#include "lista_dupla.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_inserir_buscar(void) {
    ListaDupla lista;
    lista_dupla_criar(&lista);
    assert(lista_dupla_inserir_inicio(&lista, 2) == 1);
    assert(lista_dupla_inserir_inicio(&lista, 1) == 1);
    assert(lista_dupla_inserir_fim(&lista, 3) == 1);
    assert(lista_dupla_tamanho(&lista) == 3U);
    assert(lista.inicio != NULL && lista.inicio->valor == 1);
    assert(lista.fim != NULL && lista.fim->valor == 3);
    assert(lista_dupla_buscar(&lista, 2) == 1);
    assert(lista_dupla_buscar(&lista, 99) == 0);
    lista_dupla_destruir(&lista);
    PASS("test_inserir_buscar");
}

static void test_remover_inicio_meio_fim(void) {
    ListaDupla lista;
    lista_dupla_criar(&lista);
    assert(lista_dupla_inserir_fim(&lista, 1) == 1);
    assert(lista_dupla_inserir_fim(&lista, 2) == 1);
    assert(lista_dupla_inserir_fim(&lista, 3) == 1);
    assert(lista_dupla_remover(&lista, 1) == 1);
    assert(lista.inicio != NULL && lista.inicio->valor == 2);
    assert(lista_dupla_remover(&lista, 3) == 1);
    assert(lista.fim != NULL && lista.fim->valor == 2);
    assert(lista_dupla_remover(&lista, 2) == 1);
    assert(lista.inicio == NULL && lista.fim == NULL);
    assert(lista_dupla_tamanho(&lista) == 0U);
    lista_dupla_destruir(&lista);
    PASS("test_remover_inicio_meio_fim");
}

static void test_invalidos(void) {
    assert(lista_dupla_inserir_inicio(NULL, 1) == 0);
    assert(lista_dupla_inserir_fim(NULL, 1) == 0);
    assert(lista_dupla_remover(NULL, 1) == 0);
    assert(lista_dupla_buscar(NULL, 1) == 0);
    assert(lista_dupla_tamanho(NULL) == 0U);
    PASS("test_invalidos");
}

static void test_complexidade(void) {
    assert(strcmp(lista_dupla_complexidade(),
                  "Lista duplamente encadeada: inserir inicio/fim O(1), buscar/remover por valor O(n).") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: Lista Duplamente Encadeada ===\n");
    test_inserir_buscar();
    test_remover_inicio_meio_fim();
    test_invalidos();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
