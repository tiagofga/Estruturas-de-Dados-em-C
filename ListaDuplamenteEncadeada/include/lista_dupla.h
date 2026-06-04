#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include <stddef.h>

typedef struct ListaDuplaNo {
    int valor;
    struct ListaDuplaNo *anterior;
    struct ListaDuplaNo *proximo;
} ListaDuplaNo;

typedef struct {
    ListaDuplaNo *inicio;
    ListaDuplaNo *fim;
    size_t tamanho;
} ListaDupla;

void lista_dupla_criar(ListaDupla *lista);
void lista_dupla_destruir(ListaDupla *lista);
int lista_dupla_inserir_inicio(ListaDupla *lista, int valor);
int lista_dupla_inserir_fim(ListaDupla *lista, int valor);
int lista_dupla_remover(ListaDupla *lista, int valor);
int lista_dupla_buscar(const ListaDupla *lista, int valor);
size_t lista_dupla_tamanho(const ListaDupla *lista);
void lista_dupla_imprimir_inicio_fim(const ListaDupla *lista);
void lista_dupla_imprimir_fim_inicio(const ListaDupla *lista);
const char *lista_dupla_complexidade(void);

#endif
