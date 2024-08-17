#include <stdlib.h>
#include <stdio.h>
#include "Filas.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};


Fila* Fila_criar(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void Fila_apagar(Fila* fi){
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = no->prox;
            free(no);
        }
        free(fi);
    }
}

int Fila_cheia(Fila* fi){
    return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == 0);
}

int Fila_tamanho(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return fi->qtd;
}

int Fila_inserir(Fila* fi, struct aluno al){
    if(fi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if(fi->inicio == NULL){
        fi->inicio = no;
    }
    else{
        fi->final->prox = no;
    }
    fi->final = no;
    fi->qtd++;
    return 1;
}

int Fila_remover(Fila* fi){
    if(fi == NULL || Fila_vazia(fi)){
        return 0;
    }
    Elem *no = fi->inicio;
    fi->inicio = no->prox;
    free(no);
    if(fi->inicio == NULL){
        fi->final = NULL;
    }
    fi->qtd--;
    return 1;
}

int Fila_consultar(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi)){
        return 0;
    }
    *al = fi->inicio->dados;
    return 1;
}
