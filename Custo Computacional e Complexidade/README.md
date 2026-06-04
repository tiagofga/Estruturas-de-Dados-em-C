# Custo Computacional e Complexidade de Algoritmos

Esta pasta centraliza uma explicação introdutória sobre **custo computacional**
e **complexidade de algoritmos**, com foco em análise de tempo e espaço.

## Conteúdo desta pasta

- visão geral sobre custo computacional
- noções de complexidade assintótica
- ordens de crescimento mais comuns
- referência para a documentação detalhada do repositório

## Resumo rápido

- **Custo computacional** mede os recursos consumidos por um algoritmo.
- Os recursos mais observados são **tempo** e **memória**.
- **Complexidade** descreve como esse custo cresce em função da entrada `n`.
- A notação mais usada é **Big-O**, comum para comparar algoritmos.

| Complexidade | Interpretação | Exemplo |
|--------------|---------------|---------|
| `O(1)` | constante | acesso por índice em vetor |
| `O(log n)` | logarítmica | busca binária |
| `O(n)` | linear | busca sequencial |
| `O(n log n)` | linearítmica | merge sort, heap sort |
| `O(n²)` | quadrática | bubble sort no pior caso |

## Documentação detalhada

Para aprofundar o assunto, consulte:

- [Documentação detalhada sobre custo computacional](../docs/CustoComputacional.md)
- [Documentação de algoritmos e Big-O](../docs/Algoritmos.md)

## Testes

Esta pasta é apenas **documental**, então não possui testes automatizados
próprios. Os testes existentes do projeto continuam nas pastas `tests/` de cada
módulo implementado.
