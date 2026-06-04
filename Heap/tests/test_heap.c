#include "heap.h"

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

static void test_criar_e_destruir(void) {
    Heap heap;
    assert(heap_criar(&heap, 3U) == 1);
    assert(heap.tamanho == 0U);
    assert(heap.capacidade == 3U);
    assert(heap.dados != NULL);
    heap_destruir(&heap);
    assert(heap.dados == NULL);
    assert(heap.tamanho == 0U);
    assert(heap.capacidade == 0U);
    PASS("test_criar_e_destruir");
}

static void test_criar_invalido(void) {
    Heap heap;
    assert(heap_criar(NULL, 3U) == 0);
    assert(heap_criar(&heap, 0U) == 0);
    PASS("test_criar_invalido");
}

static void test_inserir_e_consultar_raiz(void) {
    Heap heap;
    int raiz = 0;
    assert(heap_criar(&heap, 2U) == 1);
    assert(heap_inserir(&heap, 10) == 1);
    assert(heap_inserir(&heap, 50) == 1);
    assert(heap_inserir(&heap, 20) == 1);
    assert(heap_consultar_raiz(&heap, &raiz) == 1);
    assert(raiz == 50);
    assert(heap_valido(&heap) == 1);
    heap_destruir(&heap);
    PASS("test_inserir_e_consultar_raiz");
}

static void test_remover_raiz(void) {
    Heap heap;
    int removido = 0;
    assert(heap_criar(&heap, 4U) == 1);
    assert(heap_inserir(&heap, 40) == 1);
    assert(heap_inserir(&heap, 10) == 1);
    assert(heap_inserir(&heap, 70) == 1);
    assert(heap_inserir(&heap, 30) == 1);

    assert(heap_remover_raiz(&heap, &removido) == 1);
    assert(removido == 70);
    assert(heap_valido(&heap) == 1);
    assert(heap_remover_raiz(&heap, &removido) == 1);
    assert(removido == 40);
    assert(heap_remover_raiz(&heap, &removido) == 1);
    assert(removido == 30);
    assert(heap_remover_raiz(&heap, &removido) == 1);
    assert(removido == 10);
    assert(heap_remover_raiz(&heap, &removido) == 0);

    heap_destruir(&heap);
    PASS("test_remover_raiz");
}

static void test_construir_heap(void) {
    const int valores[] = {4, 1, 9, 3, 7, 8};
    Heap heap;
    int raiz = 0;
    assert(heap_construir(&heap, valores, sizeof(valores) / sizeof(valores[0])) == 1);
    assert(heap_valido(&heap) == 1);
    assert(heap_consultar_raiz(&heap, &raiz) == 1);
    assert(raiz == 9);
    heap_destruir(&heap);
    PASS("test_construir_heap");
}

static void test_heap_sort(void) {
    int vetor[] = {5, 1, 9, 3, 7, 2, 8, 4, 6};
    const size_t n = sizeof(vetor) / sizeof(vetor[0]);
    heap_sort(vetor, n);
    assert(vetor_ordenado(vetor, n));
    PASS("test_heap_sort");
}

static void test_operacoes_invalidas(void) {
    Heap heap;
    int valor = 0;
    assert(heap_consultar_raiz(NULL, &valor) == 0);
    assert(heap_remover_raiz(NULL, &valor) == 0);
    assert(heap_inserir(NULL, 1) == 0);
    assert(heap_valido(NULL) == 0);

    assert(heap_criar(&heap, 2U) == 1);
    assert(heap_consultar_raiz(&heap, &valor) == 0);
    assert(heap_remover_raiz(&heap, &valor) == 0);
    heap_destruir(&heap);
    PASS("test_operacoes_invalidas");
}

static void test_complexidade(void) {
    assert(strcmp(heap_complexidade(),
                  "Heap maximo: consultar raiz O(1), inserir/remover O(log n), construir O(n), heapsort O(n log n).") == 0);
    PASS("test_complexidade");
}

int main(void) {
    printf("=== Testes: Heap ===\n");
    test_criar_e_destruir();
    test_criar_invalido();
    test_inserir_e_consultar_raiz();
    test_remover_raiz();
    test_construir_heap();
    test_heap_sort();
    test_operacoes_invalidas();
    test_complexidade();
    printf("Todos os testes passaram.\n");
    return 0;
}
