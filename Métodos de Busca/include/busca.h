#ifndef BUSCA_H
#define BUSCA_H

#include <stddef.h>

typedef enum {
    BUSCA_LINEAR = 0,
    BUSCA_BINARIA = 1,
    BUSCA_SALTO = 2,
    BUSCA_INTERPOLACAO = 3,
    BUSCA_EXPONENCIAL = 4
} BuscaMetodo;

int         busca_procurar(const int *vetor, size_t n, int alvo, BuscaMetodo metodo, size_t *indice_encontrado);
const char *busca_nome(BuscaMetodo metodo);
const char *busca_complexidade(BuscaMetodo metodo);
const char *busca_requisito(BuscaMetodo metodo);

#endif
