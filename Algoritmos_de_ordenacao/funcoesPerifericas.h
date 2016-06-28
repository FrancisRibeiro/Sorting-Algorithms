/* 
 * File:   funcoesPerifericas.h
 * Author: FrancisEduardo
 *
 * Created on 5 de Março de 2016, 15:14
 */

//Função que gera um Menu com opções
void menu();

//Função que faz a leitura do arquivo
int *fileIn(int *tamanho);

//Função que gera o arquivo de saida com os valores ordenados
void fileOut(int *valores, int tamanho);