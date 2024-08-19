#include <stdlib.h>
#include <stdio.h>
#include "Fprio.h"

struct fpri{
    struct paciente dados[MAX];
    int qtd;
};

Fpri* Criar_fpri(){
    Fpri *fp = (Fpri*) malloc(sizeof(Fpri));
    if(fp != NULL){
        fp->qtd = 0;
    }
    return fp;
}

void Apagar_fpri(Fpri* fp){
    free(fp);
}

int Vazia_fpri(Fpri* fp){
    if(fp == NULL){
        return -1;
    }
    return (fp->qtd == 0);
}

int Cheia_fpri(Fpri* fp){
    if(fp == NULL){
        return -1;
    }
    return (fp->qtd == MAX);
}

int Tamanho_fpri(Fpri* fp){
    if(fp == NULL){
        return -1;
    }
    return fp->qtd;
}

int Inserir_fpri(Fpri* fp, struct paciente p){
    if(fp == NULL || Cheia_fpri(fp)){
        return 0;
    }
    int i, j, index;
    for(i = 0; i < fp->qtd; i++){
        if(p.prio < fp->dados[i].prio){
            index = i;
            break;
        }
    }
    for(i = fp->qtd; i > index; i--){
        fp->dados[i] = fp->dados[i-1];
    }
    fp->dados[index] = p;
    fp->qtd++;
    return 1;
}

int Remover_fpri(Fpri* fp){
    if(fp == NULL || Vazia_fpri(fp)){
        return 0;
    }
    fp->qtd--;
    return 1;
}

int Consultar_fpri(Fpri* fp, struct paciente *p){
    if(fp == NULL || Vazia_fpri(fp)){
        return 0;
    }
    *p = fp->dados[fp->qtd-1];
    return 1;
}

int Printar_fpri(Fpri* fp){
    if(fp == NULL || Vazia_fpri(fp)){
        return 0;
    }
    int i;
    for(i = 0; i < fp->qtd; i++){
        printf("%s\n", fp->dados[i].nome);
    }
    return 1;
}
