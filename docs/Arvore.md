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

```c
No *arvore_inserir(No *raiz, int valor);
```

Insere `valor` na BST mantendo a propriedade de ordenação.

- Se `raiz == NULL`, cria e retorna um novo nó com `valor`.
- Percorre iterativamente até encontrar a posição correta.
- **Duplicatas são ignoradas** — se `valor` já existe, a árvore não é modificada.
- **Retorna** o ponteiro para a raiz (que pode ter mudado se a árvore estava vazia),
  ou `NULL` em caso de falha de alocação.
- **Complexidade**: O(log n) médio, O(n) pior caso (árvore degenerada).

> **Importante:** sempre reatribua `raiz = arvore_inserir(raiz, valor)` para capturar
> a raiz quando a árvore estava vazia.

---

### `arvore_buscar`

```c
int arvore_buscar(const No *raiz, int valor);
```

Busca recursiva por `valor` na BST.

- Em cada nó, descende para a esquerda se `valor < raiz->valor` ou para a direita
  se `valor > raiz->valor`.
- **Retorna** `1` se encontrado, `0` caso contrário (incluindo `raiz == NULL`).
- **Complexidade**: O(log n) médio, O(n) pior caso.

---

### `arvore_em_ordem`

```c
void arvore_em_ordem(const No *raiz);
```

Percurso **em-ordem** (esquerda → raiz → direita), que imprime os valores em ordem
crescente, separados por espaço.

- **Complexidade**: O(n).

---

### `arvore_destruir`

```c
void arvore_destruir(No *raiz);
```

Libera recursivamente todos os nós da árvore (percurso pós-ordem).
Seguro para chamar com `raiz == NULL`.

- **Complexidade**: O(n).

---

## Complexidade resumida

| Operação | Caso médio | Pior caso |
|----------|-----------|-----------|
| Inserir | O(log n) | O(n) |
| Buscar | O(log n) | O(n) |
| Percurso em-ordem | O(n) | O(n) |
| Destruir | O(n) | O(n) |

> O pior caso O(n) ocorre em árvores degeneradas (inserções em ordem crescente ou
> decrescente), formando uma lista encadeada. Árvores auto-balanceadas (AVL, Red-Black)
> eliminam esse problema mas não fazem parte deste módulo.

---

## Propriedade BST

Para todo nó `N` na árvore:

```
todos os valores em N->esquerda  <  N->valor
todos os valores em N->direita   >  N->valor
```

Exemplo com inserções na ordem 40, 20, 60, 10, 30:

```
        40
       /  \
      20   60
     / \
    10  30
```

Percurso em-ordem: `10 20 30 40 60` (ordem crescente).

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
    arvore_em_ordem(raiz);   /* 10 20 30 40 60 */
    printf("\n");

    printf("Buscar 30: %s\n", arvore_buscar(raiz, 30) ? "encontrado" : "não encontrado");
    printf("Buscar 99: %s\n", arvore_buscar(raiz, 99) ? "encontrado" : "não encontrado");

    arvore_destruir(raiz);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Árvore
make        # compila o exemplo em build/app
make run    # executa o exemplo
make test   # executa os testes automatizados
make clean  # remove artefatos
```

---

Voltar para o [índice da documentação](./README.md).
