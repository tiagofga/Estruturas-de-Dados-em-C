#include "lista_estatica.h"

#include <stdio.h>

int main(void) {
    ListaEstatica lista;
    int removido = 0;

    if (!lista_estatica_criar(&lista, 5U)) {
        fprintf(stderr, "Erro ao criar lista estática.\n");
        return 1;
    }

    lista_estatica_inserir_fim(&lista, 10);
    lista_estatica_inserir_fim(&lista, 20);
    lista_estatica_inserir_posicao(&lista, 1U, 15);

    printf("Lista estática: ");
    lista_estatica_imprimir(&lista);

    if (lista_estatica_remover_posicao(&lista, 1U, &removido)) {
        printf("Removido: %d\n", removido);
    }

    lista_estatica_destruir(&lista);
    return 0;
}
