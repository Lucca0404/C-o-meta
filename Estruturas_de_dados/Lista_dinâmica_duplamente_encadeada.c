#include <stdlib.h>
#include <stdio.h>
#include "LDDE.h"

struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* Lista_criar(){
    Lista* li = (Elem*) malloc(sizeof(Elem));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void Lista_apagar(Lista* li){
    if(li != NULL){
        Elem *no;
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
    Elem *no = *li;
    while(no->prox != *li){
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
    if((*li) == NULL){
        return 1;
    }
    return 0;
}

int Lista_insere_inicio(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->ant = NULL;
    no->prox = *li;
    if((*li) != NULL){
        (*li)->ant = no;
    }
    *li = no;
    return 1;
}

int Lista_insere_final(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        no->ant = NULL;
        *li = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != *li){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int Lista_insere_ordenada(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if((*li) == NULL){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *aux = *li;
        while(aux != NULL && aux->dados.matricula < al.matricula){
            ante = aux;
            aux = aux->prox;
        }
        if(atual == (*li)){
            no->ant = NULL;
            no->prox = *li;
            (*li)->ant = no;
            *li = no;
        }
        else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
        return 1;
    }
}

int Lista_remove(Lista* li, int mat){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no->ant == NULL){
        *li = no->prox;
    }
    else{
        no->ant->prox = no->prox;
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}

int Lista_remove_inicio(Lista* li){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    Elem *no = (*li);
    *li = no->prox;
    if(no->prox != NULL){
        no->prox->ant = NULL;
    }
    free(no);
    return 1;
}

int Lista_remove_final(Lista* li){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    Elem *no = (*li);
    while(no->prox != NULL){
        no = no->prox;
    }
    
    if(no->ant != NULL){
        no->ant->prox = NULL;
    }
    else{
        *li = no->prox;
    }
    free(no);
    return 1;
}

int Lista_busca_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || Lista_vazia(li)){
        return 0;
    }
    Elem *no = (*li);
    int i = 1;
    while(no != NULL || i < pos){
        no = no->prox;
        i++;
    }
    if(i != pos){
        return 0;
    }
    else{
        *al = no->dados;
        return 1;
    }
}

int Lista_busca_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    Elem *no = (*li);
    while(no != NULL || no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    else{
        *al = no->dados;
        return 1;
    }
}
