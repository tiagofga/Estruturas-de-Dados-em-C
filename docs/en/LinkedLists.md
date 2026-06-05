# Linked Lists

## Singly linked list

A singly linked list stores nodes containing a value and a pointer to the next node.

### Main operations

```c
void lista_encadeada_criar(ListaEncadeada *lista);
void lista_encadeada_destruir(ListaEncadeada *lista);
int lista_encadeada_inserir_inicio(ListaEncadeada *lista, int valor);
int lista_encadeada_inserir_fim(ListaEncadeada *lista, int valor);
int lista_encadeada_remover(ListaEncadeada *lista, int valor);
int lista_encadeada_buscar(const ListaEncadeada *lista, int valor);
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

A doubly linked list stores nodes with pointers to both the previous and next nodes. This enables traversal in both directions.

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

A singly linked list is smaller and simpler. A doubly linked list uses more memory per node but makes reverse traversal and operations near the tail easier.
