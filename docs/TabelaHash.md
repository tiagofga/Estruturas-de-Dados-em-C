# Tabela Hash — Encadeamento Separado

## Visão geral

Implementação de uma **tabela hash** em C usando **encadeamento separado** para tratamento de colisões. Cada balde da tabela armazena uma lista ligada de pares `(chave, valor)`.

## Operações principais

```c
int tabela_hash_criar(TabelaHash *tabela, size_t capacidade);
void tabela_hash_destruir(TabelaHash *tabela);
int tabela_hash_inserir(TabelaHash *tabela, int chave, int valor);
int tabela_hash_buscar(const TabelaHash *tabela, int chave, int *valor);
int tabela_hash_remover(TabelaHash *tabela, int chave);
int tabela_hash_contem(const TabelaHash *tabela, int chave);
```

## Complexidade

| Operação | Caso médio | Pior caso |
|----------|------------|-----------|
| Inserir | O(1) | O(n) |
| Buscar | O(1) | O(n) |
| Remover | O(1) | O(n) |
| Espaço | O(n + m) | O(n + m) |

`n` é o número de elementos e `m` é o número de baldes.

## Observações

O pior caso ocorre quando muitas chaves colidem no mesmo balde. O fator de carga ajuda a avaliar quando a tabela deve ser redimensionada.
