#ifndef LISTAMINERAIS_H
#define LISTAMINERAIS_H
#define MaxTam 5
#define InicioArranjo 0
#include "Mineral.h"

typedef int ApontadorMineral;
typedef struct
{
    Mineral ListaM[MaxTam];
    ApontadorMineral first, last;
} ListaMinerais;

void FLVaziaMine(ListaMinerais *LMinerais);
int LEhVaziaMine(ListaMinerais *LMinerais);
int LInsereMine(ListaMinerais *LMinerais, Mineral x);
void LImprimeMine(ListaMinerais *LMinerais);

#endif