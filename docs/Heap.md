# Heap — Heap Máximo e Fila de Prioridade

## Visão geral

Implementação de um **heap máximo** em C usando vetor dinâmico. O maior elemento fica sempre na raiz, permitindo consulta em O(1) e remoção/inserção em O(log n).

O heap é uma árvore binária completa representada implicitamente em um array:

- pai de `i`: `(i - 1) / 2`
- filho esquerdo de `i`: `2 * i + 1`
- filho direito de `i`: `2 * i + 2`

---

## Estrutura de dados

```c
/* include/heap.h */
typedef struct {
    int    *dados;
    size_t  tamanho;
    size_t  capacidade;
} Heap;
```

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `dados` | `int *` | Vetor alocado dinamicamente |
| `tamanho` | `size_t` | Quantidade de elementos armazenados |
| `capacidade` | `size_t` | Capacidade alocada no vetor |

---

## Interface pública

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

## Operações detalhadas

### `heap_inserir`

Insere um valor no fim do vetor e aplica subida (*sift-up*) até restaurar a propriedade de heap máximo.

- **Complexidade**: O(log n)
- Redimensiona automaticamente quando a capacidade é atingida.

### `heap_consultar_raiz`

Consulta o maior elemento, localizado na posição `0`.

- **Complexidade**: O(1)

### `heap_remover_raiz`

Remove o maior elemento, substitui a raiz pelo último elemento e aplica descida (*sift-down*).

- **Complexidade**: O(log n)

### `heap_construir`

Constrói um heap a partir de um vetor existente usando heapificação de baixo para cima.

- **Complexidade**: O(n)

### `heap_sort`

Ordena um vetor em ordem crescente usando heap máximo.

- **Complexidade**: O(n log n)
- **Espaço extra**: O(1)
- **Estável**: não

---

## Complexidade resumida

| Operação | Complexidade |
|----------|-------------|
| Consultar maior elemento | O(1) |
| Inserir | O(log n) |
| Remover maior elemento | O(log n) |
| Construir heap | O(n) |
| Heapsort | O(n log n) |
| Verificar propriedade de heap | O(n) |

---

## Exemplo de uso

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
    printf("Maior: %d\n", maior);

    while (heap_remover_raiz(&heap, &maior)) {
        printf("%d ", maior);
    }

    heap_destruir(&heap);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Heap
make
make run
make test
make clean
```

---

Voltar para o [índice da documentação](./README.md).
