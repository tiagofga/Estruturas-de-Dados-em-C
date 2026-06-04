#include "lista_encadeada.h"

#include <stdio.h>
#include <stdlib.h>

void lista_encadeada_criar(ListaEncadeada *lista) {
    if (lista == NULL) {
        return;
    }
    lista->inicio = NULL;
    lista->tamanho = 0U;
}

void lista_encadeada_destruir(ListaEncadeada *lista) {
    if (lista == NULL) {
        return;
    }
    ListaEncadeadaNo *atual = lista->inicio;
    while (atual != NULL) {
        ListaEncadeadaNo *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->tamanho = 0U;
}

int lista_encadeada_inserir_inicio(ListaEncadeada *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    ListaEncadeadaNo *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    ++lista->tamanho;
    return 1;
}

int lista_encadeada_inserir_fim(ListaEncadeada *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    ListaEncadeadaNo *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;
    novo->proximo = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        ListaEncadeadaNo *atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    ++lista->tamanho;
    return 1;
}

int lista_encadeada_remover(ListaEncadeada *lista, int valor) {
    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }
    ListaEncadeadaNo *atual = lista->inicio;
    ListaEncadeadaNo *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            --lista->tamanho;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}

int lista_encadeada_buscar(const ListaEncadeada *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    for (ListaEncadeadaNo *atual = lista->inicio; atual != NULL; atual = atual->proximo) {
        if (atual->valor == valor) {
            return 1;
        }
    }
    return 0;
}

size_t lista_encadeada_tamanho(const ListaEncadeada *lista) {
    return lista != NULL ? lista->tamanho : 0U;
}

void lista_encadeada_imprimir(const ListaEncadeada *lista) {
    if (lista == NULL) {
        printf("Lista invalida.\n");
        return;
    }
    printf("[");
    for (ListaEncadeadaNo *atual = lista->inicio; atual != NULL; atual = atual->proximo) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

const char *lista_encadeada_complexidade(void) {
    return "Lista simplesmente encadeada: inserir inicio O(1), inserir fim/buscar/remover O(n).";
}
