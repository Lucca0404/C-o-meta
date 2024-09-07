#include <stdlib.h>
#include <stdio.h>
#include "skiplist.h"

struct NO{
    int dados;
    struct NO **prox;
};

struct SkipList{
    int NivelMAX;
    float p;
    int nivel;
    struct NO* inicio;
};

struct NO* novoNO(int num, int nivel){
    struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo != NULL){
        novo->dados = num;
        novo->prox = (struct NO**) malloc((nivel+1) * sizeof(struct NO*));
        int i;
        for(i = 0; i < nivel+1; i++){
            novo->prox[i] = NULL;
        }
    }
    return novo;
}

SkipList* cria_SkipList(int MAXLVL, float p){
    SkipList* sk = (SkipList*) malloc(sizeof(SkipList));
    if(sk != NULL){
        sk->NivelMAX = MAXLVL;
        sk->p = p;
        sk->nivel = 0;
        sk->inicio = novoNO(-1, MAXLVL);
    }
    return sk;
}

void apaga_SkipList(SkipList* sk){
    if(sk != NULL){
        struct NO *no, *atual;
        atual = sk->inicio->prox[0];
        while(atual != NULL){
            no = atual;
            atual = atual->prox[0];
            free(no->prox);
            free(no);
        }
        free(sk->inicio);
        free(sk);
    }
}

int vazia_SkipList(SkipList* sk){
    return (sk == NULL || sk->inicio->prox[0] == NULL);
}

int tamanho_SkipList(SkipList* sk){
    if(vazia_SkipList(sk)){
        return 0;
    }
    struct NO* atual = sk->inicio->prox[0];
    int cont = 0;
    while(atual != NULL){
        cont++;
        atual = atual->prox[0];
    }
    return cont;
}

int sorteio(SkipList* sk){
    float r = (float) rand()/ RAND_MAX;
    int nivel = 0;
    while(r < sk->p && nivel < sk->NivelMAX){
        nivel++;
        r = (float) rand()/ RAND_MAX;
    }
    return nivel;
}

int insere_SkipList(SkipList* sk, int num){
    if(sk == NULL){
        return 0;
    }
    int i;
    struct NO **aux;
    aux = (struct NO**) malloc(sk->NivelMAX+1 * sizeof(struct NO*));
    for(i = 0; i < sk->NivelMAX+1; i++){
        aux[i] = NULL;
    }
    struct NO* atual = sk->inicio;
    for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->dados < num){
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }
    atual = atual->prox[0];
    if(atual == NULL || atual->dados != num){
        int novo_nivel = sorteio(sk);
        struct NO* novo = novoNO(num, novo_nivel);
        if(novo == NULL){
            free(aux);
            return 0;
        }
        if(novo_nivel > sk->nivel){
            for(i = sk->nivel+1; i <= novo_nivel; i++){
                aux[i] = sk->inicio;
            }
            sk->nivel = novo_nivel;
        }
        
        for(i = 0; i <= novo_nivel; i++){
            novo->prox[i] = aux[i]->prox[i];
            aux[i]->prox[i] = novo;
        }
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

int remove_SkipList(SkipList* sk, int num){
    if(sk == NULL){
        return 0;
    }
    int i;
    struct NO** aux;
    aux = (struct NO**) malloc(sizeof(struct NO*) * sk->NivelMAX+1);
    for(i = 0; i < sk->NivelMAX+1; i++){
        aux[i] = NULL;
    }
    struct NO* atual = sk->inicio;
    for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->dados < num){
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }
    atual = atual->prox[0];
    if(atual != NULL && atual->dados == num){
        for(i = 0; i < sk->nivel; i++){
            if(aux[i]->prox[i] != atual){
                break;
            }
            aux[i]->prox[i] = atual->prox[i];
        }
        while(sk->nivel > 0 && sk->inicio->prox[sk->nivel] == NULL){
            sk->nivel--;
        }
        free(atual->prox);
        free(atual);
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

int  consulta_SkipList(SkipList* sk, int num){
    if(sk == NULL){
        return 0;
    }
    struct NO* atual = sk->inicio;
    int i;
    for(i = sk->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->dados < num){
            atual = atual->prox[i];
        }
    }
    atual = atual->prox[0];
    if(atual != NULL && atual->dados == num){
        return 1;
    }
    return 0;
}

