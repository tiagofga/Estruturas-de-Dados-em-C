#include "avl.h"

#include <stdio.h>

int main(void) {
    AVLNo *raiz = NULL;
    int valores[] = {30, 20, 10, 40, 50, 25};
    size_t n = sizeof(valores) / sizeof(valores[0]);

    for (size_t i = 0U; i < n; ++i) {
        raiz = avl_inserir(raiz, valores[i]);
    }

    printf("Em ordem: ");
    avl_imprimir_em_ordem(raiz);
    printf("\nAltura: %d\n", avl_altura(raiz));
    printf("Balanceada? %s\n", avl_esta_balanceada(raiz) ? "sim" : "nao");
    printf("Contem 25? %s\n", avl_buscar(raiz, 25) ? "sim" : "nao");
    printf("%s\n", avl_complexidade());

    avl_destruir(raiz);
    return 0;
}
