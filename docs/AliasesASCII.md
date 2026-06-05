# Aliases ASCII para módulos antigos

Alguns módulos antigos do repositório foram preservados com acentos ou espaços no nome para manter compatibilidade histórica com links e materiais já existentes.

Para facilitar o uso em terminais, scripts, CI e ambientes que lidam mal com acentuação, foram adicionados aliases com nomes ASCII.

| Diretório histórico | Alias ASCII | Situação |
|--------------------|-------------|----------|
| `Árvore` | `Arvore` | Alias compatível via Makefile |
| `Métodos de Ordenação` | `MetodosOrdenacao` | Alias compatível via Makefile |
| `Métodos de Busca` | `MetodosBusca` | Alias compatível via Makefile |

## Como usar

Em vez de:

```bash
make -C "Métodos de Ordenação" test
```

pode-se usar:

```bash
make -C MetodosOrdenacao test
```

## Política para novos módulos

Novos módulos devem usar apenas nomes ASCII, sem acentos e sem espaços. Exemplos:

- `AlgoritmosGrafos`
- `TabelaHash`
- `ListaEncadeada`
- `GrafoListaAdjacencia`

Os diretórios antigos não foram renomeados para evitar quebra de compatibilidade com links, aulas e referências externas.
