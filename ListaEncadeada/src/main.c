#include "lista_encadeada.h"

#include <stdio.h>

int main(void) {
    ListaEncadeada *lista = lista_encadeada_criar();
    if (lista == NULL) {
        fprintf(stderr, "Falha ao criar lista encadeada.\n");
        return 1;
    }

    lista_encadeada_inserir_inicio(lista, 30);
    lista_encadeada_inserir_inicio(lista, 20);
    lista_encadeada_inserir_fim(lista, 40);

    lista_encadeada_imprimir(lista);
    printf("Contem 20? %s\n", lista_encadeada_buscar(lista, 20) ? "sim" : "nao");

    lista_encadeada_remover(lista, 20);
    lista_encadeada_imprimir(lista);
    printf("%s\n", lista_encadeada_complexidade());

    lista_encadeada_destruir(lista);
    return 0;
}
