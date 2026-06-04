# Métodos de Busca — Referência de Complexidade

Este documento é a referência detalhada dos algoritmos de busca implementados no módulo
[Métodos de Busca](../Métodos%20de%20Busca).

---

## Notação usada

| Símbolo | Significado |
|---------|-------------|
| n | número de elementos no vetor |
| O(f(n)) | limite assintótico superior |
| Ω(f(n)) | limite assintótico inferior |
| Θ(f(n)) | limite assintótico exato |

---

## 1. Busca Linear

**Ideia:** varre o vetor da primeira até a última posição.

| Caso | Tempo |
|------|-------|
| Melhor | Ω(1) |
| Médio | O(n) |
| Pior | O(n) |

- **Espaço extra:** O(1)
- **Pré-requisito:** nenhum
- **Custo em vetor:** acesso sequencial simples; melhor opção para vetores não ordenados.

---

## 2. Busca Binária

**Ideia:** compara com o meio e elimina metade do intervalo por iteração.

| Caso | Tempo |
|------|-------|
| Melhor | Ω(1) |
| Médio | O(log n) |
| Pior | O(log n) |

- **Espaço extra:** O(1) (iterativa)
- **Pré-requisito:** vetor ordenado crescente
- **Custo em vetor:** número muito baixo de comparações em vetores grandes.

---

## 3. Busca por Salto (Jump Search)

**Ideia:** salta blocos de tamanho `√n` e faz varredura linear no bloco alvo.

| Caso | Tempo |
|------|-------|
| Melhor | Ω(1) |
| Médio | O(√n) |
| Pior | O(√n) |

- **Espaço extra:** O(1)
- **Pré-requisito:** vetor ordenado crescente
- **Custo em vetor:** equilíbrio entre simplicidade e menos comparações que busca linear.

---

## 4. Busca por Interpolação

**Ideia:** estima posição provável usando os valores extremos e a chave procurada.

| Caso | Tempo | Condição |
|------|-------|----------|
| Melhor | Ω(1) | |
| Médio | O(log log n) | dados uniformemente distribuídos |
| Pior | O(n) | distribuição desfavorável |

- **Espaço extra:** O(1)
- **Pré-requisito:** vetor ordenado crescente
- **Custo em vetor:** ótima em dados uniformes; pode degradar com dados concentrados.

---

## 5. Busca Exponencial

**Ideia:** dobra o limite de busca (`1, 2, 4, 8...`) e aplica busca binária na faixa.

| Caso | Tempo |
|------|-------|
| Melhor | Ω(1) |
| Médio | O(log n) |
| Pior | O(log n) |

- **Espaço extra:** O(1)
- **Pré-requisito:** vetor ordenado crescente
- **Custo em vetor:** eficiente para chaves próximas ao início e vetores grandes.

---

## Tabela comparativa

| Algoritmo | Melhor | Médio | Pior | Espaço extra | Ordenado |
|-----------|--------|-------|------|--------------|----------|
| Linear | Ω(1) | O(n) | O(n) | O(1) | Não |
| Binária | Ω(1) | O(log n) | O(log n) | O(1) | Sim |
| Salto | Ω(1) | O(√n) | O(√n) | O(1) | Sim |
| Interpolação | Ω(1) | O(log log n) | O(n) | O(1) | Sim |
| Exponencial | Ω(1) | O(log n) | O(log n) | O(1) | Sim |

---

## Como escolher

| Situação | Recomendado |
|----------|-------------|
| Vetor desordenado | Busca Linear |
| Vetor ordenado com consultas gerais | Busca Binária |
| Vetor ordenado e implementação simples sem divisão contínua | Busca por Salto |
| Dados uniformes (IDs sequenciais, faixas regulares) | Busca por Interpolação |
| Alvos frequentes no início ou crescimento de faixa desconhecida | Busca Exponencial |

---

Voltar para o [índice da documentação](./README.md).
