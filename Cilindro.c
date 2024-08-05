#include <stdlib.h>
#include <math.h>
#include "Cilindro.h"

#define PI 3.14159265358979323846

struct cilindro{
    float altura;
    float raio;
};

Cilindro* Cilindro_cria(float altura, float raio){
    Cilindro* c = (Cilindro*) malloc(sizeof(Cilindro));
    
    c->altura = altura;
    c->raio = raio;
    
    return c;
}

void Cilindro_libera(Cilindro* c){
    free(c);
}

int Cilindro_acessa(Cilindro* c, float* altura, float* raio){
    if(c == NULL){
        return 0;
    }
    
    *altura = c->altura;
    *raio = c->raio;
    return 1;
}

int Cilidro_atribui(Cilindro* c, float altura, float raio){
    if(c == NULL){
        return 0;
    }
    c->altura = altura;
    c->raio = raio;
    return 1;
}

float Cilindro_area(Cilindro* c){
    if(c == NULL){
        return -1;
    }
    float area = (2*PI*c->raio)* c->altura + PI*pow(c->raio,2) *2;
    return area;
}

float Cilindro_volume(Cilindro* c){
    if(c == NULL){
        return -1;
    }
    float volume = PI*pow(c->raio,2) * c->altura;
    return volume;
}

float Cilindro_raio(Cilindro* c){
    if(c == NULL){
        return 0;
    }
    return c->raio;
}

float Cilindro_altura(Cilindro* c){
    if(c == NULL){
        return 0;
    }
    return c->altura;
}
