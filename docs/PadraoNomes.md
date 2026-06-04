# Política de nomes de módulos

## Objetivo

A partir desta versão, novos módulos devem usar nomes compatíveis com diferentes sistemas operacionais, terminais, scripts e ferramentas de CI.

## Padrão recomendado

Use nomes:

- em ASCII;
- sem acentos;
- sem espaços;
- em PascalCase para diretórios de módulos.

Exemplos recomendados:

- `TabelaHash`
- `ListaEncadeada`
- `ListaDuplamenteEncadeada`
- `GrafoListaAdjacencia`
- `AVL`

## Módulos antigos

Alguns módulos antigos ainda usam acentos ou espaços, como:

- `Árvore`
- `Métodos de Ordenação`
- `Métodos de Busca`
- `Custo Computacional e Complexidade`

Eles foram mantidos para evitar quebra de links, histórico e materiais já existentes. Uma renomeação completa pode ser feita em uma versão maior, com aliases ou documentação de migração.

## Justificativa

Nomes sem acentos e sem espaços reduzem problemas com:

- shells diferentes;
- scripts de build;
- GitHub Actions;
- Windows/Linux/macOS;
- ferramentas que não lidam bem com codificação UTF-8.
