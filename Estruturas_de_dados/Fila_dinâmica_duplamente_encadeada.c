#include <stdio.h>
#include <stdlib.h>
#include "Filas.h"

struct elemento{
    int dados;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Fila* Criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        *fi = NULL;
    }
}

void Apagar_fila(Fila* fi){
    if(fi != NULL){
        Elem *no;
        while(*fi != NULL){
            no = *fi;
            *fi = no->prox;
            free(no);
        }
        free(fi);
    }
}

int Vazia_fila(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (*fi == NULL);
}

int Cheia_fila(Fila* fi){
    return 0;
}

int Tamanho_fila(Fila* fi){
    if(fi == NULL || *fi == NULL){
        return 0;
    }
    Elem *no = *fi;
    int cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Inserir_fila(Fila* fi, int num){
    if(fi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    no->prox = NULL;
    if(*fi == NULL){
        *fi = no;
        no->ant = NULL;
        return 1;
    }
    Elem *aux = *fi;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = no;
    no->ant = aux;
    return 1;
}

int Remover_fila(Fila* fi){
    if(fi == NULL || *fi == NULL){
        return 0;
    }
    Elem *no = *fi;
    *fi = no->prox;
    if(*fi != NULL){
        (*fi)->ant = NULL;
    }
    free(no);
    return 1;
}

int Consulta_fila(Fila* fi, int* num){
    if(fi == NULL || *fi == NULL){
        return 0;
    }
    *num = (*fi)->dados;
    return 1;
}
