#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

typedef struct {
    int *dados;
    size_t tamanho;
    size_t capacidade;
} Lista;

typedef enum {
    LISTA_ORDENACAO_BUBBLE = 0,
    LISTA_ORDENACAO_INSERTION = 1,
    LISTA_ORDENACAO_SELECTION = 2
} ListaMetodoOrdenacao;

typedef enum {
    LISTA_BUSCA_LINEAR = 0,
    LISTA_BUSCA_BINARIA = 1
} ListaMetodoBusca;

int lista_criar(Lista *lista, size_t capacidade_inicial);
void lista_destruir(Lista *lista);
int lista_vazia(const Lista *lista);
int lista_inserir_fim(Lista *lista, int valor);
int lista_inserir_posicao(Lista *lista, size_t posicao, int valor);
int lista_remover_posicao(Lista *lista, size_t posicao, int *valor_removido);
int lista_buscar(const Lista *lista, int valor, size_t *posicao_encontrada);
int lista_buscar_metodo(const Lista *lista, int valor, size_t *posicao_encontrada, ListaMetodoBusca metodo);
int lista_ordenar(Lista *lista, ListaMetodoOrdenacao metodo);
const char *lista_complexidade_busca(ListaMetodoBusca metodo);
const char *lista_complexidade_ordenacao(ListaMetodoOrdenacao metodo);
void lista_imprimir(const Lista *lista);

#endif
