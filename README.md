# Estruturas de Dados e Algoritmos em C

[![CI](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml/badge.svg)](https://github.com/tiagofga/Estruturas-de-Dados-e-Algoritmos-em-C/actions/workflows/ci.yml)
![release](https://img.shields.io/badge/release-v0.2.0-orange)
[![license](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](./LICENSE)
![C](https://img.shields.io/badge/C-language-brightgreen)
![gcc](https://img.shields.io/badge/GCC-7%2B-informational)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](../../issues)
<br>
[![issues welcome](https://img.shields.io/badge/issues-welcome-brightgreen.svg)](../../issues)

Repositório educacional com implementações de estruturas de dados e algoritmos em C, cobrindo estruturas fundamentais com exemplos executáveis, testes automatizados e documentação por módulo.

> **Dica:** a escolha da estrutura de dados certa é tão importante quanto o algoritmo.
> Cada estrutura tem um conjunto de operações e trade-offs de complexidade distintos.

---

## Estruturas e algoritmos implementados

| Módulo | Documentação | Descrição | Complexidade principal |
|--------|-------------|-----------|------------------------|
| [TAD](./TAD) | [docs/TAD.md](./docs/TAD.md) | Tipo Abstrato de Dados — conceito de interface vs. implementação | — |
| [Lista](./Lista) | [docs/Lista.md](./docs/Lista.md) | Lista sequencial dinâmica com busca linear/binária e ordenação configurável | O(1) fim, O(n) meio |
| [Fila](./Fila) | [docs/Fila.md](./docs/Fila.md) | Fila circular (FIFO) com capacidade fixa | O(1) enfileirar/desenfileirar |
| [Pilha](./Pilha) | [docs/Pilha.md](./docs/Pilha.md) | Pilha sequencial (LIFO) com capacidade fixa | O(1) empilhar/desempilhar |
| [Heap](./Heap) | [docs/Heap.md](./docs/Heap.md) | Heap máximo dinâmico, fila de prioridade e Heap Sort | O(1) consultar raiz, O(log n) inserir/remover |
| [Árvore](./Árvore) | [docs/Arvore.md](./docs/Arvore.md) | Árvore Binária de Busca (BST) + conceitos AVL/Rubro-Negra | O(log n) médio, O(n) pior |
| [Grafo](./Grafo) | [docs/Grafo.md](./docs/Grafo.md) | Grafo direcionado/não-direcionado com matriz de adjacência + BFS/DFS/Dijkstra/topológica | O(1) consulta de aresta |
| [Métodos de Ordenação](./Métodos%20de%20Ordenação) | [docs/MetodosOrdenacao.md](./docs/MetodosOrdenacao.md) | Bubble, Insertion, Selection, Merge, Quick e Heap Sort para vetores | O(n²) a O(n log n) |
| [Métodos de Busca](./Métodos%20de%20Busca) | [docs/MetodosBusca.md](./docs/MetodosBusca.md) | Busca Linear, Binária, por Salto, por Interpolação e Exponencial para vetores | O(n) a O(log n) |
| [Custo Computacional e Complexidade](./Custo%20Computacional%20e%20Complexidade) | [docs/CustoComputacional.md](./docs/CustoComputacional.md) | Introdução ao custo de tempo/espaço, ordens de crescimento e análise assintótica | O(1) a O(2ⁿ) |

---

## Pré-requisitos

- GCC 7 ou superior
- GNU Make

```bash
gcc --version
make --version
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
make clean
```

### Compilar e executar um módulo

```bash
cd Lista        # ou Fila, Pilha, Heap, Árvore, Grafo
make            # compila
make run        # executa o exemplo dinâmico
make run_static # executa o exemplo estático (Lista/Fila/Pilha)
make test       # executa os testes
make clean      # remove artefatos
```

### Compilar com símbolos de depuração

```bash
make debug
make run
```

### Compilar com otimização máxima

```bash
make release
make run
```

---

## Padrão de build

Todos os módulos seguem o mesmo padrão de `Makefile`, com:

```
<Módulo>/
├── include/        # cabeçalhos públicos (.h)
├── src/            # implementações (.c) + main.c de exemplo
├── tests/          # testes automatizados
├── build/          # artefatos gerados (ignorado pelo git)
│   ├── app         # executável de exemplo
│   ├── test_runner # executável de testes
│   └── objects/    # arquivos objeto
└── Makefile
```

### Alvos disponíveis

| Alvo | Descrição |
|------|-----------|
| `make` / `make all` | Compila o exemplo |
| `make debug` | Compila com `-g -DDEBUG` |
| `make release` | Compila com `-O3` |
| `make run` | Executa o exemplo compilado |
| `make test` | Compila e executa os testes |
| `make clean` | Remove todos os artefatos |

---

## Documentação

A pasta [`docs/`](./docs) contém a documentação completa de cada módulo:

- [TAD — Tipo Abstrato de Dados](./docs/TAD.md)
- [Lista sequencial dinâmica](./docs/Lista.md)
- [Fila circular](./docs/Fila.md)
- [Pilha sequencial](./docs/Pilha.md)
- [Heap máximo e fila de prioridade](./docs/Heap.md)
- [Árvore Binária de Busca](./docs/Arvore.md)
- [Grafo com matriz de adjacência](./docs/Grafo.md)
- [Complexidade (Big-O)](./docs/Algoritmos.md#notação-de-complexidade-big-o)
- [Custo computacional e complexidade](./docs/CustoComputacional.md)
- [Métodos de busca para vetores](./docs/MetodosBusca.md)
- [Métodos de ordenação para vetores](./docs/MetodosOrdenacao.md)
- [Lista/Fila/Pilha estática vs dinâmica](./docs/EstaticoVsDinamico.md)

## Testes automatizados

Os testes do projeto já existem e estão organizados nas pastas `tests/` de cada módulo implementado:

- `Lista/tests/test_lista.c`
- `Fila/tests/test_fila.c`
- `Pilha/tests/test_pilha.c`
- `Heap/tests/test_heap.c`
- `Árvore/tests/test_arvore.c`
- `Grafo/tests/test_grafo.c`
- `Métodos de Ordenação/tests/test_ordenacao.c`
- `Métodos de Busca/tests/test_busca.c`

Como a pasta **Custo Computacional e Complexidade** é apenas documental, ela não precisa de testes automatizados próprios.

---

## Contribuindo

1. Faça um fork do repositório.
2. Crie uma branch descritiva: `git checkout -b feat/minha-estrutura`.
3. Implemente seguindo o padrão de estrutura de diretórios acima.
4. Adicione testes em `tests/`.
5. Garanta que `make` e `make test` passam sem erros.
6. Abra um pull request descrevendo as mudanças.

Encontrou um bug ou tem uma sugestão? [Abra uma issue!](../../issues/new/choose)

---

## Licença

Distribuído sob a licença **Apache 2.0**. Consulte [LICENSE](./LICENSE) para mais informações.
