# Benchmarks

Este repositório inclui um benchmark simples e reprodutível para medir operações representativas em módulos centrais.

## Como executar

```bash
make benchmark
```

ou diretamente:

```bash
cd benchmarks
make run
```

## Saída

A saída segue formato CSV:

```text
module,size,operation,time_ms
AVL,5000,insert+search+remove_half,1.234
TabelaHash,5000,insert+search+remove_half,0.456
Kruskal,200,mst_edges_600_ok_1,0.789
```

## Módulos avaliados

| Módulo | Operação medida |
|--------|-----------------|
| AVL | Inserção, busca e remoção de metade dos elementos |
| TabelaHash | Inserção, busca e remoção de metade dos elementos |
| AlgoritmosGrafos | Kruskal em grafo ponderado sintético |

## Observações

O benchmark usa `clock()` da biblioteca padrão C. Ele é adequado para comparação didática e análise relativa, mas não substitui ferramentas profissionais como `perf`, `hyperfine` ou suites estatísticas de microbenchmark.
