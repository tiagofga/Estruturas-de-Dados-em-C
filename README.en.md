# Data Structures and Algorithms in C

[Português](./README.md) | **English**

[![CI](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml/badge.svg)](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml)
![release](https://img.shields.io/badge/release-v0.3.0-orange)
[![license](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](./LICENSE)
![C](https://img.shields.io/badge/C-language-brightgreen)
![gcc](https://img.shields.io/badge/GCC-7%2B-informational)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](../../issues)
<br>
[![issues welcome](https://img.shields.io/badge/issues-welcome-brightgreen.svg)](../../issues)

Educational repository with implementations of data structures and algorithms in C, including executable examples, automated tests, module-level documentation, and practical exercises.

> **Tip:** choosing the right data structure is as important as choosing the right algorithm.
> Each structure has its own operations, costs, and complexity trade-offs.

---

## Implemented structures and algorithms

| Module | Documentation | Description | Main complexity |
|--------|---------------|-------------|-----------------|
| [ADT](./TAD) | [docs/en/TAD.md](./docs/en/TAD.md) | Abstract Data Type — interface vs. implementation | — |
| [List](./Lista) | [docs/en/List.md](./docs/en/List.md) | Dynamic sequential list with linear/binary search and configurable sorting | O(1) end insertion, O(n) middle operations |
| [SinglyLinkedList](./ListaEncadeada) | [docs/ListasEncadeadas.md](./docs/ListasEncadeadas.md) | Singly linked list | O(1) front insertion, O(n) search/removal |
| [DoublyLinkedList](./ListaDuplamenteEncadeada) | [docs/ListasEncadeadas.md](./docs/ListasEncadeadas.md) | Doubly linked list | O(1) front/back insertion, O(n) search/removal |
| [Queue](./Fila) | [docs/en/Queue.md](./docs/en/Queue.md) | Circular queue (FIFO) with fixed capacity | O(1) enqueue/dequeue |
| [Stack](./Pilha) | [docs/en/Stack.md](./docs/en/Stack.md) | Sequential stack (LIFO) with fixed capacity | O(1) push/pop |
| [HashTable](./TabelaHash) | [docs/TabelaHash.md](./docs/TabelaHash.md) | Hash table with separate chaining | O(1) average, O(n) worst case |
| [Heap](./Heap) | [docs/en/Heap.md](./docs/en/Heap.md) | Dynamic max heap, priority queue, and heap sort | O(1) peek, O(log n) insert/remove |
| [Tree](./Árvore) | [docs/en/Tree.md](./docs/en/Tree.md) | Binary Search Tree (BST) + AVL/Red-Black concepts | O(log n) average, O(n) worst case |
| [AVL](./AVL) | [docs/AVL.md](./docs/AVL.md) | AVL tree with rotations and automatic balancing | O(log n) search/insert |
| [Graph](./Grafo) | [docs/en/Graph.md](./docs/en/Graph.md) | Graph using adjacency matrix + BFS/DFS/Dijkstra/topological sort | O(1) edge lookup |
| [AdjacencyListGraph](./GrafoListaAdjacencia) | [docs/GrafoListaAdjacencia.md](./docs/GrafoListaAdjacencia.md) | Graph using adjacency lists + BFS/DFS/Dijkstra | O(V + E) BFS/DFS |
| [Sorting Methods](./Métodos%20de%20Ordenação) | [docs/en/SortingMethods.md](./docs/en/SortingMethods.md) | Bubble, Insertion, Selection, Merge, Quick, and Heap Sort | O(n²) to O(n log n) |
| [Search Methods](./Métodos%20de%20Busca) | [docs/en/SearchMethods.md](./docs/en/SearchMethods.md) | Linear, Binary, Jump, Interpolation, and Exponential Search | O(n) to O(log n) |
| [Computational Cost and Complexity](./Custo%20Computacional%20e%20Complexidade) | [docs/en/ComputationalCost.md](./docs/en/ComputationalCost.md) | Time/space cost, growth rates, and asymptotic analysis | O(1) to O(2ⁿ) |

---

## Requirements

- GCC 7 or newer
- GNU Make

```bash
gcc --version
make --version
```

---

## Usage

### Clone the repository

```bash
git clone https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C.git
cd Estruturas-de-Dados-e-Algoritmos-em-C
```

### Build and test the whole project

```bash
make
make test
make clean
```

### Run sanitizer tests for the new modules

```bash
make sanitize
```

### Build and run one module

```bash
cd TabelaHash  # or ListaEncadeada, ListaDuplamenteEncadeada, GrafoListaAdjacencia, AVL, etc.
make
make run
make test
make clean
```

---

## Documentation

The [`docs/`](./docs) directory contains the full Portuguese documentation. The English documentation is available in [`docs/en/`](./docs/en).

## Exercises

The [`exercicios/`](./exercicios) directory contains practical exercises by topic:

- [Lists](./exercicios/01-listas.md)
- [Stacks and queues](./exercicios/02-pilhas-filas.md)
- [Hash table and heap](./exercicios/03-hash-heap.md)
- [Trees](./exercicios/04-arvores.md)
- [Graphs](./exercicios/05-grafos.md)
- [Search, sorting, and complexity](./exercicios/06-busca-ordenacao-complexidade.md)

## Automated tests

Automated tests are organized in each module's `tests/` directory. The CI builds and tests all implemented modules, and also runs sanitizer tests for the new modules.

---

## Contributing

1. Fork the repository.
2. Create a descriptive branch: `git checkout -b feat/my-structure`.
3. Follow the existing directory layout.
4. Use ASCII names, without accents and without spaces, for new modules.
5. Add tests in `tests/`.
6. Ensure `make`, `make test`, and, when applicable, `make sanitize` pass.
7. Open a pull request describing the changes.

Found a bug or have a suggestion? [Open an issue.](../../issues/new/choose)

---

## License

Distributed under the **Apache 2.0** license. See [LICENSE](./LICENSE) for more information.
