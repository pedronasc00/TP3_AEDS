#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaMinerais.h"

void FLVaziaMine(ListaMinerais *LMinerais)
{
    LMinerais->first = 0;
    LMinerais->last = LMinerais->first;
}

int LEhVaziaMine(ListaMinerais *LMinerais)
{
    return (LMinerais->last == LMinerais->first);
}

int LInsereMine(ListaMinerais *LMinerais, Mineral x)
{
    if (LMinerais->last == MaxTam)
        return 0; // Lista cheia
    LMinerais->ListaM[LMinerais->last++] = x;
    return 1;
}

void LImprimeMine(ListaMinerais *LMinerais)
{
    int i;

    printf("Info dos minerais:\n");
    for (i = LMinerais->first; i < LMinerais->last; i++)
    {
        printf("Nome: %s\n", LMinerais->ListaM[i].nome);
        printf("Cor: %s\n", LMinerais->ListaM[i].cor);
        printf("Dureza: %.3lf\n", LMinerais->ListaM[i].dureza);
        printf("Reatividade: %.3lf\n\n", LMinerais->ListaM[i].reativ);
    }
}