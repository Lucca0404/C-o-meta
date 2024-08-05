#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include "Complexo.h"

struct complexo{
    float x;
    float y;
    float valor;
};

Complexo* Complexo_cria(float x, float y){
    Complexo* c = (Complexo*) malloc(sizeof(Complexo));
    c->x = x;
    c->y = y;
    c->valor = x + y*sqrt(I);
    
    return c;
}

void Complexo_libera(Complexo* c){
    free(c);
}

int Complexo_acessa(Complexo* c, float* x, float* y){
    if(c == NULL){
        return 0;
    }
    *x = c->x;
    *y = c->y;
    c->valor = c->x + c->y * sqrt(I);
    return 1;
}

int Complexo_atribui(Complexo* c, float x, float y){
    if(c == NULL){
        return 0;
    }
    c->x = x;
    c->y = y;
    c->valor = x + y * sqrt(I);
    return 1;
}

float Complexo_soma(Complexo* c1, Complexo* c2){
    if(c1 == NULL || c2 == NULL){
        return -1;
    }
    return c1->valor + c2-> valor;
}

float Complexo_subtracao(Complexo* c1, Complexo* c2){
    if(c1 == NULL || c2 == NULL){
        return -1;
    }
    return c1->valor - c2-> valor;
}

float Complexo_multiplicacao(Complexo* c1, Complexo* c2){
    if(c1 == NULL || c2 == NULL){
        return -1;
    }
    return c1->valor * c2-> valor;
}

float Complexo_divisao(Complexo* c1, Complexo* c2){
    if(c1 == NULL || c2 == NULL){
        return -1;
    }
    return c1->valor / c2-> valor;
}
