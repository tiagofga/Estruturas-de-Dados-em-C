# Roteiro semanal sugerido

Este roteiro organiza o repositório como apoio a uma disciplina de Estruturas de Dados e Algoritmos em C. A distribuição pode ser ajustada conforme a carga horária da turma.

## Plano de 15 semanas

| Semana | Tema | Módulos sugeridos | Atividade prática |
|--------|------|-------------------|-------------------|
| 1 | Revisão de C, ponteiros, alocação dinâmica e Makefile | `TAD`, `docs/Algoritmos.md` | Compilar módulos e executar primeiros testes |
| 2 | Tipo Abstrato de Dados e encapsulamento | `TAD` | Separar interface `.h` e implementação `.c` em um pequeno TAD |
| 3 | Lista sequencial dinâmica | `Lista` | Implementar remoção por posição e testes |
| 4 | Listas encadeadas | `ListaEncadeada`, `ListaDuplamenteEncadeada` | Comparar inserção, busca e remoção em listas sequenciais e encadeadas |
| 5 | Pilhas | `Pilha` | Verificar parênteses balanceados com pilha |
| 6 | Filas | `Fila` | Simular fila de atendimento e fila circular |
| 7 | Busca e análise de complexidade | `Métodos de Busca`, `Custo Computacional e Complexidade` | Comparar busca linear e binária |
| 8 | Ordenação quadrática | `Métodos de Ordenação` | Instrumentar comparações em Bubble, Insertion e Selection Sort |
| 9 | Ordenação eficiente | `Métodos de Ordenação`, `Heap` | Comparar Merge Sort, Quick Sort e Heap Sort |
| 10 | Heap e fila de prioridade | `Heap` | Implementar min heap ou fila de prioridade com pares `(prioridade, valor)` |
| 11 | Tabela hash | `TabelaHash` | Medir colisões e fator de carga com diferentes capacidades |
| 12 | Árvores binárias de busca | `Árvore` | Implementar remoção em BST e comparar casos de árvore degenerada |
| 13 | AVL | `AVL` | Testar rotações, inserções e remoções balanceadas |
| 14 | Grafos básicos | `Grafo`, `GrafoListaAdjacencia` | Comparar matriz e lista de adjacência em grafos esparsos e densos |
| 15 | Algoritmos avançados de grafos | `AlgoritmosGrafos` | Resolver MST com Kruskal/Prim e caminhos mínimos com Bellman-Ford/Floyd-Warshall |

## Avaliações sugeridas

1. **Lista prática 1:** TAD, lista, pilha e fila.
2. **Lista prática 2:** busca, ordenação e complexidade.
3. **Lista prática 3:** hash, heap e árvores.
4. **Projeto final:** modelagem de problema com grafos e aplicação de pelo menos dois algoritmos avançados.

## Projeto final sugerido

Implementar um sistema de rotas entre cidades ou pontos de interesse. O projeto pode exigir:

- representação do grafo por matriz e por lista de adjacência;
- cálculo de menor caminho com Dijkstra ou Bellman-Ford;
- cálculo de árvore geradora mínima com Kruskal ou Prim;
- relatório curto comparando complexidade e uso de memória;
- testes automatizados para os principais casos.

## Critérios de avaliação

| Critério | Peso sugerido |
|----------|---------------|
| Correção funcional | 40% |
| Organização do código | 20% |
| Testes automatizados | 20% |
| Análise de complexidade | 10% |
| Clareza da documentação | 10% |
