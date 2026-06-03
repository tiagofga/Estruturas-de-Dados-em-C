#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

static int lista_redimensionar(Lista *lista, size_t nova_capacidade) {
    int *novo_buffer = realloc(lista->dados, nova_capacidade * sizeof(int));
    if (novo_buffer == NULL) {
        return 0;
    }

    lista->dados = novo_buffer;
    lista->capacidade = nova_capacidade;
    return 1;
}

int lista_criar(Lista *lista, size_t capacidade_inicial) {
    if (lista == NULL || capacidade_inicial == 0) {
        return 0;
    }

    lista->dados = calloc(capacidade_inicial, sizeof(int));
    if (lista->dados == NULL) {
        return 0;
    }

    lista->tamanho = 0;
    lista->capacidade = capacidade_inicial;
    return 1;
}

void lista_destruir(Lista *lista) {
    if (lista == NULL) {
        return;
    }

    free(lista->dados);
    lista->dados = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

int lista_vazia(const Lista *lista) {
    return lista == NULL || lista->tamanho == 0;
}

int lista_inserir_fim(Lista *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }

    if (lista->tamanho == lista->capacidade && !lista_redimensionar(lista, lista->capacidade * 2U)) {
        return 0;
    }

    lista->dados[lista->tamanho++] = valor;
    return 1;
}

int lista_inserir_posicao(Lista *lista, size_t posicao, int valor) {
    if (lista == NULL || posicao > lista->tamanho) {
        return 0;
    }

    if (lista->tamanho == lista->capacidade && !lista_redimensionar(lista, lista->capacidade * 2U)) {
        return 0;
    }

    for (size_t i = lista->tamanho; i > posicao; --i) {
        lista->dados[i] = lista->dados[i - 1U];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return 1;
}

int lista_remover_posicao(Lista *lista, size_t posicao, int *valor_removido) {
    if (lista == NULL || lista_vazia(lista) || posicao >= lista->tamanho) {
        return 0;
    }

    if (valor_removido != NULL) {
        *valor_removido = lista->dados[posicao];
    }

    for (size_t i = posicao; i + 1U < lista->tamanho; ++i) {
        lista->dados[i] = lista->dados[i + 1U];
    }

    lista->tamanho--;
    return 1;
}

int lista_buscar(const Lista *lista, int valor, size_t *posicao_encontrada) {
    if (lista == NULL) {
        return 0;
    }

    for (size_t i = 0; i < lista->tamanho; ++i) {
        if (lista->dados[i] == valor) {
            if (posicao_encontrada != NULL) {
                *posicao_encontrada = i;
            }
            return 1;
        }
    }

    return 0;
}

void lista_imprimir(const Lista *lista) {
    if (lista == NULL) {
        return;
    }

    printf("[ ");
    for (size_t i = 0; i < lista->tamanho; ++i) {
        printf("%d", lista->dados[i]);
        if (i + 1U < lista->tamanho) {
            printf(", ");
        }
    }
    printf(" ]\n");
}
