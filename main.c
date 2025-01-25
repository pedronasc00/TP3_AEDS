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
    int mov = 0, comp = 0;

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
    int opcao;
    printf("Digite '1' para escolher o SelectionSort, ou '2' para escolher o QuickSort: ");
    scanf("%d", &opcao);
    if (opcao ==1)
    {
            start = clock();
            SelectionSort(copiaVetor.ListaR, LTamanho(&copiaVetor), &mov, &comp);
            stop = clock();

            LImprimeRocha(&copiaVetor);
            printf("\nMovimentacoes Selection = %d\n", mov);
            printf("Comparacoes Seletion = %d\n", comp);
            double timeS = (double)(stop - start) / CLOCKS_PER_SEC;
            printf("\nTempo para SeletionSort: %.15lf segundos\n\n", timeS);
    }else if(opcao ==2){
        start = clock();
        QuickSort(&ListaRocha, LTamanho(&ListaRocha));
        stop = clock();
        
        double timeQ = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("\nTempo para QuickSort: %.7lf segundos\n\n", timeQ);
    }
   
}