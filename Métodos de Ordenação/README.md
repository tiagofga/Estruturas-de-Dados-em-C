# Métodos de Ordenação para Vetores

Implementações dos principais algoritmos de ordenação para vetores (`int[]`) em C,
com análise de complexidade de tempo e espaço para cada método.

---

## Algoritmos implementados

| # | Algoritmo | Melhor | Médio | Pior | Espaço extra | Estável |
|---|-----------|--------|-------|------|--------------|---------|
| 1 | Bubble Sort | Ω(n) | O(n²) | O(n²) | O(1) | Sim |
| 2 | Insertion Sort | Ω(n) | O(n²) | O(n²) | O(1) | Sim |
| 3 | Selection Sort | Θ(n²) | Θ(n²) | Θ(n²) | O(1) | Não |
| 4 | Merge Sort | Θ(n log n) | Θ(n log n) | Θ(n log n) | O(n) | Sim |
| 5 | Quick Sort | Ω(n log n) | O(n log n) | O(n²) | O(log n) | Não |
| 6 | Heap Sort | Θ(n log n) | Θ(n log n) | Θ(n log n) | O(1) | Não |

---

## Explicação dos algoritmos

### 1. Bubble Sort

Percorre o vetor repetidamente comparando pares adjacentes e trocando quando estão fora de ordem.
A cada passagem o maior elemento "borbulha" para o final.
A implementação inclui a otimização de parada antecipada: se nenhuma troca ocorrer, o vetor já está ordenado.

**Custo no vetor:**
- Acessa elementos consecutivos → boa localidade de cache.
- Alto número de trocas no pior caso.

---

### 2. Insertion Sort

Mantém um prefixo ordenado e, a cada passo, insere o próximo elemento na posição correta deslocando os maiores.

**Custo no vetor:**
- Deslocamento de elementos é O(n) por iteração no pior caso.
- Excelente para vetores pequenos ou quase ordenados.
- Usado internamente por Timsort (Python/Java) para subvetores pequenos.

---

### 3. Selection Sort

Seleciona o menor elemento da parte não ordenada e troca com a posição atual.

**Custo no vetor:**
- Sempre O(n²) comparações, independentemente dos dados.
- Apenas O(n) trocas — vantagem quando trocas são custosas.
- Não é estável na forma clássica (a troca pode mudar a ordem relativa de iguais).

---

### 4. Merge Sort

Divide o vetor ao meio recursivamente até subarranjos de tamanho 1, depois intercala (merge) as partes já ordenadas.

**Custo no vetor:**
- Requer O(n) de memória auxiliar para a etapa de intercalação.
- Garantia de O(n log n) em todos os casos.
- Estável — preserva a ordem relativa de elementos iguais.
- Preferido quando estabilidade é obrigatória ou os dados estão em memória externa.

---

### 5. Quick Sort

Escolhe um pivô (mediana de três neste módulo), particiona o vetor em menores/maiores e ordena recursivamente cada partição.

**Custo no vetor:**
- Muito cache-friendly: opera in-place.
- Melhor desempenho médio prático entre os O(n log n).
- Pior caso O(n²) ocorre com pivôs ruins (e.g., vetor já ordenado com pivô no extremo).
  A escolha da mediana de três mitiga esse risco.
- Espaço extra O(log n) médio pela pilha de recursão.

---

### 6. Heap Sort

Constrói um heap máximo no próprio vetor e extrai repetidamente o maior elemento para o final.

**Custo no vetor:**
- In-place: O(1) espaço extra.
- Garantia de O(n log n) sem risco de pior caso O(n²).
- Não é estável.
- Menor localidade de cache que Merge/Quick na prática — acessos ao heap pulam posições.

---

## Estrutura do módulo

```
Métodos de Ordenação/
├── include/
│   └── ordenacao.h      # API pública e enum OrdenacaoMetodo
├── src/
│   ├── ordenacao.c      # implementações dos seis algoritmos
│   └── main.c           # exemplo executável
├── tests/
│   └── test_ordenacao.c # testes automatizados
└── Makefile
```

---

## Como usar

```bash
cd "Métodos de Ordenação"
make            # compila o exemplo
make run        # executa o exemplo
make test       # executa os testes
make debug      # compila com -g -DDEBUG
make release    # compila com -O3
make clean      # remove artefatos
```

---

## API pública (`ordenacao.h`)

```c
/* Seleciona o algoritmo de ordenação */
typedef enum {
    ORDENACAO_BUBBLE    = 0,
    ORDENACAO_INSERTION = 1,
    ORDENACAO_SELECTION = 2,
    ORDENACAO_MERGE     = 3,
    ORDENACAO_QUICK     = 4,
    ORDENACAO_HEAP      = 5
} OrdenacaoMetodo;

/* Ordena `vetor` de `n` inteiros usando o método escolhido */
void ordenacao_ordenar(int *vetor, size_t n, OrdenacaoMetodo metodo);

/* Retorna string com notação de complexidade do método */
const char *ordenacao_complexidade(OrdenacaoMetodo metodo);

/* Retorna o nome legível do método */
const char *ordenacao_nome(OrdenacaoMetodo metodo);

/* Imprime o vetor no formato [ a, b, c ] */
void ordenacao_imprimir(const int *vetor, size_t n);
```

---

## Quando usar cada algoritmo

| Situação | Recomendado |
|----------|-------------|
| Vetor pequeno (≤ ~20 elementos) | Insertion Sort |
| Vetor quase ordenado | Insertion Sort ou Bubble Sort |
| Necessidade de estabilidade garantida | Merge Sort |
| Melhor desempenho médio, sem restrição de memória | Quick Sort |
| Garantia O(n log n) com O(1) espaço extra | Heap Sort |
| Minimizar número de trocas | Selection Sort |

---

Voltar para o [índice da documentação](../docs/README.md).
