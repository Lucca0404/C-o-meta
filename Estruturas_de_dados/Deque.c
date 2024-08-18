#include <stdlib.h>
#include <stdio.h>
#include "Filas.h"

struct elemento{
    struct elemento *prox;
    int dados;
};

typedef struct elemento Elem;

struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* Criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void Apagar_fila(Fila* fi){
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

int Vazia_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    return (fi->inicio == NULL);
}

int Cheia_fila(Fila* fi){
    return 0;
}

int Tamanho_fila(Fila* fi){
    if(fi == NULL){
        return 0;
    }
    return (fi->qtd);
}

int Inserir_inicio_fila(Fila* fi, int num){
    if(fi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    no->prox = fi->inicio;
    fi->inicio = no;
    if(fi->final == NULL){
        fi->final = no;
    }
    fi->qtd++;
    return 1;
}

int Inserir_final_fila(Fila* fi, int num){
    if(fi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
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

int Remover_inicio_fila(Fila* fi){
    if(fi == NULL || Vazia_fila(fi)){
        return 0;
    }
    Elem *no = fi->inicio;
    fi->inicio = no->prox;
    if(fi->final = no){
        fi->final = NULL;
    }
    free(no);
    fi->qtd--;
    return 1;
}

int Remover_final_fila(Fila* fi){
    if(fi == NULL || Vazia_fila(fi)){
        return 0;
    }
    Elem *ant, *no = fi->inicio;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == fi->inicio){
        fi->inicio = NULL;
        fi->final = NULL;
    }
    else{
        ant->prox = NULL;
        fi->final = ant;
    }
    free(no);
    fi->qtd--;
    return 1;
}

int Consultar_inicio_fila(Fila* fi, int* num){
    if(fi == NULL || Vazia_fila(fi)){
        return 0;
    }
    *num = fi->inicio->dados;
    return 1;
}

int Consultar_final_fila(Fila* fi, int* num){
    if(fi == NULL || Vazia_fila(fi)){
        return 0;
    }
    *num = fi->final->dados;
    return 1;
}

int Printar_fila(Fila* fi){
    if(fi == NULL || Vazia_fila(fi)){
        return 0;
    }
    Elem *no = fi->inicio;
    while(no != NULL){
        printf("%d\n", no->dados);
        no = no->prox;
    }
    return 1;
}
