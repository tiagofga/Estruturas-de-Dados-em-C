#include "tabela_hash.h"

#include <stdio.h>
#include <stdlib.h>

static size_t hash_int(int chave, size_t capacidade) {
    unsigned int x = (unsigned int)chave;
    x = ((x >> 16U) ^ x) * 0x45d9f3bU;
    x = ((x >> 16U) ^ x) * 0x45d9f3bU;
    x = (x >> 16U) ^ x;
    return (size_t)(x % capacidade);
}

int tabela_hash_criar(TabelaHash *tabela, size_t capacidade) {
    if (tabela == NULL || capacidade == 0U) {
        return 0;
    }
    tabela->baldes = calloc(capacidade, sizeof(TabelaHashItem *));
    if (tabela->baldes == NULL) {
        tabela->capacidade = 0U;
        tabela->tamanho = 0U;
        return 0;
    }
    tabela->capacidade = capacidade;
    tabela->tamanho = 0U;
    return 1;
}

void tabela_hash_destruir(TabelaHash *tabela) {
    if (tabela == NULL || tabela->baldes == NULL) {
        return;
    }
    for (size_t i = 0U; i < tabela->capacidade; ++i) {
        TabelaHashItem *atual = tabela->baldes[i];
        while (atual != NULL) {
            TabelaHashItem *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(tabela->baldes);
    tabela->baldes = NULL;
    tabela->capacidade = 0U;
    tabela->tamanho = 0U;
}

int tabela_hash_inserir(TabelaHash *tabela, int chave, int valor) {
    if (tabela == NULL || tabela->baldes == NULL || tabela->capacidade == 0U) {
        return 0;
    }
    size_t indice = hash_int(chave, tabela->capacidade);
    TabelaHashItem *atual = tabela->baldes[indice];
    while (atual != NULL) {
        if (atual->chave == chave) {
            atual->valor = valor;
            return 1;
        }
        atual = atual->proximo;
    }
    TabelaHashItem *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return 0;
    }
    novo->chave = chave;
    novo->valor = valor;
    novo->proximo = tabela->baldes[indice];
    tabela->baldes[indice] = novo;
    ++tabela->tamanho;
    return 1;
}

int tabela_hash_buscar(const TabelaHash *tabela, int chave, int *valor) {
    if (tabela == NULL || tabela->baldes == NULL || valor == NULL || tabela->capacidade == 0U) {
        return 0;
    }
    size_t indice = hash_int(chave, tabela->capacidade);
    for (TabelaHashItem *atual = tabela->baldes[indice]; atual != NULL; atual = atual->proximo) {
        if (atual->chave == chave) {
            *valor = atual->valor;
            return 1;
        }
    }
    return 0;
}

int tabela_hash_remover(TabelaHash *tabela, int chave) {
    if (tabela == NULL || tabela->baldes == NULL || tabela->capacidade == 0U) {
        return 0;
    }
    size_t indice = hash_int(chave, tabela->capacidade);
    TabelaHashItem *atual = tabela->baldes[indice];
    TabelaHashItem *anterior = NULL;
    while (atual != NULL) {
        if (atual->chave == chave) {
            if (anterior == NULL) {
                tabela->baldes[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            --tabela->tamanho;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}

int tabela_hash_contem(const TabelaHash *tabela, int chave) {
    int valor = 0;
    return tabela_hash_buscar(tabela, chave, &valor);
}

size_t tabela_hash_tamanho(const TabelaHash *tabela) {
    return tabela != NULL ? tabela->tamanho : 0U;
}

double tabela_hash_fator_carga(const TabelaHash *tabela) {
    if (tabela == NULL || tabela->capacidade == 0U) {
        return 0.0;
    }
    return (double)tabela->tamanho / (double)tabela->capacidade;
}

void tabela_hash_imprimir(const TabelaHash *tabela) {
    if (tabela == NULL || tabela->baldes == NULL) {
        printf("Tabela hash invalida.\n");
        return;
    }
    for (size_t i = 0U; i < tabela->capacidade; ++i) {
        printf("[%zu]", i);
        for (TabelaHashItem *atual = tabela->baldes[i]; atual != NULL; atual = atual->proximo) {
            printf(" -> (%d, %d)", atual->chave, atual->valor);
        }
        printf("\n");
    }
}

const char *tabela_hash_complexidade(void) {
    return "Tabela hash com encadeamento separado: inserir/buscar/remover O(1) medio, O(n) pior caso.";
}
