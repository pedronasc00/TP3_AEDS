#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Compartimento.h"

int main() {
    int N_rochas;
    double lat_r, long_r;
    float peso_r;
    char linha[255];
    Compartimento ListaRocha;
    RochaMineral rocha;

    printf("Digite o nome do arquivo: ");

    char nomearq[33];
    scanf("%32s", nomearq);
    FILE *arq = fopen(nomearq, "r");

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo\n");
        return 1;
    }

    fscanf(arq, "%d", &N_rochas);   

    return 0;
}
