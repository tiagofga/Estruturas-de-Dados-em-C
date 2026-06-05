# AVL — Self-Balancing Binary Search Tree

## Overview

An **AVL tree** is a self-balancing binary search tree. For each node, the difference between the height of the left subtree and the height of the right subtree must remain between `-1` and `1`.

This prevents the tree from degrading into a linked list and keeps search, insertion, and removal in O(log n).

## Main operations

```c
AVLNo *avl_inserir(AVLNo *raiz, int valor);
AVLNo *avl_remover(AVLNo *raiz, int valor);
int avl_buscar(const AVLNo *raiz, int valor);
int avl_altura(const AVLNo *raiz);
int avl_fator_balanceamento(const AVLNo *raiz);
int avl_esta_balanceada(const AVLNo *raiz);
void avl_em_ordem(const AVLNo *raiz, int *vetor, size_t capacidade, size_t *tamanho);
void avl_destruir(AVLNo *raiz);
```

## Rotations

The implementation covers the four classic AVL cases:

- single right rotation;
- single left rotation;
- left-right double rotation;
- right-left double rotation.

Rotations are used after insertions and removals whenever a subtree becomes unbalanced.

## Removal

The removal operation handles the standard BST cases:

1. leaf node;
2. node with one child;
3. node with two children, using the in-order successor.

After removing the node, the path back to the root is rebalanced.

## Complexity

| Operation | Complexity |
|----------|------------|
| Search | O(log n) |
| Insert | O(log n) |
| Remove | O(log n) |
| Traversal | O(n) |
| Space | O(n) |
