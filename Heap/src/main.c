#include "heap.h"

#include <stdio.h>

int main(void) {
    Heap heap;
    int maior = 0;

    if (!heap_criar(&heap, 4U)) {
        fprintf(stderr, "Erro ao criar heap.\n");
        return 1;
    }

    heap_inserir(&heap, 40);
    heap_inserir(&heap, 10);
    heap_inserir(&heap, 70);
    heap_inserir(&heap, 30);
    heap_inserir(&heap, 90);

    printf("Heap maximo: ");
    heap_imprimir(&heap);

    if (heap_consultar_raiz(&heap, &maior)) {
        printf("Maior elemento: %d\n", maior);
    }

    printf("Removendo em ordem de prioridade: ");
    while (heap_remover_raiz(&heap, &maior)) {
        printf("%d ", maior);
    }
    printf("\n");

    heap_destruir(&heap);
    return 0;
}
