# Graph — Adjacency List

## Overview

This module implements a graph in C using an **adjacency list**. This representation is suitable for sparse graphs because memory usage is proportional to the number of vertices and edges.

## Main operations

```c
int grafo_lista_criar(GrafoLista *grafo, size_t vertices, int direcionado);
void grafo_lista_destruir(GrafoLista *grafo);
int grafo_lista_adicionar_aresta(GrafoLista *grafo, size_t origem, size_t destino);
int grafo_lista_adicionar_aresta_ponderada(GrafoLista *grafo, size_t origem, size_t destino, int peso);
int grafo_lista_remover_aresta(GrafoLista *grafo, size_t origem, size_t destino);
int grafo_lista_bfs(const GrafoLista *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int grafo_lista_dfs(const GrafoLista *grafo, size_t inicio, size_t *ordem, size_t capacidade, size_t *visitados);
int grafo_lista_dijkstra(const GrafoLista *grafo, size_t origem, int *distancias, size_t capacidade);
```

## Features

- Directed and undirected graphs.
- Positive weighted edges.
- BFS and DFS traversal.
- Single-source shortest paths with Dijkstra for positive weights.

## Complexity

| Operation | Complexity |
|----------|------------|
| Space | O(V + E) |
| Insert edge | O(degree of vertex), due to duplicate updates |
| Remove edge | O(degree of vertex) |
| Check edge | O(degree of vertex) |
| BFS | O(V + E) |
| DFS | O(V + E) |
| Simple Dijkstra | O(V² + E) |

## Matrix vs. list

An adjacency matrix is better for dense graphs and O(1) edge lookup. An adjacency list is better for sparse graphs and efficient neighbor iteration with lower memory usage.
