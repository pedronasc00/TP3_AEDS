#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"

void FLVaziaRocha(Compartimento *LRocha, int n)
{
    LRocha->ListaR = (RochaMineral *)malloc(sizeof(RochaMineral) * n);
    LRocha->first = InicioArranjo;
    LRocha->last = LRocha->first;
}
int LEhVaziaRocha(Compartimento *LRocha)
{
    return LRocha->last == LRocha->first;
}
int LInsereRocha(Compartimento *LRocha, RochaMineral x, int n)
{
    if (LRocha->last == n)
        return 0;
    LRocha->ListaR[LRocha->last++] = x;
    return 1;
}
void LImprimeRocha(Compartimento *LRocha)
{
    int i;

    printf("----------------------------\n");
    for (i = LRocha->first; i < LRocha->last; i++)
    {
        printf("%s %.2f\n", LRocha->ListaR[i].categoria, LRocha->ListaR[i].peso);
    }
}
int LTamanho(Compartimento *LRocha)
{
    if (LRocha->first == LRocha->last)
    {
        return 0;
    }
    return LRocha->last - LRocha->first;
}
void SelectionSort(RochaMineral *ListaR, int n, int *mov, int *comp)
{
    int i, j, Min;
    RochaMineral Aux;

    for (i = 0; i < n - 1; i++)
    {
        Min = i;
        for (j = i + 1; j < n; j++){
           (*comp)++;
            if (ListaR[j].peso < ListaR[Min].peso)
            {
                Min = j;
            }
        }    
        if (Min!=i){
        Aux = ListaR[Min];
        ListaR[Min] = ListaR[i];
        ListaR[i] = Aux;
        (*mov)++;
        }
    }
   
}
void Ordena(int Esq, int Dir, Compartimento *A, int *comp, int *mov)
{
    int i, j;
    Particao(Esq, Dir, &i, &j, A, comp, mov);
    if (Esq < j)
    {
        Ordena(Esq, j, A, comp, mov);
    }
    if (i < Dir)
    {
        Ordena(i, Dir, A, comp, mov);
    }
}
void Particao(int Esq, int Dir, int *i, int *j, Compartimento *A, int *comp, int *mov)
{
    RochaMineral pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = A->ListaR[(*i + *j) / 2];
    do
    {
        (*comp)++;
        while (pivo.peso > A->ListaR[*i].peso)
        {
            (*i)++;
            (*comp)++;
        }
        (*comp)++;
        while (pivo.peso < A->ListaR[*j].peso)
        {
            (*j)--;
            (*comp)++;
        }
        (*comp)++;

        if (*i <= *j)
        {
            aux = A->ListaR[*i];
            A->ListaR[*i] = A->ListaR[*j];
            A->ListaR[*j] = aux;
            (*mov)++;
            (*i)++;
            (*j)--;
        }

    } while (*i <= *j);
}
void QuickSort(Compartimento *A, int n, int *movi, int*cont)
{
    int comp = 0, mov = 0;
    Ordena(0, n - 1, A, cont, movi);
    
    
}