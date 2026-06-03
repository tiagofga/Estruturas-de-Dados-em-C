#include "pilha.h"

#include <stdio.h>

int main(void) {
    Pilha pilha;
    int valor = 0;

    if (!pilha_criar(&pilha, 5U)) {
        fprintf(stderr, "Erro ao criar pilha.\n");
        return 1;
    }

    pilha_empilhar(&pilha, 5);
    pilha_empilhar(&pilha, 10);
    pilha_empilhar(&pilha, 15);

    printf("Pilha após empilhar: ");
    pilha_imprimir(&pilha);

    if (pilha_topo(&pilha, &valor)) {
        printf("Topo da pilha: %d\n", valor);
    }

    if (pilha_desempilhar(&pilha, &valor)) {
        printf("Removido da pilha: %d\n", valor);
    }

    printf("Pilha final: ");
    pilha_imprimir(&pilha);

    pilha_destruir(&pilha);
    return 0;
}
