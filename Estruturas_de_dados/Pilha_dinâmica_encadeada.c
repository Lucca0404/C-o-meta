#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct elemento{
    int dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void apagar_pilha(Pilha* pi){
    if(pi != NULL){
        Elem *no;
        while(*pi != NULL){
            no = *pi;
            *pi = no->prox;
            free(no);
        }
        free(pi);
    }
}

int vazia_pilha(Pilha* pi){
    if(pi == NULL || *pi == NULL){
        return 1;
    }
    return 0;
}

int cheia_pilha(Pilha* pi){
    return 0;
}

int tamanho_pilha(Pilha* pi){
    if(vazia_pilha(pi)){
        return 0;
    }
    Elem *no = *pi;
    int cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int inserir_pilha(Pilha* pi, int num){
    if(pi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    no->prox = *pi;
    *pi = no;
    return 1;
}

int remover_pilha(Pilha* pi){
    if(vazia_pilha(pi)){
        return 0;
    }
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int consultar_pilha(Pilha* pi, int *num){
    if(vazia_pilha(pi)){
        return 0;
    }
    Elem *no = *pi;
    *num = no->dados;
    return 1;
}
