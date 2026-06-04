# Custo Computacional e Complexidade de Algoritmos

Este diretório reúne uma explicação introdutória sobre **custo computacional** e
**complexidade de algoritmos**, com foco em análise de tempo e espaço.

## O que é custo computacional?

Custo computacional é a quantidade de recursos que um algoritmo consome para
resolver um problema.

Os recursos mais analisados são:

- **Tempo de execução** (quantidade de operações)
- **Memória adicional** (espaço extra utilizado)

## O que é complexidade de algoritmos?

A complexidade descreve como o custo cresce quando o tamanho da entrada `n`
aumenta.

A notação mais usada é a **Big-O**, que representa o limite assintótico superior
(do pior crescimento).

## Ordens de crescimento mais comuns

| Complexidade | Interpretação | Exemplo |
|--------------|---------------|---------|
| `O(1)` | custo constante | acesso por índice em vetor |
| `O(log n)` | crescimento lento | busca binária |
| `O(n)` | proporcional ao tamanho da entrada | busca linear |
| `O(n log n)` | intermediária | merge sort, heap sort |
| `O(n²)` | custo quadrático | bubble/selection/insertion (pior caso) |

## Boas práticas de análise

- Avaliar **melhor caso, caso médio e pior caso**.
- Diferenciar **tempo** de **espaço extra**.
- Considerar a estrutura de dados usada.
- Comparar algoritmos para o mesmo problema conforme o tamanho da entrada.

## Referência no repositório

Para uma explicação complementar com tabelas e comparações, consulte:

- [Documentação de algoritmos e Big-O](../docs/Algoritmos.md)
