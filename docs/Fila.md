# Fila — Fila Circular (FIFO)

## Visão geral

Implementação de uma **fila circular** (ring buffer) em C com capacidade fixa.
Segue a política **FIFO** (First In, First Out): o primeiro elemento inserido é o
primeiro a ser removido. O uso de índices circulares evita deslocamento de elementos,
mantendo enfileirar e desenfileirar em O(1).

---

## Estrutura de dados

```c
/* include/fila.h */
typedef struct {
    int    *dados;      /* array circular de elementos */
    size_t  capacidade; /* capacidade máxima (fixa) */
    size_t  tamanho;    /* número de elementos presentes */
    size_t  inicio;     /* índice do próximo elemento a sair */
    size_t  fim;        /* índice da próxima posição livre */
} Fila;
```

### Campos

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `dados` | `int *` | Array alocado dinamicamente no heap |
| `capacidade` | `size_t` | Número máximo de elementos (imutável após criação) |
| `tamanho` | `size_t` | Quantidade de elementos presentes |
| `inicio` | `size_t` | Índice do elemento na frente da fila |
| `fim` | `size_t` | Índice onde o próximo elemento será inserido |

---

## Interface pública

```c
int  fila_criar(Fila *fila, size_t capacidade);
void fila_destruir(Fila *fila);
int  fila_vazia(const Fila *fila);
int  fila_cheia(const Fila *fila);
int  fila_enfileirar(Fila *fila, int valor);
int  fila_desenfileirar(Fila *fila, int *valor_removido);
int  fila_frente(const Fila *fila, int *valor);
void fila_imprimir(const Fila *fila);
```

---

## Operações detalhadas

### `fila_criar`

```c
int fila_criar(Fila *fila, size_t capacidade);
```

Inicializa a fila alocando `capacidade` posições.

- **Retorna** `1` em caso de sucesso, `0` se `fila == NULL`, `capacidade == 0`
  ou falha de alocação.
- Após a chamada, `inicio == 0`, `fim == 0`, `tamanho == 0`.

---

### `fila_destruir`

```c
void fila_destruir(Fila *fila);
```

Libera o array e zera todos os campos. Seguro com `fila == NULL`.

---

### `fila_vazia`

```c
int fila_vazia(const Fila *fila);
```

- **Retorna** `1` se `fila == NULL` ou `tamanho == 0`, `0` caso contrário.

---

### `fila_cheia`

```c
int fila_cheia(const Fila *fila);
```

- **Retorna** `1` se `tamanho == capacidade`, `0` caso contrário.

---

### `fila_enfileirar`

```c
int fila_enfileirar(Fila *fila, int valor);
```

Insere `valor` no fim da fila.

- Falha se a fila estiver cheia.
- Avança `fim` de forma circular: `fim = (fim + 1) % capacidade`.
- **Complexidade**: O(1).
- **Retorna** `1` em caso de sucesso, `0` se fila cheia ou `NULL`.

---

### `fila_desenfileirar`

```c
int fila_desenfileirar(Fila *fila, int *valor_removido);
```

Remove e retorna o elemento da frente.

- Se `valor_removido != NULL`, grava o valor no endereço apontado.
- Avança `inicio` de forma circular: `inicio = (inicio + 1) % capacidade`.
- **Complexidade**: O(1).
- **Retorna** `1` em caso de sucesso, `0` se fila vazia ou `NULL`.

---

### `fila_frente`

```c
int fila_frente(const Fila *fila, int *valor);
```

Consulta o elemento da frente sem removê-lo.

- Grava o valor em `*valor` (que deve ser não-NULL).
- **Complexidade**: O(1).
- **Retorna** `1` em caso de sucesso, `0` se fila vazia, `NULL` ou `valor == NULL`.

---

### `fila_imprimir`

```c
void fila_imprimir(const Fila *fila);
```

Imprime os elementos na ordem FIFO no formato `[ a, b, c ]` seguido de nova linha.
Usa os índices circulares corretamente para percorrer apenas os elementos válidos.

---

## Complexidade resumida

| Operação | Complexidade |
|----------|-------------|
| Enfileirar | O(1) |
| Desenfileirar | O(1) |
| Consultar frente | O(1) |
| Criar / Destruir | O(1) |

---

## Funcionamento circular

```
capacidade = 5, tamanho = 3

índice:   0    1    2    3    4
dados:  [ 10 | 20 | 30 |  - |  - ]
                            ^fim (próxima escrita)
          ^inicio (próxima leitura)

Após desenfileirar:
  inicio = 1  →  [ - | 20 | 30 | - | - ]

Após enfileirar(40):
  fim    = 3  →  [ - | 20 | 30 | 40 | - ]
```

Quando `inicio` ou `fim` chegam ao fim do array, voltam para `0` via `% capacidade`.

---

## Exemplo de uso

```c
#include "fila.h"
#include <stdio.h>

int main(void) {
    Fila fila;
    int valor = 0;

    fila_criar(&fila, 5U);

    fila_enfileirar(&fila, 5);
    fila_enfileirar(&fila, 10);
    fila_enfileirar(&fila, 15);

    fila_imprimir(&fila);          /* [ 5, 10, 15 ] */

    fila_frente(&fila, &valor);
    printf("Frente: %d\n", valor); /* Frente: 5 */

    fila_desenfileirar(&fila, &valor);
    printf("Removido: %d\n", valor); /* Removido: 5 */

    fila_imprimir(&fila);          /* [ 10, 15 ] */

    fila_destruir(&fila);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Fila
make        # compila o exemplo em build/app
make run    # executa o exemplo
make test   # executa os testes automatizados
make clean  # remove artefatos
```

---

Voltar para o [índice da documentação](./README.md).
