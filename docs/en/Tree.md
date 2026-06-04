# Tree — Binary Search Tree

[Português](../Arvore.md) | **English**

## Overview

Implementation of a **Binary Search Tree (BST)** in C. For each node:

- values smaller than the node are stored in the left subtree;
- values greater than the node are stored in the right subtree.

This property allows efficient search, insertion, and traversal when the tree is reasonably balanced.

---

## Main operations

- create nodes;
- insert values;
- search for values;
- traverse the tree in order;
- free the allocated memory;
- inspect theoretical concepts such as AVL and Red-Black trees.

---

## Complexity summary

| Operation | Average case | Worst case |
|-----------|--------------|------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Traversal | O(n) | O(n) |

The worst case occurs when the tree becomes highly unbalanced, similar to a linked list.

---

## Notes

This module focuses on the basic BST implementation. Balanced trees such as AVL and Red-Black trees are discussed conceptually and can be added as future implementations.

---

Back to the [documentation index](./README.md).
