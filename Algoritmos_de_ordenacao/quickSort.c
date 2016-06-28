/* 
 * File:   quickSort.c
 * Author: francis
 *
 * Created on 23 de Março de 2016, 08:27
 */

#include "quickSort.h"

void quickSort(int *vetor, int inicio, int fim) {
    int pivo;

    if (inicio < fim) {
        pivo = separa(vetor, inicio, fim);
        quickSort(vetor, inicio, (pivo - 1));
        quickSort(vetor, (pivo + 1), fim);
    }
}

int separa(int *vetor, int inicio, int fim) {
    int i, j, pivo, aux;

    pivo = *(vetor + inicio);
    i = inicio + 1;
    j = fim;

    while (i <= j) {
        if (*(vetor + i) <= pivo) {
            i++;
        } else if (pivo < *(vetor + j)) {
            --j;
        } else {
            aux = *(vetor + i);
            *(vetor + i) = *(vetor + j);
            *(vetor + j) = aux;
            ++i;
            --j;
        }
    }

    *(vetor + inicio) = *(vetor + j);
    *(vetor + j) = pivo;

    return j;
}