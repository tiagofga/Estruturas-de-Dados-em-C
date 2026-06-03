# TAD — Tipo Abstrato de Dados

## O que é um TAD?

Um **Tipo Abstrato de Dados (TAD)** é um modelo matemático/conceitual que descreve
**o que** uma estrutura de dados faz — suas operações e regras de uso — sem revelar
**como** ela é implementada internamente.

Em outras palavras, o TAD é um **contrato**: quem usa a estrutura só precisa conhecer
as operações disponíveis e o que elas fazem; os detalhes de implementação ficam ocultos.

---

## Dados e Ações

Todo TAD é formado por dois elementos fundamentais:

### Dados
São os valores armazenados e gerenciados pela estrutura internamente.

- Exemplo na Lista: o array `dados`, o `tamanho` atual e a `capacidade` alocada.
- Exemplo na Fila: o array circular, os índices `inicio` e `fim` e o `tamanho`.
- Exemplo na Árvore: cada nó com `valor`, ponteiro para `esquerda` e para `direita`.

### Ações (operações)
São as funções que compõem a interface pública — o único ponto de contato entre
quem usa o TAD e a estrutura interna.

- Exemplos: `inserir`, `remover`, `buscar`, `esta_vazia`, `destruir`.

O usuário do TAD **só enxerga as ações**; os dados internos ficam encapsulados.

---

## Separação entre interface e implementação em C

Em C, a convenção usada neste repositório é:

| Arquivo | Papel |
|---------|-------|
| `include/<nome>.h` | Interface pública (TAD) — declara tipos e funções |
| `src/<nome>.c` | Implementação interna — define como as funções funcionam |

Quem usa o módulo inclui apenas o `.h`. A mudança na implementação `.c`
**não requer recompilação** de quem só depende do cabeçalho.

---

## Exemplo básico em C — `Ponto 2D`

### `ponto.h` — interface pública (TAD)

```c
typedef struct {
    float x;
    float y;
} Ponto;

/* cria um ponto no heap e retorna ponteiro */
Ponto *ponto_criar(float x, float y);

/* libera a memória */
void ponto_destruir(Ponto *p);

/* calcula a distância até a origem */
float ponto_distancia_origem(const Ponto *p);
```

### `main.c` — uso do TAD

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

Ponto *ponto_criar(float x, float y) {
    Ponto *p = malloc(sizeof(Ponto));
    p->x = x;   /* acesso via ponteiro: usa -> */
    p->y = y;
    return p;
}

void ponto_destruir(Ponto *p) { free(p); }

float ponto_distancia_origem(const Ponto *p) {
    return sqrtf(p->x * p->x + p->y * p->y);
}

int main(void) {
    /* 1. Acesso por PONTEIRO — operador -> */
    Ponto *dinamico = ponto_criar(3.0f, 4.0f);
    printf("Ponteiro  -> x=%.1f, y=%.1f, dist=%.1f\n",
           dinamico->x, dinamico->y,
           ponto_distancia_origem(dinamico));
    ponto_destruir(dinamico);

    /* 2. Acesso por VALOR (struct na pilha) — operador . */
    Ponto estatico = {6.0f, 8.0f};
    printf("Por valor  . x=%.1f, y=%.1f, dist=%.1f\n",
           estatico.x, estatico.y,
           ponto_distancia_origem(&estatico));

    return 0;
}
```

### Diferença entre `.` e `->`

| Situação | Operador | Exemplo |
|----------|----------|---------|
| Variável do tipo struct (valor na pilha) | `.` | `estatico.x` |
| Ponteiro para struct (heap) | `->` | `dinamico->x` |

`p->x` é equivalente a `(*p).x` — o `->` desreferencia o ponteiro e acessa o campo em uma etapa.

---

## Por que usar TAD?

| Motivo | Benefício prático |
|--------|-------------------|
| **Encapsulamento** | A implementação pode mudar sem afetar quem usa o TAD |
| **Manutenção** | Bugs ficam isolados dentro do módulo |
| **Reutilização** | O mesmo TAD pode ser usado em projetos diferentes |
| **Legibilidade** | O código cliente fica mais expressivo e de alto nível |
| **Testabilidade** | É possível testar cada operação de forma independente |

---

Voltar para o [índice da documentação](./README.md).
