#ifndef LISTA_H
#define LISTA_H

#define TAM 10

typedef struct {
    int chave;
    int valor;
}ITEM;

typedef struct{
    ITEM itens[TAM];
    int fim;
}LISTA;

void criar (LISTA *lista);
void imprimir (LISTA *lista);
int vazia (LISTA *lista);
int cheia (LISTA *lista);
int inserir_fim (LISTA *lista, ITEM *item);
int inserir_posicao (LISTA *lista, ITEM *item, int pos);
int remover (LISTA *lista, int pos);
int tamanho (LISTA *lista);
int recuperar_item(LISTA *lista, ITEM *item, int chave);
int ordenadacres (LISTA *lista);
int ordenadadecres (LISTA *lista);
int copia (LISTA *lista, LISTA *lista2, ITEM *item);
int copia_repetir (LISTA *lista, LISTA *lista2, ITEM *item, int pos);
int inverterL1_L2 (LISTA *lista, LISTA *lista2, ITEM *item);
int inverterL1 (LISTA *lista, ITEM *item);
int eliminar (LISTA *lista, ITEM *item, int chave);
#endif
