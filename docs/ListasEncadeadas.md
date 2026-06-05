# Listas Encadeadas

## Lista simplesmente encadeada

A lista simplesmente encadeada armazena nós com um valor e um ponteiro para o próximo nó. No módulo `ListaEncadeada`, o tipo `ListaEncadeada` é opaco no header público: a alocação, os nós e os campos internos ficam privados na implementação.

### Operações principais

```c
ListaEncadeada *lista_encadeada_criar(void);
void lista_encadeada_destruir(ListaEncadeada *lista);
int lista_encadeada_inserir_inicio(ListaEncadeada *lista, int valor);
int lista_encadeada_inserir_fim(ListaEncadeada *lista, int valor);
int lista_encadeada_remover(ListaEncadeada *lista, int valor);
int lista_encadeada_buscar(const ListaEncadeada *lista, int valor);
size_t lista_encadeada_tamanho(const ListaEncadeada *lista);
```

### Complexidade

| Operação | Complexidade |
|----------|-------------|
| Inserir no início | O(1) |
| Inserir no fim | O(n) |
| Buscar | O(n) |
| Remover por valor | O(n) |
| Espaço | O(n) |

## Lista duplamente encadeada

A lista duplamente encadeada armazena nós com ponteiro para o nó anterior e para o próximo nó. Isso permite percorrer a lista nos dois sentidos.

### Complexidade

| Operação | Complexidade |
|----------|-------------|
| Inserir no início | O(1) |
| Inserir no fim | O(1) |
| Buscar | O(n) |
| Remover por valor | O(n) |
| Espaço | O(n) |

## Comparação

A lista simples é menor e mais direta. A lista dupla usa mais memória por nó, mas facilita operações próximas ao fim e percursos reversos.
