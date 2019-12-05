#include <iostream>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;

int shellSort_Donald(int *vetor, int tamanho )
{
    auto tempoInicial = high_resolution_clock::now();

    int quantidadeComparacao = 0;
    
    for (int h = tamanho/2; h > 0; h /= 2)  {

        for (int i = h; i < tamanho; i += 1) {
            int temp = vetor[i];
            int j;
            quantidadeComparacao++;
            for (j = i; j >= h && vetor[j - h] > temp; j -= h) {
                vetor[j] = vetor[j - h];
                quantidadeComparacao++;
            }
            vetor[j] = temp;
        }
    }

    auto tempoFinal = std::chrono::high_resolution_clock::now();
    auto i_millis = duration_cast<milliseconds>( tempoFinal - tempoInicial);
    auto f_secs = duration_cast<duration<double>>( tempoFinal - tempoInicial);
    cout  << tamanho << ";" << quantidadeComparacao << ";" << i_millis.count() << ";" << f_secs.count() << endl;
   
    return 0;
}

void shellSort_Knuth(int *vetor, int tamanho) {

    auto tempoInicial = high_resolution_clock::now();
      
    int quantidadeComparacao = 0;
    int i , j , value;
    int h = 1;
    while (h < tamanho) {
       h = h*3+1;
    }
    while (h > 1) {
        h /= 3;
        for (i = h; i < tamanho; i++) {
            value = vetor[i];
            j = i;
            quantidadeComparacao++;
            while (j >= h && value < vetor[j-h]) {
                vetor[j] = vetor[j-h];
                j -= h;
                quantidadeComparacao++;;
            }
            vetor[j] = value;
        }
    }

    auto tempoFinal = std::chrono::high_resolution_clock::now();
    auto i_millis = duration_cast<milliseconds>( tempoFinal - tempoInicial);
    auto f_secs = duration_cast<duration<double>>( tempoFinal - tempoInicial);
    cout  << tamanho << ";" << quantidadeComparacao << ";" << i_millis.count() << ";" << f_secs.count() << endl;

}