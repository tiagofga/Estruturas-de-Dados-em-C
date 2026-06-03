#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

int pilha_criar(Pilha *pilha, size_t capacidade) {
    if (pilha == NULL || capacidade == 0U) {
        return 0;
    }

    pilha->dados = calloc(capacidade, sizeof(int));
    if (pilha->dados == NULL) {
        return 0;
    }

    pilha->capacidade = capacidade;
    pilha->tamanho = 0;
    return 1;
}

void pilha_destruir(Pilha *pilha) {
    if (pilha == NULL) {
        return;
    }

    free(pilha->dados);
    pilha->dados = NULL;
    pilha->capacidade = 0;
    pilha->tamanho = 0;
}

int pilha_vazia(const Pilha *pilha) {
    return pilha == NULL || pilha->tamanho == 0;
}

int pilha_cheia(const Pilha *pilha) {
    return pilha != NULL && pilha->tamanho == pilha->capacidade;
}

int pilha_empilhar(Pilha *pilha, int valor) {
    if (pilha == NULL || pilha_cheia(pilha)) {
        return 0;
    }

    pilha->dados[pilha->tamanho] = valor;
    pilha->tamanho++;
    return 1;
}

int pilha_desempilhar(Pilha *pilha, int *valor_removido) {
    if (pilha == NULL || pilha_vazia(pilha)) {
        return 0;
    }

    pilha->tamanho--;
    if (valor_removido != NULL) {
        *valor_removido = pilha->dados[pilha->tamanho];
    }

    return 1;
}

int pilha_topo(const Pilha *pilha, int *valor) {
    if (pilha == NULL || pilha_vazia(pilha) || valor == NULL) {
        return 0;
    }

    *valor = pilha->dados[pilha->tamanho - 1U];
    return 1;
}

void pilha_imprimir(const Pilha *pilha) {
    if (pilha == NULL) {
        return;
    }

    printf("[ ");
    for (size_t i = 0; i < pilha->tamanho; ++i) {
        printf("%d", pilha->dados[i]);
        if (i + 1U < pilha->tamanho) {
            printf(", ");
        }
    }
    printf(" ]\n");
}
