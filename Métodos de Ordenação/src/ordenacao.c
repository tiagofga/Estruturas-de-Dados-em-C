#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Utilitário interno                                                  */
/* ------------------------------------------------------------------ */

static void trocar(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

/* ------------------------------------------------------------------ */
/* Bubble Sort                                                         */
/* ------------------------------------------------------------------ */

static void bubble_sort(int *v, size_t n) {
    if (n <= 1U) {
        return;
    }

    for (size_t i = 0U; i + 1U < n; ++i) {
        int trocou = 0;

        for (size_t j = 0U; j + 1U < n - i; ++j) {
            if (v[j] > v[j + 1U]) {
                trocar(&v[j], &v[j + 1U]);
                trocou = 1;
            }
        }

        if (!trocou) {
            break;
        }
    }
}

/* ------------------------------------------------------------------ */
/* Insertion Sort                                                      */
/* ------------------------------------------------------------------ */

static void insertion_sort(int *v, size_t n) {
    if (n <= 1U) {
        return;
    }

    for (size_t i = 1U; i < n; ++i) {
        const int chave = v[i];
        size_t j = i;

        while (j > 0U && v[j - 1U] > chave) {
            v[j] = v[j - 1U];
            --j;
        }

        v[j] = chave;
    }
}

/* ------------------------------------------------------------------ */
/* Selection Sort                                                      */
/* ------------------------------------------------------------------ */

static void selection_sort(int *v, size_t n) {
    if (n <= 1U) {
        return;
    }

    for (size_t i = 0U; i + 1U < n; ++i) {
        size_t menor = i;

        for (size_t j = i + 1U; j < n; ++j) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            trocar(&v[i], &v[menor]);
        }
    }
}

/* ------------------------------------------------------------------ */
/* Merge Sort                                                          */
/* ------------------------------------------------------------------ */

static void merge(int *v, size_t esq, size_t meio, size_t dir) {
    const size_t tam_esq = meio - esq;
    const size_t tam_dir = dir - meio;

    int *esq_buf = malloc(tam_esq * sizeof(int));
    int *dir_buf = malloc(tam_dir * sizeof(int));

    if (esq_buf == NULL || dir_buf == NULL) {
        free(esq_buf);
        free(dir_buf);
        return;
    }

    memcpy(esq_buf, v + esq, tam_esq * sizeof(int));
    memcpy(dir_buf, v + meio, tam_dir * sizeof(int));

    size_t i = 0U, j = 0U, k = esq;

    while (i < tam_esq && j < tam_dir) {
        if (esq_buf[i] <= dir_buf[j]) {
            v[k++] = esq_buf[i++];
        } else {
            v[k++] = dir_buf[j++];
        }
    }

    while (i < tam_esq) {
        v[k++] = esq_buf[i++];
    }

    while (j < tam_dir) {
        v[k++] = dir_buf[j++];
    }

    free(esq_buf);
    free(dir_buf);
}

static void merge_sort_rec(int *v, size_t esq, size_t dir) {
    if (dir - esq <= 1U) {
        return;
    }

    const size_t meio = esq + (dir - esq) / 2U;
    merge_sort_rec(v, esq, meio);
    merge_sort_rec(v, meio, dir);
    merge(v, esq, meio, dir);
}

static void merge_sort(int *v, size_t n) {
    if (n <= 1U) {
        return;
    }

    merge_sort_rec(v, 0U, n);
}

/* ------------------------------------------------------------------ */
/* Quick Sort                                                          */
/* ------------------------------------------------------------------ */

static size_t particionar(int *v, size_t esq, size_t dir) {
    const size_t meio = esq + (dir - esq - 1U) / 2U;
    trocar(&v[meio], &v[dir - 1U]);

    const int pivo = v[dir - 1U];
    size_t i = esq;

    for (size_t j = esq; j < dir - 1U; ++j) {
        if (v[j] <= pivo) {
            trocar(&v[i], &v[j]);
            ++i;
        }
    }

    trocar(&v[i], &v[dir - 1U]);
    return i;
}

static void quick_sort_rec(int *v, size_t esq, size_t dir) {
    if (dir - esq <= 1U) {
        return;
    }

    const size_t p = particionar(v, esq, dir);

    if (p > esq) {
        quick_sort_rec(v, esq, p);
    }

    quick_sort_rec(v, p + 1U, dir);
}

static void quick_sort(int *v, size_t n) {
    if (n <= 1U) {
        return;
    }

    quick_sort_rec(v, 0U, n);
}

/* ------------------------------------------------------------------ */
/* Heap Sort                                                           */
/* ------------------------------------------------------------------ */

static void heap_descer(int *v, size_t n, size_t raiz) {
    while (1) {
        size_t maior = raiz;
        const size_t esq = 2U * raiz + 1U;
        const size_t dir = 2U * raiz + 2U;

        if (esq < n && v[esq] > v[maior]) {
            maior = esq;
        }

        if (dir < n && v[dir] > v[maior]) {
            maior = dir;
        }

        if (maior == raiz) {
            break;
        }

        trocar(&v[raiz], &v[maior]);
        raiz = maior;
    }
}

static void heap_sort(int *v, size_t n) {
    if (n <= 1U) {
        return;
    }

    for (size_t i = n / 2U; i-- > 0U;) {
        heap_descer(v, n, i);
    }

    for (size_t i = n - 1U; i > 0U; --i) {
        trocar(&v[0], &v[i]);
        heap_descer(v, i, 0U);
    }
}

/* ------------------------------------------------------------------ */
/* API pública                                                         */
/* ------------------------------------------------------------------ */

void ordenacao_ordenar(int *vetor, size_t n, OrdenacaoMetodo metodo) {
    if (vetor == NULL || n == 0U) {
        return;
    }

    switch (metodo) {
        case ORDENACAO_BUBBLE:    bubble_sort(vetor, n);    break;
        case ORDENACAO_INSERTION: insertion_sort(vetor, n); break;
        case ORDENACAO_SELECTION: selection_sort(vetor, n); break;
        case ORDENACAO_MERGE:     merge_sort(vetor, n);     break;
        case ORDENACAO_QUICK:     quick_sort(vetor, n);     break;
        case ORDENACAO_HEAP:      heap_sort(vetor, n);      break;
        default:                                            break;
    }
}

const char *ordenacao_complexidade(OrdenacaoMetodo metodo) {
    switch (metodo) {
        case ORDENACAO_BUBBLE:
            return "Bubble: O(n) melhor, O(n^2) medio/pior, O(1) espaco, estavel.";
        case ORDENACAO_INSERTION:
            return "Insertion: O(n) melhor, O(n^2) medio/pior, O(1) espaco, estavel.";
        case ORDENACAO_SELECTION:
            return "Selection: O(n^2) todos os casos, O(1) espaco, nao estavel.";
        case ORDENACAO_MERGE:
            return "Merge: O(n log n) todos os casos, O(n) espaco extra, estavel.";
        case ORDENACAO_QUICK:
            return "Quick: O(n log n) medio, O(n^2) pior, O(log n) espaco extra, nao estavel.";
        case ORDENACAO_HEAP:
            return "Heap: O(n log n) todos os casos, O(1) espaco extra, nao estavel.";
        default:
            return "Metodo de ordenacao invalido.";
    }
}

const char *ordenacao_nome(OrdenacaoMetodo metodo) {
    switch (metodo) {
        case ORDENACAO_BUBBLE:    return "Bubble Sort";
        case ORDENACAO_INSERTION: return "Insertion Sort";
        case ORDENACAO_SELECTION: return "Selection Sort";
        case ORDENACAO_MERGE:     return "Merge Sort";
        case ORDENACAO_QUICK:     return "Quick Sort";
        case ORDENACAO_HEAP:      return "Heap Sort";
        default:                  return "Desconhecido";
    }
}

void ordenacao_imprimir(const int *vetor, size_t n) {
    if (vetor == NULL) {
        return;
    }

    printf("[ ");
    for (size_t i = 0U; i < n; ++i) {
        printf("%d", vetor[i]);
        if (i + 1U < n) {
            printf(", ");
        }
    }
    printf(" ]\n");
}
