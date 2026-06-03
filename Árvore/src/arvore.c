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

    if (valor < raiz->valor) {
        No *esquerda = arvore_inserir(raiz->esquerda, valor);
        if (esquerda != NULL) {
            raiz->esquerda = esquerda;
        }
    } else if (valor > raiz->valor) {
        No *direita = arvore_inserir(raiz->direita, valor);
        if (direita != NULL) {
            raiz->direita = direita;
        }
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
