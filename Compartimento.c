#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"

void FLVaziaRocha(Compartimento* LRocha) {
    LRocha->first = InicioArranjo;
    LRocha->last = LRocha->first;
}   
int LEhVaziaRocha(Compartimento* LRocha) {
    return LRocha->last == LRocha->first;
}
int LInsereRocha(Compartimento* LRocha, RochaMineral x) {
    if (LRocha->last == MAX)
        return 0;
    LRocha->ListaR[LRocha->last++] = x;
    return 1;
}
void LImprimeRocha(Compartimento* LRocha) {
    int i;

    printf("----------------------------\n");
    for (i = LRocha->first; i < LRocha->last; i++) {
        printf("%s %.2f\n", LRocha->ListaR[i].categoria, LRocha->ListaR[i].peso);
    }
}
int LTamanho(Compartimento *LRocha) {
    if (LRocha->first == LRocha->last) {
        return 0;
    }
    return LRocha->last - LRocha->first;
}
void SelectionSort(Compartimento *LRocha, int n) {
    int i, j, Min;
    int mov = 0, comp = 0;
    RochaMineral Aux;

    for (i = 0; i < n - 1; i++) {
        Min = i;
        for (j = i + 1; j < n; j++)
            if (LRocha->ListaR[j].peso < LRocha->ListaR[Min].peso) {
                Min = j;
                comp += 1;
            }
        Aux = LRocha->ListaR[Min];
        LRocha->ListaR[Min] = LRocha->ListaR[i];
        LRocha->ListaR[i] = Aux;
        mov += 1;
    }

    //LImprimeRocha(LRocha);
    printf("\nMovimentacoes Selection = %d\n", mov);
    printf("Comparacoes Seletion = %d\n", comp);
}
void Ordena(int Esq, int Dir, Compartimento *A, int *comp, int *mov) {
    int i, j;
    Particao(Esq, Dir, &i, &j, A, comp, mov);
    if (Esq < j) {
        Ordena(Esq, j, A, comp, mov);
    }
    if (i < Dir) {
        Ordena(i, Dir, A, comp, mov);
    }
}
void Particao(int Esq, int Dir, int *i, int *j, Compartimento *A, int *comp, int *mov) {
    RochaMineral pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = A->ListaR[(*i + *j) / 2];
    do {
        while (pivo.peso > A->ListaR[*i].peso) {
            (*i)++;
            (*comp)++;
        }
        (*comp)++;
        while (pivo.peso < A->ListaR[*j].peso) {
            (*j)--;
            (*comp)++;
        }
        (*comp)++;


        if (*i <= *j) {
            aux = A->ListaR[*i];
            A->ListaR[*i] = A->ListaR[*j];
            A->ListaR[*j] = aux;
            (*mov) += 3;
            (*i)++;
            (*j)--;
        }
        (*comp)++;
    } while (*i <= *j);
}
void QuickSort(Compartimento *A, int n) {
    int comp = 0, mov = 0;
    Ordena(0, n - 1, A, &comp, &mov);
    //LImprimeRocha(A);
    printf("\nMovimentacoes QuickSort: %d\n", mov);
    printf("Comparacoes QuickSort: %d\n", comp);
}