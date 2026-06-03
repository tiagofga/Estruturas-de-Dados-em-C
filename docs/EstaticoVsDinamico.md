# Lista, Fila e Pilha — Estática vs Dinâmica (com ponteiros)

## Implementações deste repositório

As duas versões (estática e dinâmica) para **Lista**, **Fila** e **Pilha** já estão implementadas no código.

- **Dinâmica**: `src/lista.c`, `src/fila.c`, `src/pilha.c`
- **Estática**: `src/lista_estatica.c`, `src/fila_estatica.c`, `src/pilha_estatica.c`

Todas as estruturas usam **ponteiros** para acessar e alterar dados via funções:

- `Lista *lista`, `Fila *fila`, `Pilha *pilha`
- arrays alocados no heap com `malloc/calloc` e liberados com `free`

---

## Diferença: estrutura estática x dinâmica

## 1) Estática

A memória é definida em tempo de compilação (ou fixada no escopo local) e não cresce.

Exemplo conceitual:

- `int dados[100];`

### Vantagens

- Simples de implementar.
- Sem custo de alocação dinâmica em runtime.

### Desvantagens

- Capacidade rígida.
- Pode desperdiçar memória.
- Limite máximo fixo.

---

## 2) Dinâmica

A memória é alocada em runtime no heap usando ponteiros.

Exemplo conceitual:

- `int *dados = malloc(capacidade * sizeof(int));`

### Vantagens

- Flexível para diferentes tamanhos.
- Melhor aproveitamento de memória para entradas variáveis.

### Desvantagens

- Exige controle manual (`malloc/calloc/free`).
- Risco de vazamento se não liberar memória corretamente.

---

## Comparativo rápido

| Estrutura | Versão estática | Versão dinâmica |
|----------|------------------|-----------------|
| Lista | Array fixo (`int dados[N]`) | Array com ponteiro e realocação (`int *dados`, `realloc`) |
| Fila | Buffer circular fixo (`int dados[N]`) | Buffer circular no heap (`int *dados`) |
| Pilha | Array fixo com topo | Array no heap com topo/tamanho |

---

## Sobre uso de ponteiros

Neste projeto, o padrão é:

1. Criar estrutura (`*_criar`) com alocação dinâmica.
2. Passar ponteiro da estrutura para operações (`*_inserir`, `*_remover`, etc.).
3. Destruir estrutura (`*_destruir`) para liberar memória.

Isso garante manipulação eficiente sem copiar estruturas inteiras entre chamadas.

Para Lista/Fila/Pilha, o Makefile agora oferece duas opções de execução:

- `make run` (implementação dinâmica)
- `make run_static` (implementação estática)

---

Voltar para o [índice da documentação](./README.md).
