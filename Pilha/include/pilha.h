#ifndef PILHA_H
#define PILHA_H

#include <stddef.h>

typedef struct {
    int *dados;
    size_t capacidade;
    size_t tamanho;
} Pilha;

int pilha_criar(Pilha *pilha, size_t capacidade);
void pilha_destruir(Pilha *pilha);
int pilha_vazia(const Pilha *pilha);
int pilha_cheia(const Pilha *pilha);
int pilha_empilhar(Pilha *pilha, int valor);
int pilha_desempilhar(Pilha *pilha, int *valor_removido);
int pilha_topo(const Pilha *pilha, int *valor);
void pilha_imprimir(const Pilha *pilha);

#endif
