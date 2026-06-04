#include "busca.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PASS(nome) printf("  [OK] %s\n", nome)

static void test_busca_linear_desordenado(void) {
    const int vetor[] = {9, 4, 7, 1, 5, 3};
    size_t indice = 999U;

    assert(busca_procurar(vetor, 6U, 1, BUSCA_LINEAR, &indice) == 1);
    assert(indice == 3U);
    assert(busca_procurar(vetor, 6U, 8, BUSCA_LINEAR, &indice) == 0);
    PASS("test_busca_linear_desordenado");
}

static void test_metodos_ordenados_encontram(void) {
    const int vetor[] = {2, 5, 9, 12, 18, 24, 31, 40, 55};
    const BuscaMetodo metodos[] = {BUSCA_BINARIA, BUSCA_SALTO, BUSCA_INTERPOLACAO, BUSCA_EXPONENCIAL};
    const size_t total = sizeof(metodos) / sizeof(metodos[0]);

    for (size_t i = 0U; i < total; ++i) {
        size_t indice = 999U;
        assert(busca_procurar(vetor, 9U, 24, metodos[i], &indice) == 1);
        assert(indice == 5U);
    }

    PASS("test_metodos_ordenados_encontram");
}

static void test_metodos_ordenados_nao_encontram(void) {
    const int vetor[] = {2, 5, 9, 12, 18, 24, 31, 40, 55};
    const BuscaMetodo metodos[] = {BUSCA_BINARIA, BUSCA_SALTO, BUSCA_INTERPOLACAO, BUSCA_EXPONENCIAL};
    const size_t total = sizeof(metodos) / sizeof(metodos[0]);

    for (size_t i = 0U; i < total; ++i) {
        assert(busca_procurar(vetor, 9U, 999, metodos[i], NULL) == 0);
    }

    PASS("test_metodos_ordenados_nao_encontram");
}

static void test_limites_e_invalidos(void) {
    const int vetor[] = {1, 2, 3};
    size_t indice = 123U;

    assert(busca_procurar(NULL, 3U, 2, BUSCA_LINEAR, &indice) == 0);
    assert(busca_procurar(vetor, 0U, 2, BUSCA_LINEAR, &indice) == 0);
    assert(busca_procurar(vetor, 3U, 2, (BuscaMetodo)99, &indice) == 0);
    PASS("test_limites_e_invalidos");
}

static void test_strings_api(void) {
    assert(strcmp(busca_nome(BUSCA_LINEAR), "Busca Linear") == 0);
    assert(strcmp(busca_nome(BUSCA_BINARIA), "Busca Binaria") == 0);
    assert(strcmp(busca_nome(BUSCA_SALTO), "Busca por Salto") == 0);
    assert(strcmp(busca_nome(BUSCA_INTERPOLACAO), "Busca por Interpolacao") == 0);
    assert(strcmp(busca_nome(BUSCA_EXPONENCIAL), "Busca Exponencial") == 0);
    assert(strcmp(busca_nome((BuscaMetodo)99), "Desconhecido") == 0);

    assert(strcmp(busca_complexidade(BUSCA_LINEAR), "Linear: O(1) melhor, O(n) medio/pior, O(1) espaco.") == 0);
    assert(strcmp(busca_complexidade(BUSCA_BINARIA), "Binaria: O(1) melhor, O(log n) medio/pior, O(1) espaco.") == 0);
    assert(strcmp(busca_complexidade(BUSCA_SALTO), "Salto: O(1) melhor, O(sqrt(n)) medio/pior, O(1) espaco.") == 0);
    assert(strcmp(busca_complexidade(BUSCA_INTERPOLACAO),
                  "Interpolacao: O(1) melhor, O(log log n) medio, O(n) pior, O(1) espaco.") == 0);
    assert(strcmp(busca_complexidade(BUSCA_EXPONENCIAL), "Exponencial: O(1) melhor, O(log n) medio/pior, O(1) espaco.") == 0);
    assert(strcmp(busca_complexidade((BuscaMetodo)99), "Metodo de busca invalido.") == 0);

    assert(strcmp(busca_requisito(BUSCA_LINEAR), "Nenhum pre-requisito de ordenacao.") == 0);
    assert(strcmp(busca_requisito(BUSCA_BINARIA), "Requer vetor ordenado em ordem crescente.") == 0);
    assert(strcmp(busca_requisito(BUSCA_SALTO), "Requer vetor ordenado em ordem crescente.") == 0);
    assert(strcmp(busca_requisito(BUSCA_INTERPOLACAO), "Requer vetor ordenado em ordem crescente.") == 0);
    assert(strcmp(busca_requisito(BUSCA_EXPONENCIAL), "Requer vetor ordenado em ordem crescente.") == 0);
    assert(strcmp(busca_requisito((BuscaMetodo)99), "Metodo de busca invalido.") == 0);

    PASS("test_strings_api");
}

int main(void) {
    printf("=== Testes: Métodos de Busca ===\n");
    test_busca_linear_desordenado();
    test_metodos_ordenados_encontram();
    test_metodos_ordenados_nao_encontram();
    test_limites_e_invalidos();
    test_strings_api();
    printf("Todos os testes passaram.\n");
    return 0;
}
