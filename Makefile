.RECIPEPREFIX := >

.PHONY: all test clean \
        run-lista run-fila run-pilha run-arvore run-grafo run-heap run-ordenacao run-busca

all:
>$(MAKE) -C Lista
>$(MAKE) -C Fila
>$(MAKE) -C Pilha
>$(MAKE) -C Árvore
>$(MAKE) -C Grafo
>$(MAKE) -C Heap
>$(MAKE) -C "Métodos de Ordenação"
>$(MAKE) -C "Métodos de Busca"

test:
>$(MAKE) -C Lista test
>$(MAKE) -C Fila test
>$(MAKE) -C Pilha test
>$(MAKE) -C Árvore test
>$(MAKE) -C Grafo test
>$(MAKE) -C Heap test
>$(MAKE) -C "Métodos de Ordenação" test
>$(MAKE) -C "Métodos de Busca" test

clean:
>$(MAKE) -C Lista clean
>$(MAKE) -C Fila clean
>$(MAKE) -C Pilha clean
>$(MAKE) -C Árvore clean
>$(MAKE) -C Grafo clean
>$(MAKE) -C Heap clean
>$(MAKE) -C "Métodos de Ordenação" clean
>$(MAKE) -C "Métodos de Busca" clean

run-lista:
>$(MAKE) -C Lista run

run-fila:
>$(MAKE) -C Fila run

run-pilha:
>$(MAKE) -C Pilha run

run-arvore:
>$(MAKE) -C Árvore run

run-grafo:
>$(MAKE) -C Grafo run

run-heap:
>$(MAKE) -C Heap run

run-ordenacao:
>$(MAKE) -C "Métodos de Ordenação" run

run-busca:
>$(MAKE) -C "Métodos de Busca" run
