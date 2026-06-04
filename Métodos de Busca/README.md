# Métodos de Busca para Vetores

Implementações de algoritmos clássicos de busca em vetores (`int[]`) em C,
com explicação, notação de complexidade e custo de acesso para cada método.

---

## Algoritmos implementados

| # | Algoritmo | Melhor | Médio | Pior | Espaço extra | Requer vetor ordenado |
|---|-----------|--------|-------|------|--------------|------------------------|
| 1 | Busca Linear | Ω(1) | O(n) | O(n) | O(1) | Não |
| 2 | Busca Binária | Ω(1) | O(log n) | O(log n) | O(1) | Sim |
| 3 | Busca por Salto (Jump Search) | Ω(1) | O(√n) | O(√n) | O(1) | Sim |
| 4 | Busca por Interpolação | Ω(1) | O(log log n) | O(n) | O(1) | Sim |
| 5 | Busca Exponencial | Ω(1) | O(log n) | O(log n) | O(1) | Sim |

---

## Explicação dos algoritmos

### 1. Busca Linear

Percorre o vetor do início ao fim até encontrar o valor.

**Custo no vetor:**
- Não exige ordenação prévia.
- Acessos sequenciais com boa localidade de cache.
- Em média verifica cerca de metade dos elementos.

---

### 2. Busca Binária

Em vetor ordenado, compara com o elemento do meio e descarta metade do intervalo a cada passo.

**Custo no vetor:**
- Exige vetor ordenado em ordem crescente.
- Reduz comparações para ordem logarítmica.
- Excelente para grandes vetores estáticos com muitas consultas.

---

### 3. Busca por Salto (Jump Search)

Salta blocos de tamanho aproximadamente `√n` e, ao ultrapassar o alvo,
faz busca linear apenas no bloco candidato.

**Custo no vetor:**
- Exige vetor ordenado.
- Menos comparações que busca linear em vetores grandes.
- Simples de implementar sem recursão.

---

### 4. Busca por Interpolação

Estima a posição provável do alvo usando a distribuição dos valores
(similar a uma regra de três), em vez de sempre usar o meio.

**Custo no vetor:**
- Exige vetor ordenado.
- Em dados quase uniformes, pode ser mais rápida que a binária.
- Em distribuição ruim, degrada para O(n).

---

### 5. Busca Exponencial

Expande rapidamente a faixa de busca em potências de 2 e, em seguida,
aplica busca binária apenas no intervalo encontrado.

**Custo no vetor:**
- Exige vetor ordenado.
- Eficiente quando o alvo tende a estar no começo do vetor.
- Boa opção para vetores muito grandes com tamanho conhecido.

---

## Estrutura do módulo

```
Métodos de Busca/
├── include/
│   └── busca.h      # API pública e enum BuscaMetodo
├── src/
│   ├── busca.c      # implementações dos cinco métodos
│   └── main.c       # exemplo executável
├── tests/
│   └── test_busca.c # testes automatizados
└── Makefile
```

---

## Como usar

```bash
cd "Métodos de Busca"
make            # compila o exemplo
make run        # executa o exemplo
make test       # executa os testes
make debug      # compila com -g -DDEBUG
make release    # compila com -O3
make clean      # remove artefatos
```

---

## API pública (`busca.h`)

```c
typedef enum {
    BUSCA_LINEAR = 0,
    BUSCA_BINARIA = 1,
    BUSCA_SALTO = 2,
    BUSCA_INTERPOLACAO = 3,
    BUSCA_EXPONENCIAL = 4
} BuscaMetodo;

int busca_procurar(const int *vetor, size_t n, int alvo, BuscaMetodo metodo, size_t *indice_encontrado);
const char *busca_nome(BuscaMetodo metodo);
const char *busca_complexidade(BuscaMetodo metodo);
const char *busca_requisito(BuscaMetodo metodo);
```

---

Voltar para o [índice da documentação](../docs/README.md).
