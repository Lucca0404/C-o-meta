#include <stdlib.h>
#include <stdio.h>
#include "LDE.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* Lista_criar(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void Lista_apagar(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int Lista_tamanho(Lista* li){
    if(li == NULL){
        return 0;
    }
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Lista_cheia(Lista* li){
    return 0;
}

int Lista_vazia(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int Lista_insere_inicio(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int Lista_insere_final(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if(*li == NULL){
        *li = no;
    }
    else{
        Elem* aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int Lista_insere_ordenada(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if(*li == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant = NULL, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }
        else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int Lista_remove_inicio(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int Lista_remove_final(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)){
        *li = no->prox;
    }
    else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int Lista_remove(Lista* li, int mat){
    if(li == NULL){
        return 0;
    }
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    
    if(no == (*li)){
        *li = no->prox;
    }
    else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int Lista_busca_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0){
        return 0;
    }
    Elem *no = *li;
    int i = 1;
    while(no != NULL || i < pos){
        no = no->prox;
        i++;
    }
    if(no != NULL){
        *al = no->dados;
        return 1;
    }
    else{
        return 0;
    }
}

int Lista_busca_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL || no->dados.matricula != mat){
        no = no->prox;
    }
    if(no != NULL){
        *al = no->dados;
        return 1;
    }
    else{
        return 0;
    }
}
