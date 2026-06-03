#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

int fila_criar(Fila *fila, size_t capacidade) {
    if (fila == NULL || capacidade == 0U) {
        return 0;
    }

    fila->dados = calloc(capacidade, sizeof(int));
    if (fila->dados == NULL) {
        return 0;
    }

    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;
    return 1;
}

void fila_destruir(Fila *fila) {
    if (fila == NULL) {
        return;
    }

    free(fila->dados);
    fila->dados = NULL;
    fila->capacidade = 0;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;
}

int fila_vazia(const Fila *fila) {
    return fila == NULL || fila->tamanho == 0;
}

int fila_cheia(const Fila *fila) {
    return fila != NULL && fila->tamanho == fila->capacidade;
}

int fila_enfileirar(Fila *fila, int valor) {
    if (fila == NULL || fila_cheia(fila)) {
        return 0;
    }

    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1U) % fila->capacidade;
    fila->tamanho++;
    return 1;
}

int fila_desenfileirar(Fila *fila, int *valor_removido) {
    if (fila == NULL || fila_vazia(fila)) {
        return 0;
    }

    if (valor_removido != NULL) {
        *valor_removido = fila->dados[fila->inicio];
    }

    fila->inicio = (fila->inicio + 1U) % fila->capacidade;
    fila->tamanho--;
    return 1;
}

int fila_frente(const Fila *fila, int *valor) {
    if (fila == NULL || fila_vazia(fila) || valor == NULL) {
        return 0;
    }

    *valor = fila->dados[fila->inicio];
    return 1;
}

void fila_imprimir(const Fila *fila) {
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
