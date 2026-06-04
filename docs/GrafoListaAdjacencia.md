# Grafo — Lista de Adjacência

## Visão geral

Implementação de grafo em C usando **lista de adjacência**. Essa representação é adequada para grafos esparsos, pois usa memória proporcional ao número de vértices e arestas.

## Operações principais

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

## Complexidade

| Operação | Complexidade |
|----------|-------------|
| Espaço | O(V + E) |
| Inserir aresta | O(grau do vértice) para atualizar duplicatas |
| Remover aresta | O(grau do vértice) |
| Verificar aresta | O(grau do vértice) |
| BFS | O(V + E) |
| DFS | O(V + E) |
| Dijkstra simples | O(V² + E) |

## Matriz vs. lista

A matriz é melhor para grafos densos e consulta O(1) de arestas. A lista de adjacência é melhor para grafos esparsos e para iterar vizinhos com menor uso de memória.
