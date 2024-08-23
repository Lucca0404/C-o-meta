#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

struct grafo{
    int eh_ponderado;
    int nro_vert;
    int Gmax;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* cria_grafo(int nro_vert, int Gmax, int eh_ponderado){
    Grafo *ga = (Grafo*) malloc(sizeof(Grafo));
    if(ga != NULL){
        int i;
        ga->nro_vert = nro_vert;
        ga->Gmax = Gmax;
        ga->eh_ponderado = (eh_ponderado != 0)? 1:0;
        ga->grau = (int*) calloc(ga->nro_vert, sizeof(int));
        
        ga->arestas = (int**) malloc(ga->nro_vert * sizeof(int*));
        for(i = 0; i < ga->nro_vert; i++){
            ga->arestas[i] = (int*) malloc(ga->Gmax * sizeof(int));
        }
        if(ga->eh_ponderado){
            ga->pesos = (float**) malloc(ga->nro_vert * sizeof(float*));
            for(i = 0; i < ga->nro_vert; i++){
                ga->pesos[i] = (float*) malloc(ga->Gmax * sizeof(float));
            }
        }
    }
    return ga;
}
    
void libera_grafo(Grafo* ga){
    if(ga != NULL){
        int i;
        for(i = 0; i < ga->nro_vert; i++){
            free(ga->arestas[i]);
        }
        free(ga->arestas);
        if(ga->eh_ponderado){
            for(i = 0; i < ga->nro_vert; i++){
                free(ga->pesos[i]);
            }
            free(ga->pesos);
        }
        free(ga->grau);
        free(ga);
    }
}

int insere_aresta(Grafo* ga, int orig, int dest, int digrafo, float peso){
    if(ga == NULL){
        return 0;
    }
    if(orig < 0 || orig >= ga->nro_vert){
        return 0;
    }
    if(dest < 0 || dest >= ga->nro_vert){
        return 0;
    }
    
    if(ga->grau[orig] == ga->Gmax){
        return 0;
    }
    
    ga->arestas[orig][ga->grau[orig]] = dest;
    if(ga->eh_ponderado){
        ga->pesos[orig][ga->grau[orig]] = peso;
    }
    ga->grau[orig]++;
    if(digrafo == 0){
        return insere_aresta(ga, dest, orig, 1, peso);
    }
    return 1;
}

int remove_aresta(Grafo* ga, int orig, int dest, int digrafo){
    if(ga == NULL){
        return 0;
    }
    if(orig < 0 || orig >= ga->nro_vert){
        return 0;
    }
    if(dest < 0 || dest >= ga->nro_vert){
        return 0;
    }
    
    int i = 0;
    while(i < ga->grau[orig] && ga->arestas[orig][i] != dest){
        i++;
    }
    if(i == ga->grau[orig]){
        return 0;
    }
    ga->grau[orig]--;
    ga->arestas[orig][i] = ga->arestas[orig][ga->grau[orig]];
    if(ga->eh_ponderado){
        ga->pesos[orig][i] = ga->pesos[orig][ga->grau[orig]];
    }
    if(digrafo == 0){
        remove_aresta(ga, dest, orig, 1);
    }
    return 1;
}
