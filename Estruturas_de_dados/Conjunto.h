typedef struct conjunto Conjunto;

Conjunto* Conjunto_cria();

void Conjunto_apagar(Conjunto* c);

Conjunto* Conjunto_uniao(Conjunto* c1, Conjunto* c2);

void Conjunto_inserir(Conjunto* c, int num);

void Conjunto_remover(Conjunto* c, int index);

Conjunto* Conjunto_diferenca(Conjunto* c1, Conjunto* c2);

Conjunto* Conjunto_interseccao(Conjunto* c1, Conjunto* c2);

int Conjunto_pertence(Conjunto* c, int num);

int Conjunto_menor_valor(Conjunto* c);

int Conjunto_maior_valor(Conjunto* c);

int Conjunto_igualdade(Conjunto* c1, Conjunto* c2);

int Conjunto_tamanho(Conjunto* c);

int Conjunto_vazio(Conjunto* c);
