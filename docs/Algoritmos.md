# Complexidade, Métodos de Busca e Métodos de Ordenação

## Notação de complexidade (Big-O)

A notação Big-O descreve o crescimento do custo de tempo e/ou memória em função do tamanho da entrada `n`.

| Ordem | Nome comum | Exemplo típico |
|------|------------|----------------|
| O(1) | Constante | Acesso por índice em array |
| O(log n) | Logarítmica | Busca binária |
| O(n) | Linear | Busca sequencial |
| O(n log n) | Linearítmica | Merge Sort, Heap Sort |
| O(n²) | Quadrática | Bubble/Selection/Insertion (pior caso) |
| O(2ⁿ) | Exponencial | Backtracking completo |

### Boas práticas ao analisar complexidade

- Avaliar **melhor caso, caso médio e pior caso**.
- Separar **tempo** e **espaço extra**.
- Considerar a **estrutura de dados** usada pelo algoritmo.

---

## Métodos de busca

### Busca Sequencial (Linear Search)

Percorre os elementos do início ao fim até encontrar o valor.

- **Pré-requisito**: nenhum.
- **Tempo**: O(n).
- **Espaço**: O(1).
- **Quando usar**: coleções pequenas ou não ordenadas.

### Busca Binária (Binary Search)

Em coleção ordenada, compara com o elemento do meio e elimina metade do espaço de busca.

- **Pré-requisito**: dados ordenados.
- **Tempo**: O(log n).
- **Espaço**: O(1) iterativa, O(log n) recursiva (pilha de chamadas).
- **Quando usar**: arrays/vetores ordenados.

### BFS e DFS em grafos

- **BFS (Busca em Largura)**: explora por níveis.
  - Tempo: O(V + E) em lista de adjacência; O(V²) em matriz.
  - Uso: menor caminho em grafo não ponderado.
- **DFS (Busca em Profundidade)**: aprofunda caminhos.
  - Tempo: O(V + E) em lista; O(V²) em matriz.
  - Uso: componentes conexas, detecção de ciclos, ordenação topológica (DAG).

---

## Métodos de ordenação

## 1) Bubble Sort

Compara pares adjacentes e troca quando fora de ordem.

- Melhor: O(n) (com otimização de troca)
- Médio/Pior: O(n²)
- Espaço: O(1)
- Estável: sim

## 2) Selection Sort

Seleciona o menor elemento da parte não ordenada e posiciona no início.

- Melhor/Médio/Pior: O(n²)
- Espaço: O(1)
- Estável: não (na forma clássica)

## 3) Insertion Sort

Insere cada elemento na posição correta da parte já ordenada.

- Melhor: O(n)
- Médio/Pior: O(n²)
- Espaço: O(1)
- Estável: sim
- Bom para: listas pequenas/quase ordenadas

## 4) Merge Sort

Divide o vetor em metades, ordena recursivamente e intercala.

- Melhor/Médio/Pior: O(n log n)
- Espaço extra: O(n)
- Estável: sim
- Bom para: grandes volumes com necessidade de estabilidade

## 5) Quick Sort

Escolhe pivô, particiona em menores/maiores e ordena recursivamente.

- Melhor/Médio: O(n log n)
- Pior: O(n²) (pivôs ruins)
- Espaço extra: O(log n) médio (recursão)
- Estável: não (implementação in-place clássica)
- Bom para: desempenho geral em memória local (cache-friendly)

## 6) Heap Sort

Constrói heap máximo e extrai repetidamente o maior elemento.

- Melhor/Médio/Pior: O(n log n)
- Espaço extra: O(1)
- Estável: não
- Bom para: garantir O(n log n) com baixo uso de memória

## 7) Counting Sort

Conta frequência de chaves inteiras em faixa limitada.

- Tempo: O(n + k), `k` = faixa de valores
- Espaço: O(n + k)
- Estável: sim (quando implementado com prefixos)
- Bom para: inteiros com faixa pequena

## 8) Radix Sort

Ordena por dígitos (LSD/MSD), geralmente usando Counting Sort por dígito.

- Tempo: O(d * (n + k)), `d` = número de dígitos
- Espaço: O(n + k)
- Estável: sim (depende da etapa interna)
- Bom para: inteiros/strings com tamanho controlado

---

## Tabela comparativa de ordenação

| Algoritmo | Melhor | Médio | Pior | Espaço extra | Estável |
|----------|--------|-------|------|--------------|---------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Sim |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | Não |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Sim |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Sim |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) médio | Não |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | Não |
| Counting | O(n + k) | O(n + k) | O(n + k) | O(n + k) | Sim |
| Radix | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) | Sim |

---

## Como escolher

- Dados quase ordenados e pequenos: **Insertion Sort**.
- Precisa estabilidade e previsibilidade: **Merge Sort**.
- Melhor desempenho médio geral: **Quick Sort** (com escolha robusta de pivô).
- Memória extra mínima com O(n log n) garantido: **Heap Sort**.
- Chaves inteiras em faixa pequena: **Counting/Radix Sort**.

---

Voltar para o [índice da documentação](./README.md).
