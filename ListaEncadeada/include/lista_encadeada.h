#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stddef.h>

typedef struct ListaEncadeada ListaEncadeada;

ListaEncadeada *lista_encadeada_criar(void);
void lista_encadeada_destruir(ListaEncadeada *lista);
int lista_encadeada_inserir_inicio(ListaEncadeada *lista, int valor);
int lista_encadeada_inserir_fim(ListaEncadeada *lista, int valor);
int lista_encadeada_remover(ListaEncadeada *lista, int valor);
int lista_encadeada_buscar(const ListaEncadeada *lista, int valor);
size_t lista_encadeada_tamanho(const ListaEncadeada *lista);
void lista_encadeada_imprimir(const ListaEncadeada *lista);
const char *lista_encadeada_complexidade(void);

#endif
