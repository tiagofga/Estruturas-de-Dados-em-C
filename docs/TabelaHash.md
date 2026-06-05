# Tabela Hash — Encadeamento Separado

## Visão geral

Implementação de uma **tabela hash** em C usando **encadeamento separado** para tratamento de colisões. Cada balde da tabela armazena uma lista ligada de pares `(chave, valor)`.

O tipo `TabelaHash` é opaco no header público: o usuário manipula apenas ponteiros para a estrutura, sem acessar diretamente seus campos internos.

## Operações principais

```c
TabelaHash *tabela_hash_criar(size_t capacidade);
void tabela_hash_destruir(TabelaHash *tabela);
int tabela_hash_inserir(TabelaHash *tabela, int chave, int valor);
int tabela_hash_buscar(const TabelaHash *tabela, int chave, int *valor);
int tabela_hash_remover(TabelaHash *tabela, int chave);
int tabela_hash_contem(const TabelaHash *tabela, int chave);
size_t tabela_hash_tamanho(const TabelaHash *tabela);
double tabela_hash_fator_carga(const TabelaHash *tabela);
```

## Exemplo de uso

```c
TabelaHash *tabela = tabela_hash_criar(101);
if (tabela != NULL) {
    tabela_hash_inserir(tabela, 10, 100);
    tabela_hash_destruir(tabela);
}
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
