
#include <stdlib.h>
#include <stdio.h>
#include "arvoreBin.h"

struct NO{
    int info;
    struct NO *dir;
    struct NO *esq;
};

ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL; 
    }
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL){
        return;
    }
    libera_NO(no->dir);
    libera_NO(no->esq);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
    if(raiz != NULL){
        libera_NO(*raiz);
        free(raiz);
    }
}

int vazia_ArvBin(ArvBin *raiz){
    return (*raiz == NULL || raiz == NULL);
}

int altura_ArvBin(ArvBin *raiz){
    if(vazia_ArvBin(raiz)){
        return 0;
    }
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    return (alt_dir > alt_esq)? alt_dir+1 : alt_esq+1;
}

int totalNo_ArvBin(ArvBin *raiz){
    if(vazia_ArvBin(raiz)){
        return 0;
    }
    int total_esq = totalNo_ArvBin(&((*raiz)->esq));
    int total_dir = totalNo_ArvBin(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }
        if(valor > ant->info){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }
            else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }
                else{
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(atual->info == valor){
            return 1;
        }
        else if(valor > atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}
