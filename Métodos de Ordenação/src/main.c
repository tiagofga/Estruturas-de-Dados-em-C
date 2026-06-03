#include "ordenacao.h"

#include <stdio.h>
#include <string.h>

#define N 8

int main(void) {
    const int original[N] = {64, 34, 25, 12, 22, 11, 90, 1};
    int vetor[N];
    OrdenacaoMetodo metodos[] = {
        ORDENACAO_BUBBLE,
        ORDENACAO_INSERTION,
        ORDENACAO_SELECTION,
        ORDENACAO_MERGE,
        ORDENACAO_QUICK,
        ORDENACAO_HEAP
    };
    const size_t total = sizeof(metodos) / sizeof(metodos[0]);

    printf("Vetor original:  ");
    ordenacao_imprimir(original, N);
    printf("\n");

    for (size_t i = 0U; i < total; ++i) {
        memcpy(vetor, original, sizeof(original));
        ordenacao_ordenar(vetor, N, metodos[i]);
        printf("%-16s ", ordenacao_nome(metodos[i]));
        ordenacao_imprimir(vetor, N);
        printf("  %s\n\n", ordenacao_complexidade(metodos[i]));
    }

    return 0;
}
