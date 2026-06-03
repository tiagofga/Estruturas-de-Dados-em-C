#include "arvore.h"

#include <stdio.h>

static int inserir_com_validacao(No **raiz, int valor) {
    No *resultado = arvore_inserir(*raiz, valor);
    if (resultado == NULL) {
        return 0;
    }

    *raiz = resultado;
    return 1;
}

int main(void) {
    No *raiz = NULL;

    if (!inserir_com_validacao(&raiz, 40) ||
        !inserir_com_validacao(&raiz, 20) ||
        !inserir_com_validacao(&raiz, 60) ||
        !inserir_com_validacao(&raiz, 10) ||
        !inserir_com_validacao(&raiz, 30)) {
        fprintf(stderr, "Erro ao inserir nó na árvore.\n");
        arvore_destruir(raiz);
        return 1;
    }

    printf("Árvore em ordem: ");
    arvore_em_ordem(raiz);
    printf("\n");

    printf("Buscar 30: %s\n", arvore_buscar(raiz, 30) ? "encontrado" : "não encontrado");
    printf("Buscar 99: %s\n", arvore_buscar(raiz, 99) ? "encontrado" : "não encontrado");

    arvore_destruir(raiz);
    return 0;
}
