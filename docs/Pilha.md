# Pilha — Pilha Sequencial (LIFO)

## Visão geral

Implementação de uma **pilha** em C com capacidade fixa usando array dinâmico.
Segue a política **LIFO** (Last In, First Out): o último elemento inserido é o
primeiro a ser removido.

---

## Estrutura de dados

```c
/* include/pilha.h */
typedef struct {
    int    *dados;      /* array de elementos */
    size_t  capacidade; /* capacidade máxima (fixa) */
    size_t  tamanho;    /* quantidade de elementos presentes */
} Pilha;
```

### Campos

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `dados` | `int *` | Array alocado dinamicamente no heap |
| `capacidade` | `size_t` | Número máximo de elementos |
| `tamanho` | `size_t` | Número de elementos atualmente na pilha |

---

## Interface pública

```c
int  pilha_criar(Pilha *pilha, size_t capacidade);
void pilha_destruir(Pilha *pilha);
int  pilha_vazia(const Pilha *pilha);
int  pilha_cheia(const Pilha *pilha);
int  pilha_empilhar(Pilha *pilha, int valor);
int  pilha_desempilhar(Pilha *pilha, int *valor_removido);
int  pilha_topo(const Pilha *pilha, int *valor);
void pilha_imprimir(const Pilha *pilha);
```

---

## Operações detalhadas

### `pilha_criar`

Inicializa a pilha e aloca memória para `capacidade` elementos.
Retorna `1` em sucesso e `0` em caso de erro.

### `pilha_destruir`

Libera a memória da pilha e zera os campos.

### `pilha_vazia`

Retorna `1` se a pilha estiver vazia, `0` caso contrário.

### `pilha_cheia`

Retorna `1` se `tamanho == capacidade`, `0` caso contrário.

### `pilha_empilhar`

Insere elemento no topo da pilha.
- **Complexidade**: O(1)

### `pilha_desempilhar`

Remove e opcionalmente retorna o elemento do topo.
- **Complexidade**: O(1)

### `pilha_topo`

Consulta o topo sem remover.
- **Complexidade**: O(1)

---

## Complexidade resumida

| Operação | Complexidade |
|----------|-------------|
| Empilhar | O(1) |
| Desempilhar | O(1) |
| Consultar topo | O(1) |
| Criar / Destruir | O(1) |

---

## Exemplo de uso

```c
#include "pilha.h"
#include <stdio.h>

int main(void) {
    Pilha pilha;
    int valor = 0;

    pilha_criar(&pilha, 5U);
    pilha_empilhar(&pilha, 10);
    pilha_empilhar(&pilha, 20);

    pilha_topo(&pilha, &valor);
    printf("Topo: %d\n", valor); /* 20 */

    pilha_desempilhar(&pilha, &valor);
    printf("Removido: %d\n", valor); /* 20 */

    pilha_destruir(&pilha);
    return 0;
}
```

---

## Compilar e executar

```bash
cd Pilha
make
make run
make test
make clean
```

---

Voltar para o [índice da documentação](./README.md).
