/*
 * File:   funcoesPerifericas.c
 * Author: FrancisEduardo
 *
 * Created on 5 de Março de 2016, 15:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>


#include "funcoesPerifericas.h"

//Função que gera um Menu com opções

void menu() {
    int flag, *tamanho, *v;
    tamanho = 0; //Reset para o ponteiro de tamanho
    struct timeval tv1, tv2;

    //Escolhas do usuário
    printf("Algoritmos de Ordenação:\n\n"
            "   1 - Bubble Sort\n"
            "   2 - Bubble Sort Inteligente\n"
            "   3 - Selection Sort\n"
            "   4 - Insertion Sort\n"
            "   5 - Merge Sort\n"
            "   6 - Quick Sort\n");

    printf("\nQual a opção deseja utilizar? ");
    scanf("%d", &flag);

    switch (flag) {
        case 1:
            randomNumbers();
            v = fileIn(&tamanho);
            gettimeofday(&tv1, NULL);
            bubbleSort(tamanho, v);
            gettimeofday(&tv2, NULL);
            fileOut(v, tamanho);
            printf("Total time = %f seconds\n",
                    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                    (double) (tv2.tv_sec - tv1.tv_sec));
            break;
        case 2:
            randomNumbers();
            v = fileIn(&tamanho);
            gettimeofday(&tv1, NULL);
            bubbleSortInteligente(tamanho, v);
            gettimeofday(&tv2, NULL);
            fileOut(v, tamanho);
            printf("Total time = %f seconds\n",
                    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                    (double) (tv2.tv_sec - tv1.tv_sec));
            break;
        case 3:
            randomNumbers();
            v = fileIn(&tamanho);
            gettimeofday(&tv1, NULL);
            selectionSort(tamanho, v);
            gettimeofday(&tv2, NULL);
            fileOut(v, tamanho);
            printf("Total time = %f seconds\n",
                    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                    (double) (tv2.tv_sec - tv1.tv_sec));
            break;
        case 4:
            randomNumbers();
            v = fileIn(&tamanho);
            gettimeofday(&tv1, NULL);
            insertionSort(tamanho, v);
            gettimeofday(&tv2, NULL);
            fileOut(v, tamanho);
            printf("Total time = %f seconds\n",
                    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                    (double) (tv2.tv_sec - tv1.tv_sec));
            break;
        case 5:
            randomNumbers();
            v = fileIn(&tamanho);
            gettimeofday(&tv1, NULL);
            mergeSort(v, 0, tamanho);
            gettimeofday(&tv2, NULL);
            fileOut(v, tamanho);
            printf("Total time = %f seconds\n",
                    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                    (double) (tv2.tv_sec - tv1.tv_sec));
            break;
        case 6:
            randomNumbers();
            v = fileIn(&tamanho);
            gettimeofday(&tv1, NULL);
            quickSort(v, 0, tamanho);
            gettimeofday(&tv2, NULL);
            fileOut(v, tamanho);
            printf("Total time = %f seconds\n",
                    (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
                    (double) (tv2.tv_sec - tv1.tv_sec));
            break;
        default:
            printf("\nOPÇÃO INVÁLIDA!!!\n"); //Imprime mensagem
            //_sleep(1000); //Exibe mensagem por 1 segundo
            //system("cls"); //Limpa o terminal
            menu(); //Faz a chamada do menu novamente
    }
}

//Função que faz a leitura do arquivo

int *fileIn(int *tamanho) {
    FILE *arquivo;
    char nomeArquivo[40];
    int *valores, i = 0;

    printf("\nInsira o arquivo para ordenação (*.TXT): ");
    scanf("%s", &nomeArquivo);
    strcat(nomeArquivo, ".txt"); //Concatenação do arquivo com sua extensão

    arquivo = fopen(nomeArquivo, "r"); //Abertura do arquivo contendo os valores

    if (!arquivo) {
        printf("\nERRO NA LEITURA DO ARQUIVO!"); //Imprime mensagem
        //_sleep(2000); //Exibe mensagem por 2 segundos
        //system("cls"); //Limpa o terminal
        menu(); //Faz a chamada do menu novamente
    } else {
        fscanf(arquivo, "%d", tamanho); //Lê a quantidade de valores do arquivo
        valores = malloc(*tamanho * sizeof (int)); //Alocando memória para o vetor

        for (i = 0; i < *tamanho; i++) {
            fscanf(arquivo, "%d", &valores[i]); //coloca os arquivos em um vetor
        }
    }

    fclose(arquivo);

    return valores;
}

//Função que gera o arquivo de saida com os valores ordenados

void fileOut(int *valores, int tamanho) {
    FILE *arquivo;
    char nomeArquivo[40];
    int i = 0;

    printf("\nInsira o nome do arquivo de saida: ");
    scanf("%s", &nomeArquivo);
    strcat(nomeArquivo, ".txt"); //Concatenação do arquivo com sua extensão

    arquivo = fopen(nomeArquivo, "w+"); //Criação do arquivo de saida

    if (!arquivo) {
        printf("\nERRO NA CRIAÇÃO DO ARQUIVO!"); //Imprime mensagem
        //_sleep(2000); //Exibe mensagem por 2 segundos
        //system("cls"); //Limpa o terminal
        menu(); //Faz a chamada do menu novamente
    } else {
        for (i = 0; i < tamanho; i++) {
            fprintf(arquivo, "%d ", valores[i]);
        }
        printf("\n-> Arquivo %s gerado com sucesso!!!\n\n", nomeArquivo);
    }

    fclose(arquivo);
}


//Função para gerar números aletórios

void randomNumbers() {
    int i, r, tamanho;
    char flag, fileName[40];
    FILE *arquivo;

    //set da função time para gerar números aleatorios
    srand(time(NULL));

    printf("\nDeseja gerar valores aletorios?[S/N] ");
    scanf(" %c", &flag);

    if (flag == 's' || flag == 'S') {
        printf("\nQuantos valores? ");
        scanf("%d", &tamanho);

        printf("\nQual o nome do arquivo? ");
        scanf("%s", fileName);
        strcat(fileName, ".txt");

        arquivo = fopen(fileName, "w+");

        if (!arquivo) {
            printf("\nERRO NA CRIAÇÃO DO ARQUIVO!"); //Imprime mensagem
            //_sleep(2000); //Exibe mensagem por 2 segundos
            //system("cls"); //Limpa o terminal
            menu(); //Faz a chamada do menu novamente
        } else {
            fprintf(arquivo, "%d ", tamanho);
            for (i = 0; i < tamanho; i++) {
                r = rand() % tamanho;
                fprintf(arquivo, "%d ", r);
            }
            printf("\n-> Arquivo %s gerado com sucesso!!!\n", fileName);
        }

        fclose(arquivo);

    } else {
        return;
    }
}