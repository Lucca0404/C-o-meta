void busca_largura_grafo(Grafo* ga, int ini, int* visitados){
    int i, vert, NV, cont = 1;
    int *fila, IF = 0, FF = 0;
    for(i = 0; i < ga->nro_vert; i++){
        visitados[i] = 0;
    }
    NV = ga->nro_vert;
    fila = (int*) malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitados[ini] = cont;
    while(IF != FF){
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        for(i = 0; i < ga->grau[vert]; i++){
            if(!visitados[ga->arestas[vert][i]]){
                FF = (FF + 1) % NV;
                fila[FF] = ga->arestas[vert][i];
                visitados[ga->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}
