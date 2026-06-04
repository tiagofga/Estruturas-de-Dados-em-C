#include "tabela_hash.h"

#include <stdio.h>

int main(void) {
    TabelaHash tabela;
    int valor = 0;

    if (!tabela_hash_criar(&tabela, 7U)) {
        fprintf(stderr, "Falha ao criar tabela hash.\n");
        return 1;
    }

    tabela_hash_inserir(&tabela, 10, 100);
    tabela_hash_inserir(&tabela, 17, 170);
    tabela_hash_inserir(&tabela, 24, 240);
    tabela_hash_inserir(&tabela, 10, 101);

    tabela_hash_imprimir(&tabela);

    if (tabela_hash_buscar(&tabela, 10, &valor)) {
        printf("Valor associado a chave 10: %d\n", valor);
    }

    tabela_hash_remover(&tabela, 17);
    printf("Apos remover chave 17:\n");
    tabela_hash_imprimir(&tabela);

    printf("Fator de carga: %.2f\n", tabela_hash_fator_carga(&tabela));
    printf("%s\n", tabela_hash_complexidade());

    tabela_hash_destruir(&tabela);
    return 0;
}
