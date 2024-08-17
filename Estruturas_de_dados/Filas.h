#define MAX 100

struct aluno{
    int matricula;
    float n1, n2, n3;
    char nome[30];
};

typedef struct fila Fila;

Fila* Fila_criar();

void Fila_apagar(Fila* fi);

int Fila_cheia(Fila* fi);

int Fila_vazia(Fila* fi);

int Fila_tamanho(Fila* fi);

int Fila_inserir(Fila* fi, struct aluno al);

int Fila_remover(Fila* fi);

int Fila_consultar(Fila* fi, struct aluno *al);
