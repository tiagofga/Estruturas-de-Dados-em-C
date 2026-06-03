#include "arvore.h"

#include <stdio.h>

int main(void) {
    No *raiz = NULL;

    raiz = arvore_inserir(raiz, 40);
    raiz = arvore_inserir(raiz, 20);
    raiz = arvore_inserir(raiz, 60);
    raiz = arvore_inserir(raiz, 10);
    raiz = arvore_inserir(raiz, 30);

    printf("Árvore em ordem: ");
    arvore_em_ordem(raiz);
    printf("\n");

    printf("Buscar 30: %s\n", arvore_buscar(raiz, 30) ? "encontrado" : "não encontrado");
    printf("Buscar 99: %s\n", arvore_buscar(raiz, 99) ? "encontrado" : "não encontrado");

    arvore_destruir(raiz);
    return 0;
}
