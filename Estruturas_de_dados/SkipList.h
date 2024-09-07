typedef struct SkipList SkipList;

SkipList* cria_SkipList(int MAXLVL, float p);

void apaga_SkipList(SkipList* sk);

int vazia_SkipList(SkipList* sk);

int tamanho_SkipList(SkipList* sk);

int insere_SkipList(SkipList* sk, int num);

int remove_SkipList(SkipList* sk, int num);

int  consulta_SkipList(SkipList* sk, int num);
