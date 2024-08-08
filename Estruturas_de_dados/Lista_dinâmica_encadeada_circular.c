#include <stdlib.h>
#include <stdio.h>
#include "LDEC.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* Lista_criar(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li = NULL;
    }
    return li;
}

void Lista_apagar(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(li);
        free(no);
    }
}

int Lista_tamanho(Lista* li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    int cont = 0;
    Elem *no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no->prox != (*li));
    return cont;
}

int Lista_cheia(Lista* li){
    return 0;
}

int Lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
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
    if((*li) == NULL){
        (*li) = no;
        no->prox = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
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
    if((*li) == NULL){
        (*li) = no;
        no->prox = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
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
        (*li) = no;
        no->prox = no;
        return 1;
    }
    else{
        if((*li)->dados.matricula > al.matricula){
            Elem *atual = *li;
            while(atual->prox != (*li)){
                atual = atual->prox;
            }
            no->prox = *li;
            atual->prox = no;
            *li = no;
            return 1;
        }
        else{
            Elem *ant = *li, *atual = (*li)->prox;
            while(atual != (*li) && atual->dados.matricula < al.matricula){
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = no;
            no->prox = atual;
            return 1;
        }
    }
}

int Lista_remove(Lista* li, int mat){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    if(no->dados.matricula == mat){
        if(no == no->prox){
            free(no);
            *li = NULL;
            return 1;
        }
    }
    else{
        Elem *ult = *li;
        while(ult->prox != (*li)){
            ult = ult->prox;
        }
        ult->prox = (*li)->prox;
        *li = (*li)->prox;
        free(no);
        return 1;
    }
    Elem *ant = no;
    no = no->prox;
        while(no != (*li) && no->dados.matricula != mat){
            ant = no;
            no = no->prox;
        }
        if(no == *li){
            return 0;
        }
        ant->prox = no->prox;
        free(no);
        return 1;
}

int Lista_remove_inicio(Lista* li){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
            while(atual->prox != (*li)){
                atual = atual->prox;
            }
            Elem *no = *li;
            atual->prox = no->prox;
            *li = no->prox;
            free(no);
            return 1;
}

int Lista_remove_final(Lista* li){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *atual = *li;
            while(atual->prox != (*li)){
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = atual->prox;
            free(atual);
            return 1;
}

int Lista_busca_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || Lista_vazia(li) || pos <= 0){
        return 0;
    }
    Elem *no = *li;
    int i = 1;
    while(no->prox != *li || i < pos){
        i++;
        no = no->prox;
    }
    if(i != pos){
        return 0;
    }
    *al = no->dados;
    return 1;
}

int Lista_busca_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    while(no->prox != *li || no->dados.matricula != mat){
        no = no->prox;
    }
    if(no->dados.matricula != mat){
        return 0;
    }
    *al = no->dados;
    return 1;
}
