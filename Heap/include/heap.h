#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef struct {
    int *dados;
    size_t tamanho;
    size_t capacidade;
} Heap;

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

#endif
