# Estruturas de Dados em C

[![CI](https://github.com/tiagofga/Estruturas-de-Dados-em-C/actions/workflows/ci.yml/badge.svg)](https://github.com/tiagofga/Estruturas-de-Dados-em-C/actions/workflows/ci.yml)
![release](https://img.shields.io/badge/release-v0.1.0-orange)
[![license](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](./LICENSE)
![C](https://img.shields.io/badge/C-language-brightgreen)
![gcc](https://img.shields.io/badge/GCC-7%2B-informational)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](../../issues)
<br>
[![issues welcome](https://img.shields.io/badge/issues-welcome-brightgreen.svg)](../../issues)

Repositório educacional com implementações de estruturas de dados em C, cobrindo as
estruturas mais fundamentais com exemplos executáveis, testes automatizados e explicações
em cada módulo.

> **Dica:** A escolha da estrutura de dados certa é tão importante quanto o algoritmo.
> Cada estrutura tem um conjunto de operações e trade-offs de complexidade distintos.

---

## Estruturas implementadas

| Módulo | Documentação | Descrição | Complexidade de acesso |
|--------|-------------|-----------|------------------------|
| [TAD](./TAD) | [docs/TAD.md](./docs/TAD.md) | Tipo Abstrato de Dados — conceito de interface vs. implementação | — |
| [Lista](./Lista) | [docs/Lista.md](./docs/Lista.md) | Lista sequencial dinâmica com redimensionamento automático | O(1) fim, O(n) meio |
| [Fila](./Fila) | [docs/Fila.md](./docs/Fila.md) | Fila circular (FIFO) com capacidade fixa | O(1) enfileirar/desenfileirar |
| [Pilha](./Pilha) | [docs/Pilha.md](./docs/Pilha.md) | Pilha sequencial (LIFO) com capacidade fixa | O(1) empilhar/desempilhar |
| [Árvore](./Árvore) | [docs/Arvore.md](./docs/Arvore.md) | Árvore Binária de Busca (BST) + conceitos AVL/Rubro-Negra | O(log n) médio, O(n) pior |
| [Grafo](./Grafo) | [docs/Grafo.md](./docs/Grafo.md) | Grafo não-direcionado com matriz de adjacência + algoritmos clássicos | O(1) consulta de aresta |

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
cd Lista        # ou Fila, Pilha, Árvore, Grafo
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

## Documentação

A pasta [`docs/`](./docs) contém a documentação completa de cada módulo:

- [TAD — Tipo Abstrato de Dados](./docs/TAD.md)
- [Lista sequencial dinâmica](./docs/Lista.md)
- [Fila circular](./docs/Fila.md)
- [Pilha sequencial](./docs/Pilha.md)
- [Árvore Binária de Busca](./docs/Arvore.md)
- [Grafo com matriz de adjacência](./docs/Grafo.md)
- [Complexidade, busca e ordenação](./docs/Algoritmos.md)
- [Lista/Fila/Pilha estática vs dinâmica](./docs/EstaticoVsDinamico.md)

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
