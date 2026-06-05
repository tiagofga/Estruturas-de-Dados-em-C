# Hash Table — Separate Chaining

## Overview

This module implements a **hash table** in C using **separate chaining** to handle collisions. Each bucket stores a linked list of `(key, value)` pairs.

The `TabelaHash` type is opaque in the public header: users manipulate only pointers to the structure and cannot access its internal fields directly.

## Main operations

```c
TabelaHash *tabela_hash_criar(size_t capacidade);
void tabela_hash_destruir(TabelaHash *tabela);
int tabela_hash_inserir(TabelaHash *tabela, int chave, int valor);
int tabela_hash_buscar(const TabelaHash *tabela, int chave, int *valor);
int tabela_hash_remover(TabelaHash *tabela, int chave);
int tabela_hash_contem(const TabelaHash *tabela, int chave);
size_t tabela_hash_tamanho(const TabelaHash *tabela);
double tabela_hash_fator_carga(const TabelaHash *tabela);
```

## Usage example

```c
TabelaHash *tabela = tabela_hash_criar(101);
if (tabela != NULL) {
    tabela_hash_inserir(tabela, 10, 100);
    tabela_hash_destruir(tabela);
}
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
