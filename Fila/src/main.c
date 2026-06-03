#include "fila.h"

#include <stdio.h>

int main(void) {
    Fila fila;
    int valor = 0;

    if (!fila_criar(&fila, 5U)) {
        fprintf(stderr, "Erro ao criar fila.\n");
        return 1;
    }

    fila_enfileirar(&fila, 5);
    fila_enfileirar(&fila, 10);
    fila_enfileirar(&fila, 15);

    printf("Fila após enfileirar: ");
    fila_imprimir(&fila);

    if (fila_frente(&fila, &valor)) {
        printf("Frente da fila: %d\n", valor);
    }

    if (fila_desenfileirar(&fila, &valor)) {
        printf("Removido da fila: %d\n", valor);
    }

    printf("Fila final: ");
    fila_imprimir(&fila);

    fila_destruir(&fila);
    return 0;
}
