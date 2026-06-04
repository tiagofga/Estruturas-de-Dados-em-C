#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stddef.h>

typedef struct TabelaHashItem {
    int chave;
    int valor;
    struct TabelaHashItem *proximo;
} TabelaHashItem;

typedef struct {
    TabelaHashItem **baldes;
    size_t capacidade;
    size_t tamanho;
} TabelaHash;

int tabela_hash_criar(TabelaHash *tabela, size_t capacidade);
void tabela_hash_destruir(TabelaHash *tabela);
int tabela_hash_inserir(TabelaHash *tabela, int chave, int valor);
int tabela_hash_buscar(const TabelaHash *tabela, int chave, int *valor);
int tabela_hash_remover(TabelaHash *tabela, int chave);
int tabela_hash_contem(const TabelaHash *tabela, int chave);
size_t tabela_hash_tamanho(const TabelaHash *tabela);
double tabela_hash_fator_carga(const TabelaHash *tabela);
void tabela_hash_imprimir(const TabelaHash *tabela);
const char *tabela_hash_complexidade(void);

#endif
