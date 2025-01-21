#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "Rocha.h"

typedef int ApontadorRocha;
typedef struct 
{
    RochaMineral ListaR[MaxTam];
    ApontadorRocha first, last;
}Compartimento;

void FLVaziaRocha(Compartimento *LRocha);
int LEhVaziaRocha(Compartimento *LRocha);
int LInsereRocha(Compartimento *LRocha, RochaMineral x);
void LImprimeRocha(Compartimento *LRocha);

#endif