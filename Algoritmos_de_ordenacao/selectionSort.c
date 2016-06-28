/* 
 * File:   selectionSort.c
 * Author: FrancisEduardo
 *
 * Created on 7 de Março de 2016, 15:10
 */

#include "selectionSort.h"

void selectionSort(int tamanho, int *valores) {
    int i, menor, aux;

    for (i = 0; i < tamanho - 1; i++) {
        menor = encontrarMenorPosicao(valores, tamanho, i);
        if (*(valores + menor) < *(valores + i)) {
            aux = *(valores + menor);
            *(valores + menor) = *(valores + i);
            *(valores + i) = aux;
        }
    }

}

int encontrarMenorPosicao(int *valores, int tamanho, int marcador) {
    int i;

    for (i = marcador + 1; i < tamanho; i++) {
        if (*(valores + i) < *(valores + marcador)) {
            marcador = i;
        }
    }
    return marcador;
}