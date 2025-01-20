#ifndef LISTAMINERAIS_H
#define LISTAMINERAIS_H
#define MaxTam 10000
#define InicioArranjo 0
#include "Mineral.h"

typedef int ApontadorMineral;
typedef struct 
{
    Mineral ListaM[MaxTam];
    ApontadorMineral first, last;
}ListaMinerais;

void FLVaziaMine(ListaMinerais *LMinerais);
int LEhVaziaMine(ListaMinerais *LMinerais);
int LInsereMine(ListaMinerais *LMinerais, Mineral x);
int LRetiraMine(ListaMinerais *LMinerais, char *nome, Mineral *pX);
void LImprimeMine(ListaMinerais *LMinerais);

#endif