# Estruturas de Dados em C

[![Licença](https://img.shields.io/badge/licen%C3%A7a-Apache%202.0-blue.svg)](./LICENSE)
[![Linguagem](https://img.shields.io/badge/linguagem-C-brightgreen.svg)]()

Repositório educacional com implementações de estruturas de dados em C, cobrindo as
estruturas mais fundamentais com exemplos executáveis, testes automatizados e explicações
em cada módulo.

> **Dica:** A escolha da estrutura de dados certa é tão importante quanto o algoritmo.
> Cada estrutura tem um conjunto de operações e trade-offs de complexidade distintos.

---

## Estruturas implementadas

| Módulo | Descrição | Complexidade de acesso |
|--------|-----------|------------------------|
| [TAD](./TAD) | Tipo Abstrato de Dados — conceito de interface vs. implementação | — |
| [Lista](./Lista) | Lista sequencial dinâmica com redimensionamento automático | O(1) fim, O(n) meio |
| [Fila](./Fila) | Fila circular (FIFO) com capacidade fixa | O(1) enfileirar/desenfileirar |
| [Árvore](./Árvore) | Árvore Binária de Busca (BST) | O(log n) médio, O(n) pior |
| [Grafo](./Grafo) | Grafo não-direcionado com matriz de adjacência | O(1) consulta de aresta |

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
git clone https://github.com/tiagofga/Estruturas-de-Dados-em-C.git
cd Estruturas-de-Dados-em-C
```

### Compilar e executar um módulo

```bash
cd Lista        # ou Fila, Árvore, Grafo
make            # compila
make run        # executa o exemplo
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

## Contribuindo

1. Faça um fork do repositório.
2. Crie uma branch descritiva: `git checkout -b feat/pilha`.
3. Implemente seguindo o padrão de estrutura de diretórios acima.
4. Adicione testes em `tests/`.
5. Garanta que `make` e `make test` passam sem erros.
6. Abra um pull request descrevendo as mudanças.

---

## Licença

Distribuído sob a licença **Apache 2.0**. Consulte [LICENSE](./LICENSE) para mais informações.
