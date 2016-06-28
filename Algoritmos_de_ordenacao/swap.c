/* 
 * File:   swap.c
 * Author: FrancisEduardo
 *
 * Created on 7 de Março de 2016, 15:10
 */

#include "swap.h"

void swap(int *valores, int a, int b) {
    int aux;

    aux = *(valores + a);
    *(valores + a) = *(valores + b);
    *(valores + b) = aux;
}


