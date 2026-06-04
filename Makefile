.RECIPEPREFIX := >

MODULES := Lista Fila Pilha Árvore Grafo Heap TabelaHash ListaEncadeada ListaDuplamenteEncadeada GrafoListaAdjacencia AVL
QUOTED_MODULES := "Métodos de Ordenação" "Métodos de Busca"

.PHONY: all test sanitize clean \
        run-lista run-fila run-pilha run-arvore run-grafo run-heap \
        run-tabela-hash run-lista-encadeada run-lista-dupla run-grafo-lista run-avl \
        run-ordenacao run-busca

all:
>@for module in $(MODULES); do $(MAKE) -C "$$module" || exit 1; done
>@for module in $(QUOTED_MODULES); do $(MAKE) -C "$$module" || exit 1; done

test:
>@for module in $(MODULES); do $(MAKE) -C "$$module" test || exit 1; done
>@for module in $(QUOTED_MODULES); do $(MAKE) -C "$$module" test || exit 1; done

sanitize:
>@for module in TabelaHash ListaEncadeada ListaDuplamenteEncadeada GrafoListaAdjacencia AVL Heap; do $(MAKE) -C "$$module" sanitize || exit 1; done

clean:
>@for module in $(MODULES); do $(MAKE) -C "$$module" clean || exit 1; done
>@for module in $(QUOTED_MODULES); do $(MAKE) -C "$$module" clean || exit 1; done

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

run-tabela-hash:
>$(MAKE) -C TabelaHash run

run-lista-encadeada:
>$(MAKE) -C ListaEncadeada run

run-lista-dupla:
>$(MAKE) -C ListaDuplamenteEncadeada run

run-grafo-lista:
>$(MAKE) -C GrafoListaAdjacencia run

run-avl:
>$(MAKE) -C AVL run

run-ordenacao:
>$(MAKE) -C "Métodos de Ordenação" run

run-busca:
>$(MAKE) -C "Métodos de Busca" run
