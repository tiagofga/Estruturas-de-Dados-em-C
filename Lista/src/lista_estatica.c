#include "lista_estatica.h"

#include <stdio.h>

int lista_estatica_criar(ListaEstatica *lista, size_t capacidade) {
    if (lista == NULL || capacidade == 0U || capacidade > LISTA_ESTATICA_CAPACIDADE_MAX) {
        return 0;
    }

    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return 1;
}

void lista_estatica_destruir(ListaEstatica *lista) {
    if (lista == NULL) {
        return;
    }

    lista->tamanho = 0;
    lista->capacidade = 0;
}

int lista_estatica_vazia(const ListaEstatica *lista) {
    return lista == NULL || lista->tamanho == 0U;
}

int lista_estatica_cheia(const ListaEstatica *lista) {
    return lista != NULL && lista->tamanho == lista->capacidade;
}

int lista_estatica_inserir_fim(ListaEstatica *lista, int valor) {
    if (lista == NULL || lista_estatica_cheia(lista)) {
        return 0;
    }

    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}

int lista_estatica_inserir_posicao(ListaEstatica *lista, size_t posicao, int valor) {
    if (lista == NULL || posicao > lista->tamanho || lista_estatica_cheia(lista)) {
        return 0;
    }

    for (size_t i = lista->tamanho; i > posicao; --i) {
        lista->dados[i] = lista->dados[i - 1U];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return 1;
}

int lista_estatica_remover_posicao(ListaEstatica *lista, size_t posicao, int *valor_removido) {
    if (lista == NULL || lista_estatica_vazia(lista) || posicao >= lista->tamanho) {
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

int lista_estatica_buscar(const ListaEstatica *lista, int valor, size_t *posicao_encontrada) {
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

void lista_estatica_imprimir(const ListaEstatica *lista) {
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
