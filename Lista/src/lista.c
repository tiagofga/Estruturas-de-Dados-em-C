#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

static int lista_redimensionar(Lista *lista, size_t nova_capacidade) {
    int *novo_buffer = realloc(lista->dados, nova_capacidade * sizeof(int));
    if (novo_buffer == NULL) {
        return 0;
    }

    lista->dados = novo_buffer;
    lista->capacidade = nova_capacidade;
    return 1;
}

static void lista_bubble_sort(Lista *lista) {
    if (lista == NULL || lista->tamanho <= 1U) {
        return;
    }

    for (size_t i = 0U; i + 1U < lista->tamanho; ++i) {
        for (size_t j = 0U; j + 1U < lista->tamanho - i; ++j) {
            if (lista->dados[j] > lista->dados[j + 1U]) {
                const int temp = lista->dados[j];
                lista->dados[j] = lista->dados[j + 1U];
                lista->dados[j + 1U] = temp;
            }
        }
    }
}

static void lista_insertion_sort(Lista *lista) {
    if (lista == NULL || lista->tamanho <= 1U) {
        return;
    }

    for (size_t i = 1U; i < lista->tamanho; ++i) {
        const int chave = lista->dados[i];
        size_t j = i;

        while (j > 0U && lista->dados[j - 1U] > chave) {
            lista->dados[j] = lista->dados[j - 1U];
            --j;
        }

        lista->dados[j] = chave;
    }
}

static void lista_selection_sort(Lista *lista) {
    if (lista == NULL || lista->tamanho <= 1U) {
        return;
    }

    for (size_t i = 0U; i + 1U < lista->tamanho; ++i) {
        size_t menor_indice = i;

        for (size_t j = i + 1U; j < lista->tamanho; ++j) {
            if (lista->dados[j] < lista->dados[menor_indice]) {
                menor_indice = j;
            }
        }

        if (menor_indice != i) {
            const int temp = lista->dados[i];
            lista->dados[i] = lista->dados[menor_indice];
            lista->dados[menor_indice] = temp;
        }
    }
}

int lista_criar(Lista *lista, size_t capacidade_inicial) {
    if (lista == NULL || capacidade_inicial == 0) {
        return 0;
    }

    lista->dados = calloc(capacidade_inicial, sizeof(int));
    if (lista->dados == NULL) {
        return 0;
    }

    lista->tamanho = 0;
    lista->capacidade = capacidade_inicial;
    return 1;
}

void lista_destruir(Lista *lista) {
    if (lista == NULL) {
        return;
    }

    free(lista->dados);
    lista->dados = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

int lista_vazia(const Lista *lista) {
    return lista == NULL || lista->tamanho == 0;
}

int lista_inserir_fim(Lista *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }

    if (lista->tamanho == lista->capacidade && !lista_redimensionar(lista, lista->capacidade * 2U)) {
        return 0;
    }

    lista->dados[lista->tamanho++] = valor;
    return 1;
}

int lista_inserir_posicao(Lista *lista, size_t posicao, int valor) {
    if (lista == NULL || posicao > lista->tamanho) {
        return 0;
    }

    if (lista->tamanho == lista->capacidade && !lista_redimensionar(lista, lista->capacidade * 2U)) {
        return 0;
    }

    for (size_t i = lista->tamanho; i > posicao; --i) {
        lista->dados[i] = lista->dados[i - 1U];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return 1;
}

int lista_remover_posicao(Lista *lista, size_t posicao, int *valor_removido) {
    if (lista == NULL || lista_vazia(lista) || posicao >= lista->tamanho) {
        return 0;
    }

    if (valor_removido != NULL) {
        *valor_removido = lista->dados[posicao];
    }

    for (size_t i = posicao; i + 1U < lista->tamanho; ++i) {
        lista->dados[i] = lista->dados[i + 1U];
    }

    lista->tamanho--;
    return 1;
}

int lista_buscar(const Lista *lista, int valor, size_t *posicao_encontrada) {
    return lista_buscar_metodo(lista, valor, posicao_encontrada, LISTA_BUSCA_LINEAR);
}

int lista_buscar_metodo(const Lista *lista, int valor, size_t *posicao_encontrada, ListaMetodoBusca metodo) {
    if (lista == NULL) {
        return 0;
    }

    if (metodo == LISTA_BUSCA_LINEAR) {
        for (size_t i = 0; i < lista->tamanho; ++i) {
            if (lista->dados[i] == valor) {
                if (posicao_encontrada != NULL) {
                    *posicao_encontrada = i;
                }
                return 1;
            }
        }

        return 0;
    }

    if (metodo == LISTA_BUSCA_BINARIA) {
        if (lista_vazia(lista)) {
            return 0;
        }

        size_t esquerda = 0U;
        size_t direita = lista->tamanho;

        while (esquerda < direita) {
            const size_t meio = esquerda + (direita - esquerda) / 2U;
            const int atual = lista->dados[meio];

            if (atual == valor) {
                if (posicao_encontrada != NULL) {
                    *posicao_encontrada = meio;
                }
                return 1;
            }

            if (atual < valor) {
                esquerda = meio + 1U;
            } else {
                direita = meio;
            }
        }

        return 0;
    }

    return 0;
}

int lista_ordenar(Lista *lista, ListaMetodoOrdenacao metodo) {
    if (lista == NULL) {
        return 0;
    }

    if (metodo == LISTA_ORDENACAO_BUBBLE) {
        lista_bubble_sort(lista);
        return 1;
    }

    if (metodo == LISTA_ORDENACAO_INSERTION) {
        lista_insertion_sort(lista);
        return 1;
    }

    if (metodo == LISTA_ORDENACAO_SELECTION) {
        lista_selection_sort(lista);
        return 1;
    }

    return 0;
}

const char *lista_complexidade_busca(ListaMetodoBusca metodo) {
    if (metodo == LISTA_BUSCA_LINEAR) {
        return "Busca linear: O(n) tempo, O(1) espaco.";
    }

    if (metodo == LISTA_BUSCA_BINARIA) {
        return "Busca binaria: O(log n) tempo, O(1) espaco (requer lista ordenada).";
    }

    return "Metodo de busca invalido.";
}

const char *lista_complexidade_ordenacao(ListaMetodoOrdenacao metodo) {
    if (metodo == LISTA_ORDENACAO_BUBBLE) {
        return "Bubble sort: O(n^2) medio/pior, O(1) espaco.";
    }

    if (metodo == LISTA_ORDENACAO_INSERTION) {
        return "Insertion sort: O(n) melhor, O(n^2) medio/pior, O(1) espaco.";
    }

    if (metodo == LISTA_ORDENACAO_SELECTION) {
        return "Selection sort: O(n^2) em todos os casos, O(1) espaco.";
    }

    return "Metodo de ordenacao invalido.";
}

void lista_imprimir(const Lista *lista) {
    if (lista == NULL) {
        return;
    }

    printf("[ ");
    for (size_t i = 0; i < lista->tamanho; ++i) {
        printf("%d", lista->dados[i]);
        if (i + 1U < lista->tamanho) {
            printf(", ");
        }
    }
    printf(" ]\n");
}
