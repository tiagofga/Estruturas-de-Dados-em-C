# Linked Lists

## Singly linked list

A singly linked list stores values in connected nodes. The `ListaEncadeada` module now uses an opaque public type. Client code creates a list with `lista_encadeada_criar()` and releases it with `lista_encadeada_destruir()`.

### Main operations

```c
ListaEncadeada *lista_encadeada_criar(void);
void lista_encadeada_destruir(ListaEncadeada *lista);
int lista_encadeada_inserir_inicio(ListaEncadeada *lista, int valor);
int lista_encadeada_inserir_fim(ListaEncadeada *lista, int valor);
int lista_encadeada_remover(ListaEncadeada *lista, int valor);
int lista_encadeada_buscar(const ListaEncadeada *lista, int valor);
size_t lista_encadeada_tamanho(const ListaEncadeada *lista);
```

### Complexity

| Operation | Complexity |
|----------|------------|
| Insert at front | O(1) |
| Insert at back | O(n) |
| Search | O(n) |
| Remove by value | O(n) |
| Space | O(n) |

## Doubly linked list

The double linked list module keeps the original educational interface.

### Main operations

```c
void lista_dupla_criar(ListaDupla *lista);
void lista_dupla_destruir(ListaDupla *lista);
int lista_dupla_inserir_inicio(ListaDupla *lista, int valor);
int lista_dupla_inserir_fim(ListaDupla *lista, int valor);
int lista_dupla_remover(ListaDupla *lista, int valor);
int lista_dupla_buscar(const ListaDupla *lista, int valor);
```

### Complexity

| Operation | Complexity |
|----------|------------|
| Insert at front | O(1) |
| Insert at back | O(1) |
| Search | O(n) |
| Remove by value | O(n) |
| Space | O(n) |

## Comparison

The singly linked list is smaller and simpler. The double linked list uses more memory per node, but supports traversal in both directions.
