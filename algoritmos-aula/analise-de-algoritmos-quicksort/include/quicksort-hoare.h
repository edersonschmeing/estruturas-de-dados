#include <iostream>
#include <stdlib.h>
#include <stdio.h>


#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;

//https://www.blogcyberini.com/2018/08/quicksort-analise-e-implementacoes.html


void swap1(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

/*int partition_pivo_inicio(int vetor[], int inicio , int fim) {
    int pivo = vetor[inicio];
    int i = inicio;

    for(int j = inicio + 1; j <= fim; j++) {
        if(pivo >= vetor[j]) {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i], vetor[inicio]);
    return i;
}*/

int partitionHoare(int vetor[], int inicio, int fim) {
    
    int pivo = vetor[inicio];
    int i = inicio + 1;
    int j = fim;

    while (i <= j) {
        while (i <= j && vetor[i] <= pivo) {
            i++;
        }
        while (i <= j && vetor[j] > pivo) {
            j--;
        }
        if (i < j) {
            swap1(vetor, i, j);
        }
    }
    swap1(vetor, inicio, j);
    return j; 
}

void quicksortHoare(int A[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = partitionHoare(A, inicio, fim);
        quicksortHoare(A, inicio, posicaoPivo - 1);
        quicksortHoare(A, posicaoPivo + 1, fim);
    }
}















