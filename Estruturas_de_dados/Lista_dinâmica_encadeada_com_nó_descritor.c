#include <stdlib.h>
#include <stdio.h>
#include "LDEN.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int tamanho;
};

Lista* Lista_criar(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->tamanho = 0;
        li->inicio = NULL;
        li->final = NULL;
    }
    return li;
}

void Lista_apagar(Lista* li){
    if(li != NULL){
        Elem *no = li->inicio;
        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int Lista_tamanho(Lista* li){
    if(li == NULL){
        return -1;
    }
    return li->tamanho;
}

int Lista_cheia(Lista* li){
    return 0;
}

int Lista_vazia(Lista* li){
    if(li->tamanho == 0 || li == NULL){
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
    no->prox = li->inicio;
    if(li->inicio == NULL){
        li->final = no;
    }
    li->inicio = no;
    li->tamanho++;
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
    if(li->inicio == NULL){
        li->inicio = no;
    }
    else{
        li->final->prox = no;
    }
    li->final = no;
    li->tamanho++;
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
    if(li->inicio == NULL){
        li->inicio = no;
        li->final = no;
        li->tamanho++;
        return 1;
    }
    else{
        Elem *aux = li->inicio;
        while(aux->prox != NULL && no->dados.matricula > aux->dados.matricula){
            aux = aux->prox;
        }
        if(aux->prox == NULL){
            aux->prox = no;
            no->prox = NULL;
            li->final = no;
        }
        else{
            no->prox = aux->prox;
            aux->prox = no;
        }
        li->tamanho++;
        return 1;
    }
}

int Lista_remove(Lista* li, int mat){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *ant, *no = li->inicio;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    ant->prox = no->prox;
    li->tamanho--;
    free(no);
    return 1;
}

int Lista_remove_inicio(Lista* li){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = li->inicio;
    if(no->prox == NULL){
        li->final = NULL;
    }
    li->inicio = no->prox;
    li->tamanho--;
    free(no);
    return 1;
}

int Lista_remove_final(Lista* li){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = li->final;
    li->final = NULL;
    if(no->prox == NULL){
        li->inicio = NULL;
    }
    li->tamanho--;
    free(no);
    return 1;
}

int Lista_busca_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0){
        return 0;
    }
    Elem *no = li->inicio;
    int i = 1;
    while(no != NULL || i < pos){
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
    if(li == NULL){
        return 0;
    }
    Elem *no = li->inicio;
    while(no != NULL || no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    *al = no->dados;
    return 1;
}
