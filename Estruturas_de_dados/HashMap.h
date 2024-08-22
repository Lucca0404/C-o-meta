struct aluno{
    int mat;
    char nome[30];
};

typedef struct hash Hash;

Hash* cria_hash(int tamanho);

void libera_hash(Hash* ha);

int valor_string(char *str);

int insere_sem_colisao_hash(Hash* ha, struct aluno al);

int busca_sem_colisao_hash(Hash* ha, int mat, struct aluno *al);
