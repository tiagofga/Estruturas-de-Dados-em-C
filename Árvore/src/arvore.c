#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>

No *arvore_inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo_no = malloc(sizeof(No));
        if (novo_no == NULL) {
            return NULL;
        }

        novo_no->valor = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
        return novo_no;
    }

    No *atual = raiz;
    No *pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (valor < atual->valor) {
            atual = atual->esquerda;
        } else if (valor > atual->valor) {
            atual = atual->direita;
        } else {
            return raiz;
        }
    }

    No *novo_no = malloc(sizeof(No));
    if (novo_no == NULL) {
        return NULL;
    }

    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;

    if (valor < pai->valor) {
        pai->esquerda = novo_no;
    } else {
        pai->direita = novo_no;
    }

    return raiz;
}

int arvore_buscar(const No *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }

    if (valor == raiz->valor) {
        return 1;
    }

    if (valor < raiz->valor) {
        return arvore_buscar(raiz->esquerda, valor);
    }

    return arvore_buscar(raiz->direita, valor);
}

void arvore_em_ordem(const No *raiz) {
    if (raiz == NULL) {
        return;
    }

    arvore_em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    arvore_em_ordem(raiz->direita);
}

void arvore_destruir(No *raiz) {
    if (raiz == NULL) {
        return;
    }

    arvore_destruir(raiz->esquerda);
    arvore_destruir(raiz->direita);
    free(raiz);
}
