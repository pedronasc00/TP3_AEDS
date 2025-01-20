#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaMinerais.h"

void FLVaziaMine(ListaMinerais *LMinerais)
{
    LMinerais->first = InicioArranjo;
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

int LRetiraMine(ListaMinerais *LMinerais, char *nome, Mineral *pX)
{
    int i, cont;

    for (i = 0; i < LMinerais->last; i++)
    {
        if (strcmp(LMinerais->ListaM[i].nome, nome) == 0)
        {
            *pX = LMinerais->ListaM[i];

            LMinerais->last--;

            for (cont = i + 1; cont <= LMinerais->last; cont++)
            {
                LMinerais->ListaM[cont - 1] = LMinerais->ListaM[cont];
            }

            return 1;
        }
    }
    return 0;
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