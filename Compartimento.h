#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#define MAX 1525
#include "Rocha.h"

typedef int ApontadorRocha;
typedef struct 
{
    RochaMineral ListaR[MAX];
    ApontadorRocha first, last;
}Compartimento;

void FLVaziaRocha(Compartimento *LRocha);
int LEhVaziaRocha(Compartimento *LRocha);
int LInsereRocha(Compartimento *LRocha, RochaMineral x);
void LImprimeRocha(Compartimento *LRocha);
void SelectionSort(Compartimento *LRocha, int n);
int LTamanho(Compartimento *LRocha);
void QuickSort(Compartimento *A, int n);
void Ordena(int Esq, int Dir, Compartimento *A, int *comp, int *mov);
void Particao(int Esq, int Dir, int *i, int *j, Compartimento *A, int *comp, int *mov);

#endif