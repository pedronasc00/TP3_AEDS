#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Compartimento.h"

int main(int argc, char const *argv[])
{
    clock_t start = clock();
    
    int N_rochas;
    double lat_r, long_r;
    float peso_r;
    char linha[255];
    Compartimento ListaRocha;
    printf("AAAAAAAA1\n");

    FLVaziaRocha(&ListaRocha);
    printf("AAAAAAAA1\n");

    printf("Digite o nome do arquivo: ");
    printf("AAAAAAAA1\n");

    char nomearq[33];
    scanf("%32s", nomearq);
    FILE *arq = fopen(nomearq, "r");

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo\n");
        return 1;
    }

    fscanf(arq, "%d", &N_rochas);   

    for (int i = 0; i < N_rochas; i++) {
        RochaMineral RochaN;
        Mineral mineral;

        fscanf(arq, "%lf %lf %f", &lat_r, &long_r, &peso_r);

        FLVaziaMine(&RochaN.LMinerais);
        fgets(linha, sizeof(linha), arq);

        if (linha[strlen(linha)-1] == '\n') {
            linha[strlen(linha)-1] = '\0';
        } else {
            linha[strlen(linha)] = '\0';
        }
        const char delim[] = " ";
        char *parteMinerais = strtok(linha, delim);

        while (parteMinerais != NULL) {
            strcpy(mineral.nome, parteMinerais);
            LInsereMine(&RochaN.LMinerais, mineral);
            parteMinerais = strtok(NULL, delim);
        }
        InicializaRocha(&RochaN, (i + 1), peso_r, DefCategoria(&RochaN), lat_r, long_r);
        LInsereRocha(&ListaRocha, RochaN);
    }
    fclose(arq);

    SelectionSort(&ListaRocha, LTamanho(&ListaRocha));
    
    clock_t stop = clock();
    double timep = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\n Tempo gasto: %.5lf segundos\n\n", timep);
}
