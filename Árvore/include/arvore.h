#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No *arvore_inserir(No *raiz, int valor);
int arvore_buscar(const No *raiz, int valor);
void arvore_em_ordem(const No *raiz);
void arvore_destruir(No *raiz);

#endif
