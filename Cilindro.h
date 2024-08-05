typedef struct cilindro Cilindro;

Cilindro* Cilindro_cria(float altura, float raio);

void Cilindro_libera(Cilindro* c);

int Cilindro_acessa(Cilindro* c, float* altura, float* raio);

int Cilidro_atribui(Cilindro* c, float altura, float raio);

float Cilindro_area(Cilindro* c);

float Cilindro_volume(Cilindro* c);

float Cilindro_raio(Cilindro* c);

float Cilindro_altura(Cilindro* c);
