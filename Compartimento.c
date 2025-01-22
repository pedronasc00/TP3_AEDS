#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"

void FLVaziaRocha(Compartimento* LRocha) {
    LRocha->first = 0;
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
        printf("%s %f\n", LRocha->ListaR[i].categoria, LRocha->ListaR[i].peso);
    }
}
int LTamanho(Compartimento *LRocha) {
    if (LRocha->first == LRocha->last) {
        return 0;
    }
    return LRocha->last - LRocha->first + 1;
}
void SelectionSort(Compartimento *LRocha, int n) {
    int i, j, Min;
    int mov = 0, comp = 0;
    RochaMineral Aux;

    for (i = 0; i < n - 1; i++) {
        Min = i;
        for (j = i + 1 ; j < n; j++)
            if (LRocha->ListaR[j].peso < LRocha->ListaR[Min].peso) {
                Min = j;
                comp += 1;
            }
        Aux = LRocha->ListaR[Min];
        LRocha->ListaR[Min] = LRocha->ListaR[i];
        LRocha->ListaR[i] = Aux;
        mov += 1;
    }

    LImprimeRocha(LRocha);
    printf("Movimentacoes = %d\n", mov);
    printf("Comparacoes = %d\n", comp);
}