#include "pilha_estatica.h"

#include <stdio.h>

int main(void) {
    PilhaEstatica pilha;
    int valor = 0;

    if (!pilha_estatica_criar(&pilha, 4U)) {
        fprintf(stderr, "Erro ao criar pilha estática.\n");
        return 1;
    }

    pilha_estatica_empilhar(&pilha, 5);
    pilha_estatica_empilhar(&pilha, 10);

    printf("Pilha estática: ");
    pilha_estatica_imprimir(&pilha);

    if (pilha_estatica_desempilhar(&pilha, &valor)) {
        printf("Removido: %d\n", valor);
    }

    pilha_estatica_destruir(&pilha);
    return 0;
}
