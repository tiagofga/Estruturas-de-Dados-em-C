#include "lista_dupla.h"

#include <stdio.h>
#include <stdlib.h>

void lista_dupla_criar(ListaDupla *lista) {
    if (lista == NULL) {
        return;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0U;
}

void lista_dupla_destruir(ListaDupla *lista) {
    if (lista == NULL) {
        return;
    }
    ListaDuplaNo *atual = lista->inicio;
    while (atual != NULL) {
        ListaDuplaNo *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0U;
}

static int inserir_lista_vazia(ListaDupla *lista, ListaDuplaNo *novo) {
    lista->inicio = novo;
    lista->fim = novo;
    ++lista->tamanho;
    return 1;
}

int lista_dupla_inserir_inicio(ListaDupla *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    ListaDuplaNo *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;
    if (lista->inicio == NULL) {
        return inserir_lista_vazia(lista, novo);
    }
    lista->inicio->anterior = novo;
    lista->inicio = novo;
    ++lista->tamanho;
    return 1;
}

int lista_dupla_inserir_fim(ListaDupla *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    ListaDuplaNo *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;
    novo->anterior = lista->fim;
    novo->proximo = NULL;
    if (lista->fim == NULL) {
        return inserir_lista_vazia(lista, novo);
    }
    lista->fim->proximo = novo;
    lista->fim = novo;
    ++lista->tamanho;
    return 1;
}

int lista_dupla_remover(ListaDupla *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    ListaDuplaNo *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            } else {
                lista->inicio = atual->proximo;
            }
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            } else {
                lista->fim = atual->anterior;
            }
            free(atual);
            --lista->tamanho;
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_dupla_buscar(const ListaDupla *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }
    for (ListaDuplaNo *atual = lista->inicio; atual != NULL; atual = atual->proximo) {
        if (atual->valor == valor) {
            return 1;
        }
    }
    return 0;
}

size_t lista_dupla_tamanho(const ListaDupla *lista) {
    return lista != NULL ? lista->tamanho : 0U;
}

void lista_dupla_imprimir_inicio_fim(const ListaDupla *lista) {
    if (lista == NULL) {
        printf("Lista invalida.\n");
        return;
    }
    printf("[");
    for (ListaDuplaNo *atual = lista->inicio; atual != NULL; atual = atual->proximo) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void lista_dupla_imprimir_fim_inicio(const ListaDupla *lista) {
    if (lista == NULL) {
        printf("Lista invalida.\n");
        return;
    }
    printf("[");
    for (ListaDuplaNo *atual = lista->fim; atual != NULL; atual = atual->anterior) {
        printf("%d", atual->valor);
        if (atual->anterior != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

const char *lista_dupla_complexidade(void) {
    return "Lista duplamente encadeada: inserir inicio/fim O(1), buscar/remover por valor O(n).";
}
