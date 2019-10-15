#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define TAM 10

int main(int argc, char** argv) {
    LISTA *lista=NULL, *lista2=NULL;
    
    criar(lista);
    criar(lista2);
    if (vazia(lista) == 1) {
        printf("A lista 1 esta vazia! \n");
    } else {
        printf("A lista 1 nao esta vazia! \n");
    }
    if (vazia(lista2) == 1) {
        printf("A lista 2 esta vazia! \n");
    } else {
        printf("A lista 2 nao esta vazia! \n");
    }
    ITEM *item=NULL;
    printf("\n");
    printf("Lista 1: \n");
    imprimir(lista);

    copia(lista, lista2, item);
    printf("\n");
    printf("Lista 2: \n");
    imprimir(lista2);

    inverterL1(lista, item);
    printf("\n");
    printf("Lista 1 invertida: \n");
    imprimir(lista);

    inverterL1_L2(lista, lista2, item);
    printf("\n");
    printf("Lista 1 invertida com a Lista 2: \n");
    imprimir (lista2);

    int chave;

    printf("Digite uma chave para ser eliminada: \n");
    scanf("%d", &chave);
    if (eliminar(lista, item, chave) == 1) {
        printf("Chave removida com sucesso! \n");
    }else{
        printf("Chave não removida!\n");
    }
    imprimir(lista);

}

