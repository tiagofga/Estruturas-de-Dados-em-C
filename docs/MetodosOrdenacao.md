# Métodos de Ordenação — Referência de Complexidade

Este documento é a referência detalhada dos algoritmos de ordenação implementados no módulo
[Métodos de Ordenação](../Métodos%20de%20Ordenação).

---

## Notação usada

| Símbolo | Significado |
|---------|-------------|
| n | número de elementos no vetor |
| O(f(n)) | limite assintótico superior (pior caso ou caso médio) |
| Ω(f(n)) | limite assintótico inferior (melhor caso) |
| Θ(f(n)) | limite exato (melhor = pior = médio) |

---

## 1. Bubble Sort

**Ideia:** compara pares adjacentes e troca quando fora de ordem; repete até não haver trocas.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Ω(n) | vetor já ordenado (otimização de parada) |
| Médio | O(n²) | |
| Pior | O(n²) | vetor em ordem inversa |

- **Espaço extra:** O(1)
- **Estável:** sim
- **Custo em vetor:** acessos sequenciais — excelente localidade de cache, mas alto número de trocas.

---

## 2. Insertion Sort

**Ideia:** mantém prefixo ordenado e insere cada novo elemento no lugar correto deslocando os maiores.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Ω(n) | vetor já ordenado |
| Médio | O(n²) | |
| Pior | O(n²) | vetor em ordem inversa |

- **Espaço extra:** O(1)
- **Estável:** sim
- **Custo em vetor:** deslocamentos são O(n) por elemento no pior caso; ótimo para n pequeno ou quase-ordenado.

---

## 3. Selection Sort

**Ideia:** encontra o menor elemento da parte não ordenada e o coloca na posição correta.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Θ(n²) | independente dos dados |
| Médio | Θ(n²) | |
| Pior | Θ(n²) | |

- **Espaço extra:** O(1)
- **Estável:** não (troca pode quebrar ordem relativa de iguais)
- **Custo em vetor:** sempre O(n) trocas — indicado quando trocas são caras e comparações são baratas.

---

## 4. Merge Sort

**Ideia:** divide o vetor ao meio recursivamente; intercala (merge) subvetores já ordenados.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Θ(n log n) | |
| Médio | Θ(n log n) | |
| Pior | Θ(n log n) | |

- **Espaço extra:** O(n) — buffers temporários para a etapa de intercalação
- **Estável:** sim
- **Custo em vetor:** requer alocação dinâmica; garantia de O(n log n) em todos os cenários.

---

## 5. Quick Sort

**Ideia:** escolhe pivô (mediana de três neste módulo), particiona em menores/maiores e ordena recursivamente.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Ω(n log n) | partições equilibradas |
| Médio | O(n log n) | |
| Pior | O(n²) | pivôs extremos (mitigado pela mediana de três) |

- **Espaço extra:** O(log n) médio (pilha de recursão); O(n) pior caso
- **Estável:** não (implementação in-place clássica)
- **Custo em vetor:** in-place e cache-friendly; melhor desempenho prático médio.

---

## 6. Heap Sort

**Ideia:** constrói heap máximo no próprio vetor; extrai repetidamente o maior para o final.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Θ(n log n) | |
| Médio | Θ(n log n) | |
| Pior | Θ(n log n) | |

- **Espaço extra:** O(1) — in-place
- **Estável:** não
- **Custo em vetor:** acessos não sequenciais ao heap reduzem localidade de cache; compensa pela garantia de O(n log n) com O(1) espaço.

---

## Tabela comparativa

| Algoritmo | Melhor | Médio | Pior | Espaço extra | Estável |
|-----------|--------|-------|------|--------------|---------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Sim |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Sim |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | Não |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Sim |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | Não |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | Não |

---

## Como escolher

| Situação | Algoritmo recomendado |
|----------|-----------------------|
| Vetor pequeno (≤ ~20 elementos) | Insertion Sort |
| Vetor quase ordenado | Insertion Sort ou Bubble Sort |
| Estabilidade obrigatória | Merge Sort |
| Melhor desempenho médio geral | Quick Sort |
| O(n log n) garantido com O(1) espaço | Heap Sort |
| Minimizar trocas de elementos | Selection Sort |

---

Voltar para o [índice da documentação](./README.md).
