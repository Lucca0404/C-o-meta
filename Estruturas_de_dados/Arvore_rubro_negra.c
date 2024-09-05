#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"

#define RED 1
#define BLACK 0

struct NO{
    int info;
    int cor;
    struct NO* esq;
    struct NO* dir;
};

typedef struct NO* ArvRN;

ArvRN* cria_ArvRN(){
    ArvRN *raiz = (ArvRN*) malloc(sizeof(ArvRN));
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

void libera_ArvRN(ArvRN *raiz){
    if(raiz != NULL){
        libera_NO(*raiz);
        free(raiz);
    }
}

int vazia_ArvRN(ArvRN *raiz){
    return (*raiz == NULL || raiz == NULL);
}

int altura_ArvRN(ArvRN *raiz){
    if(vazia_ArvRN(raiz)){
        return 0;
    }
    int alt_esq = altura_ArvRN(&((*raiz)->esq));
    int alt_dir = altura_ArvRN(&((*raiz)->dir));
    return (alt_dir > alt_esq)? alt_dir+1 : alt_esq+1;
}

int totalNo_ArvRN(ArvRN *raiz){
    if(vazia_ArvRN(raiz)){
        return 0;
    }
    int total_esq = totalNo_ArvRN(&((*raiz)->esq));
    int total_dir = totalNo_ArvRN(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int cor(struct NO* H){
    if(H == NULL){
        return BLACK;
    }
    return H->cor;
}

void trocaCor(struct NO* H){
    H->cor = !H->cor;
    if(H->esq != NULL){
        H->esq->cor = !H->esq->cor;
    }
    if(H->dir != NULL){
        H->dir->cor = !H->dir->cor;
    }
}

struct NO* rotacionaEsquerda(struct NO* A){
    struct NO* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* rotacionaDireita(struct NO* A){
    struct NO* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* move2EsqRed(struct NO* H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO* move2DirRed(struct NO* H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO* balancear(struct NO* H){
    if(cor(H->dir) == RED){
        H = rotacionaEsquerda(H);
    }
    
    if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    
    return H;
}

struct NO* insereNO(struct NO* H, int valor, int* resp){
    if(H == NULL){
        struct NO* novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }
        novo->info = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }
    if(valor == H->info){
        *resp = 0;
    }
    else{
        if(valor < H->info){
            H->esq = insereNO(H->esq,valor,resp);
        }
        else{
            H->dir = insereNO(H->dir,valor,resp);
        }
    }
    if(cor(H->dir) == RED && cor(H->esq) == BLACK){
        H = rotacionaEsquerda(H);
    }
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    return H;
}

int insere_ArvRN(ArvRN *raiz, int valor){
    int resp;
    *raiz = insereNO(*raiz,valor,&resp);
    if(*raiz != NULL){
        (*raiz)->cor = BLACK;
    }
    return resp;
}

struct NO* procura_menor(struct NO *atual){
    struct NO *no1 = atual, *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO* remove_menor(struct NO* H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
        H = move2EsqRed(H);
    }
    H->esq = remove_menor(H->esq);
    return balancear(H);
}

struct NO* removeNO(struct NO* H, int valor){
    if(valor < H->info){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
            H = move2EsqRed(H);
        }
        H->esq = removeNO(H->esq, valor);
    }
    else{
        if(cor(H->esq) == RED){
            H = rotacionaDireita(H);
        }
        if(valor == H->info && H->dir == NULL){
            free(H);
            return NULL;
        }
        
        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK){
            H = move2DirRed(H);
        }
        if(valor == H->info){
            struct NO* X = procura_menor(H->dir);
            H->info = X->info;
            H->dir = remove_menor(H->dir);
        }
        else{
            H->dir = removeNO(H->dir,valor);
        }
    }
    return balancear(H);
}

int remove_ArvRN(ArvRN *raiz, int valor){
    if(consulta_ArvRN(raiz,valor)){
        struct NO* h = *raiz;
        *raiz = removeNO(h,valor);
        if(*raiz != NULL){
            (*raiz)->cor = BLACK;
        }
        return 1;
    }
    else{
        return 0;
    }
}

int consulta_ArvRN(ArvRN *raiz, int valor){
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

void preOrdem_ArvRN(ArvRN *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvRN(&((*raiz)->esq));
        preOrdem_ArvRN(&((*raiz)->dir));
    }
}

void emOrdem_ArvRN(ArvRN *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvRN(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvRN(&((*raiz)->dir));
    }
}

void posOrdem_ArvRN(ArvRN *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvRN(&((*raiz)->esq));
        posOrdem_ArvRN(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}
