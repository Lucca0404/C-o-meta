#include <stdlib.h>
#include <math.h>
#include "Esfera.h"

#define PI 3.14159265359

struct esfera{
    float raio;
};

Esfera* Esfera_cria(float raio){
    Esfera* e = (Esfera*) malloc(sizeof(Esfera));
    
    e->raio = raio;
    return e;
}

void Esfera_libera(Esfera* e){
    free(e);
}

int Esfera_acessa(Esfera* e, float* raio){
    if(e == NULL){
        return 0;
    }
    *raio = e->raio;
    return 1;
}

int Esfera_atribui(Esfera* e, float raio){
    if(e == NULL){
        return 0;
    }
    e->raio = raio;
    return 1;
}

float Esfera_area(Esfera* e){
    if(e == NULL){
        return -1;
    }
    float area = PI * 4 * e->raio * e->raio;
    return area;
}

float Esfera_volume(Esfera* e){
    if(e == NULL){
        return -1;
    }
    float volume = PI * 4 * pow(e->raio,3) / 3;
    return volume;
}
