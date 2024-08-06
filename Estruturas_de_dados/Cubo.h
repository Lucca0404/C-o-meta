typedef struct cubo Cubo;

Cubo* Cubo_cria(float lado);

void Cubo_libera(Cubo* c);

int Cubo_acessa(Cubo* c, float* lado);

int Cubo_atribui(Cubo* c, float lado);

float Cubo_area(Cubo* c);

float Cubo_volume(Cubo* c);
