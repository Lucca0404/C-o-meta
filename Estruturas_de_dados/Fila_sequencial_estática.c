#include <stdlib.h>
#include <stdio.h>
#include "Filas.h"

struct fila{
    int inicio;
    int final;
    int qtd;
    struct aluno dados[MAX];
};

Fila* Fila_criar(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void Fila_apagar(Fila* fi){
    free(fi);
}

int Fila_cheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return (fi->qtd == MAX);
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
    if(fi == NULL || Fila_cheia(fi)){
        return 0;
    }
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;
    return 1;
}

int Fila_remover(Fila* fi){
    if(fi == NULL || Fila_vazia(fi)){
        return 0;
    }
    fi->inicio = (fi->inicio+1) % MAX;
    fi->qtd--;
    return 1;
}

int Fila_consultar(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi)){
        return 0;
    }
    *al = fi->dados[fi->inicio];
    return 1;
}
