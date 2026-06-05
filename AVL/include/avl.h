#ifndef AVL_H
#define AVL_H

#include <stddef.h>

typedef struct AVLNo AVLNo;

AVLNo *avl_inserir(AVLNo *raiz, int valor);
AVLNo *avl_remover(AVLNo *raiz, int valor);
int avl_buscar(const AVLNo *raiz, int valor);
int avl_altura(const AVLNo *raiz);
int avl_fator_balanceamento(const AVLNo *raiz);
int avl_esta_balanceada(const AVLNo *raiz);
size_t avl_tamanho(const AVLNo *raiz);
void avl_em_ordem(const AVLNo *raiz, int *vetor, size_t capacidade, size_t *tamanho);
void avl_imprimir_em_ordem(const AVLNo *raiz);
void avl_destruir(AVLNo *raiz);
const char *avl_complexidade(void);

#endif
