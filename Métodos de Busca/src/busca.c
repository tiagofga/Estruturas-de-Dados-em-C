#include "busca.h"

#include <math.h>

static int busca_linear(const int *vetor, size_t n, int alvo, size_t *indice_encontrado) {
    for (size_t i = 0U; i < n; ++i) {
        if (vetor[i] == alvo) {
            if (indice_encontrado != NULL) {
                *indice_encontrado = i;
            }
            return 1;
        }
    }
    return 0;
}

static int busca_binaria_faixa(const int *vetor, size_t esquerda, size_t direita, int alvo, size_t *indice_encontrado) {
    while (esquerda < direita) {
        const size_t meio = esquerda + (direita - esquerda) / 2U;
        if (vetor[meio] == alvo) {
            if (indice_encontrado != NULL) {
                *indice_encontrado = meio;
            }
            return 1;
        }

        if (vetor[meio] < alvo) {
            esquerda = meio + 1U;
        } else {
            direita = meio;
        }
    }

    return 0;
}

static int busca_binaria(const int *vetor, size_t n, int alvo, size_t *indice_encontrado) {
    return busca_binaria_faixa(vetor, 0U, n, alvo, indice_encontrado);
}

static int busca_salto(const int *vetor, size_t n, int alvo, size_t *indice_encontrado) {
    if (n == 0U) {
        return 0;
    }

    size_t passo = (size_t)sqrt((double)n);
    if (passo == 0U) {
        passo = 1U;
    }

    size_t anterior = 0U;
    size_t atual = passo;

    while (anterior < n && vetor[(atual < n ? atual : n) - 1U] < alvo) {
        anterior = atual;
        atual += passo;
        if (anterior >= n) {
            return 0;
        }
    }

    const size_t limite = (atual < n) ? atual : n;
    for (size_t i = anterior; i < limite; ++i) {
        if (vetor[i] == alvo) {
            if (indice_encontrado != NULL) {
                *indice_encontrado = i;
            }
            return 1;
        }
    }

    return 0;
}

static int busca_interpolacao(const int *vetor, size_t n, int alvo, size_t *indice_encontrado) {
    if (n == 0U) {
        return 0;
    }

    size_t esquerda = 0U;
    size_t direita = n - 1U;

    while (esquerda <= direita && alvo >= vetor[esquerda] && alvo <= vetor[direita]) {
        if (vetor[esquerda] == vetor[direita]) {
            if (vetor[esquerda] == alvo) {
                if (indice_encontrado != NULL) {
                    *indice_encontrado = esquerda;
                }
                return 1;
            }
            return 0;
        }

        const long long faixa_valores = (long long)vetor[direita] - (long long)vetor[esquerda];
        const long long deslocamento = (long long)alvo - (long long)vetor[esquerda];
        const size_t pos = esquerda + (size_t)(((long long)(direita - esquerda) * deslocamento) / faixa_valores);

        if (vetor[pos] == alvo) {
            if (indice_encontrado != NULL) {
                *indice_encontrado = pos;
            }
            return 1;
        }

        if (vetor[pos] < alvo) {
            esquerda = pos + 1U;
        } else {
            if (pos == 0U) {
                break;
            }
            direita = pos - 1U;
        }
    }

    return 0;
}

static int busca_exponencial(const int *vetor, size_t n, int alvo, size_t *indice_encontrado) {
    if (n == 0U) {
        return 0;
    }

    if (vetor[0] == alvo) {
        if (indice_encontrado != NULL) {
            *indice_encontrado = 0U;
        }
        return 1;
    }

    size_t limite = 1U;
    while (limite < n && vetor[limite] < alvo) {
        limite *= 2U;
    }

    const size_t esquerda = limite / 2U;
    const size_t direita = (limite < n) ? (limite + 1U) : n;
    return busca_binaria_faixa(vetor, esquerda, direita, alvo, indice_encontrado);
}

int busca_procurar(const int *vetor, size_t n, int alvo, BuscaMetodo metodo, size_t *indice_encontrado) {
    if (vetor == NULL || n == 0U) {
        return 0;
    }

    switch (metodo) {
        case BUSCA_LINEAR:
            return busca_linear(vetor, n, alvo, indice_encontrado);
        case BUSCA_BINARIA:
            return busca_binaria(vetor, n, alvo, indice_encontrado);
        case BUSCA_SALTO:
            return busca_salto(vetor, n, alvo, indice_encontrado);
        case BUSCA_INTERPOLACAO:
            return busca_interpolacao(vetor, n, alvo, indice_encontrado);
        case BUSCA_EXPONENCIAL:
            return busca_exponencial(vetor, n, alvo, indice_encontrado);
        default:
            return 0;
    }
}

const char *busca_nome(BuscaMetodo metodo) {
    switch (metodo) {
        case BUSCA_LINEAR:
            return "Busca Linear";
        case BUSCA_BINARIA:
            return "Busca Binaria";
        case BUSCA_SALTO:
            return "Busca por Salto";
        case BUSCA_INTERPOLACAO:
            return "Busca por Interpolacao";
        case BUSCA_EXPONENCIAL:
            return "Busca Exponencial";
        default:
            return "Desconhecido";
    }
}

const char *busca_complexidade(BuscaMetodo metodo) {
    switch (metodo) {
        case BUSCA_LINEAR:
            return "Linear: O(1) melhor, O(n) medio/pior, O(1) espaco.";
        case BUSCA_BINARIA:
            return "Binaria: O(1) melhor, O(log n) medio/pior, O(1) espaco.";
        case BUSCA_SALTO:
            return "Salto: O(1) melhor, O(sqrt(n)) medio/pior, O(1) espaco.";
        case BUSCA_INTERPOLACAO:
            return "Interpolacao: O(1) melhor, O(log log n) medio, O(n) pior, O(1) espaco.";
        case BUSCA_EXPONENCIAL:
            return "Exponencial: O(1) melhor, O(log n) medio/pior, O(1) espaco.";
        default:
            return "Metodo de busca invalido.";
    }
}

const char *busca_requisito(BuscaMetodo metodo) {
    switch (metodo) {
        case BUSCA_LINEAR:
            return "Nenhum pre-requisito de ordenacao.";
        case BUSCA_BINARIA:
        case BUSCA_SALTO:
        case BUSCA_INTERPOLACAO:
        case BUSCA_EXPONENCIAL:
            return "Requer vetor ordenado em ordem crescente.";
        default:
            return "Metodo de busca invalido.";
    }
}
