#include "lista.h"
#include <stdio.h>

int ordenadacres(LISTA *lista){
    int i;
    if (vazia(lista)==1){
        return 0;
    }
    for (i=0;i<lista->fim-1;i++){
        if (lista->itens[i].valor > lista->itens[i+1].valor){
            return 0;
        }
        return 1;
    }
    return 0;
}

int ordenadadecres(LISTA *lista){
    int i;
    if (vazia(lista)==1){
        return 0;
    }
    for (i=0;i<lista->fim-1;i++){
        if (lista->itens[i].valor < lista->itens[i+1].valor){
            return 0;
        }
        return 1;
    }
    return 0;
}

int copia (LISTA *lista, LISTA *lista2, ITEM *item){
    int i;
    if (vazia(lista)==1){
        return 0;
    }
    criar(lista2);
    for (i=0;i<lista->fim;i++){
        *item = lista->itens[i];
        inserir_fim(lista2,item);
        return 0;
    }
    return 0;
}

int copia_repetir (LISTA *lista, LISTA *lista2, ITEM *item, int pos){
    int i;
    if (vazia(lista)==1){
        return 0;
    }
    criar(lista2);
    for (i=0;i<lista->fim;i++){
        if (lista->itens[i].valor == lista2->itens[i].valor){
            remover(lista2, pos);
            return 0;
        }
        else {
        
        *item = lista->itens[i];
        inserir_fim(lista2,item);
        return 0;
        }
    }
    return 0;
}

int inverterL1_L2 (LISTA *lista, LISTA *lista2, ITEM *item){
    int i;
    if (vazia(lista)==1){
        return 0;
    }
    for (i=lista->fim-1;i>=0;i--){
        lista->itens[lista->fim] = lista->itens[i];
        return 1;
    }
    *item = lista->itens[i];
    inserir_fim(lista2,item);
    return 0;
}

int inverterL1 (LISTA *lista, ITEM *item){
    int i;
    if (vazia(lista)==1){
        return 0;
    } 
    for (i=lista->fim-1;i>=0;i--){
        lista->itens[lista->fim] = lista->itens[i];
        return 1;
    }
    return 0;
}

int eliminar (LISTA *lista, ITEM *item, int chave){
    int i;
    if (vazia(lista)==1){
        return 0;
    }
    for (i=0;i<lista->fim;i++){
        if (lista->itens[i].chave == chave){
            remover(lista,i);
            return 1;
        }
    }
    return 0;
}

void criar(LISTA *lista){
    int i;
    for (i=0;i<TAM;i++){
        lista->itens[i].chave=i;
        lista->itens[i].valor=i;
    }
    lista->fim=0;
}

int recuperar_item(LISTA *lista, ITEM *item, int chave){
    if(vazia(lista)==1){
        return 0;
    }
    int i;
    for (i=0;i<lista->fim;i++){
        if (lista->itens[i].chave==chave){
            *item = lista->itens[i];
            return 1;
        }
    }
    return 0;
}

int vazia(LISTA *lista){
    if(lista->fim==0){
        return 1;
    }
    return 0;
}

int cheia(LISTA *lista){
    if(lista->fim==100){
        return 1;
    }
        return 0;
}

void imprimir(LISTA *lista){
    int i;
    for (i=0;i<TAM;i++){
        printf("Item %d: chave: %d valor: %d \n", i+1, lista->itens[i].chave, lista->itens[i].valor);
    }
}

int tamanho(LISTA *lista){
    return lista->fim;
}

int inserir_fim(LISTA *lista, ITEM *item){
    if (cheia(lista)==1){
        return 0;
    }else{
        lista->itens[lista->fim] = *item;
        lista->fim++;
    }
    return 1;
}

int inserir_posicao(LISTA *lista, ITEM *item, int pos){
    int i;
    if(!cheia(lista) && pos<= lista->fim+1){
        for(i=lista->fim; i>= pos; i--){
            lista->itens[i+1] = lista-> itens[i];
        }
        lista-> itens[pos]=*item;
        lista-> fim++;
        return 1;
    }else{
        return 0;
    }
}

int remover (LISTA *lista, int pos){
    int i;
    if (!vazia(lista) && pos<lista->fim){
        for (i=pos;i<lista->fim-1;i++){
            lista->itens[i]=lista->itens[i+1];
            lista->fim--;
        }
    }
    return 0;
}








