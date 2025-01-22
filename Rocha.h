#ifndef ROCHA_H
#define ROCHA_H
#include "ListaMinerais.h"

typedef struct
{
    float peso;
    char categoria[40];
    double latitude, longitude;
    ListaMinerais LMinerais;
} RochaMineral;

void InicializaRocha(RochaMineral *rocha, float peso, char *categoria, double latitude, double longitude);
char *DefCategoria(RochaMineral *rocha);

float getPeso(RochaMineral *rocha);
char *getCategoria(RochaMineral *rocha);
double getLatitude(RochaMineral *rocha);
double getLongitude(RochaMineral *rocha);

void setPeso(RochaMineral *rocha, float peso);
void setCategoria(RochaMineral *rocha, char *categoria);
void setLocalizacao(RochaMineral *rocha, double latitude, double longitude);

#endif