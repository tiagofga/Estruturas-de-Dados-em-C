#ifndef FILA_H
#define FILA_H

#include <stddef.h>

typedef struct {
    int *dados;
    size_t capacidade;
    size_t tamanho;
    size_t inicio;
    size_t fim;
} Fila;

int fila_criar(Fila *fila, size_t capacidade);
void fila_destruir(Fila *fila);
int fila_vazia(const Fila *fila);
int fila_cheia(const Fila *fila);
int fila_enfileirar(Fila *fila, int valor);
int fila_desenfileirar(Fila *fila, int *valor_removido);
int fila_frente(const Fila *fila, int *valor);
void fila_imprimir(const Fila *fila);

#endif
