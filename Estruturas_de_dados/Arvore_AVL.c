#include <stdlib.h>
#include <stdio.h>
#include "arvoreBin.h"

struct NO{
    int info;
    int alt;
    struct NO* esq;
    struct NO* dir;
};

ArvAVL* cria_ArvAVL(){
    ArvAVL *raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
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

void libera_ArvAVL(ArvAVL *raiz){
    if(raiz != NULL){
        libera_NO(*raiz);
        free(raiz);
    }
}

int vazia_ArvAVL(ArvAVL *raiz){
    return (*raiz == NULL || raiz == NULL);
}

int altura_ArvAVL(ArvAVL *raiz){
    if(vazia_ArvAVL(raiz)){
        return 0;
    }
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    return (alt_dir > alt_esq)? alt_dir+1 : alt_esq+1;
}

int totalNo_ArvAVL(ArvAVL *raiz){
    if(vazia_ArvAVL(raiz)){
        return 0;
    }
    int total_esq = totalNo_ArvAVL(&((*raiz)->esq));
    int total_dir = totalNo_ArvAVL(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int alt_NO(struct NO* no){
    if(no == NULL){
        return -1;
    }
    return no->alt;
}

int fator_balanceamento_no(struct NO* no){
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
    
}

int maior(int x, int y){
    if(x > y){
        return x;
    }
    else return y;
}

void rotacao_LL(ArvAVL *A){
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->alt = maior(alt_NO((*A)->esq), alt_NO((*A)->dir)) + 1;
    B->alt = maior(alt_NO(B->esq),(*A)->alt) + 1;
    *A = B;
}

void rotacao_RR(ArvAVL *A){
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = *A;
    (*A)->alt = maior(alt_NO((*A)->esq), alt_NO((*A)->dir)) + 1;
    B->alt = maior(alt_NO(B->dir),(*A)->alt) + 1;
    *A = B;
}

void rotacao_LR(ArvAVL *A){
    rotacao_RR(&(*A)->esq);
    rotacao_LL(A);
}

void rotacao_RL(ArvAVL *A){
    rotacao_LL(&(*A)->dir);
    rotacao_RR(A);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;
        }
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    
    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fator_balanceamento_no(atual) >= 2){
                if(valor < (*raiz)->esq->info){
                    rotacao_LL(raiz);
                }
                else{
                    rotacao_LR(raiz);
                }
            }
        }
    }
    else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fator_balanceamento_no(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        rotacao_RR(raiz);
                    }
                    else{
                        rotacao_RL(raiz);
                    }
                }
            }
        }
        else{
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    return res;
}

struct NO* procura_menor(struct NO *atual){
    struct NO *no1 = atual, *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
    if(*raiz == NULL){
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        if((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1){
            if(fator_balanceamento_no(*raiz) >= 2){
                if(alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir)){
                    rotacao_RR(raiz);
                }
                else{
                    rotacao_RL(raiz);
                }
            }
        }
    }
    if((*raiz)->info < valor){
        if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fator_balanceamento_no(*raiz) >= 2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
                    rotacao_LL(raiz);
                }
                else{
                    rotacao_LR(raiz);
                }
            }
        }
    }
    if((*raiz)->info == valor){
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            }
            else{
                *raiz = (*raiz)->dir;
            }
            free(oldNode);
        }
        else{
            struct NO* temp = procura_menor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fator_balanceamento_no(*raiz) >= 2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
                    rotacao_LL(raiz);
                }
                else{
                    rotacao_LR(raiz);
                }
            }
        }
        if(*raiz != NULL){
            (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
        }
        return 1;
    }
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    return res;
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
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

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}
