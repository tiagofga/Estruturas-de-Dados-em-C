#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stddef.h>

typedef enum {
    ORDENACAO_BUBBLE    = 0,
    ORDENACAO_INSERTION = 1,
    ORDENACAO_SELECTION = 2,
    ORDENACAO_MERGE     = 3,
    ORDENACAO_QUICK     = 4,
    ORDENACAO_HEAP      = 5
} OrdenacaoMetodo;

void        ordenacao_ordenar(int *vetor, size_t n, OrdenacaoMetodo metodo);
const char *ordenacao_complexidade(OrdenacaoMetodo metodo);
const char *ordenacao_nome(OrdenacaoMetodo metodo);
void        ordenacao_imprimir(const int *vetor, size_t n);

#endif
