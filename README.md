# Estruturas de Dados e Algoritmos em C

**Português** | [English](./README.en.md)

[![CI](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml/badge.svg)](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml)
![release](https://img.shields.io/badge/release-v0.5.0-orange)
[![license](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](./LICENSE)
![C](https://img.shields.io/badge/C-language-brightgreen)
![gcc](https://img.shields.io/badge/GCC-7%2B-informational)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](../../issues)
<br>
[![issues welcome](https://img.shields.io/badge/issues-welcome-brightgreen.svg)](../../issues)

Repositório educacional com implementações de estruturas de dados e algoritmos em C, cobrindo estruturas fundamentais e avançadas com exemplos executáveis, testes automatizados, documentação por módulo, exercícios práticos, cobertura de testes e benchmarks.

> **Dica:** a escolha da estrutura de dados certa é tão importante quanto o algoritmo.
> Cada estrutura tem um conjunto de operações e trade-offs de complexidade distintos.

---

## Estruturas e algoritmos implementados

| Módulo | Documentação | Descrição | Complexidade principal |
|--------|-------------|-----------|------------------------|
| [TAD](./TAD) | [docs/TAD.md](./docs/TAD.md) | Tipo Abstrato de Dados — conceito de interface vs. implementação | — |
| [Lista](./Lista) | [docs/Lista.md](./docs/Lista.md) | Lista sequencial dinâmica com busca linear/binária e ordenação configurável | O(1) fim, O(n) meio |
| [ListaEncadeada](./ListaEncadeada) | [docs/ListasEncadeadas.md](./docs/ListasEncadeadas.md) | Lista simplesmente encadeada | O(1) início, O(n) busca/remoção |
| [ListaDuplamenteEncadeada](./ListaDuplamenteEncadeada) | [docs/ListasEncadeadas.md](./docs/ListasEncadeadas.md) | Lista duplamente encadeada | O(1) início/fim, O(n) busca/remoção |
| [Fila](./Fila) | [docs/Fila.md](./docs/Fila.md) | Fila circular (FIFO) com capacidade fixa | O(1) enfileirar/desenfileirar |
| [Pilha](./Pilha) | [docs/Pilha.md](./docs/Pilha.md) | Pilha sequencial (LIFO) com capacidade fixa | O(1) empilhar/desempilhar |
| [TabelaHash](./TabelaHash) | [docs/TabelaHash.md](./docs/TabelaHash.md) | Tabela hash com encadeamento separado | O(1) médio, O(n) pior caso |
| [Heap](./Heap) | [docs/Heap.md](./docs/Heap.md) | Heap máximo dinâmico, fila de prioridade e Heap Sort | O(1) consultar raiz, O(log n) inserir/remover |
| [Árvore](./Árvore) / [Arvore](./Arvore) | [docs/Arvore.md](./docs/Arvore.md) | Árvore Binária de Busca (BST) + conceitos AVL/Rubro-Negra | O(log n) médio, O(n) pior |
| [AVL](./AVL) | [docs/AVL.md](./docs/AVL.md) | Árvore AVL com inserção, remoção, rotações e balanceamento automático | O(log n) buscar/inserir/remover |
| [Grafo](./Grafo) | [docs/Grafo.md](./docs/Grafo.md) | Grafo com matriz de adjacência + BFS/DFS/Dijkstra/topológica | O(1) consulta de aresta |
| [GrafoListaAdjacencia](./GrafoListaAdjacencia) | [docs/GrafoListaAdjacencia.md](./docs/GrafoListaAdjacencia.md) | Grafo com lista de adjacência + BFS/DFS/Dijkstra | O(V + E) BFS/DFS |
| [AlgoritmosGrafos](./AlgoritmosGrafos) | [docs/AlgoritmosGrafos.md](./docs/AlgoritmosGrafos.md) | Union-Find, Kruskal, Prim, Bellman-Ford e Floyd-Warshall | O(E log E), O(VE), O(V³) |
| [Métodos de Ordenação](./Métodos%20de%20Ordenação) / [MetodosOrdenacao](./MetodosOrdenacao) | [docs/MetodosOrdenacao.md](./docs/MetodosOrdenacao.md) | Bubble, Insertion, Selection, Merge, Quick e Heap Sort para vetores | O(n²) a O(n log n) |
| [Métodos de Busca](./Métodos%20de%20Busca) / [MetodosBusca](./MetodosBusca) | [docs/MetodosBusca.md](./docs/MetodosBusca.md) | Busca Linear, Binária, por Salto, por Interpolação e Exponencial para vetores | O(n) a O(log n) |
| [Custo Computacional e Complexidade](./Custo%20Computacional%20e%20Complexidade) | [docs/CustoComputacional.md](./docs/CustoComputacional.md) | Introdução ao custo de tempo/espaço, ordens de crescimento e análise assintótica | O(1) a O(2ⁿ) |

---

## Status por módulo

| Módulo | Build | Testes | Sanitizer | Cobertura | Benchmark | Documentação PT/EN |
|--------|-------|--------|-----------|-----------|-----------|--------------------|
| Lista/Fila/Pilha | CI | CI | — | — | — | Sim |
| Heap | CI | CI | CI | CI | — | Sim |
| TabelaHash | CI | CI | CI | CI | CI | Sim |
| ListaEncadeada / ListaDuplamenteEncadeada | CI | CI | CI | CI | — | Sim |
| Árvore / AVL | CI | CI | AVL | AVL | AVL | Sim |
| Grafo / GrafoListaAdjacencia | CI | CI | GrafoListaAdjacencia | GrafoListaAdjacencia | — | Sim |
| AlgoritmosGrafos | CI | CI | CI | CI | CI | Sim |
| Busca / Ordenação | CI | CI | — | — | — | Sim |

---

## Qualidade técnica

- `AVL` usa nó opaco no header público.
- `UnionFind` usa TAD opaco no header público de `AlgoritmosGrafos`.
- `make coverage` gera relatório com `gcov` para módulos novos e avançados.
- `make benchmark` executa benchmark CSV em `benchmarks/`.
- Módulos antigos com acentos/espaços têm aliases ASCII: `Arvore`, `MetodosOrdenacao` e `MetodosBusca`.

---

## Pré-requisitos

- GCC 7 ou superior
- GNU Make
- `gcov`, para cobertura de testes

```bash
gcc --version
make --version
gcov --version
```

---

## Como usar

### Clonar o repositório

```bash
git clone https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C.git
cd Estruturas-de-Dados-e-Algoritmos-em-C
```

### Compilar e testar todo o projeto

```bash
make
make test
make sanitize
make coverage
make benchmark
make clean
```

### Compilar e executar um módulo

```bash
cd AlgoritmosGrafos  # ou TabelaHash, ListaEncadeada, GrafoListaAdjacencia, AVL etc.
make
make run
make test
make clean
```

---

## Documentação

A pasta [`docs/`](./docs) contém a documentação completa em português. A versão em inglês está disponível em [`docs/en/`](./docs/en).

- [TAD — Tipo Abstrato de Dados](./docs/TAD.md)
- [Lista sequencial dinâmica](./docs/Lista.md)
- [Listas encadeadas](./docs/ListasEncadeadas.md)
- [Fila circular](./docs/Fila.md)
- [Pilha sequencial](./docs/Pilha.md)
- [Tabela hash](./docs/TabelaHash.md)
- [Heap máximo e fila de prioridade](./docs/Heap.md)
- [Árvore Binária de Busca](./docs/Arvore.md)
- [AVL](./docs/AVL.md)
- [Grafo com matriz de adjacência](./docs/Grafo.md)
- [Grafo com lista de adjacência](./docs/GrafoListaAdjacencia.md)
- [Algoritmos avançados de grafos](./docs/AlgoritmosGrafos.md)
- [Benchmarks](./docs/Benchmarks.md)
- [Aliases ASCII](./docs/AliasesASCII.md)
- [Complexidade (Big-O)](./docs/Algoritmos.md#notação-de-complexidade-big-o)
- [Custo computacional e complexidade](./docs/CustoComputacional.md)
- [Métodos de busca para vetores](./docs/MetodosBusca.md)
- [Métodos de ordenação para vetores](./docs/MetodosOrdenacao.md)
- [Lista/Fila/Pilha estática vs dinâmica](./docs/EstaticoVsDinamico.md)
- [Política de nomes de módulos](./docs/PadraoNomes.md)

## Exercícios e roteiro de aulas

- [Exercícios por módulo](./exercicios/README.md)
- [Roteiro semanal sugerido](./docs/RoteiroAulas.md)

## Testes automatizados

Os testes do projeto estão organizados nas pastas `tests/` de cada módulo implementado. A CI compila e testa todos os módulos com implementação em C, executa sanitizers, gera cobertura e roda benchmarks.

---

## Contribuindo

1. Faça um fork do repositório.
2. Crie uma branch descritiva: `git checkout -b feat/minha-estrutura`.
3. Implemente seguindo o padrão de estrutura de diretórios acima.
4. Use nomes ASCII, sem acentos e sem espaços, para novos módulos.
5. Adicione testes em `tests/`.
6. Garanta que `make`, `make test`, `make sanitize`, `make coverage` e `make benchmark` passam sem erros, quando aplicável.
7. Abra um pull request descrevendo as mudanças.

Encontrou um bug ou tem uma sugestão? [Abra uma issue!](../../issues/new/choose)

---

## Licença

Distribuído sob a licença **Apache 2.0**. Consulte [LICENSE](./LICENSE) para mais informações.
