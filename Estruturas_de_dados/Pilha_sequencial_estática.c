#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha{
    int dados[MAX];
    int qtd;
};

Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void apagar_pilha(Pilha* pi){
    free(pi);
}

int vazia_pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == 0);
}

int cheia_pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == MAX);
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }
    return pi->qtd;
}

int inserir_pilha(Pilha* pi, int num){
    if(pi == NULL || cheia_pilha(pi)){
        return 0;
    }
    pi->dados[pi->qtd] = num;
    pi->qtd++;
    return 1;
}

int remover_pilha(Pilha* pi){
    if(pi == NULL || cheia_pilha(pi)){
        return 0;
    }
    pi->qtd--;
    return 1;
}

int consultar_pilha(Pilha* pi, int *num){
    if(pi == NULL || cheia_pilha(pi)){
        return 0;
    }
    *num = pi->dados[pi->qtd-1];
    return 1;
}
