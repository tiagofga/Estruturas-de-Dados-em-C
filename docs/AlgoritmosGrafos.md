# Algoritmos Avançados de Grafos

## Visão geral

Este módulo reúne algoritmos clássicos usados em problemas de conectividade, árvores geradoras mínimas e caminhos mínimos.

Algoritmos implementados:

- Union-Find / Disjoint Set Union (DSU)
- Kruskal
- Prim com matriz de adjacência
- Bellman-Ford
- Floyd-Warshall

---

## Estruturas principais

```c
typedef struct {
    size_t origem;
    size_t destino;
    int peso;
} ArestaPeso;

typedef struct {
    size_t *pai;
    size_t *rank;
    size_t tamanho;
} UnionFind;
```

`ArestaPeso` representa uma aresta ponderada. `UnionFind` representa conjuntos disjuntos com compressão de caminho e união por rank.

---

## Union-Find

Union-Find é usado para manter componentes disjuntas e responder rapidamente se dois vértices pertencem ao mesmo conjunto.

Operações:

```c
int union_find_criar(UnionFind *uf, size_t tamanho);
void union_find_destruir(UnionFind *uf);
size_t union_find_encontrar(UnionFind *uf, size_t elemento);
int union_find_unir(UnionFind *uf, size_t a, size_t b);
int union_find_mesmo_conjunto(UnionFind *uf, size_t a, size_t b);
```

Complexidade amortizada: quase O(1), usualmente representada por O(α(n)), em que α é a função inversa de Ackermann.

---

## Kruskal

Kruskal calcula uma árvore geradora mínima em grafo não direcionado e ponderado. O algoritmo ordena as arestas por peso e usa Union-Find para evitar ciclos.

```c
int kruskal(size_t vertices,
            const ArestaPeso *arestas,
            size_t quantidade_arestas,
            ArestaPeso *arvore_geradora_minima,
            size_t capacidade_arvore,
            size_t *quantidade_arvore,
            int *peso_total);
```

Complexidade: O(E log E), dominada pela ordenação das arestas.

---

## Prim com matriz

Prim também calcula uma árvore geradora mínima. Nesta implementação, usa matriz de adjacência e escolhe o próximo vértice de menor chave por varredura linear.

```c
int prim_matriz(size_t vertices,
                const int *matriz,
                ArestaPeso *arvore_geradora_minima,
                size_t capacidade_arvore,
                size_t *quantidade_arvore,
                int *peso_total);
```

Complexidade: O(V²).

---

## Bellman-Ford

Bellman-Ford calcula caminhos mínimos a partir de uma origem e aceita pesos negativos. Também detecta ciclos negativos alcançáveis a partir da origem.

```c
int bellman_ford(size_t vertices,
                 const ArestaPeso *arestas,
                 size_t quantidade_arestas,
                 size_t origem,
                 int *distancias);
```

Retornos:

- `1`: execução bem-sucedida;
- `0`: entrada inválida;
- `-1`: ciclo negativo detectado.

Complexidade: O(VE).

---

## Floyd-Warshall

Floyd-Warshall calcula os menores caminhos entre todos os pares de vértices.

```c
int floyd_warshall(size_t vertices, const int *matriz, int *distancias);
```

Retornos:

- `1`: execução bem-sucedida;
- `0`: entrada inválida;
- `-1`: ciclo negativo detectado.

Complexidade: O(V³).

---

## Resumo de complexidade

| Algoritmo | Uso principal | Complexidade |
|----------|---------------|--------------|
| Union-Find | Componentes disjuntas | O(α(n)) amortizado |
| Kruskal | Árvore geradora mínima | O(E log E) |
| Prim com matriz | Árvore geradora mínima | O(V²) |
| Bellman-Ford | Caminho mínimo com pesos negativos | O(VE) |
| Floyd-Warshall | Caminho mínimo entre todos os pares | O(V³) |
