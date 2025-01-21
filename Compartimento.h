#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#define MaxCOP 10000
#include "Rocha.h"

typedef int ApontadorRocha;
typedef struct 
{
    RochaMineral ListaR[MaxCOP];
    ApontadorRocha first, last;
}Compartimento;

void FLVaziaRocha(Compartimento *LRocha);
int LEhVaziaRocha(Compartimento *LRocha);
int LInsereRocha(Compartimento *LRocha, RochaMineral x);
void LImprimeRocha(Compartimento *LRocha);
void SelectionSort(Compartimento *LRocha, int n);
void Ordena(int Esq, int Dir, Compartimento *LRocha);
void QuickSort(RochaMineral *LRocha, int n);
void Particao(int Esq, int Dir, int *i, int *j, Compartimento *LRocha);
int LTamanho(Compartimento *LRocha);

#endif