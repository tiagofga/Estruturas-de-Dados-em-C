#include "lista.h"

#include <stdio.h>

int main(void) {
    Lista lista;
    size_t posicao = 0;
    int removido = 0;

    if (!lista_criar(&lista, 4U)) {
        fprintf(stderr, "Erro ao criar lista.\n");
        return 1;
    }

    lista_inserir_fim(&lista, 10);
    lista_inserir_fim(&lista, 20);
    lista_inserir_fim(&lista, 30);
    lista_inserir_posicao(&lista, 1U, 15);
    lista_inserir_fim(&lista, 12);

    printf("Lista após inserções: ");
    lista_imprimir(&lista);

    if (lista_ordenar(&lista, LISTA_ORDENACAO_INSERTION)) {
        printf("Lista ordenada (Insertion Sort): ");
        lista_imprimir(&lista);
    }

    if (lista_buscar_metodo(&lista, 20, &posicao, LISTA_BUSCA_BINARIA)) {
        printf("Valor 20 encontrado na posição %zu (busca binária).\n", posicao);
    }

    printf("%s\n", lista_complexidade_ordenacao(LISTA_ORDENACAO_INSERTION));
    printf("%s\n", lista_complexidade_busca(LISTA_BUSCA_BINARIA));

    if (lista_remover_posicao(&lista, 3U, &removido)) {
        printf("Valor removido: %d\n", removido);
    }

    printf("Lista final: ");
    lista_imprimir(&lista);

    lista_destruir(&lista);
    return 0;
}
