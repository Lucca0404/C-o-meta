struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* Lista_criar();

void Lista_apagar(Lista* li);

int Lista_busca_pos(Lista* li, int pos, struct aluno *al);

int Lista_busca_mat(Lista* li, int mat, struct aluno *al);

int Lista_insere_inicio(Lista* li, struct aluno al);

int Lista_insere_final(Lista* li, struct aluno al);

int Lista_insere_ordenada(Lista* li, struct aluno al);

int Lista_remove(Lista* li, int mat);

int Lista_remove_inicio(Lista* li);

int Lista_remove_final(Lista* li);

int Lista_tamanho(Lista* li);

int Lista_cheia(Lista* li);

int Lista_vazia(Lista* li);
