#include <stdlib.h>
#include <math.h>
#include "Conjunto.h"

struct conjunto {
    int num;
	int *numeros;
	int index;
};

Conjunto* Conjunto_cria() {
	Conjunto *c = (Conjunto*) malloc(sizeof(Conjunto));
	c->index = 0;
	c->numeros = &c->num;

	return c;
}

void Conjunto_apagar(Conjunto* c) {
	free(c);
}

int Conjunto_pertence(Conjunto* c, int num) {
	if(c == NULL) {
		return 0;
	}
	int i;
	for(i = 0; i <= c->index; i++) {
		if(c->numeros[i] == num) {
			return 1;
		}
	}
	return 0;
}

void Conjunto_inserir(Conjunto* c, int num) {
	if(c == NULL) {
		return;
	}
	if(Conjunto_pertence(c,num)) {
		return;
	}
	c->numeros[c->index] = num;
	c->index++;
}

void Conjunto_remover(Conjunto* c, int index) {
	if(c == NULL) {
		return;
	}
	int i;
	for(i = index; i < c->index; i++) {
		c->numeros[i] = c->numeros[i+1];
	}
	c->index--;
}

int Conjunto_menor_valor(Conjunto* c) {
	if(c == NULL) {
		return 0;
	}
	int menor = c->numeros[0];
	int i;
	for(i = 0; i < c->index; i++) {
		if(c->numeros[i] < menor) {
			menor = c->numeros[i];
		}
	}
	return menor;
}

int Conjunto_maior_valor(Conjunto* c){
    if(c == NULL) {
		return 0;
	}
	int maior = c->numeros[0];
	int i;
	for(i = 0; i < c->index; i++) {
		if(c->numeros[i] > maior) {
			maior = c->numeros[i];
		}
	}
	return maior;
}

int Conjunto_igualdade(Conjunto* c1, Conjunto* c2){
    if(c1->index != c2->index || c1 == NULL || c2 == NULL){
        return 0;
    }
    int i;
    int j;
    int cont = 0;
    for(i = 0; i < c1->index; i++){
        for(j = 0; j < c1->index; j++){
            if(c1->numeros[i] == c2->numeros[j]){
                cont++;
                break;
            }
        }
    }
    if(cont == c1->index){
        return 1;
    }
    return 0;
}

int Conjunto_tamanho(Conjunto* c){
    return c->index;
}

int Conjunto_vazio(Conjunto* c){
    if(c == NULL || c->index > 0){
        return 0;
    }
    return 1;
    
}

Conjunto* Conjunto_diferenca(Conjunto* c1, Conjunto* c2){
    if(c1 == NULL || c2 == NULL){
        return NULL;
    }
    Conjunto *c = Conjunto_cria();
    int i;
    int j;
    int flag = 0;
    for(i = 0; i < c1->index; i++){
        flag = 0;
        for(j = 0; j < c2->index; j++){
            if(c1->numeros[i] == c2->numeros[j]){
                flag = 1;
            }
        }
        if(!flag){
            Conjunto_inserir(c,c1->numeros[i]);
        }
    }
    
    return c;
}

Conjunto* Conjunto_interseccao(Conjunto* c1, Conjunto* c2){
    if(c1 == NULL || c2 == NULL){
        return NULL;
    }
    Conjunto *c = Conjunto_cria();;
    int i;
    int j;
    for(i = 0; i < c1->index; i++){
        for(j = 0; j < c2->index; j++){
            if(c1->numeros[i] == c2->numeros[j]){
                Conjunto_inserir(c,c1->numeros[i]);
                break;
            }
        }
    }
    
    return c;
}

Conjunto* Conjunto_uniao(Conjunto* c1, Conjunto* c2){
    if(c1 == NULL || c2 == NULL){
        return NULL;
    }
    Conjunto *c = Conjunto_cria();
    int i;
    int j;
    for(i = 0; i < c1->index; i++){
        Conjunto_inserir(c,c1->numeros[i]);
    }
    for(i = 0; i < c2->index; i++){
        Conjunto_inserir(c,c2->numeros[i]);
    }
    
    return c;
}
