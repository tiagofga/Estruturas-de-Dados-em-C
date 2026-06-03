#include "arvore.h"

#include <assert.h>
#include <stdio.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_inserir_raiz_nula(void) {
    No *raiz = NULL;
    raiz = arvore_inserir(raiz, 10);
    assert(raiz != NULL);
    assert(raiz->valor == 10);
    assert(raiz->esquerda == NULL);
    assert(raiz->direita == NULL);
    arvore_destruir(raiz);
    PASS("test_inserir_raiz_nula");
}

static void test_inserir_esquerda_direita(void) {
    No *raiz = NULL;
    raiz = arvore_inserir(raiz, 20);
    raiz = arvore_inserir(raiz, 10);
    raiz = arvore_inserir(raiz, 30);

    assert(raiz->valor == 20);
    assert(raiz->esquerda->valor == 10);
    assert(raiz->direita->valor == 30);

    arvore_destruir(raiz);
    PASS("test_inserir_esquerda_direita");
}

static void test_inserir_duplicado(void) {
    No *raiz = NULL;
    raiz = arvore_inserir(raiz, 10);
    raiz = arvore_inserir(raiz, 10);

    assert(raiz->esquerda == NULL);
    assert(raiz->direita == NULL);

    arvore_destruir(raiz);
    PASS("test_inserir_duplicado");
}

static void test_buscar_encontrado(void) {
    No *raiz = NULL;
    raiz = arvore_inserir(raiz, 40);
    raiz = arvore_inserir(raiz, 20);
    raiz = arvore_inserir(raiz, 60);
    raiz = arvore_inserir(raiz, 10);
    raiz = arvore_inserir(raiz, 30);

    assert(arvore_buscar(raiz, 40) == 1);
    assert(arvore_buscar(raiz, 10) == 1);
    assert(arvore_buscar(raiz, 30) == 1);
    assert(arvore_buscar(raiz, 60) == 1);

    arvore_destruir(raiz);
    PASS("test_buscar_encontrado");
}

static void test_buscar_nao_encontrado(void) {
    No *raiz = NULL;
    raiz = arvore_inserir(raiz, 40);
    raiz = arvore_inserir(raiz, 20);

    assert(arvore_buscar(raiz, 99) == 0);
    assert(arvore_buscar(raiz, 0) == 0);

    arvore_destruir(raiz);
    PASS("test_buscar_nao_encontrado");
}

static void test_buscar_arvore_vazia(void) {
    assert(arvore_buscar(NULL, 10) == 0);
    PASS("test_buscar_arvore_vazia");
}

static void test_destruir_nulo(void) {
    arvore_destruir(NULL);
    PASS("test_destruir_nulo");
}

int main(void) {
    printf("=== Testes: Árvore ===\n");
    test_inserir_raiz_nula();
    test_inserir_esquerda_direita();
    test_inserir_duplicado();
    test_buscar_encontrado();
    test_buscar_nao_encontrado();
    test_buscar_arvore_vazia();
    test_destruir_nulo();
    printf("Todos os testes passaram.\n");
    return 0;
}
