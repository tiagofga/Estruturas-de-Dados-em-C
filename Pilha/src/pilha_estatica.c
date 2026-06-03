#include "pilha_estatica.h"

#include <stdio.h>

int pilha_estatica_criar(PilhaEstatica *pilha, size_t capacidade) {
    if (pilha == NULL || capacidade == 0U || capacidade > PILHA_ESTATICA_CAPACIDADE_MAX) {
        return 0;
    }

    pilha->capacidade = capacidade;
    pilha->tamanho = 0;
    return 1;
}

void pilha_estatica_destruir(PilhaEstatica *pilha) {
    if (pilha == NULL) {
        return;
    }

    pilha->capacidade = 0;
    pilha->tamanho = 0;
}

int pilha_estatica_vazia(const PilhaEstatica *pilha) {
    return pilha == NULL || pilha->tamanho == 0U;
}

int pilha_estatica_cheia(const PilhaEstatica *pilha) {
    return pilha != NULL && pilha->tamanho == pilha->capacidade;
}

int pilha_estatica_empilhar(PilhaEstatica *pilha, int valor) {
    if (pilha == NULL || pilha_estatica_cheia(pilha)) {
        return 0;
    }

    pilha->dados[pilha->tamanho] = valor;
    pilha->tamanho++;
    return 1;
}

int pilha_estatica_desempilhar(PilhaEstatica *pilha, int *valor_removido) {
    if (pilha == NULL || pilha_estatica_vazia(pilha)) {
        return 0;
    }

    pilha->tamanho--;
    if (valor_removido != NULL) {
        *valor_removido = pilha->dados[pilha->tamanho];
    }

    return 1;
}

int pilha_estatica_topo(const PilhaEstatica *pilha, int *valor) {
    if (pilha == NULL || pilha_estatica_vazia(pilha) || valor == NULL) {
        return 0;
    }

    *valor = pilha->dados[pilha->tamanho - 1U];
    return 1;
}

void pilha_estatica_imprimir(const PilhaEstatica *pilha) {
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
