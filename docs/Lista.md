# Lista — Lista Sequencial Dinâmica

## Visão geral

Implementação de uma **lista sequencial dinâmica** em C. Os elementos são armazenados
em um array contíguo de inteiros que cresce automaticamente (dobra de capacidade)
quando necessário, garantindo amortização de custo nas inserções no fim.

---

## Estrutura de dados

```c
/* include/lista.h */
typedef struct {
    int    *dados;       /* ponteiro para o array de elementos */
    size_t  tamanho;     /* número de elementos presentes */
    size_t  capacidade;  /* capacidade alocada no momento */
} Lista;
```

### Campos

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `dados` | `int *` | Array alocado dinamicamente no heap |
| `tamanho` | `size_t` | Quantidade de elementos válidos |
| `capacidade` | `size_t` | Espaço total alocado (em elementos) |

---

## Interface pública

```c
int  lista_criar(Lista *lista, size_t capacidade_inicial);
void lista_destruir(Lista *lista);
int  lista_vazia(const Lista *lista);
int  lista_inserir_fim(Lista *lista, int valor);
int  lista_inserir_posicao(Lista *lista, size_t posicao, int valor);
int  lista_remover_posicao(Lista *lista, size_t posicao, int *valor_removido);
int  lista_buscar(const Lista *lista, int valor, size_t *posicao_encontrada);
int  lista_buscar_metodo(const Lista *lista, int valor, size_t *posicao_encontrada, ListaMetodoBusca metodo);
int  lista_ordenar(Lista *lista, ListaMetodoOrdenacao metodo);
const char *lista_complexidade_busca(ListaMetodoBusca metodo);
const char *lista_complexidade_ordenacao(ListaMetodoOrdenacao metodo);
void lista_imprimir(const Lista *lista);
```

---

## Operações detalhadas

### `lista_criar`

```c
int lista_criar(Lista *lista, size_t capacidade_inicial);
```

Inicializa a lista alocando `capacidade_inicial` posições.

- **Retorna** `1` em caso de sucesso, `0` se `lista == NULL`, `capacidade_inicial == 0`
  ou falha de alocação.
- Após a chamada, `lista->tamanho == 0` e `lista->capacidade == capacidade_inicial`.

---

### `lista_destruir`

```c
void lista_destruir(Lista *lista);
```

Libera o array interno e zera todos os campos. Seguro para chamar com `lista == NULL`.

---

### `lista_vazia`

```c
int lista_vazia(const Lista *lista);
```

- **Retorna** `1` se `lista == NULL` ou `tamanho == 0`, `0` caso contrário.

---

### `lista_inserir_fim`

```c
int lista_inserir_fim(Lista *lista, int valor);
```

Insere `valor` após o último elemento.

- Se `tamanho == capacidade`, a capacidade é **dobrada** antes da inserção.
- **Complexidade**: O(1) amortizado.
- **Retorna** `1` em caso de sucesso, `0` em caso de falha.

---

### `lista_inserir_posicao`

```c
int lista_inserir_posicao(Lista *lista, size_t posicao, int valor);
```

Insere `valor` na posição `posicao` (0-indexado), deslocando os elementos seguintes.

- `posicao` pode ser de `0` até `tamanho` (inserção ao fim inclusive).
- **Complexidade**: O(n) para deslocamento.
- **Retorna** `1` em caso de sucesso, `0` se posição inválida ou falha de alocação.

---

### `lista_remover_posicao`

```c
int lista_remover_posicao(Lista *lista, size_t posicao, int *valor_removido);
```

Remove o elemento na posição `posicao`, deslocando os seguintes para a esquerda.

- Se `valor_removido != NULL`, o valor removido é gravado no endereço apontado.
- **Complexidade**: O(n) para deslocamento.
- **Retorna** `1` em caso de sucesso, `0` se lista vazia ou posição inválida.

---

### `lista_buscar`

```c
int lista_buscar(const Lista *lista, int valor, size_t *posicao_encontrada);
```

Busca linear por `valor`.

- Se encontrado e `posicao_encontrada != NULL`, grava o índice no endereço apontado.
- **Complexidade**: O(n).
- **Retorna** `1` se encontrado, `0` caso contrário.

---

### `lista_buscar_metodo`

```c
int lista_buscar_metodo(const Lista *lista, int valor, size_t *posicao_encontrada, ListaMetodoBusca metodo);
```

Permite escolher o método de busca:

- `LISTA_BUSCA_LINEAR`: busca sequencial tradicional.
- `LISTA_BUSCA_BINARIA`: busca binária (requer lista ordenada em ordem crescente).

---

### `lista_ordenar`

```c
int lista_ordenar(Lista *lista, ListaMetodoOrdenacao metodo);
```

Ordena os elementos em ordem crescente com o método escolhido:

- `LISTA_ORDENACAO_BUBBLE`
- `LISTA_ORDENACAO_INSERTION`
- `LISTA_ORDENACAO_SELECTION`

Retorna `1` em sucesso e `0` para método inválido ou lista nula.

---

### `lista_complexidade_busca` e `lista_complexidade_ordenacao`

```c
const char *lista_complexidade_busca(ListaMetodoBusca metodo);
const char *lista_complexidade_ordenacao(ListaMetodoOrdenacao metodo);
```

Retornam uma descrição textual da complexidade de tempo/espaço do método informado.

---

### `lista_imprimir`

```c
void lista_imprimir(const Lista *lista);
```

Imprime os elementos no formato `[ a, b, c ]` seguido de nova linha.

---

## Complexidade resumida

| Operação | Complexidade |
|----------|-------------|
| Inserir no fim | O(1) amortizado |
| Inserir em posição | O(n) |
| Remover por posição | O(n) |
| Busca linear | O(n) |
| Busca binária (lista ordenada) | O(log n) |
| Ordenação Bubble/Insertion/Selection | O(n²) médio/pior |
| Acesso por índice | O(1) |
| Criar / Destruir | O(1) |

---

## Exemplo de uso

```c
#include "lista.h"
#include <stdio.h>

int main(void) {
    Lista lista;
    size_t posicao = 0;
    int removido = 0;

    lista_criar(&lista, 4U);

    lista_inserir_fim(&lista, 10);
    lista_inserir_fim(&lista, 20);
    lista_inserir_fim(&lista, 30);
    lista_inserir_posicao(&lista, 1U, 15);  /* [10, 15, 20, 30] */

    lista_imprimir(&lista);                 /* [ 10, 15, 20, 30 ] */

    lista_ordenar(&lista, LISTA_ORDENACAO_INSERTION);
    lista_buscar_metodo(&lista, 20, &posicao, LISTA_BUSCA_BINARIA);
    printf("20 encontrado na posição %zu\n", posicao);
    printf("%s\n", lista_complexidade_ordenacao(LISTA_ORDENACAO_INSERTION));
    printf("%s\n", lista_complexidade_busca(LISTA_BUSCA_BINARIA));

    lista_remover_posicao(&lista, 2U, &removido);
    printf("Removido: %d\n", removido);    /* Removido: 20 */

    lista_imprimir(&lista);                /* [ 10, 15, 30 ] */

    lista_destruir(&lista);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Lista
make        # compila o exemplo em build/app
make run    # executa o exemplo
make test   # executa os testes automatizados
make clean  # remove artefatos
```

---

Voltar para o [índice da documentação](./README.md).
