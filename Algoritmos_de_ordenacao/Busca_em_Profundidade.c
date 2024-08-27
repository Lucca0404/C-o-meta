void busca_profundidade(Grafo* ga, int inicio,int* visitado, int cont){
    int i;
    visitado[inicio] = cont;
    printf("%d", inicio);
    for(i = 0; i < ga->grau[inicio]; i++){
        if(!visitado[ga->arestas[inicio][i]]){
            busca_profundidade(ga, ga->arestas[inicio][i], visitado, cont+1);
        }
    }
}

void busca_profundidade_grafo(Grafo* ga, int inicio, int *visitado){
    int i, cont = 1;
    for(i = 0; i < ga->nro_vert; i++){
        visitado[i] = 0;
    }
    busca_profundidade(ga,inicio,visitado,cont);
}
