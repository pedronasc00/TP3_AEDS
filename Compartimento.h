#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "Rocha.h"

typedef int ApontadorRocha;
typedef struct
{
    RochaMineral* ListaR;
    ApontadorRocha first, last;
} Compartimento;

void FLVaziaRocha(Compartimento *LRocha, int n);
int LEhVaziaRocha(Compartimento *LRocha);
int LInsereRocha(Compartimento *LRocha, RochaMineral x, int n);
void LImprimeRocha(Compartimento *LRocha);
void SelectionSort(RochaMineral *ListaR, int n, int *mov, int *comp);
int LTamanho(Compartimento *LRocha);
void QuickSort(Compartimento *A, int n, int *movi, int *cont);
void Ordena(int Esq, int Dir, Compartimento *A, int *comp, int *mov);
void Particao(int Esq, int Dir, int *i, int *j, Compartimento *A, int *comp, int *mov);

#endif