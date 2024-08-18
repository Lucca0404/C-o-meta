typedef struct descritor Fila;

Fila* Criar_fila();

void Apagar_fila(Fila* fi);

int Vazia_fila(Fila* fi);

int Cheia_fila(Fila* fi);

int Tamanho_fila(Fila* fi);

int Inserir_inicio_fila(Fila* fi, int num);

int Inserir_final_fila(Fila* fi, int num);

int Remover_inicio_fila(Fila* fi);

int Remover_final_fila(Fila* fi);

int Consultar_inicio_fila(Fila* fi, int* num);

int Consultar_final_fila(Fila* fi, int* num);

int Printar_fila(Fila* fi);
