#include "algoritmos_grafos.h"
#include "avl.h"
#include "tabela_hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCH_SIZE 5000

static double elapsed_ms(clock_t start, clock_t end) {
    return ((double)(end - start) * 1000.0) / (double)CLOCKS_PER_SEC;
}

static void bench_avl(void) {
    AVLNo *raiz = NULL;
    clock_t start = clock();
    for (int i = 0; i < BENCH_SIZE; ++i) {
        raiz = avl_inserir(raiz, i);
    }
    for (int i = 0; i < BENCH_SIZE; ++i) {
        (void)avl_buscar(raiz, i);
    }
    for (int i = 0; i < BENCH_SIZE; i += 2) {
        raiz = avl_remover(raiz, i);
    }
    clock_t end = clock();
    printf("AVL,%d,insert+search+remove_half,%.3f\n", BENCH_SIZE, elapsed_ms(start, end));
    avl_destruir(raiz);
}

static void bench_tabela_hash(void) {
    TabelaHash *tabela = tabela_hash_criar(10007U);
    if (tabela == NULL) {
        fprintf(stderr, "failed to create hash table\n");
        return;
    }

    clock_t start = clock();
    for (int i = 0; i < BENCH_SIZE; ++i) {
        (void)tabela_hash_inserir(tabela, i, i * 2);
    }
    for (int i = 0; i < BENCH_SIZE; ++i) {
        int valor = 0;
        (void)tabela_hash_buscar(tabela, i, &valor);
    }
    for (int i = 0; i < BENCH_SIZE; i += 2) {
        (void)tabela_hash_remover(tabela, i);
    }
    clock_t end = clock();
    printf("TabelaHash,%d,insert+search+remove_half,%.3f\n", BENCH_SIZE, elapsed_ms(start, end));
    tabela_hash_destruir(tabela);
}

static void bench_kruskal(void) {
    const size_t vertices = 200U;
    const size_t edges = vertices * 3U;
    ArestaPeso *arestas = malloc(edges * sizeof(*arestas));
    ArestaPeso *mst = malloc((vertices - 1U) * sizeof(*mst));
    if (arestas == NULL || mst == NULL) {
        free(arestas);
        free(mst);
        fprintf(stderr, "failed to allocate graph benchmark\n");
        return;
    }

    for (size_t i = 0U; i < edges; ++i) {
        arestas[i].origem = i % vertices;
        arestas[i].destino = (i * 37U + 1U) % vertices;
        if (arestas[i].origem == arestas[i].destino) {
            arestas[i].destino = (arestas[i].destino + 1U) % vertices;
        }
        arestas[i].peso = (int)((i * 17U) % 1000U) + 1;
    }

    size_t quantidade = 0U;
    int peso_total = 0;
    clock_t start = clock();
    int ok = kruskal(vertices, arestas, edges, mst, vertices - 1U, &quantidade, &peso_total);
    clock_t end = clock();
    printf("Kruskal,%zu,mst_edges_%zu_ok_%d,%.3f\n", vertices, edges, ok, elapsed_ms(start, end));

    free(arestas);
    free(mst);
}

int main(void) {
    puts("module,size,operation,time_ms");
    bench_avl();
    bench_tabela_hash();
    bench_kruskal();
    return 0;
}
