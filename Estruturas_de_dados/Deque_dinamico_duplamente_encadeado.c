#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

struct elemento{
    struct elemento *prox;
    struct elemento *ant;
    int dados;
};

typedef struct elemento Elem;

struct deque{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Deque* Criar_deque(){
    Deque *de = (Deque*) malloc(sizeof(Deque));
    if(de != NULL){
        de->inicio = NULL;
        de->final = NULL;
        de->qtd = 0;
    }
    return de;
}

void Apagar_deque(Deque* de){
    if(de != NULL){
        Elem *no;
        while(de->inicio != NULL){
            no = de->inicio;
            de->inicio = no->prox;
            free(no);
        }
        free(de);
    }
}

int Vazio_deque(Deque* de){
    if(de == NULL || de->qtd == 0){
        return 1;
    }
    return 0;
}

int Cheio_deque(Deque* de){
    return 0;
}

int Tamanho_deque(Deque* de){
    if(de == NULL){
        return -1;
    }
    return de->qtd;
}

int Inserir_inicio_deque(Deque* de, int num){
    if(de == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    no->ant = NULL;
    no->prox = de->inicio;
    if(de->inicio != NULL){
        de->inicio->ant = no;
    }
    else{
        de->final = no;
    }
    de->inicio = no;
    de->qtd++;
    return 1;
}

int Inserir_final_deque(Deque* de, int num){
    if(de == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    no->prox = NULL;
    if(de->inicio == NULL){
        no->ant = NULL;
        de->inicio = no;
    }
    else{
        no->ant = de->final;
        de->final->prox = no;
    }
    de->final = no;
    de->qtd++;
    return 1;
}

int Remover_inicio_deque(Deque* de){
    if(de == NULL || Vazio_deque(de)){
        return 0;
    }
    Elem *no = de->inicio;
    de->inicio = no->prox;
    if(de->inicio != NULL){
        de->inicio->ant = NULL;
    }
    else{
        de->final = NULL;
    }
    free(no);
    de->qtd--;
    return 1;
}

int Remover_final_deque(Deque* de){
    if(de == NULL || Vazio_deque(de)){
        return 0;
    }
    if(de == NULL || Vazio_deque(de)){
        return 0;
    }
    Elem *no = de->final;
    de->final = no->ant;
    if(de->final != NULL){
        de->final->prox = NULL;
    }
    else{
        de->inicio = NULL;
    }
    free(no);
    de->qtd--;
    return 1;
}

int Consultar_inicio_deque(Deque* de, int *num){
    if(de == NULL || Vazio_deque(de)){
        return 0;
    }
    *num = de->inicio->dados;
    return 1;
}

int Consultar_final_deque(Deque* de, int *num){
    if(de == NULL || Vazio_deque(de)){
        return 0;
    }
    *num = de->final->dados;
    return 1;
}

int Printar_deque(Deque *de){
    if(de == NULL || Vazio_deque(de)){
        return 0;
    }
    Elem *no = de->inicio;
    while(no != NULL){
        printf("%d\n", no->dados);
        no = no->prox;
    }
    return 1;
}
