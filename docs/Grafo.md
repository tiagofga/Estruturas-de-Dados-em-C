# Grafo — Grafo direcionado e não-direcionado com Matriz de Adjacência

## Visão geral

Implementação de um grafo em C usando **matriz de adjacência**, com suporte a:

- modo **não-direcionado**
- modo **direcionado**
- algoritmos principais (BFS, DFS, Dijkstra e ordenação topológica)
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
| `matriz` | `int **` | Matriz `V x V` com 0/1 para ausência/presença de aresta |

---

## Interface pública

```c
int  grafo_criar(Grafo *grafo, size_t vertices);
int  grafo_criar_direcionado(Grafo *grafo, size_t vertices, int direcionado);
void grafo_destruir(Grafo *grafo);
int  grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
int  grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
int  grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino);
int  grafo_bfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int  grafo_dfs(const Grafo *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int  grafo_dijkstra(const Grafo *grafo, size_t origem, int *distancias, size_t capacidade);
int  grafo_ordenacao_topologica(const Grafo *grafo, size_t *ordem, size_t capacidade, size_t *tamanho_ordem);
void grafo_imprimir(const Grafo *grafo);
```

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

---

## Algoritmos clássicos em grafos

### Menor caminho

- **Dijkstra**: implementado para matriz de adjacência com pesos não negativos.
- Complexidade desta implementação: **O(V²)**.

### Ordenação Topológica (grafos direcionados acíclicos)

- Implementada com algoritmo de **Kahn** (graus de entrada).
- Retorna falha para grafos com ciclo.
- Complexidade (matriz): **O(V²)**.

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
    size_t ordem[5];
    size_t visitados = 0U;
    int distancias[5];
    size_t topologica[5];
    size_t total_topologica = 0U;

    grafo_criar_direcionado(&grafo, 5U, 1);
    grafo_adicionar_aresta(&grafo, 0U, 1U);
    grafo_adicionar_aresta(&grafo, 0U, 2U);
    grafo_adicionar_aresta(&grafo, 1U, 3U);
    grafo_adicionar_aresta(&grafo, 2U, 3U);
    grafo_adicionar_aresta(&grafo, 3U, 4U);

    grafo_imprimir(&grafo);

    grafo_bfs(&grafo, 0U, ordem, 5U, &visitados);
    grafo_dfs(&grafo, 0U, ordem, 5U, &visitados);
    grafo_dijkstra(&grafo, 0U, distancias, 5U);
    grafo_ordenacao_topologica(&grafo, topologica, 5U, &total_topologica);

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
