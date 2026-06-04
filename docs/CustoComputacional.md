# Custo Computacional e Complexidade de Algoritmos

Este material apresenta os conceitos básicos usados para analisar a eficiência de
um algoritmo antes mesmo da implementação final.

## O que é custo computacional?

Custo computacional é a medida dos recursos consumidos por um algoritmo para
resolver um problema.

Os dois recursos mais observados são:

- **Tempo**: quantidade de operações executadas
- **Espaço**: memória adicional necessária durante a execução

A análise normalmente não depende do computador usado, mas sim do crescimento do
custo conforme a entrada aumenta.

## O que é complexidade?

Complexidade é a forma de descrever como esse custo cresce em função do tamanho
da entrada `n`.

As notações assintóticas mais comuns são:

- **Big-O (`O`)**: limite superior de crescimento
- **Big-Theta (`Θ`)**: crescimento exato assintótico
- **Big-Omega (`Ω`)**: limite inferior de crescimento

Neste repositório, a notação mais usada é **Big-O**, por ser a forma mais comum
para comparar algoritmos e estruturas de dados.

## Ordens de crescimento mais comuns

| Complexidade | Interpretação | Exemplo |
|--------------|---------------|---------|
| `O(1)` | constante | acesso por índice em vetor |
| `O(log n)` | logarítmica | busca binária |
| `O(n)` | linear | busca sequencial |
| `O(n log n)` | linearítmica | merge sort, heap sort |
| `O(n²)` | quadrática | bubble sort no pior caso |
| `O(2ⁿ)` | exponencial | busca exaustiva em muitos problemas combinatórios |

## Tempo x espaço

Nem sempre o algoritmo mais rápido é o que usa menos memória.

- **Busca linear**: tempo `O(n)`, espaço `O(1)`
- **Merge sort**: tempo `O(n log n)`, espaço extra `O(n)`
- **Heap sort**: tempo `O(n log n)`, espaço extra `O(1)`

Por isso, a análise deve considerar o contexto e a restrição principal do
problema.

## Melhor caso, caso médio e pior caso

Um mesmo algoritmo pode apresentar comportamentos diferentes dependendo da
entrada.

- **Melhor caso**: situação mais favorável
- **Caso médio**: comportamento esperado para entradas típicas
- **Pior caso**: situação de maior custo

Exemplo:

- **Busca linear**
  - melhor caso: `O(1)`
  - pior caso: `O(n)`
- **Insertion sort**
  - melhor caso: `O(n)`
  - pior caso: `O(n²)`

## Como analisar um algoritmo

Ao estudar um algoritmo, vale responder:

1. Quantas vezes o laço principal executa?
2. Existem laços aninhados?
3. Há chamadas recursivas?
4. O algoritmo usa estruturas auxiliares?
5. A entrada precisa estar ordenada ou preparada antes?

## Relação com este repositório

Os módulos deste repositório usam análise de complexidade para comparar
operações e algoritmos, por exemplo:

- listas com inserção e remoção em posições diferentes
- buscas lineares e logarítmicas
- ordenações quadráticas e `O(n log n)`
- grafos e árvores com custos dependentes da estrutura usada

## Testes relacionados

Este conteúdo é apenas documental, então **não exige testes automatizados
próprios**. Os testes automatizados do repositório continuam concentrados nas
pastas `tests/` dos módulos implementados:

- `Lista/tests/test_lista.c`
- `Fila/tests/test_fila.c`
- `Pilha/tests/test_pilha.c`
- `Árvore/tests/test_arvore.c`
- `Grafo/tests/test_grafo.c`
- `Métodos de Ordenação/tests/test_ordenacao.c`
- `Métodos de Busca/tests/test_busca.c`

## Leitura complementar

- [Resumo introdutório na pasta temática](../Custo%20Computacional%20e%20Complexidade/README.md)
- [Big-O, métodos de busca e ordenação](./Algoritmos.md)
- [Índice da documentação](./README.md)
