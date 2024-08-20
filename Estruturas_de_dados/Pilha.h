#define MAX 100

typedef struct pilha Pilha;

Pilha* criar_pilha();

void apagar_pilha(Pilha* pi);

int vazia_pilha(Pilha* pi);

int cheia_pilha(Pilha* pi);

int tamanho_pilha(Pilha* pi);

int inserir_pilha(Pilha* pi, int num);

int remover_pilha(Pilha* pi);

int consultar_pilha(Pilha* pi, int *num);
