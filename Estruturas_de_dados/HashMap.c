#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash* cria_hash(int tamanho){
    Hash *ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
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

int chaveMultiplicacao(int chave, int tamanho){
    float A = 0.6180339887;
    float val = chave * A;
    return (int) (tamanho * val);
}

int sondaLinear(int pos, int i, int tamanho){
    return ((pos +i) & 0x7FFFFFFF) % tamanho;
}

int sondaQuadratica(int pos, int i, int tamanho){
    pos = pos + 2 * i + 5 * i * i;
    return (pos & 0x7FFFFFFF) % tamanho;
}

int duploHash(int H1, int chave, int i, int tamanho){
    int H2 = chaveDivisao(chave,tamanho-1) + 1;
    return ((H1 + i*H2) & 0x7FFFFFFF) % tamanho;
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

int busca_sem_colisao_hash(Hash* ha, char* nome, struct aluno *al){
    if(ha == NULL){
        return 0;
    }
    int chave = valor_string(nome);
    int pos = chaveDivisao(chave,ha->TABLE_SIZE);
    if(ha->itens[pos] == NULL){
        return 0;
    }
    *al = *(ha->itens[pos]);
    return 1;
}

int insere_hash_ender_aberto(Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
    }
    int chave = valor_string(al.nome);
    
    int i, pos, newpos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newpos = sondaLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newpos] == NULL){
            struct aluno* novo = (struct aluno*) malloc(sizeof(struct aluno));
            if(novo == NULL){
                return 0;
            }
            *novo = al;
            ha->itens[newpos] = novo;
            ha->qtd++;
            return 1;
        }
    }
}

int busca_ender_aberto_hash(Hash* ha, char* nome, struct aluno *al){
    if(ha == NULL){
        return 0;
    }
    int chave = valor_string(nome);
    
    int i, pos, newpos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(i = 0; i < ha->TABLE_SIZE; i++){
        newpos = sondaLinear(pos, i, ha->TABLE_SIZE);
        if(ha->itens[newpos] == NULL){
            return 0;
        }
        if(ha->itens[newpos]->nome == nome){
            *al = *(ha->itens[newpos]);
            return 1;
        }
    }
}
