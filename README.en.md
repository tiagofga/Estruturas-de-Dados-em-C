# Data Structures and Algorithms in C

[Português](./README.md) | **English**

[![CI](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml/badge.svg)](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml)
![release](https://img.shields.io/badge/release-v0.5.0-orange)
[![license](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](./LICENSE)
![C](https://img.shields.io/badge/C-language-brightgreen)
![gcc](https://img.shields.io/badge/GCC-7%2B-informational)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](../../issues)
<br>
[![issues welcome](https://img.shields.io/badge/issues-welcome-brightgreen.svg)](../../issues)

Educational repository with implementations of data structures and algorithms in C, including fundamental and advanced structures, executable examples, automated tests, module-level documentation, practical exercises, test coverage, and benchmarks.

> **Tip:** choosing the right data structure is as important as choosing the right algorithm.
> Each structure has its own operations, costs, and complexity trade-offs.

---

## Implemented structures and algorithms

| Module | Documentation | Description | Main complexity |
|--------|---------------|-------------|-----------------|
| [ADT](./TAD) | [docs/en/TAD.md](./docs/en/TAD.md) | Abstract Data Type — interface vs. implementation | — |
| [List](./Lista) | [docs/en/List.md](./docs/en/List.md) | Dynamic sequential list with linear/binary search and configurable sorting | O(1) end insertion, O(n) middle operations |
| [SinglyLinkedList](./ListaEncadeada) | [docs/en/LinkedLists.md](./docs/en/LinkedLists.md) | Singly linked list | O(1) front insertion, O(n) search/removal |
| [DoublyLinkedList](./ListaDuplamenteEncadeada) | [docs/en/LinkedLists.md](./docs/en/LinkedLists.md) | Doubly linked list | O(1) front/back insertion, O(n) search/removal |
| [Queue](./Fila) | [docs/en/Queue.md](./docs/en/Queue.md) | Circular queue (FIFO) with fixed capacity | O(1) enqueue/dequeue |
| [Stack](./Pilha) | [docs/en/Stack.md](./docs/en/Stack.md) | Sequential stack (LIFO) with fixed capacity | O(1) push/pop |
| [HashTable](./TabelaHash) | [docs/en/HashTable.md](./docs/en/HashTable.md) | Opaque hash table with separate chaining | O(1) average, O(n) worst case |
| [Heap](./Heap) | [docs/en/Heap.md](./docs/en/Heap.md) | Dynamic max heap, priority queue, and heap sort | O(1) peek, O(log n) insert/remove |
| [Tree](./Árvore) / [Arvore](./Arvore) | [docs/en/Tree.md](./docs/en/Tree.md) | Binary Search Tree (BST) + AVL/Red-Black concepts | O(log n) average, O(n) worst case |
| [AVL](./AVL) | [docs/en/AVL.md](./docs/en/AVL.md) | Opaque AVL tree with insertion, removal, rotations, and automatic balancing | O(log n) search/insert/remove |
| [Graph](./Grafo) | [docs/en/Graph.md](./docs/en/Graph.md) | Graph using adjacency matrix + BFS/DFS/Dijkstra/topological sort | O(1) edge lookup |
| [AdjacencyListGraph](./GrafoListaAdjacencia) | [docs/en/AdjacencyListGraph.md](./docs/en/AdjacencyListGraph.md) | Graph using adjacency lists + BFS/DFS/Dijkstra | O(V + E) BFS/DFS |
| [GraphAlgorithms](./AlgoritmosGrafos) | [docs/en/AdvancedGraphAlgorithms.md](./docs/en/AdvancedGraphAlgorithms.md) | Opaque Union-Find, Kruskal, Prim, Bellman-Ford, and Floyd-Warshall | O(E log E), O(VE), O(V³) |
| [Sorting Methods](./Métodos%20de%20Ordenação) / [MetodosOrdenacao](./MetodosOrdenacao) | [docs/en/SortingMethods.md](./docs/en/SortingMethods.md) | Bubble, Insertion, Selection, Merge, Quick, and Heap Sort | O(n²) to O(n log n) |
| [Search Methods](./Métodos%20de%20Busca) / [MetodosBusca](./MetodosBusca) | [docs/en/SearchMethods.md](./docs/en/SearchMethods.md) | Linear, Binary, Jump, Interpolation, and Exponential Search | O(n) to O(log n) |
| [Computational Cost and Complexity](./Custo%20Computacional%20e%20Complexidade) | [docs/en/ComputationalCost.md](./docs/en/ComputationalCost.md) | Time/space cost, growth rates, and asymptotic analysis | O(1) to O(2ⁿ) |

---

## Module status

| Module | Build | Tests | Sanitizer | Coverage | Benchmark | PT/EN docs |
|--------|-------|-------|-----------|----------|-----------|------------|
| List/Queue/Stack | CI | CI | — | — | — | Yes |
| Heap | CI | CI | CI | CI | — | Yes |
| HashTable | CI | CI | CI | CI | CI | Yes |
| Singly/Doubly linked lists | CI | CI | CI | CI | — | Yes |
| Tree / AVL | CI | CI | AVL | AVL | AVL | Yes |
| Graph / AdjacencyListGraph | CI | CI | AdjacencyListGraph | AdjacencyListGraph | — | Yes |
| GraphAlgorithms | CI | CI | CI | CI | CI | Yes |
| Search / Sorting | CI | CI | — | — | — | Yes |

---

## Technical quality

- `AVL` uses an opaque node type in the public header.
- `TabelaHash` uses an opaque ADT in the public header.
- `UnionFind` uses an opaque ADT in the public header of `AlgoritmosGrafos`.
- `make coverage` generates a `gcov` report for new and advanced modules.
- `make benchmark` runs a CSV benchmark in `benchmarks/`.
- Legacy modules with accents/spaces have ASCII aliases: `Arvore`, `MetodosOrdenacao`, and `MetodosBusca`.

---

## Usage

```bash
git clone https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C.git
cd Estruturas-de-Dados-e-Algoritmos-em-C
make
make test
make sanitize
make coverage
make benchmark
```

To run a specific module:

```bash
cd AlgoritmosGrafos
make
make run
make test
```

---

## Documentation, exercises, and course plan

- [Portuguese documentation](./docs/README.md)
- [English documentation](./docs/en/README.md)
- [Benchmarks](./docs/Benchmarks.md)
- [ASCII aliases](./docs/AliasesASCII.md)
- [Exercises](./exercicios/README.md)
- [Suggested weekly course plan](./docs/RoteiroAulas.md)

---

## Automated tests

Automated tests are organized in each module's `tests/` directory. The CI builds and tests all implemented modules, runs sanitizer tests, generates coverage artifacts, and executes benchmarks.

---

## Contributing

1. Fork the repository.
2. Create a descriptive branch: `git checkout -b feat/my-structure`.
3. Follow the existing directory layout.
4. Use ASCII names, without accents and without spaces, for new modules.
5. Add tests in `tests/`.
6. Ensure `make`, `make test`, `make sanitize`, `make coverage`, and `make benchmark` pass when applicable.
7. Open a pull request describing the changes.

Found a bug or have a suggestion? [Open an issue.](../../issues/new/choose)

---

## License

Distributed under the **Apache 2.0** license. See [LICENSE](./LICENSE) for more information.
