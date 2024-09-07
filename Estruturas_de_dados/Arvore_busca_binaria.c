#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
};

Arv* criar_Arv(){
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    if(arv != NULL){
        *arv = NULL;
    }
    return arv;
}

void libera_NO(struct NO* no){
    if(no == NULL){
        return;
    }
    else{
        libera_NO(no->dir);
        libera_NO(no->esq);
        free(no);
        no = NULL;
    }
}

void apagar_Arv(Arv* raiz){
    if(raiz != NULL){
        libera_NO(*raiz);
        free(raiz);
    }
}

int vazia_Arv(Arv* raiz){
    return (raiz == NULL || *raiz == NULL);
}

int altura_Arv(Arv* raiz){
    if(vazia_Arv(raiz)){
        return 0;
    }
    int alt_esq = altura_Arv(&(*raiz)->esq);
    int alt_dir = altura_Arv(&(*raiz)->dir);
    return (alt_dir > alt_esq)? alt_dir+1 : alt_esq+1;
}

int totalNO_Arv(Arv* raiz){
    if(vazia_Arv(raiz)){
        return 0;
    }
    int noEsq = totalNO_Arv(&(*raiz)->esq);
    int noDir = totalNO_Arv(&(*raiz)->dir);
    return (noEsq + noDir + 1);
}

int insere_Arv(Arv* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
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
    struct NO* no1, *no2;
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

int remove_Arv(Arv* raiz, int valor){
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

int consulta_Arv(Arv* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* no = *raiz;
    while(no != NULL){
        if(no->info == valor){
            return 1;
        }
        else{
            if(no->info < valor){
                no = no->dir;
            }
            else{
                no = no->esq;
            }
        }
    }
    return 0;
}

int preOrdem_Arv(Arv* raiz){
    if(*raiz == NULL){
        return 0;
    }
    printf("%d\n", (*raiz)->info);
    preOrdem_Arv(&(*raiz)->esq);
    preOrdem_Arv(&(*raiz)->dir);
}

int emOrdem_Arv(Arv* raiz){
    if(*raiz == NULL){
        return 0;
    }
    emOrdem_Arv(&((*raiz)->esq));
    printf("%d\n", (*raiz)->info);
    emOrdem_Arv(&((*raiz)->dir));
}

int posOrdem_Arv(Arv* raiz){
    if(*raiz == NULL){
        return 0;
    }
    posOrdem_Arv(&(*raiz)->esq);
    posOrdem_Arv(&(*raiz)->dir);
    printf("%d\n", (*raiz)->info);
}

int totalInter_Arv(Arv* raiz){
    if(vazia_Arv(raiz)){
        return 0;
    }
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
        return 0;
    }
    int noEsq = totalInter_Arv(&(*raiz)->esq);
    int noDir = totalInter_Arv(&(*raiz)->dir);
    return (noEsq + noDir + 1);
}

int totalFolha_Arv(Arv* raiz){
    if(vazia_Arv(raiz)){
        return 0;
    }
    int noEsq = totalFolha_Arv(&(*raiz)->esq);
    int noDir = totalFolha_Arv(&(*raiz)->dir);
    
    return (noEsq + noDir + (((*raiz)->esq == NULL && (*raiz)->dir == NULL)? 1:0));
}

int removerPares_Arv(Arv* raiz){
    if(vazia_Arv(raiz)){
        return 0;
    }
    removerPares_Arv(&(*raiz)->esq);
    removerPares_Arv(&(*raiz)->dir);
    if((*raiz)->info % 2 == 0){
        remove_Arv(raiz,(*raiz)->info);
    }
    return 1;
}

int ehBusca_Arv(Arv* raiz){
    if(raiz == NULL){
        return -1;
    }
    if((*raiz)->esq == NULL){
        return 1;
    }
    else{
        if((*raiz)->esq->info >= (*raiz)->info){
            return 0;
        }
    }
    if((*raiz)->dir == NULL){
        return 1;
    }
    else{
        if((*raiz)->dir->info < (*raiz)->info){
            return 0;
        }
    }
    ehBusca_Arv(&(*raiz)->esq);
    ehBusca_Arv(&(*raiz)->dir);
    return 1;
}

int maiorValor_Arv(Arv* raiz){
    if(vazia_Arv(raiz)){
        return 0;
    }
    struct NO *no = *raiz, *ant = no;
    while(no != NULL){
        ant = no;
        no = no->dir;
    }
    return ant->info;
}

int similares(Arv* raiz1, Arv* raiz2){
    if(totalNO_Arv(raiz1) != totalNO_Arv(raiz2)){
        return 0;
    }
    if(altura_Arv(raiz1) != altura_Arv(raiz2)){
        return 0;
    }
    if(vazia_Arv(raiz1) && vazia_Arv(raiz2)){
        return 1;
    }
    else{
        if(vazia_Arv(raiz1) || vazia_Arv(raiz2)){
            return 0;
        }
    }
    return (similares(&(*raiz1)->esq,&(*raiz2)->esq) && similares(&(*raiz1)->dir,&(*raiz2)->dir));
}

int iguais(Arv* raiz1, Arv* raiz2){
    if(vazia_Arv(raiz1) && vazia_Arv(raiz2)){
        return 1;
    }
    if(vazia_Arv(raiz1) || vazia_Arv(raiz2)){
        return 0;
    }
    if((*raiz1)->info != (*raiz2)->info){
        return 0;
    }
    return (iguais(&(*raiz1)->esq,&(*raiz2)->esq) && iguais(&(*raiz1)->dir,&(*raiz2)->dir));
}
