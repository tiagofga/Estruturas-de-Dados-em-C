#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

typedef struct {
    int *dados;
    size_t tamanho;
    size_t capacidade;
} Lista;

int lista_criar(Lista *lista, size_t capacidade_inicial);
void lista_destruir(Lista *lista);
int lista_vazia(const Lista *lista);
int lista_inserir_fim(Lista *lista, int valor);
int lista_inserir_posicao(Lista *lista, size_t posicao, int valor);
int lista_remover_posicao(Lista *lista, size_t posicao, int *valor_removido);
int lista_buscar(const Lista *lista, int valor, size_t *posicao_encontrada);
void lista_imprimir(const Lista *lista);

#endif
