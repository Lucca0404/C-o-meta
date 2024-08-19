#define MAX 100

struct paciente{
    char nome[30];
    int prio;
};

typedef struct fpri Fpri;

typedef struct paciente paciente;

Fpri* Criar_fpri();

void Apagar_fpri(Fpri* fp);

int Vazia_fpri(Fpri* fp);

int Cheia_fpri(Fpri* fp);

int Tamanho_fpri(Fpri* fp);

int Inserir_fpri(Fpri* fp, struct paciente p);

int Remover_fpri(Fpri* fp);

int Consultar_fpri(Fpri* fp, struct paciente *p);

int Printar_fpri(Fpri* fp);
