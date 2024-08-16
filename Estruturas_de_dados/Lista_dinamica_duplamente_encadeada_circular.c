#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

struct elemento{
    int dados;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Lista* Lista_criar(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void Lista_apagar(Lista* li){
    if(li != NULL && *li != NULL){
        Elem *aux, *no = *li;
        while(no->prox != *li){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int Lista_cheia(Lista* li){
    return 0;
}

int Lista_vazia(Lista* li){
    if(li == NULL || *li == NULL){
        return 1;
    }
    return 0;
}

int Lista_tamanho(Lista* li){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    int cont = 0;
    do{
        cont++;
        no = no->prox;
    }while(no != *li);
    return cont;
}

int Lista_inserir_inicio(Lista* li, int num){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    if(*li == NULL){
        *li = no;
        no->prox = no;
        no->ant = no;
        return 1;
    }
    Elem *aux = *li;
    no->prox = aux;
    no->ant = aux->ant;
    aux->ant = no;
    if(aux-> prox == aux){
        aux->prox = no;
    }
    *li = no;
    return 1;
}

int Lista_inserir_final(Lista* li, int num){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    if(*li == NULL){
        *li = no;
        no->prox = no;
        no->ant = no;
        return 1;
    }
    Elem *aux = *li;
    no->prox = aux;
    no->ant = aux->ant;
    aux->ant = no;
    if(aux-> prox == aux){
        aux->prox = no;
    }
    return 1;
}

int Lista_inserir_ordenada(Lista* li, int num){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = num;
    if(*li == NULL){
        *li = no;
        no->prox = no;
        no->ant = no;
        return 1;
    }
    if((*li)->dados > num){
        Elem *aux2 = *li;
        no->prox = aux2;
        no->ant = aux2->ant;
        aux2->ant = no;
        if(aux2-> prox == aux2){
            aux2->prox = no;
        }
        *li = no;
    }
    else{
        Elem *aux = *li;
        while(aux->prox != *li && aux->dados < num){
            aux = aux->prox;
        }
        no->prox = aux->prox;
        aux->prox->ant = no;
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int Lista_remover_inicio(Lista* li){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    if((*li)->prox == *li){
        *li = NULL;
        free(no);
        return 1;
    }
    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    *li = no->prox;
    free(no);
    return 1;
}

int Lista_remover_final(Lista* li){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    if((*li)->prox == *li){
        *li = NULL;
        free(no);
        return 1;
    }
    Elem *aux = no->ant;
    aux->ant->prox = no;
    no->ant = aux->ant;
    free(aux);
    return 1;
}

int Lista_remover(Lista* li, int num){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    if(no->dados == num){
        if(no->prox == no){
            *li = NULL;
            free(no);
            return 1;
        }
        else{
            no->ant->prox = no->prox;
            no->prox->ant = no->ant;
            *li = no->prox;
            free(no);
            return 1;
        }
            
    }
    while(no->prox != *li && no->dados != num){
        no = no->prox;
    }
    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
    return 1;
}

int Lista_busca_pos(Lista* li, int pos){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    
    while(no->prox != *li && no->dados != num){
        no = no->prox;
    }
    if(no->dados != num){
        return 0;
    }
    *num = no->dados;
    return 1;
}

int Lista_printar(Lista* li){
    if(Lista_vazia(li)){
        return 0;
    }
    Elem *no = *li;
    do{
        printf("%d\n", no->dados);
        no = no->prox;
    }while(no != *li);
    return 1;
}
