#include <stdlib.h>
#include <math.h>
#include "Cubo.h"

struct cubo{
    float lado;
};

Cubo* Cubo_cria(float lado){
    Cubo *c = (Cubo*) malloc(sizeof(Cubo));
    
    c->lado = lado;
    return c;
}

void Cubo_libera(Cubo* c){
    free(c);
}

int Cubo_acessa(Cubo* c, float* lado){
    if(c == NULL){
        return 0;
    }
    *lado = c->lado;
    return 1;
}

int Cubo_atribui(Cubo* c, float lado){
    if(c == NULL){
        return 0;
    }
    c->lado = lado;
    return 1;
}

float Cubo_area(Cubo* c){
    if(c == NULL){
        return -1;
    }
    int num_de_lados = 6;
    float area = pow(c->lado,2) * num_de_lados;
    return area;
}

float Cubo_volume(Cubo* c){
    if(c == NULL){
        return -1;
    }
    float volume = pow(c->lado,3);
    return volume;
}
