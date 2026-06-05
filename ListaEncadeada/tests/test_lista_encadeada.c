#include "lista_encadeada.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_criar_inserir_buscar(void) {
    ListaEncadeada *lista = lista_encadeada_criar();
    assert(lista != NULL);
    assert(lista_encadeada_tamanho(lista) == 0U);
    assert(lista_encadeada_inserir_inicio(lista, 2) == 1);
    assert(lista_encadeada_inserir_inicio(lista, 1) == 1);
    assert(lista_encadeada_inserir_fim(lista, 3) == 1);
    assert(lista_encadeada_tamanho(lista) == 3U);
    assert(lista_encadeada_buscar(lista, 1) == 1);
    assert(lista_encadeada_buscar(lista, 3) == 1);
    assert(lista_encadeada_buscar(lista, 99) == 0);
    lista_encadeada_destruir(lista);
    PASS("test_criar_inserir_buscar");
}

static void test_remover(void) {
    ListaEncadeada *lista = lista_encadeada_criar();
    assert(lista != NULL);
    assert(lista_encadeada_inserir_fim(lista, 1) == 1);
    assert(lista_encadeada_inserir_fim(lista, 2) == 1);
    assert(lista_encadeada_inserir_fim(lista, 3) == 1);
    assert(lista_encadeada_remover(lista, 1) == 1);
    assert(lista_encadeada_remover(lista, 3) == 1);
    assert(lista_encadeada_remover(lista, 2) == 1);
    assert(lista_encadeada_tamanho(lista) == 0U);
    assert(lista_encadeada_remover(lista, 2) == 0);
    lista_encadeada_destruir(lista);
    PASS("test_remover");
}

static void test_invalidos(void) {
    ListaEncadeada *lista = lista_encadeada_criar();
    assert(lista != NULL);
    lista_encadeada_destruir(lista);
    assert(lista_encadeada_inserir_inicio(NULL, 1) == 0);
    assert(lista_encadeada_inserir_fim(NULL, 1) == 0);
    assert(lista_encadeada_remover(NULL, 1) == 0);
    assert(lista_encadeada_buscar(NULL, 1) == 0);
    assert(lista_encadeada_tamanho(NULL) == 0U);
    PASS("test_invalidos");
}

static void test_complexidade(void) {
    assert(strcmp(lista_encadeada_complexidade(),
                  "Lista simplesmente encadeada: inserir inicio O(1), inserir fim/buscar/remover O(n).") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: Lista Encadeada ===\n");
    test_criar_inserir_buscar();
    test_remover();
    test_invalidos();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
