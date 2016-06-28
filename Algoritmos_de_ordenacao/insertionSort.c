/* 
 * File:   insertiopnSort.c
 * Author: FrancisEduardo
 *
 * Created on 9 de Março de 2016, 14:07
 */

void insertionSort(int tamanho, int *vetor) {
    int marcador, pos, aux;

    for (marcador = 1; marcador < (tamanho); marcador++) {
        aux = *(vetor + marcador);
        pos = marcador - 1;
        while (pos >= 0 && *(vetor + pos) > aux) {
            *(vetor + pos + 1) = *(vetor + pos);
            pos--;
        }
        *(vetor + pos + 1) = aux;
    }
}
