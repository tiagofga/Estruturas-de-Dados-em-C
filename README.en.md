# Data Structures and Algorithms in C

[Português](./README.md) | **English**

[![CI](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml/badge.svg)](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml)
![release](https://img.shields.io/badge/release-v0.2.0-orange)
[![license](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](./LICENSE)
![C](https://img.shields.io/badge/C-language-brightgreen)
![gcc](https://img.shields.io/badge/GCC-7%2B-informational)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](../../issues)
<br>
[![issues welcome](https://img.shields.io/badge/issues-welcome-brightgreen.svg)](../../issues)

Educational repository with implementations of data structures and algorithms in C, including executable examples, automated tests, and module-level documentation.

> **Tip:** choosing the right data structure is as important as choosing the right algorithm.
> Each structure has its own operations, costs, and complexity trade-offs.

---

## Implemented structures and algorithms

| Module | Documentation | Description | Main complexity |
|--------|---------------|-------------|-----------------|
| [ADT](./TAD) | [docs/en/TAD.md](./docs/en/TAD.md) | Abstract Data Type — interface vs. implementation | — |
| [List](./Lista) | [docs/en/List.md](./docs/en/List.md) | Dynamic sequential list with linear/binary search and configurable sorting | O(1) end insertion, O(n) middle operations |
| [Queue](./Fila) | [docs/en/Queue.md](./docs/en/Queue.md) | Circular queue (FIFO) with fixed capacity | O(1) enqueue/dequeue |
| [Stack](./Pilha) | [docs/en/Stack.md](./docs/en/Stack.md) | Sequential stack (LIFO) with fixed capacity | O(1) push/pop |
| [Heap](./Heap) | [docs/en/Heap.md](./docs/en/Heap.md) | Dynamic max heap, priority queue, and heap sort | O(1) peek, O(log n) insert/remove |
| [Tree](./Árvore) | [docs/en/Tree.md](./docs/en/Tree.md) | Binary Search Tree (BST) + AVL/Red-Black concepts | O(log n) average, O(n) worst case |
| [Graph](./Grafo) | [docs/en/Graph.md](./docs/en/Graph.md) | Directed/undirected graph using adjacency matrix + BFS/DFS/Dijkstra/topological sort | O(1) edge lookup |
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

### Build and run one module

```bash
cd Lista        # or Fila, Pilha, Heap, Árvore, Grafo
make            # builds the example
make run        # runs the dynamic example
make run_static # runs the static example (Lista/Fila/Pilha)
make test       # runs automated tests
make clean      # removes build artifacts
```

### Build with debug symbols

```bash
make debug
make run
```

### Build with maximum optimization

```bash
make release
make run
```

---

## Build layout

All modules follow the same `Makefile` layout:

```
<Module>/
├── include/        # public headers (.h)
├── src/            # implementations (.c) + example main.c
├── tests/          # automated tests
├── build/          # generated artifacts (ignored by git)
│   ├── app         # example executable
│   ├── test_runner # test executable
│   └── objects/    # object files
└── Makefile
```

### Available targets

| Target | Description |
|--------|-------------|
| `make` / `make all` | Builds the example |
| `make debug` | Builds with `-g -DDEBUG` |
| `make release` | Builds with `-O3` |
| `make run` | Runs the compiled example |
| `make test` | Builds and runs automated tests |
| `make clean` | Removes generated artifacts |

---

## Documentation

The [`docs/`](./docs) directory contains the full Portuguese documentation. The English documentation is available in [`docs/en/`](./docs/en):

- [ADT — Abstract Data Type](./docs/en/TAD.md)
- [Dynamic sequential list](./docs/en/List.md)
- [Circular queue](./docs/en/Queue.md)
- [Sequential stack](./docs/en/Stack.md)
- [Max heap and priority queue](./docs/en/Heap.md)
- [Binary Search Tree](./docs/en/Tree.md)
- [Graph with adjacency matrix](./docs/en/Graph.md)
- [Complexity and Big-O](./docs/en/Algorithms.md)
- [Computational cost and complexity](./docs/en/ComputationalCost.md)
- [Search methods for arrays](./docs/en/SearchMethods.md)
- [Sorting methods for arrays](./docs/en/SortingMethods.md)
- [Static vs. dynamic structures](./docs/en/StaticVsDynamic.md)

## Automated tests

Automated tests are organized in each module's `tests/` directory:

- `Lista/tests/test_lista.c`
- `Fila/tests/test_fila.c`
- `Pilha/tests/test_pilha.c`
- `Heap/tests/test_heap.c`
- `Árvore/tests/test_arvore.c`
- `Grafo/tests/test_grafo.c`
- `Métodos de Ordenação/tests/test_ordenacao.c`
- `Métodos de Busca/tests/test_busca.c`

The **Computational Cost and Complexity** directory is documentation-only, so it does not require automated tests.

---

## Contributing

1. Fork the repository.
2. Create a descriptive branch: `git checkout -b feat/my-structure`.
3. Follow the existing directory layout.
4. Add tests in `tests/`.
5. Ensure `make` and `make test` pass.
6. Open a pull request describing the changes.

Found a bug or have a suggestion? [Open an issue.](../../issues/new/choose)

---

## License

Distributed under the **Apache 2.0** license. See [LICENSE](./LICENSE) for more information.
