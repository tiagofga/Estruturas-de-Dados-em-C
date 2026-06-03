#include "fila_estatica.h"

#include <stdio.h>

int fila_estatica_criar(FilaEstatica *fila, size_t capacidade) {
    if (fila == NULL || capacidade == 0U || capacidade > FILA_ESTATICA_CAPACIDADE_MAX) {
        return 0;
    }

    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;
    return 1;
}

void fila_estatica_destruir(FilaEstatica *fila) {
    if (fila == NULL) {
        return;
    }

    fila->capacidade = 0;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;
}

int fila_estatica_vazia(const FilaEstatica *fila) {
    return fila == NULL || fila->tamanho == 0U;
}

int fila_estatica_cheia(const FilaEstatica *fila) {
    return fila != NULL && fila->tamanho == fila->capacidade;
}

int fila_estatica_enfileirar(FilaEstatica *fila, int valor) {
    if (fila == NULL || fila_estatica_cheia(fila)) {
        return 0;
    }

    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1U) % fila->capacidade;
    fila->tamanho++;
    return 1;
}

int fila_estatica_desenfileirar(FilaEstatica *fila, int *valor_removido) {
    if (fila == NULL || fila_estatica_vazia(fila)) {
        return 0;
    }

    if (valor_removido != NULL) {
        *valor_removido = fila->dados[fila->inicio];
    }

    fila->inicio = (fila->inicio + 1U) % fila->capacidade;
    fila->tamanho--;
    return 1;
}

int fila_estatica_frente(const FilaEstatica *fila, int *valor) {
    if (fila == NULL || fila_estatica_vazia(fila) || valor == NULL) {
        return 0;
    }

    *valor = fila->dados[fila->inicio];
    return 1;
}

void fila_estatica_imprimir(const FilaEstatica *fila) {
    if (fila == NULL) {
        return;
    }

    printf("[ ");
    for (size_t i = 0; i < fila->tamanho; ++i) {
        size_t indice = (fila->inicio + i) % fila->capacidade;
        printf("%d", fila->dados[indice]);
        if (i + 1U < fila->tamanho) {
            printf(", ");
        }
    }
    printf(" ]\n");
}
