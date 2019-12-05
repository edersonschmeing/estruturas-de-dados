#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;


//https://www.blogcyberini.com/2018/08/quicksort-mediana-de-tres.html


//função auxiliar para realizar as trocas de elementos
void swapM(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


int partitionCormen3(int vetor[], int inicio, int fim) {
    
    int pivo = vetor[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            swapM(vetor, i, j);
        }
    }
    swapM(vetor, i + 1, fim);
    return i + 1;
}

//testar
/*int encontrarPartitionMedianaDeTres(int vetor[], int posicaoInicio, int posicaoFim) {

    int middle_pos = posicaoFim % 2 ? posicaoFim / 2 : (posicaoFim / 2 - 1);
  
    int first  = array[posicaoInicio];
    int middle = array[middle_pos];
    int last   = array[posicaoFim];

    if (first <= middle) {
      if (middle <= last) {
          // first - middle - last
          return middle_pos;
      } else if (first <= last) {
          // first - last - middle
          return last_pos;
      }
      // last - first - middle
      return first_pos;
    }

    if (first <= last) {
        // middle - first - last
        return first_pos;
    } else if (middle <= last) {
        // middle - last - first
        return last_pos;
    }
    // last - middle - first
    return middle_pos;
} */

int partitionMedianaDeTres(int vetor[], int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    
    int meio = (inicio + fim) / 2;
    
    int a = vetor[inicio];
    int b = vetor[meio];
    int c = vetor[fim];
    int medianaIndice; //índice da mediana
    
    //A sequência de if...else a seguir verifica qual é a mediana
    
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    
    //int posicaoMediana = encontrarPartitionMedianaDeTres(vetor, inicio, fim);
    //swap(vetor, posicaoMediana, fim);
 
    swapM(vetor, medianaIndice, fim);
     
    return partitionCormen3(vetor, inicio, fim);
       
}

void quicksortMedianaDeTres(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = partitionMedianaDeTres(vetor, inicio, fim);
        quicksortMedianaDeTres(vetor, inicio, posicaoPivo - 1);
        quicksortMedianaDeTres(vetor, posicaoPivo + 1, fim);
    }
}