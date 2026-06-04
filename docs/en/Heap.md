# Heap — Max Heap and Priority Queue

[Português](../Heap.md) | **English**

## Overview

Implementation of a **max heap** in C using a dynamic array. The largest element is always stored at the root, allowing O(1) access to the maximum value and O(log n) insertion/removal.

A heap is a complete binary tree represented implicitly in an array:

- parent of `i`: `(i - 1) / 2`
- left child of `i`: `2 * i + 1`
- right child of `i`: `2 * i + 2`

---

## Data structure

```c
/* include/heap.h */
typedef struct {
    int    *dados;
    size_t  tamanho;
    size_t  capacidade;
} Heap;
```

| Field | Type | Description |
|-------|------|-------------|
| `dados` | `int *` | Dynamically allocated array |
| `tamanho` | `size_t` | Number of stored elements |
| `capacidade` | `size_t` | Allocated capacity |

---

## Public interface

```c
int heap_criar(Heap *heap, size_t capacidade_inicial);
void heap_destruir(Heap *heap);
int heap_vazio(const Heap *heap);
int heap_inserir(Heap *heap, int valor);
int heap_consultar_raiz(const Heap *heap, int *valor);
int heap_remover_raiz(Heap *heap, int *valor_removido);
int heap_construir(Heap *heap, const int *valores, size_t n);
int heap_valido(const Heap *heap);
void heap_sort(int *vetor, size_t n);
void heap_imprimir(const Heap *heap);
const char *heap_complexidade(void);
```

---

## Operations

### `heap_inserir`

Inserts a value at the end of the array and applies sift-up until the max-heap property is restored.

- **Complexity**: O(log n)
- Automatically resizes when the capacity is reached.

### `heap_consultar_raiz`

Returns the largest element, stored at position `0`.

- **Complexity**: O(1)

### `heap_remover_raiz`

Removes the largest element, replaces the root with the last element, and applies sift-down.

- **Complexity**: O(log n)

### `heap_construir`

Builds a heap from an existing array using bottom-up heapification.

- **Complexity**: O(n)

### `heap_sort`

Sorts an array in ascending order using a max heap.

- **Complexity**: O(n log n)
- **Extra space**: O(1)
- **Stable**: no

---

## Complexity summary

| Operation | Complexity |
|-----------|------------|
| Peek maximum | O(1) |
| Insert | O(log n) |
| Remove maximum | O(log n) |
| Build heap | O(n) |
| Heap sort | O(n log n) |
| Validate heap property | O(n) |

---

## Example

```c
#include "heap.h"
#include <stdio.h>

int main(void) {
    Heap heap;
    int maior = 0;

    heap_criar(&heap, 4U);
    heap_inserir(&heap, 40);
    heap_inserir(&heap, 10);
    heap_inserir(&heap, 70);

    heap_consultar_raiz(&heap, &maior);
    printf("Maximum: %d\n", maior);

    while (heap_remover_raiz(&heap, &maior)) {
        printf("%d ", maior);
    }

    heap_destruir(&heap);
    return 0;
}
```

---

## Build and run

```bash
cd Heap
make
make run
make test
make clean
```

---

Back to the [documentation index](./README.md).
