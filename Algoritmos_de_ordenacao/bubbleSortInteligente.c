/* 
 * File:   bubbleSortInteligente.c
 * Author: FrancisEduardo
 *
 * Created on 5 de Março de 2016, 10:32
 */

#include "bubbleSortInteligente.h"

void bubbleSortInteligente(int tamanho, int *valores) {
    int i, j, aux, flag;

    for (i = 0; i < tamanho; i++) {
        flag = 1;
        for (j = 0; j < tamanho -1; j++) {

            if (valores[i] > valores[j + 1]) {
                flag = 0;
                aux = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = aux;

            }
        }

        if (flag == 1) {
            return;
        }
    }
}