#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#include <stddef.h>

#define FILA_ESTATICA_CAPACIDADE_MAX 256U

typedef struct {
    int dados[FILA_ESTATICA_CAPACIDADE_MAX];
    size_t capacidade;
    size_t tamanho;
    size_t inicio;
    size_t fim;
} FilaEstatica;

int fila_estatica_criar(FilaEstatica *fila, size_t capacidade);
void fila_estatica_destruir(FilaEstatica *fila);
int fila_estatica_vazia(const FilaEstatica *fila);
int fila_estatica_cheia(const FilaEstatica *fila);
int fila_estatica_enfileirar(FilaEstatica *fila, int valor);
int fila_estatica_desenfileirar(FilaEstatica *fila, int *valor_removido);
int fila_estatica_frente(const FilaEstatica *fila, int *valor);
void fila_estatica_imprimir(const FilaEstatica *fila);

#endif
