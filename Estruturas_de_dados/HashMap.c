#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
}

Hash* cria_hash(int tamanho){
    Hash *ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = tamanho;
        ha->itens = (struct aluno**) malloc(ha->TABLE_SIZE * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i = 0; i < ha->TABLE_SIZE; i ++){
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

int chaveDivisao(int chave, int tamanho){
    return (chave & 0x7FFFFFFF) % tamanho;
}

void libera_hash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i = 0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int valor_string(char *str){
    int i, valor = 7;
    int tamanho = strlen(str);
    for(i = 0; i < tamanho; i++){
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int insere_sem_colisao_hash(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    
    int chave = valor_string(al.nome);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);
    
    struct aluno* novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL){
        return 0;
    }
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int busca_sem_colisao_hash(Hash* ha, int mat, struct aluno *al){
    if(ha == NULL){
        return 0;
    }
    int chave = valor_string(al.nome);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        return 0;
    }
    alvo = ha->itens[pos]
    *al = *alvo;
    return 1;
}
