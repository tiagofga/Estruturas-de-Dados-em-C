# Árvore — Árvore Binária de Busca (BST)

## Visão geral

Implementação de uma **Árvore Binária de Busca** (BST — *Binary Search Tree*) em C.
Cada nó armazena um valor inteiro e dois ponteiros: filho esquerdo (valores menores)
e filho direito (valores maiores). A propriedade BST é mantida em todas as operações,
permitindo busca eficiente em O(log n) no caso médio.

---

## Estrutura de dados

```c
/* include/arvore.h */
typedef struct No {
    int          valor;
    struct No   *esquerda;
    struct No   *direita;
} No;
```

### Campos

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `valor` | `int` | Valor armazenado no nó |
| `esquerda` | `No *` | Filho esquerdo (valores menores) ou `NULL` |
| `direita` | `No *` | Filho direito (valores maiores) ou `NULL` |

A árvore inteira é representada por um **ponteiro para o nó raiz** (`No *raiz`).
Uma árvore vazia é representada por `raiz == NULL`.

---

## Interface pública

```c
No  *arvore_inserir(No *raiz, int valor);
int  arvore_buscar(const No *raiz, int valor);
void arvore_em_ordem(const No *raiz);
void arvore_destruir(No *raiz);
```

---

## Operações detalhadas

### `arvore_inserir`

Insere `valor` na BST mantendo a propriedade de ordenação.

- Se `raiz == NULL`, cria e retorna um novo nó com `valor`.
- Duplicatas são ignoradas.
- **Complexidade**: O(log n) médio, O(n) pior caso.

### `arvore_buscar`

Busca recursiva por `valor`.

- **Retorna** `1` se encontrado, `0` caso contrário.
- **Complexidade**: O(log n) médio, O(n) pior caso.

### `arvore_em_ordem`

Percurso em-ordem (esquerda → raiz → direita), imprimindo valores crescentes.

- **Complexidade**: O(n).

### `arvore_destruir`

Libera recursivamente todos os nós.

- **Complexidade**: O(n).

---

## Complexidade resumida (BST)

| Operação | Caso médio | Pior caso |
|----------|-----------|-----------|
| Inserir | O(log n) | O(n) |
| Buscar | O(log n) | O(n) |
| Percurso | O(n) | O(n) |
| Destruir | O(n) | O(n) |

O pior caso ocorre quando a árvore fica degenerada (parecida com lista encadeada).

---

## Árvores AVL

AVL é uma BST **auto-balanceada**.

- Mantém para cada nó: `|altura(esquerda) - altura(direita)| <= 1`.
- Após inserção/remoção, aplica rotações para reequilibrar:
  - rotação simples à direita (LL)
  - rotação simples à esquerda (RR)
  - rotação dupla esquerda-direita (LR)
  - rotação dupla direita-esquerda (RL)

### Complexidade (AVL)

| Operação | Complexidade |
|----------|-------------|
| Buscar | O(log n) |
| Inserir | O(log n) |
| Remover | O(log n) |

AVL costuma ter busca ligeiramente melhor que Rubro-Negra, com custo maior de rebalanceamento.

---

## Árvores Rubro-Negra

Rubro-Negra também é BST auto-balanceada, com regras de coloração:

1. Todo nó é vermelho ou preto.
2. A raiz é preta.
3. Folhas nulas são pretas.
4. Nó vermelho não pode ter filho vermelho.
5. Todo caminho da raiz até folhas nulas tem o mesmo número de nós pretos.

### Complexidade (Rubro-Negra)

| Operação | Complexidade |
|----------|-------------|
| Buscar | O(log n) |
| Inserir | O(log n) |
| Remover | O(log n) |

Rubro-Negra tende a fazer menos rotações que AVL em atualizações frequentes.

---

## Métodos de ordenação relacionados a árvores

### Tree Sort (via BST)

1. Inserir todos os elementos na BST.
2. Percorrer em-ordem.

- **Médio**: O(n log n)
- **Pior**: O(n²) sem balanceamento
- Com AVL/Rubro-Negra: O(n log n) garantido

### Heapsort (árvore implícita em array)

Embora use heap em vetor (e não BST), é ordenação baseada em estrutura de árvore.

- **Tempo**: O(n log n)
- **Espaço extra**: O(1)

---

## Métodos de busca em árvores

- **Busca em profundidade (DFS)**:
  - Pré-ordem
  - Em-ordem
  - Pós-ordem
- **Busca em largura (BFS)**:
  - Percorre nível a nível (usa fila)

Em BST, busca por chave usa a propriedade de ordenação (não precisa percorrer tudo).

---

## Exemplo de uso

```c
#include "arvore.h"
#include <stdio.h>

int main(void) {
    No *raiz = NULL;

    raiz = arvore_inserir(raiz, 40);
    raiz = arvore_inserir(raiz, 20);
    raiz = arvore_inserir(raiz, 60);
    raiz = arvore_inserir(raiz, 10);
    raiz = arvore_inserir(raiz, 30);

    printf("Em ordem: ");
    arvore_em_ordem(raiz);
    printf("\n");

    arvore_destruir(raiz);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Árvore
make
make run
make test
make clean
```

---

Voltar para o [índice da documentação](./README.md).
