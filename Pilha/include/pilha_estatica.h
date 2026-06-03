#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#include <stddef.h>

#define PILHA_ESTATICA_CAPACIDADE_MAX 256U

typedef struct {
    int dados[PILHA_ESTATICA_CAPACIDADE_MAX];
    size_t capacidade;
    size_t tamanho;
} PilhaEstatica;

int pilha_estatica_criar(PilhaEstatica *pilha, size_t capacidade);
void pilha_estatica_destruir(PilhaEstatica *pilha);
int pilha_estatica_vazia(const PilhaEstatica *pilha);
int pilha_estatica_cheia(const PilhaEstatica *pilha);
int pilha_estatica_empilhar(PilhaEstatica *pilha, int valor);
int pilha_estatica_desempilhar(PilhaEstatica *pilha, int *valor_removido);
int pilha_estatica_topo(const PilhaEstatica *pilha, int *valor);
void pilha_estatica_imprimir(const PilhaEstatica *pilha);

#endif
