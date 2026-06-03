#include "fila_estatica.h"

#include <stdio.h>

int main(void) {
    FilaEstatica fila;
    int valor = 0;

    if (!fila_estatica_criar(&fila, 4U)) {
        fprintf(stderr, "Erro ao criar fila estática.\n");
        return 1;
    }

    fila_estatica_enfileirar(&fila, 5);
    fila_estatica_enfileirar(&fila, 10);

    printf("Fila estática: ");
    fila_estatica_imprimir(&fila);

    if (fila_estatica_desenfileirar(&fila, &valor)) {
        printf("Removido: %d\n", valor);
    }

    fila_estatica_destruir(&fila);
    return 0;
}
