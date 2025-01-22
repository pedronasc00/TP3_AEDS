#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#define MAX 10000
#include "Rocha.h"

typedef int ApontadorRocha;
typedef struct
{
    RochaMineral ListaR[MAX];
    ApontadorRocha first, last;
} Compartimento;

void FLVaziaRocha(Compartimento *LRocha);
int LEhVaziaRocha(Compartimento *LRocha);
int LInsereRocha(Compartimento *LRocha, RochaMineral x);
void LImprimeRocha(Compartimento *LRocha);
void SelectionSort(Compartimento *LRocha, int n);
int LTamanho(Compartimento *LRocha);
void Ordena(int esq, int dir, RochaMineral *A);
void QuickSort(RochaMineral *A, int n);
void Particao(int esq, int dir, int *i, int *j, RochaMineral *A);
#endif