#ifndef ROCHA_H
#define ROCHA_H
#include "ListaMinerais.h"

typedef struct 
{
    int id;
    float peso;
    char categoria[40];
    double latitude, longitude;
    ListaMinerais LMinerais;
}RochaMineral;

void InicializaRocha(RochaMineral* rocha, int id, float peso, char* categoria, double latitude, double longitude);
char* DefCategoria(RochaMineral* rocha);

int getIdentificador(RochaMineral* rocha);
float getPeso(RochaMineral* rocha);
char* getCategoria(RochaMineral* rocha);
double getLatitude(RochaMineral* rocha);
double getLongitude(RochaMineral* rocha);

void setIdentificador(RochaMineral* rocha, int id);
void setPeso(RochaMineral* rocha, float peso);
void setCategoria(RochaMineral* rocha, char* categoria);
void setLocalizacao(RochaMineral* rocha, double latitude, double longitude);

#endif