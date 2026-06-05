.RECIPEPREFIX := >

MODULES := Lista Fila Pilha Arvore Grafo Heap TabelaHash ListaEncadeada ListaDuplamenteEncadeada GrafoListaAdjacencia AVL AlgoritmosGrafos MetodosOrdenacao MetodosBusca
SANITIZE_MODULES := TabelaHash ListaEncadeada ListaDuplamenteEncadeada GrafoListaAdjacencia AVL Heap AlgoritmosGrafos

.PHONY: all test sanitize coverage benchmark clean \
        run-lista run-fila run-pilha run-arvore run-grafo run-heap \
        run-tabela-hash run-lista-encadeada run-lista-dupla run-grafo-lista run-avl run-algoritmos-grafos \
        run-ordenacao run-busca

all:
>@for module in $(MODULES); do $(MAKE) -C "$$module" || exit 1; done

test:
>@for module in $(MODULES); do $(MAKE) -C "$$module" test || exit 1; done

sanitize:
>@for module in $(SANITIZE_MODULES); do $(MAKE) -C "$$module" sanitize || exit 1; done

coverage:
>bash scripts/coverage.sh

benchmark:
>$(MAKE) -C benchmarks run

clean:
>@for module in $(MODULES); do $(MAKE) -C "$$module" clean || exit 1; done
>-@$(MAKE) -C benchmarks clean
>-@rm -rf coverage

run-lista:
>$(MAKE) -C Lista run

run-fila:
>$(MAKE) -C Fila run

run-pilha:
>$(MAKE) -C Pilha run

run-arvore:
>$(MAKE) -C Arvore run

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

run-algoritmos-grafos:
>$(MAKE) -C AlgoritmosGrafos run

run-ordenacao:
>$(MAKE) -C MetodosOrdenacao run

run-busca:
>$(MAKE) -C MetodosBusca run
