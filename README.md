# Estruturas de Dados em C

Repositório educacional com implementações básicas de estruturas de dados em C.

## Estruturas implementadas
- [Tipo Abstrato de Dados (TAD)](./TAD)
- [Lista](./Lista)
- [Fila](./Fila)
- [Árvore](./Árvore)
- [Grafo](./Grafo)

## Padrão de build (forçado)
Todos os módulos usam o mesmo padrão de `Makefile`, baseado no modelo solicitado, com:
- `include/` para cabeçalhos
- `src/` para fontes
- `build/` para artefatos

### Comandos disponíveis por módulo
- `make` ou `make all`
- `make debug`
- `make release`
- `make run`
- `make clean`
