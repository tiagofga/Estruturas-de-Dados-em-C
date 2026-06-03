#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include <stddef.h>

#define LISTA_ESTATICA_CAPACIDADE_MAX 256U

typedef struct {
    int dados[LISTA_ESTATICA_CAPACIDADE_MAX];
    size_t tamanho;
    size_t capacidade;
} ListaEstatica;

int lista_estatica_criar(ListaEstatica *lista, size_t capacidade);
void lista_estatica_destruir(ListaEstatica *lista);
int lista_estatica_vazia(const ListaEstatica *lista);
int lista_estatica_cheia(const ListaEstatica *lista);
int lista_estatica_inserir_fim(ListaEstatica *lista, int valor);
int lista_estatica_inserir_posicao(ListaEstatica *lista, size_t posicao, int valor);
int lista_estatica_remover_posicao(ListaEstatica *lista, size_t posicao, int *valor_removido);
int lista_estatica_buscar(const ListaEstatica *lista, int valor, size_t *posicao_encontrada);
void lista_estatica_imprimir(const ListaEstatica *lista);

#endif
