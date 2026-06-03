# Grafo — Grafo não-direcionado com Matriz de Adjacência

## Visão geral

Implementação de um **grafo não-direcionado** em C usando **matriz de adjacência**.
Cada vértice é identificado por um índice inteiro de `0` a `vertices - 1`.

---

## Estrutura de dados

```c
/* include/grafo.h */
typedef struct {
    size_t  vertices;
    int   **matriz;
} Grafo;
```

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `vertices` | `size_t` | Número de vértices |
| `matriz` | `int **` | Matriz `V x V` com 0/1 para ausência/presença de aresta |

---

## Interface pública

```c
int  grafo_criar(Grafo *grafo, size_t vertices);
void grafo_destruir(Grafo *grafo);
int  grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
int  grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
int  grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino);
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

## Métodos de busca em grafos

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

- **Dijkstra** (pesos não negativos): O((V + E) log V) com heap.
- **Bellman-Ford** (aceita pesos negativos): O(V * E).
- **Floyd-Warshall** (todos os pares): O(V³).

### Árvore Geradora Mínima (MST)

- **Prim**: O(E log V) com heap e lista de adjacência.
- **Kruskal**: O(E log E) + Union-Find.

### Ordenação Topológica (grafos direcionados acíclicos)

- Kahn (graus de entrada) ou DFS pós-ordem.
- Complexidade: O(V + E).

---

## Matriz vs. Lista de adjacência

| Aspecto | Matriz | Lista |
|---------|--------|-------|
| Espaço | O(V²) | O(V + E) |
| Verificar aresta | O(1) | O(grau) |
| Listar vizinhos | O(V) | O(grau) |
| Melhor cenário | Grafos densos | Grafos esparsos |

---

## Métodos de ordenação relacionados a grafos

- **Ordenação topológica** (DAG): ordena vértices por dependência.
- **Não é ordenação de valores** como Quick/Merge; é ordenação estrutural de nós.

---

## Exemplo de uso

```c
#include "grafo.h"
#include <stdio.h>

int main(void) {
    Grafo grafo;

    grafo_criar(&grafo, 4U);
    grafo_adicionar_aresta(&grafo, 0U, 1U);
    grafo_adicionar_aresta(&grafo, 0U, 2U);
    grafo_adicionar_aresta(&grafo, 2U, 3U);

    grafo_imprimir(&grafo);

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
