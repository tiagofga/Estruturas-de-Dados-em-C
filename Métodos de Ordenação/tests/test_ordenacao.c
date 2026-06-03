#include "ordenacao.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

/* ------------------------------------------------------------------ */
/* Helpers                                                             */
/* ------------------------------------------------------------------ */

static int vetor_ordenado(const int *v, size_t n) {
    for (size_t i = 1U; i < n; ++i) {
        if (v[i - 1U] > v[i]) {
            return 0;
        }
    }
    return 1;
}

/* ------------------------------------------------------------------ */
/* Testes de ordenação                                                 */
/* ------------------------------------------------------------------ */

static void testar_metodo(OrdenacaoMetodo metodo) {
    int v1[] = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    const size_t n1 = sizeof(v1) / sizeof(v1[0]);
    ordenacao_ordenar(v1, n1, metodo);
    assert(vetor_ordenado(v1, n1));

    int v2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    const size_t n2 = sizeof(v2) / sizeof(v2[0]);
    ordenacao_ordenar(v2, n2, metodo);
    assert(vetor_ordenado(v2, n2));

    int v3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const size_t n3 = sizeof(v3) / sizeof(v3[0]);
    ordenacao_ordenar(v3, n3, metodo);
    assert(vetor_ordenado(v3, n3));

    int v4[] = {42};
    ordenacao_ordenar(v4, 1U, metodo);
    assert(v4[0] == 42);

    int v5[] = {7, 7, 3, 3, 1};
    const size_t n5 = sizeof(v5) / sizeof(v5[0]);
    ordenacao_ordenar(v5, n5, metodo);
    assert(vetor_ordenado(v5, n5));

    ordenacao_ordenar(NULL, 5U, metodo);
    ordenacao_ordenar(v1, 0U, metodo);
}

static void test_bubble(void) {
    testar_metodo(ORDENACAO_BUBBLE);
    PASS("test_bubble");
}

static void test_insertion(void) {
    testar_metodo(ORDENACAO_INSERTION);
    PASS("test_insertion");
}

static void test_selection(void) {
    testar_metodo(ORDENACAO_SELECTION);
    PASS("test_selection");
}

static void test_merge(void) {
    testar_metodo(ORDENACAO_MERGE);
    PASS("test_merge");
}

static void test_quick(void) {
    testar_metodo(ORDENACAO_QUICK);
    PASS("test_quick");
}

static void test_heap(void) {
    testar_metodo(ORDENACAO_HEAP);
    PASS("test_heap");
}

/* ------------------------------------------------------------------ */
/* Testes de metadados                                                 */
/* ------------------------------------------------------------------ */

static void test_complexidade(void) {
    assert(strcmp(ordenacao_complexidade(ORDENACAO_BUBBLE),
                  "Bubble: O(n) melhor, O(n^2) medio/pior, O(1) espaco, estavel.") == 0);
    assert(strcmp(ordenacao_complexidade(ORDENACAO_INSERTION),
                  "Insertion: O(n) melhor, O(n^2) medio/pior, O(1) espaco, estavel.") == 0);
    assert(strcmp(ordenacao_complexidade(ORDENACAO_SELECTION),
                  "Selection: O(n^2) todos os casos, O(1) espaco, nao estavel.") == 0);
    assert(strcmp(ordenacao_complexidade(ORDENACAO_MERGE),
                  "Merge: O(n log n) todos os casos, O(n) espaco extra, estavel.") == 0);
    assert(strcmp(ordenacao_complexidade(ORDENACAO_QUICK),
                  "Quick: O(n log n) medio, O(n^2) pior, O(log n) espaco extra, nao estavel.") == 0);
    assert(strcmp(ordenacao_complexidade(ORDENACAO_HEAP),
                  "Heap: O(n log n) todos os casos, O(1) espaco extra, nao estavel.") == 0);
    assert(strcmp(ordenacao_complexidade((OrdenacaoMetodo)99), "Metodo de ordenacao invalido.") == 0);
    PASS("test_complexidade");
}

static void test_nome(void) {
    assert(strcmp(ordenacao_nome(ORDENACAO_BUBBLE),    "Bubble Sort")    == 0);
    assert(strcmp(ordenacao_nome(ORDENACAO_INSERTION), "Insertion Sort") == 0);
    assert(strcmp(ordenacao_nome(ORDENACAO_SELECTION), "Selection Sort") == 0);
    assert(strcmp(ordenacao_nome(ORDENACAO_MERGE),     "Merge Sort")     == 0);
    assert(strcmp(ordenacao_nome(ORDENACAO_QUICK),     "Quick Sort")     == 0);
    assert(strcmp(ordenacao_nome(ORDENACAO_HEAP),      "Heap Sort")      == 0);
    assert(strcmp(ordenacao_nome((OrdenacaoMetodo)99), "Desconhecido")   == 0);
    PASS("test_nome");
}

/* ------------------------------------------------------------------ */
/* main                                                                */
/* ------------------------------------------------------------------ */

int main(void) {
    printf("=== Testes: Métodos de Ordenação ===\n");
    test_bubble();
    test_insertion();
    test_selection();
    test_merge();
    test_quick();
    test_heap();
    test_complexidade();
    test_nome();
    printf("Todos os testes passaram.\n");
    return 0;
}
