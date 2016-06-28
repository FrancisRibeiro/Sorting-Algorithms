/* 
 * File:   bubbleSort.c
 * Author: FrancisEduardo
 *
 * Created on 5 de Março de 2016, 10:30
 */

#include "bubbleSort.h"

void bubbleSort(int tamanho, int *valores) {
    int i, j, aux;

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < (tamanho - 1); j++) {
            if (*(valores + j) > *(valores + j + 1)) {
                aux = *(valores + j);
                *(valores + j) = *(valores + j + 1);
                *(valores + j + 1) = aux;
            }
        }
    }
}
