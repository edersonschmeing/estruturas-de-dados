#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;

//https://www.researchgate.net/publication/332440763_Probabilistic_Analysis_of_Perfect_Partitioning_in_Randomized_Quicksort
//https://www.blogcyberini.com/2018/09/quicksort-com-pivo-aleatorio.html


void swapA(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}


int partitionCormen1(int vetor[], int inicio, int fim) {
    
    int pivo = vetor[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            swapA(vetor, i, j);
        }
    }
    swapA(vetor, i + 1, fim);
    return i + 1;
}

int partitionAleatorio(int vetor[], int inicio, int fim) {
    
    int k;
    double d;

    //srand(time(NULL)); 
    //int aleatorio = inicio + rand() % (fim - inicio);     
    //swap(vetor[aleatorio], vetor[fim]); 
    
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (fim - inicio + 1);
    int randomIndex = inicio + k;
    
    swapA(vetor, randomIndex, fim);

    return partitionCormen1(vetor, inicio, fim);   
}

void quicksortAleatorio(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = partitionAleatorio(vetor, inicio, fim);
        quicksortAleatorio(vetor, inicio, posicaoPivo - 1);
        quicksortAleatorio(vetor, posicaoPivo + 1, fim);
    }
}









