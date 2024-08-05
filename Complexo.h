typedef struct complexo Complexo;

Complexo* Complexo_cria(float x, float y);

void Complexo_libera(Complexo* c);

int Complexo_acessa(Complexo* c, float* x, float* y);

int Complexo_atribui(Complexo* c, float x, float y);

float Complexo_soma(Complexo* c1, Complexo* c2);

float Complexo_subtracao(Complexo* c1, Complexo* c2);

float Complexo_multiplicacao(Complexo* c1, Complexo* c2);

float Complexo_divisao(Complexo* c1, Complexo* c2);
