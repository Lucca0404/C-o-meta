#include <stdlib.h>
#include <stdio.h>
#include "Fprio.h"

struct fpri{
    struct paciente dados[MAX];
    int qtd;
};

Fpri* Criar_fpri(){
    Fpri* fp = (Fpri*) malloc(sizeof(Fpri));
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

void Promover_elemento(Fpri* fp, int filho){
    int pai;
    struct paciente temp;
    pai = (filho-1)/2;
    while(filho > 0 && fp->dados[pai].prio <= fp->dados[filho].prio){
        
        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;
        
        filho = pai;
        pai = (pai-1) /2;
    }
}

int Inserir_fpri(Fpri* fp, struct paciente p){
    if(fp == NULL || Cheia_fpri(fp)){
        return 0;
    }
    fp->dados[fp->qtd] = p;
    Promover_elemento(fp,fp->qtd);
    fp->qtd++;
}

void Rebaixar_elemento(Fpri* fp, int pai){
    struct paciente temp;
    int filho = 2 * pai + 1;
    while(filho < fp->qtd){
        if(filho < fp->qtd-1){
            if(fp->dados[filho].prio < fp->dados[filho+1].prio){
                filho++;
            }
        }
        if(fp->dados[pai].prio >= fp->dados[filho].prio){
            break;
        }
        
        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;
        
        pai = filho;
        filho = 2 * pai + 1;
    }
}

int Remover_fpri(Fpri* fp){
    if(fp == NULL || Vazia_fpri(fp)){
        return 0;
    }
    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    Rebaixar_elemento(fp,0);
    return 1;
}

int Consultar_fpri(Fpri* fp, struct paciente *p){
    if(fp == NULL || Vazia_fpri(fp)){
        return 0;
    }
    *p = fp->dados[0];
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
