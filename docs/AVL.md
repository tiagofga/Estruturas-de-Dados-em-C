# AVL — Árvore Binária de Busca Balanceada

## Visão geral

A **AVL** é uma árvore binária de busca autobalanceada. Para cada nó, a diferença entre a altura da subárvore esquerda e da subárvore direita deve permanecer entre `-1` e `1`.

Esse controle evita a degradação da árvore para uma lista encadeada, mantendo busca e inserção em O(log n).

## Operações principais

```c
AVLNo *avl_inserir(AVLNo *raiz, int valor);
int avl_buscar(const AVLNo *raiz, int valor);
int avl_altura(const AVLNo *raiz);
int avl_fator_balanceamento(const AVLNo *raiz);
int avl_esta_balanceada(const AVLNo *raiz);
void avl_em_ordem(const AVLNo *raiz, int *vetor, size_t capacidade, size_t *tamanho);
void avl_destruir(AVLNo *raiz);
```

## Rotações

A implementação cobre os quatro casos clássicos:

- rotação simples à direita;
- rotação simples à esquerda;
- rotação dupla esquerda-direita;
- rotação dupla direita-esquerda.

## Complexidade

| Operação | Complexidade |
|----------|-------------|
| Buscar | O(log n) |
| Inserir | O(log n) |
| Percurso | O(n) |
| Espaço | O(n) |

## Observação

A remoção balanceada ainda pode ser adicionada como extensão futura.
