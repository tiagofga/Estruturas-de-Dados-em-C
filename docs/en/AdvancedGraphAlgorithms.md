# Advanced Graph Algorithms

## Overview

This module contains classic algorithms for connectivity, minimum spanning trees, and shortest paths.

Implemented algorithms:

- Union-Find / Disjoint Set Union (DSU)
- Kruskal
- Prim using an adjacency matrix
- Bellman-Ford
- Floyd-Warshall

---

## Main structures

```c
typedef struct {
    size_t origem;
    size_t destino;
    int peso;
} ArestaPeso;

typedef struct UnionFind UnionFind;
```

`ArestaPeso` represents a weighted edge. `UnionFind` is an opaque ADT for disjoint sets: its internal fields remain private in the `.c` file.

---

## Union-Find

Union-Find maintains disjoint components and quickly answers whether two vertices belong to the same set.

Operations:

```c
UnionFind *union_find_criar(size_t tamanho);
void union_find_destruir(UnionFind *uf);
size_t union_find_encontrar(UnionFind *uf, size_t elemento);
int union_find_unir(UnionFind *uf, size_t a, size_t b);
int union_find_mesmo_conjunto(UnionFind *uf, size_t a, size_t b);
```

Example:

```c
UnionFind *uf = union_find_criar(10);
if (uf != NULL) {
    union_find_unir(uf, 0, 1);
    union_find_destruir(uf);
}
```

Amortized complexity: almost O(1), usually represented as O(α(n)), where α is the inverse Ackermann function.

---

## Kruskal

Kruskal computes a minimum spanning tree for an undirected weighted graph. It sorts edges by weight and uses Union-Find to avoid cycles.

```c
int kruskal(size_t vertices,
            const ArestaPeso *arestas,
            size_t quantidade_arestas,
            ArestaPeso *arvore_geradora_minima,
            size_t capacidade_arvore,
            size_t *quantidade_arvore,
            int *peso_total);
```

Complexity: O(E log E), dominated by sorting the edges.

---

## Prim with adjacency matrix

Prim also computes a minimum spanning tree. This implementation uses an adjacency matrix and selects the next vertex by linear scan.

```c
int prim_matriz(size_t vertices,
                const int *matriz,
                ArestaPeso *arvore_geradora_minima,
                size_t capacidade_arvore,
                size_t *quantidade_arvore,
                int *peso_total);
```

Complexity: O(V²).

---

## Bellman-Ford

Bellman-Ford computes single-source shortest paths and accepts negative edge weights. It also detects negative cycles reachable from the source.

```c
int bellman_ford(size_t vertices,
                 const ArestaPeso *arestas,
                 size_t quantidade_arestas,
                 size_t origem,
                 int *distancias);
```

Return values:

- `1`: success;
- `0`: invalid input;
- `-1`: negative cycle detected.

Complexity: O(VE).

---

## Floyd-Warshall

Floyd-Warshall computes shortest paths between all pairs of vertices.

```c
int floyd_warshall(size_t vertices, const int *matriz, int *distancias);
```

Return values:

- `1`: success;
- `0`: invalid input;
- `-1`: negative cycle detected.

Complexity: O(V³).

---

## Complexity summary

| Algorithm | Main use | Complexity |
|----------|----------|------------|
| Union-Find | Disjoint components | amortized O(α(n)) |
| Kruskal | Minimum spanning tree | O(E log E) |
| Prim with matrix | Minimum spanning tree | O(V²) |
| Bellman-Ford | Shortest path with negative weights | O(VE) |
| Floyd-Warshall | All-pairs shortest paths | O(V³) |
