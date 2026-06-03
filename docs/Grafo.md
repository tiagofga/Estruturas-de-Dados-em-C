# Grafo — Grafo não-direcionado com Matriz de Adjacência

## Visão geral

Implementação de um **grafo não-direcionado** em C usando **matriz de adjacência**.
Cada vértice é identificado por um índice inteiro de `0` a `vertices - 1`.
Uma aresta entre `u` e `v` é representada por `matriz[u][v] = matriz[v][u] = 1`.

---

## Estrutura de dados

```c
/* include/grafo.h */
typedef struct {
    size_t  vertices;  /* número de vértices */
    int   **matriz;    /* matriz de adjacência vertices x vertices */
} Grafo;
```

### Campos

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `vertices` | `size_t` | Número de vértices (imutável após criação) |
| `matriz` | `int **` | Matriz quadrada alocada dinamicamente |

`matriz[i][j] == 1` indica a existência da aresta entre `i` e `j`;
`matriz[i][j] == 0` indica ausência.

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

## Operações detalhadas

### `grafo_criar`

```c
int grafo_criar(Grafo *grafo, size_t vertices);
```

Aloca e inicializa a matriz de adjacência com zeros.

- Aloca `vertices` ponteiros e, para cada um, um array de `vertices` inteiros.
- Em caso de falha parcial, libera a memória já alocada antes de retornar.
- **Retorna** `1` em caso de sucesso, `0` se `grafo == NULL`, `vertices == 0`
  ou falha de alocação.
- **Complexidade**: O(V²).

---

### `grafo_destruir`

```c
void grafo_destruir(Grafo *grafo);
```

Libera cada linha da matriz e depois o array de ponteiros. Zera os campos.
Seguro para chamar com `grafo == NULL` ou `grafo->matriz == NULL`.

- **Complexidade**: O(V).

---

### `grafo_adicionar_aresta`

```c
int grafo_adicionar_aresta(Grafo *grafo, size_t origem, size_t destino);
```

Adiciona a aresta não-direcionada `(origem, destino)`:
define `matriz[origem][destino] = 1` e `matriz[destino][origem] = 1`.

- **Retorna** `0` se `grafo == NULL`, matriz não alocada ou índices fora dos limites.
- **Complexidade**: O(1).

---

### `grafo_remover_aresta`

```c
int grafo_remover_aresta(Grafo *grafo, size_t origem, size_t destino);
```

Remove a aresta `(origem, destino)`:
define `matriz[origem][destino] = 0` e `matriz[destino][origem] = 0`.

- **Retorna** `0` se índices inválidos ou grafo `NULL`.
- **Complexidade**: O(1).

---

### `grafo_tem_aresta`

```c
int grafo_tem_aresta(const Grafo *grafo, size_t origem, size_t destino);
```

Verifica se a aresta `(origem, destino)` existe.

- **Retorna** `1` se a aresta existe, `0` caso contrário (inclusive índices inválidos).
- **Complexidade**: O(1).

---

### `grafo_imprimir`

```c
void grafo_imprimir(const Grafo *grafo);
```

Imprime a matriz de adjacência linha por linha, com valores separados por espaço.

---

## Complexidade resumida

| Operação | Complexidade |
|----------|-------------|
| Criar | O(V²) |
| Destruir | O(V) |
| Adicionar aresta | O(1) |
| Remover aresta | O(1) |
| Verificar aresta | O(1) |
| Imprimir | O(V²) |

---

## Representação visual

Grafo com 4 vértices e arestas `0-1`, `0-2`, `2-3`:

```
     0 --- 1
     |
     2 --- 3
```

Matriz de adjacência correspondente:

```
     0  1  2  3
0  [ 0  1  1  0 ]
1  [ 1  0  0  0 ]
2  [ 1  0  0  1 ]
3  [ 0  0  1  0 ]
```

---

## Trade-offs — Matriz vs. Lista de Adjacência

| Aspecto | Matriz de adjacência | Lista de adjacência |
|---------|---------------------|---------------------|
| Espaço | O(V²) | O(V + E) |
| Verificar aresta | O(1) | O(grau do vértice) |
| Listar vizinhos | O(V) | O(grau do vértice) |
| Melhor para | Grafos densos | Grafos esparsos |

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

    printf("Matriz de adjacência:\n");
    grafo_imprimir(&grafo);

    printf("Aresta 0-1: %s\n", grafo_tem_aresta(&grafo, 0U, 1U) ? "sim" : "não");
    printf("Aresta 1-3: %s\n", grafo_tem_aresta(&grafo, 1U, 3U) ? "sim" : "não");

    grafo_destruir(&grafo);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Grafo
make        # compila o exemplo em build/app
make run    # executa o exemplo
make test   # executa os testes automatizados
make clean  # remove artefatos
```

---

Voltar para o [índice da documentação](./README.md).
