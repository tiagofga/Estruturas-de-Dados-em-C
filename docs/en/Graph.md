# Graph — Adjacency Matrix and Graph Algorithms

[Português](../Grafo.md) | **English**

## Overview

Implementation of a graph in C using an **adjacency matrix**. The module supports directed and undirected graphs, unweighted and positively weighted edges, and basic graph algorithms.

The adjacency matrix representation provides O(1) edge lookup, but uses O(V²) memory, where `V` is the number of vertices.

---

## Data structure

The graph stores:

- number of vertices;
- whether it is directed or undirected;
- adjacency matrix;
- positive integer weights for weighted edges.

For unweighted edges, the stored weight is `1`.

---

## Main operations

```c
int grafo_criar(Grafo *grafo, size_t vertices, int direcionado);
void grafo_destruir(Grafo *grafo);
int grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
int grafo_adicionar_aresta_ponderada(Grafo *grafo, size_t origem, size_t destino, int peso);
int grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
int grafo_existe_aresta(const Grafo *grafo, size_t origem, size_t destino);
int grafo_bfs(const Grafo *grafo, size_t origem, int *visitados);
int grafo_dfs(const Grafo *grafo, size_t origem, int *visitados);
int grafo_dijkstra(const Grafo *grafo, size_t origem, int *distancias);
int grafo_ordenacao_topologica(const Grafo *grafo, int *ordem);
```

---

## Edge operations

### `grafo_adicionar_aresta`

Adds an unweighted edge with weight `1`.

In undirected graphs, the symmetric edge is also added.

### `grafo_adicionar_aresta_ponderada`

Adds an edge with a positive integer weight.

- Weight must be greater than zero.
- In undirected graphs, both directions receive the same weight.
- This function is used by Dijkstra's algorithm.

---

## Algorithms

### Breadth-First Search (BFS)

Visits vertices level by level from a source vertex.

- **Complexity with adjacency matrix**: O(V²)

### Depth-First Search (DFS)

Explores each branch as deeply as possible before backtracking.

- **Complexity with adjacency matrix**: O(V²)

### Dijkstra

Computes shortest paths from a source vertex using positive edge weights.

- **Complexity with adjacency matrix**: O(V²)
- Does not support negative weights.

### Topological sort

Computes a valid topological ordering for directed acyclic graphs (DAGs).

- **Complexity with adjacency matrix**: O(V²)

---

## Complexity summary

| Operation | Complexity |
|-----------|------------|
| Edge lookup | O(1) |
| Add/remove edge | O(1) |
| BFS | O(V²) |
| DFS | O(V²) |
| Dijkstra | O(V²) |
| Topological sort | O(V²) |
| Memory usage | O(V²) |

---

## Notes

The adjacency matrix is simple and efficient for dense graphs. For sparse graphs, an adjacency list representation is usually more memory-efficient and is a good future extension for this repository.

---

Back to the [documentation index](./README.md).
