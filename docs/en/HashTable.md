# Hash Table — Separate Chaining

## Overview

This module implements a **hash table** in C using **separate chaining** to handle collisions. Each bucket stores a linked list of `(key, value)` pairs.

## Main operations

```c
int tabela_hash_criar(TabelaHash *tabela, size_t capacidade);
void tabela_hash_destruir(TabelaHash *tabela);
int tabela_hash_inserir(TabelaHash *tabela, int chave, int valor);
int tabela_hash_buscar(const TabelaHash *tabela, int chave, int *valor);
int tabela_hash_remover(TabelaHash *tabela, int chave);
int tabela_hash_contem(const TabelaHash *tabela, int chave);
```

## Behavior

- Inserting an existing key updates its value.
- Searching returns `1` when the key is found and writes the value to the output pointer.
- Removing returns `1` when the key is found and removed.
- The load factor is computed as `size / capacity`.

## Complexity

| Operation | Average case | Worst case |
|----------|--------------|------------|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Remove | O(1) | O(n) |
| Space | O(n + m) | O(n + m) |

`n` is the number of elements and `m` is the number of buckets.

## Notes

The worst case occurs when many keys collide into the same bucket. The load factor helps decide when a hash table should be resized.
