#include <stdlib.h>
#include <stdio.h>
#include "LSE.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* Lista_criar(){
    
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li == NULL){
        return NULL;
    }
    return li;
}

void Lista_apagar(Lista* li){
    free(li);
}

int Lista_tamanho(Lista* li){
    if(li == NULL){
        return -1;
    }
    return li->qtd;
}

int Lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == MAX);
}

int Lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == 0);
}

int Lista_busca_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }
    *al = li->dados[pos-1];
    return 1;
}

int Lista_busca_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL){
        return 0;
    }
    int i;
    for(i = 0; i < li->qtd; i++){
        if(li->dados[i].matricula == mat){
            *al = li->dados[i];
            return 1;
        }
    }
    return 0;
    
    return 1;
}

int Lista_insere_inicio(Lista* li, struct aluno al){
    if(li == NULL || Lista_cheia(li)){
        return 0;
    }
    int i;
    for(i = li->qtd-1; i >= 0; i--){
        li->dados[i+1] = li->dados[i]; 
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int Lista_insere_final(Lista* li, struct aluno al){
    if(li == NULL || Lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int Lista_insere_ordenada(Lista* li, struct aluno al){
    if(li == NULL || Lista_cheia(li)){
        return 0;
    }
    int i;
    int index = li->qtd;
    for(i = 0; i < li->qtd; i++){
        if(li->dados[i].matricula > al.matricula){
            index=i;
            break;
        }
    }
    for(i = li->qtd-1; i >= index; i--){
        li->dados[i+1] = li->dados[i]; 
    }
    li->dados[index] = al;
    li->qtd++;
    return 1;
}

int Lista_remove(Lista* li, int mat){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    int i;
    int index;
    for(i = 0; i < li->qtd; i++){
        if(li->dados[i].matricula == mat){
            index = i;
            break;
        }
    }
    if(i == li->qtd){
        return 0;
    }
    
    for(i = index; i < li->qtd; i++){
        li->dados[i] = li->dados[i+1];
    }
    li->qtd--;
    return 1;
}

int Lista_remove_inicio(Lista* li){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    int i;
    for(i = 0; i < li->qtd; i++){
        li->dados[i] = li->dados[i+1];
    }
    li->qtd--;
    return 1;
}

int Lista_remove_final(Lista* li){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    li->qtd--;
    return 1;
}
