#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

struct hash{
    struct aluno** itens;
    int qtd, TAMANHO;
};

Hash* cria_hash(int tamanho){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i = 0;
        ha->TAMANHO = tamanho;
        ha->itens = (struct aluno**) malloc(tamanho * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        for(i = 0; i < ha->TAMANHO; i++){
            ha->itens[i] = NULL;
        }
        ha->qtd = 0;
    }
    return ha;
}

void libera_hash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i = 0; i < ha->TAMANHO; i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int tamanho){
    return (chave & 0x7FFFFFFF) % tamanho;
}

int valor_string(char *str){
    int i, valor = 7;
    for(i = 0; i < strlen(str); i++){
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int insere_sem_colisao_hash(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TAMANHO){
        return 0;
    }
    int chave = valor_string(al.nome);
    int pos = chaveDivisao(chave, ha->TAMANHO);
    struct aluno *alvo = (struct aluno*) malloc(sizeof(struct aluno));
    if(alvo == NULL){
        return 0;
    }
    *alvo = al;
    ha->itens[pos] = alvo;
    ha->qtd++;
    return 1;
}

int busca_sem_colisao_hash(Hash* ha, char *str, struct aluno *al){
    if(ha == NULL){
        return 0;
    }
    int chave = valor_string(al.nome);
    int pos = chaveDivisao(chave, ha->TAMANHO);
    if(ha->itens[pos] == NULL){
        return 0;
    }
    *al = *(ha->itens[pos]);
    return 1;
}
