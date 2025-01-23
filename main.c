#include "Compartimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    clock_t start, stop;

    Compartimento ListaRocha;

    int N_rochas;
    double lat_r, long_r;
    float peso_r;
    char linha[255];

    printf("Digite o nome do arquivo: ");

    char nomearq[33];
    scanf("%32s", nomearq);
    FILE *arq = fopen(nomearq, "r");

    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo\n");
        return 1;
    }

    fscanf(arq, "%d", &N_rochas);
    FLVaziaRocha(&ListaRocha, N_rochas);
    start = clock();
    for (int i = 0; i < N_rochas; i++)
    {
        RochaMineral RochaN;
        Mineral mineral;

        fscanf(arq, "%lf %lf %f", &lat_r, &long_r, &peso_r);

        FLVaziaMine(&RochaN.LMinerais);
        fgets(linha, sizeof(linha), arq);

        if (linha[strlen(linha) - 1] == '\n')
        {
            linha[strlen(linha) - 1] = '\0';
        }

        const char delim[] = " ";
        char *parteMinerais = strtok(linha, delim);

        while (parteMinerais != NULL)
        {
            strcpy(mineral.nome, parteMinerais);
            LInsereMine(&RochaN.LMinerais, mineral);
            parteMinerais = strtok(NULL, delim);
        }
        InicializaRocha(&RochaN, peso_r, DefCategoria(&RochaN), lat_r, long_r);
        LInsereRocha(&ListaRocha, RochaN, N_rochas);
    }
    fclose(arq);

    Compartimento copiaVetor = ListaRocha;

    start = clock();
    SelectionSort(copiaVetor.ListaR, LTamanho(&copiaVetor));
    stop = clock();

    double timep = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\nTempo para SeletionSort: %.5lf segundos\n\n", timep);

    start = clock();
    QuickSort(&ListaRocha, LTamanho(&ListaRocha));
    stop = clock();

    timep = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\nTempo para QuickSort: %.5lf segundos\n\n", timep);
}