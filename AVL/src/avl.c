#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

struct AVLNo {
    int valor;
    int altura;
    struct AVLNo *esquerda;
    struct AVLNo *direita;
};

static int max_int(int a, int b) {
    return a > b ? a : b;
}

int avl_altura(const AVLNo *raiz) {
    return raiz != NULL ? raiz->altura : 0;
}

int avl_fator_balanceamento(const AVLNo *raiz) {
    return raiz != NULL ? avl_altura(raiz->esquerda) - avl_altura(raiz->direita) : 0;
}

static void atualizar_altura(AVLNo *no) {
    if (no != NULL) {
        no->altura = 1 + max_int(avl_altura(no->esquerda), avl_altura(no->direita));
    }
}

static AVLNo *novo_no(int valor) {
    AVLNo *no = malloc(sizeof(*no));
    if (no == NULL) {
        return NULL;
    }
    no->valor = valor;
    no->altura = 1;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

static AVLNo *rotacao_direita(AVLNo *y) {
    AVLNo *x = y->esquerda;
    AVLNo *t2 = x->direita;
    x->direita = y;
    y->esquerda = t2;
    atualizar_altura(y);
    atualizar_altura(x);
    return x;
}

static AVLNo *rotacao_esquerda(AVLNo *x) {
    AVLNo *y = x->direita;
    AVLNo *t2 = y->esquerda;
    y->esquerda = x;
    x->direita = t2;
    atualizar_altura(x);
    atualizar_altura(y);
    return y;
}

static AVLNo *rebalancear(AVLNo *raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    atualizar_altura(raiz);
    int balanceamento = avl_fator_balanceamento(raiz);

    if (balanceamento > 1 && avl_fator_balanceamento(raiz->esquerda) >= 0) {
        return rotacao_direita(raiz);
    }
    if (balanceamento > 1 && avl_fator_balanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
        return rotacao_direita(raiz);
    }
    if (balanceamento < -1 && avl_fator_balanceamento(raiz->direita) <= 0) {
        return rotacao_esquerda(raiz);
    }
    if (balanceamento < -1 && avl_fator_balanceamento(raiz->direita) > 0) {
        raiz->direita = rotacao_direita(raiz->direita);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

AVLNo *avl_inserir(AVLNo *raiz, int valor) {
    if (raiz == NULL) {
        return novo_no(valor);
    }

    if (valor < raiz->valor) {
        AVLNo *novo_esquerda = avl_inserir(raiz->esquerda, valor);
        if (novo_esquerda == NULL && raiz->esquerda == NULL) {
            return raiz;
        }
        raiz->esquerda = novo_esquerda;
    } else if (valor > raiz->valor) {
        AVLNo *nova_direita = avl_inserir(raiz->direita, valor);
        if (nova_direita == NULL && raiz->direita == NULL) {
            return raiz;
        }
        raiz->direita = nova_direita;
    } else {
        return raiz;
    }

    return rebalancear(raiz);
}

static AVLNo *menor_no(AVLNo *raiz) {
    AVLNo *atual = raiz;
    while (atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

AVLNo *avl_remover(AVLNo *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = avl_remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = avl_remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            AVLNo *filho = raiz->esquerda != NULL ? raiz->esquerda : raiz->direita;
            free(raiz);
            return filho;
        }

        AVLNo *sucessor = menor_no(raiz->direita);
        raiz->valor = sucessor->valor;
        raiz->direita = avl_remover(raiz->direita, sucessor->valor);
    }

    return rebalancear(raiz);
}

int avl_buscar(const AVLNo *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (valor == raiz->valor) {
        return 1;
    }
    if (valor < raiz->valor) {
        return avl_buscar(raiz->esquerda, valor);
    }
    return avl_buscar(raiz->direita, valor);
}

int avl_esta_balanceada(const AVLNo *raiz) {
    if (raiz == NULL) {
        return 1;
    }
    int fb = avl_fator_balanceamento(raiz);
    if (fb < -1 || fb > 1) {
        return 0;
    }
    return avl_esta_balanceada(raiz->esquerda) && avl_esta_balanceada(raiz->direita);
}

size_t avl_tamanho(const AVLNo *raiz) {
    if (raiz == NULL) {
        return 0U;
    }
    return 1U + avl_tamanho(raiz->esquerda) + avl_tamanho(raiz->direita);
}

void avl_em_ordem(const AVLNo *raiz, int *vetor, size_t capacidade, size_t *tamanho) {
    if (raiz == NULL || vetor == NULL || tamanho == NULL || *tamanho >= capacidade) {
        return;
    }
    avl_em_ordem(raiz->esquerda, vetor, capacidade, tamanho);
    if (*tamanho < capacidade) {
        vetor[(*tamanho)++] = raiz->valor;
    }
    avl_em_ordem(raiz->direita, vetor, capacidade, tamanho);
}

void avl_imprimir_em_ordem(const AVLNo *raiz) {
    if (raiz == NULL) {
        return;
    }
    avl_imprimir_em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    avl_imprimir_em_ordem(raiz->direita);
}

void avl_destruir(AVLNo *raiz) {
    if (raiz == NULL) {
        return;
    }
    avl_destruir(raiz->esquerda);
    avl_destruir(raiz->direita);
    free(raiz);
}

const char *avl_complexidade(void) {
    return "Arvore AVL: buscar/inserir/remover O(log n), percurso O(n), espaco O(n).";
}
