#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

static void heap_trocar(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

static int heap_redimensionar(Heap *heap, size_t nova_capacidade) {
    int *novo_buffer = NULL;

    if (heap == NULL || nova_capacidade == 0U) {
        return 0;
    }

    novo_buffer = realloc(heap->dados, nova_capacidade * sizeof(int));
    if (novo_buffer == NULL) {
        return 0;
    }

    heap->dados = novo_buffer;
    heap->capacidade = nova_capacidade;
    return 1;
}

static void heap_subir(Heap *heap, size_t indice) {
    while (indice > 0U) {
        const size_t pai = (indice - 1U) / 2U;
        if (heap->dados[pai] >= heap->dados[indice]) {
            break;
        }

        heap_trocar(&heap->dados[pai], &heap->dados[indice]);
        indice = pai;
    }
}

static void heap_descer_array(int *dados, size_t tamanho, size_t indice) {
    while (1) {
        const size_t esquerda = 2U * indice + 1U;
        const size_t direita = 2U * indice + 2U;
        size_t maior = indice;

        if (esquerda < tamanho && dados[esquerda] > dados[maior]) {
            maior = esquerda;
        }

        if (direita < tamanho && dados[direita] > dados[maior]) {
            maior = direita;
        }

        if (maior == indice) {
            break;
        }

        heap_trocar(&dados[indice], &dados[maior]);
        indice = maior;
    }
}

static void heap_descer(Heap *heap, size_t indice) {
    heap_descer_array(heap->dados, heap->tamanho, indice);
}

static void heap_heapificar_array(int *dados, size_t n) {
    if (dados == NULL || n <= 1U) {
        return;
    }

    for (size_t i = n / 2U; i-- > 0U;) {
        heap_descer_array(dados, n, i);
    }
}

int heap_criar(Heap *heap, size_t capacidade_inicial) {
    if (heap == NULL || capacidade_inicial == 0U) {
        return 0;
    }

    heap->dados = calloc(capacidade_inicial, sizeof(int));
    if (heap->dados == NULL) {
        return 0;
    }

    heap->tamanho = 0U;
    heap->capacidade = capacidade_inicial;
    return 1;
}

void heap_destruir(Heap *heap) {
    if (heap == NULL) {
        return;
    }

    free(heap->dados);
    heap->dados = NULL;
    heap->tamanho = 0U;
    heap->capacidade = 0U;
}

int heap_vazio(const Heap *heap) {
    return heap == NULL || heap->tamanho == 0U;
}

int heap_inserir(Heap *heap, int valor) {
    if (heap == NULL || heap->dados == NULL) {
        return 0;
    }

    if (heap->tamanho == heap->capacidade) {
        size_t nova_capacidade = 0U;
        if (heap->capacidade > ((size_t)-1) / 2U) {
            return 0;
        }
        nova_capacidade = heap->capacidade * 2U;
        if (!heap_redimensionar(heap, nova_capacidade)) {
            return 0;
        }
    }

    heap->dados[heap->tamanho] = valor;
    heap_subir(heap, heap->tamanho);
    heap->tamanho++;
    return 1;
}

int heap_consultar_raiz(const Heap *heap, int *valor) {
    if (heap == NULL || heap->dados == NULL || heap_vazio(heap) || valor == NULL) {
        return 0;
    }

    *valor = heap->dados[0];
    return 1;
}

int heap_remover_raiz(Heap *heap, int *valor_removido) {
    if (heap == NULL || heap->dados == NULL || heap_vazio(heap)) {
        return 0;
    }

    if (valor_removido != NULL) {
        *valor_removido = heap->dados[0];
    }

    heap->tamanho--;
    if (heap->tamanho > 0U) {
        heap->dados[0] = heap->dados[heap->tamanho];
        heap_descer(heap, 0U);
    }

    return 1;
}

int heap_construir(Heap *heap, const int *valores, size_t n) {
    if (heap == NULL || valores == NULL || n == 0U) {
        return 0;
    }

    if (!heap_criar(heap, n)) {
        return 0;
    }

    for (size_t i = 0U; i < n; ++i) {
        heap->dados[i] = valores[i];
    }
    heap->tamanho = n;
    heap_heapificar_array(heap->dados, heap->tamanho);
    return 1;
}

int heap_valido(const Heap *heap) {
    if (heap == NULL || heap->dados == NULL) {
        return 0;
    }

    for (size_t i = 0U; i < heap->tamanho; ++i) {
        const size_t esquerda = 2U * i + 1U;
        const size_t direita = 2U * i + 2U;

        if (esquerda < heap->tamanho && heap->dados[i] < heap->dados[esquerda]) {
            return 0;
        }
        if (direita < heap->tamanho && heap->dados[i] < heap->dados[direita]) {
            return 0;
        }
    }

    return 1;
}

void heap_sort(int *vetor, size_t n) {
    if (vetor == NULL || n <= 1U) {
        return;
    }

    heap_heapificar_array(vetor, n);
    for (size_t fim = n; fim > 1U; --fim) {
        heap_trocar(&vetor[0], &vetor[fim - 1U]);
        heap_descer_array(vetor, fim - 1U, 0U);
    }
}

void heap_imprimir(const Heap *heap) {
    if (heap == NULL || heap->dados == NULL) {
        return;
    }

    printf("[ ");
    for (size_t i = 0U; i < heap->tamanho; ++i) {
        printf("%d", heap->dados[i]);
        if (i + 1U < heap->tamanho) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

const char *heap_complexidade(void) {
    return "Heap maximo: consultar raiz O(1), inserir/remover O(log n), construir O(n), heapsort O(n log n).";
}
