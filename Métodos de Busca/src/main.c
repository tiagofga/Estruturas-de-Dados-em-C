#include "busca.h"

#include <stdio.h>

int main(void) {
    const int vetor_ordenado[] = {3, 7, 12, 18, 25, 31, 44, 59, 63, 70};
    const int vetor_desordenado[] = {18, 3, 70, 12, 44, 7, 59, 25, 31, 63};
    const size_t n = sizeof(vetor_ordenado) / sizeof(vetor_ordenado[0]);
    const int alvo = 44;
    size_t indice = 0U;

    if (busca_procurar(vetor_desordenado, n, alvo, BUSCA_LINEAR, &indice)) {
        printf("%s encontrou %d na posicao %zu.\n", busca_nome(BUSCA_LINEAR), alvo, indice);
    }
    printf("  %s\n", busca_complexidade(BUSCA_LINEAR));
    printf("  %s\n\n", busca_requisito(BUSCA_LINEAR));

    const BuscaMetodo metodos[] = {
        BUSCA_BINARIA,
        BUSCA_SALTO,
        BUSCA_INTERPOLACAO,
        BUSCA_EXPONENCIAL
    };
    const size_t total = sizeof(metodos) / sizeof(metodos[0]);

    for (size_t i = 0U; i < total; ++i) {
        if (busca_procurar(vetor_ordenado, n, alvo, metodos[i], &indice)) {
            printf("%s encontrou %d na posicao %zu.\n", busca_nome(metodos[i]), alvo, indice);
        } else {
            printf("%s nao encontrou %d.\n", busca_nome(metodos[i]), alvo);
        }
        printf("  %s\n", busca_complexidade(metodos[i]));
        printf("  %s\n\n", busca_requisito(metodos[i]));
    }

    return 0;
}
