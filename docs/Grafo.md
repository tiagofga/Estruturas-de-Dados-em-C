# Grafo — Grafo direcionado e não-direcionado com Matriz de Adjacência

## Visão geral

Implementação de um grafo em C usando **matriz de adjacência**, com suporte a:

- modo **não-direcionado**
- modo **direcionado**
- arestas **não ponderadas** e **ponderadas com pesos positivos**
- algoritmos principais: BFS, DFS, Dijkstra e ordenação topológica

Cada vértice é identificado por um índice inteiro de `0` a `vertices - 1`.

---

## Estrutura de dados

```c
/* include/grafo.h */
typedef struct {
    size_t  vertices;
    int     direcionado;
    int   **matriz;
} Grafo;
```

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `vertices` | `size_t` | Número de vértices |
| `direcionado` | `int` | `0` para não-direcionado, `1` para direcionado |
| `matriz` | `int **` | Matriz `V x V`; `0` indica ausência de aresta; valor positivo indica peso |

---

## Interface pública

```c
int  grafo_criar(Grafo *grafo, size_t vertices);
int  grafo_criar_direcionado(Grafo *grafo, size_t vertices, int direcionado);
void grafo_destruir(Grafo *grafo);
int  grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
int  grafo_adicionar_aresta_ponderada(Grafo *grafo, size_t origem, size_t destino, int peso);
int  grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
int  grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino);
int  grafo_bfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int  grafo_dfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int  grafo_dijkstra(const Grafo *grafo, size_t origem, int *distancias, size_t capacidade);
int  grafo_ordenacao_topologica(const Grafo *grafo, size_t *ordem, size_t capacidade, size_t *tamanho_ordem);
void grafo_imprimir(const Grafo *grafo);
```

---

## Operações básicas

### `grafo_adicionar_aresta`

Adiciona uma aresta com peso `1`. É um atalho para `grafo_adicionar_aresta_ponderada(..., 1)`.

### `grafo_adicionar_aresta_ponderada`

Adiciona uma aresta com peso positivo.

- Retorna `0` se os vértices forem inválidos ou se `peso <= 0`.
- Em grafos não-direcionados, a matriz é preenchida nos dois sentidos.
- Em grafos direcionados, apenas `origem -> destino` é preenchido.

---

## Complexidade resumida (matriz de adjacência)

| Operação | Complexidade |
|----------|-------------|
| Criar | O(V²) |
| Destruir | O(V) |
| Adicionar aresta | O(1) |
| Remover aresta | O(1) |
| Verificar aresta | O(1) |
| Listar vizinhos de um vértice | O(V) |

---

## Algoritmos implementados

### BFS (Busca em Largura)

- Percorre vértices por nível (usa fila).
- Menor caminho em número de arestas para grafos não ponderados.
- Complexidade:
  - O(V + E) com lista de adjacência
  - O(V²) com matriz de adjacência

### DFS (Busca em Profundidade)

- Percorre aprofundando caminho (recursiva ou pilha).
- Usada para componentes conexas, detecção de ciclos e ordenação topológica (DAG).
- Complexidade:
  - O(V + E) com lista
  - O(V²) com matriz

### Dijkstra

- Calcula menor caminho a partir de uma origem.
- Requer pesos **não negativos**; nesta implementação, apenas pesos positivos são aceitos nas arestas.
- Complexidade desta implementação com matriz: **O(V²)**.

### Ordenação Topológica

- Implementada com algoritmo de **Kahn** (graus de entrada).
- Requer grafo direcionado acíclico (DAG).
- Retorna falha para grafos com ciclo.
- Complexidade com matriz: **O(V²)**.

---

## Matriz vs. Lista de adjacência

| Aspecto | Matriz | Lista |
|---------|--------|-------|
| Espaço | O(V²) | O(V + E) |
| Verificar aresta | O(1) | O(grau) |
| Listar vizinhos | O(V) | O(grau) |
| Melhor cenário | Grafos densos | Grafos esparsos |

---

## Exemplo de uso

```c
#include "grafo.h"
#include <stdio.h>

int main(void) {
    Grafo grafo;
    int distancias[5];

    grafo_criar_direcionado(&grafo, 5U, 1);
    grafo_adicionar_aresta_ponderada(&grafo, 0U, 1U, 10);
    grafo_adicionar_aresta_ponderada(&grafo, 0U, 2U, 3);
    grafo_adicionar_aresta_ponderada(&grafo, 2U, 1U, 4);
    grafo_adicionar_aresta_ponderada(&grafo, 1U, 3U, 2);
    grafo_adicionar_aresta_ponderada(&grafo, 3U, 4U, 7);

    grafo_dijkstra(&grafo, 0U, distancias, 5U);

    for (size_t i = 0U; i < 5U; ++i) {
        printf("Distância até %zu: %d\n", i, distancias[i]);
    }

    grafo_destruir(&grafo);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Grafo
make
make run
make test
make clean
```

---

Voltar para o [índice da documentação](./README.md).
