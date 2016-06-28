/* 
 * File:   mergeSort.c
 * Author: FrancisEduardo
 *
 * Created on 14 de Março de 2016, 17:16
 */

#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"

void mergeSort(int *vet, int inicio, int fim) {
    int meio;

    meio = (inicio + fim) / 2;

    if (inicio < fim) {
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

void merge(int *vet, int inicio, int meio, int fim) {
    int tam1, tam2, i = 0, j, k, tam;
    int *aux;

    tam = (fim - inicio) + 1;
    j = inicio;
    k = meio + 1;
    tam2 = fim - meio;
    tam1 = tam - tam2;
    aux = malloc(sizeof (int)*tam);

    while ((tam1 != 0)&&(tam2 != 0)) {
        if (*(vet + j)<*(vet + k)) {
            *(aux + i) = *(vet + j);
            j++;
            tam1--;
        } else {
            *(aux + i) = *(vet + k);
            k++;
            tam2--;
        }
        i++;
    }

    while (tam1 > 0) {
        *(aux + i) = *(vet + j);
        j++;
        i++;
        tam1--;
    }

    while (tam2 > 0) {
        *(aux + i) = *(vet + k);
        k++;
        i++;
        tam2--;
    }

    j = inicio;

    for (i = 0; i < tam; i++) {
        *(vet + j) = *(aux + i);
        j++;
    }
    return;
}


