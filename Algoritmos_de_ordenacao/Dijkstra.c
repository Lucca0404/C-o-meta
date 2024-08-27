int procura_menor_distancia(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i = 0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }
            else{
                if(dist[menor] > dist[i]){
                    menor = i;
                }
            }
        }
    }
    return menor;
}

void menor_caminho_grafo(Grafo* ga, int inicio, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, vert;
    cont = NV = ga->nro_vert;
    visitado = (int*) malloc(sizeof(int) * NV);
    for(i = 0; i < NV; i++){
        visitado[i] = 0;
        ant[i] = -1;
        dist[i] = -1;
    }
    dist[inicio] = 0;
    while(cont > 0){
        vert = procura_menor_distancia(dist,visitado,NV);
        if(vert == -1){
            break;
        }
        visitado[vert] = 1;
        cont--;
        for(i = 0; i < ga->grau[vert]; i++){
            ind = ga->arestas[vert][i];
            if(dist[ind] < 0){
                dist[ind] = dist[vert] + 1;
                ant[ind] = vert;
            }
            else{
                if(dist[ind] > dist[vert] + 1){
                    dist[ind] = dist[vert] + 1;
                    ant[ind] = vert;
                }
            }
        }
    }
    free(visitado);
}
