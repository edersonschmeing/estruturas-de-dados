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


//***********************QUICKSORT DE CORMEN******************************
//conferir com o livro.
int partitionCormen(int vetor[], int inicio, int fim, int &quantidadeComparacao ) {
    
    int pivo = vetor[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j <= fim - 1; j++) {
        quantidadeComparacao++; 
        if (vetor[j] <= pivo) {
            i++;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i + 1, fim);
    return i + 1;
}

void quicksortCormen(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
    if (inicio < fim) {
        int posicaoPivo = partitionCormen(vetor, inicio, fim, quantidadeComparacao);
        quicksortCormen(vetor, inicio, posicaoPivo - 1, quantidadeComparacao);
        quicksortCormen(vetor, posicaoPivo + 1, fim, quantidadeComparacao);
    }
}

//***********************FIM QUICKSORT DE CORMEN******************************



//***********************QUICKSORT DE HOARE******************************

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

int partitionHoare(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
    
    int pivo = vetor[inicio];
    int i = inicio + 1;
    int j = fim;

    while (i <= j) {
        while (i <= j && vetor[i] <= pivo) {
            quantidadeComparacao++;
            i++;
        }
        while (i <= j && vetor[j] > pivo) {
            quantidadeComparacao++;
            j--;
        }
        if (i < j) {
            swap(vetor, i, j);
        }
    }
    swap(vetor, inicio, j);
    return j; 
}

void quicksortHoare(int A[], int inicio, int fim, int &quantidadeComparacao) {
    if (inicio < fim) {
        int posicaoPivo = partitionHoare(A, inicio, fim, quantidadeComparacao);
        quicksortHoare(A, inicio, posicaoPivo - 1, quantidadeComparacao);
        quicksortHoare(A, posicaoPivo + 1, fim, quantidadeComparacao);
    }
}

//***********************FIM QUICKSORT DE HOARE******************************


//***********************QUICKSORT ALEATORIO******************************

int partitionAleatorio(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
    
    int k;
    double d;

    //srand(time(NULL)); 
    int aleatorio = inicio + rand() % (fim - inicio);     
    swap(vetor[aleatorio], vetor[fim]); 
    
    //d = (double) rand () / ((double) RAND_MAX + 1);
    //k = d * (fim - inicio + 1);
    //int randomIndex = inicio + k;
    
    //swap(vetor, randomIndex, fim);

    return partitionCormen(vetor, inicio, fim, quantidadeComparacao);   
}

void quicksortAleatorio(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
    
    
    if (inicio < fim) {
        int posicaoPivo = partitionAleatorio(vetor, inicio, fim, quantidadeComparacao);
        quicksortAleatorio(vetor, inicio, posicaoPivo - 1, quantidadeComparacao);
        quicksortAleatorio(vetor, posicaoPivo + 1, fim, quantidadeComparacao);
    }

}

//***********************FIM QUICKSORT ALEATORIO******************************

//***********************QUICKSORT MEDIANA DE TRES******************************

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

int partitionMedianaDeTres(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
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
 
    swap(vetor, medianaIndice, fim);
     
    return partitionCormen(vetor, inicio, fim, quantidadeComparacao);
       
}

void quicksortMedianaDeTres(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
    if (inicio < fim) {
        int posicaoPivo = partitionMedianaDeTres(vetor, inicio, fim, quantidadeComparacao);
        quicksortMedianaDeTres(vetor, inicio, posicaoPivo - 1, quantidadeComparacao);
        quicksortMedianaDeTres(vetor, posicaoPivo + 1, fim, quantidadeComparacao);
    }
}

//***********************FIM QUICKSORT MEDIANA DE TRES******************************



void quicksort(int vetor[], int tamanho, int estrategia) {
        
    auto tempoInicial = high_resolution_clock::now();
        
    int quantidadeComparacao = 0;

    switch(estrategia) {
        case 1:
            //cout << "CORMEN" << endl;
            quicksortCormen(vetor, 0, tamanho-1, quantidadeComparacao);
        break;
        case 2:
            //cout << "HOARE" << endl;
            quicksortHoare(vetor, 0, tamanho-1, quantidadeComparacao);
        break;
        case 3:
            //cout << "ALEATORIO" << endl;
            quicksortAleatorio(vetor, 0, tamanho-1, quantidadeComparacao);
        case 4:
            //cout << "MEDIANA DE TRES" << endl;
            quicksortMedianaDeTres(vetor, 0, tamanho-1, quantidadeComparacao);
        break;
        default: 
           //cout << "CORMEN" << endl;
           quicksortCormen(vetor, 0, tamanho-1, quantidadeComparacao);
    }

    auto tempoFinal = std::chrono::high_resolution_clock::now();
    auto i_millis = duration_cast<milliseconds>( tempoFinal - tempoInicial);
    auto f_secs = duration_cast<duration<double>>( tempoFinal - tempoInicial);
    

    cout  << tamanho << ";" << quantidadeComparacao << ";" << i_millis.count() << ";" << f_secs.count() << endl;


}



    
    










