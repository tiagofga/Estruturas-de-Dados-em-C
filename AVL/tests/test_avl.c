#include "avl.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static int vetor_ordenado(const int *vetor, size_t n) {
    for (size_t i = 1U; i < n; ++i) {
        if (vetor[i - 1U] > vetor[i]) {
            return 0;
        }
    }
    return 1;
}

static void test_inserir_buscar_balancear(void) {
    AVLNo *raiz = NULL;
    int valores[] = {30, 20, 10, 40, 50, 25, 5, 35};
    size_t n = sizeof(valores) / sizeof(valores[0]);
    for (size_t i = 0U; i < n; ++i) {
        raiz = avl_inserir(raiz, valores[i]);
        assert(avl_esta_balanceada(raiz) == 1);
    }
    assert(avl_tamanho(raiz) == n);
    assert(avl_buscar(raiz, 25) == 1);
    assert(avl_buscar(raiz, 99) == 0);
    avl_destruir(raiz);
    PASS("test_inserir_buscar_balancear");
}

static void test_percurso_em_ordem(void) {
    AVLNo *raiz = NULL;
    int valores[] = {3, 1, 4, 2};
    int saida[4];
    size_t tamanho = 0U;
    for (size_t i = 0U; i < 4U; ++i) {
        raiz = avl_inserir(raiz, valores[i]);
    }
    avl_em_ordem(raiz, saida, 4U, &tamanho);
    assert(tamanho == 4U);
    assert(vetor_ordenado(saida, tamanho) == 1);
    avl_destruir(raiz);
    PASS("test_percurso_em_ordem");
}

static void test_duplicados(void) {
    AVLNo *raiz = NULL;
    raiz = avl_inserir(raiz, 10);
    raiz = avl_inserir(raiz, 10);
    raiz = avl_inserir(raiz, 10);
    assert(avl_tamanho(raiz) == 1U);
    assert(avl_esta_balanceada(raiz) == 1);
    avl_destruir(raiz);
    PASS("test_duplicados");
}

static void test_nulos(void) {
    int vetor[2];
    size_t tamanho = 0U;
    assert(avl_buscar(NULL, 1) == 0);
    assert(avl_altura(NULL) == 0);
    assert(avl_fator_balanceamento(NULL) == 0);
    assert(avl_esta_balanceada(NULL) == 1);
    assert(avl_tamanho(NULL) == 0U);
    avl_em_ordem(NULL, vetor, 2U, &tamanho);
    assert(tamanho == 0U);
    PASS("test_nulos");
}

static void test_complexidade(void) {
    assert(strcmp(avl_complexidade(), "Arvore AVL: buscar/inserir O(log n), percurso O(n), espaco O(n).") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: AVL ===\n");
    test_inserir_buscar_balancear();
    test_percurso_em_ordem();
    test_duplicados();
    test_nulos();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
