#include "lista_dupla.h"

#include <stdio.h>

int main(void) {
    ListaDupla lista;
    lista_dupla_criar(&lista);

    lista_dupla_inserir_inicio(&lista, 20);
    lista_dupla_inserir_inicio(&lista, 10);
    lista_dupla_inserir_fim(&lista, 30);

    printf("Inicio -> fim: ");
    lista_dupla_imprimir_inicio_fim(&lista);
    printf("Fim -> inicio: ");
    lista_dupla_imprimir_fim_inicio(&lista);

    lista_dupla_remover(&lista, 20);
    printf("Apos remover 20: ");
    lista_dupla_imprimir_inicio_fim(&lista);
    printf("%s\n", lista_dupla_complexidade());

    lista_dupla_destruir(&lista);
    return 0;
}
