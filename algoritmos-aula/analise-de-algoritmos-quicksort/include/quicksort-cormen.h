#include <iostream>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;

void swap(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

//conferir com o livro.
int partitionCormen(int vetor[], int inicio, int fim) {
    
    int pivo = vetor[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i + 1, fim);
    return i + 1;
}


void quicksortCormen(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = partitionCormen(vetor, inicio, fim);
        quicksortCormen(vetor, inicio, posicaoPivo - 1);
        quicksortCormen(vetor, posicaoPivo + 1, fim);
    }
}











