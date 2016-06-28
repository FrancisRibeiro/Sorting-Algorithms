/* 
 * File:   main.c
 * Author: FrancisEduardo
 *
 * Created on 5 de Março de 2016, 10:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Biblioteca auxiliar
#include "funcoesPerifericas.h"

//Bibliotecas de ordenação
#include "bubbleSort.h"
#include "bubbleSortInteligente.h"

int main(void) {

    //Set para o Idioma
    setlocale(LC_ALL, "Portuguese");

    //Menu de opções
    menu();

    return 0;
}

