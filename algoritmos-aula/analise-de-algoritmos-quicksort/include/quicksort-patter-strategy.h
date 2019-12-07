#include <iostream>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;
using namespace std;

class PIVOT_STRAT {
    pivot_strat()     
}

class Pivot :PIVOT_STRAT {
    pivot_strat()     
}

class Pivot_Cormen :PIVOT_STRAT {
    pivot_strat()     
}

class Pivot_Hoare :PIVOT_STRAT {
    pivot_strat()     
}

class ARRAY {

}

template <class ARRAY>
void sort (ARRAY &array) {
    Pivot<ARRAY> *pivot_strat = Pivot<ARRAY>::make_pivot(Options::instance ()->pivot_strat ());
    quick_sort (array, pivot_strat);
}

template <class ARRAY, class PIVOT_STRAT>
quick_sort (ARRAY &array, PIVOT_STRAT *pivot_strat) {
    for (;;) {
        ARRAY::TYPE pivot; // typename ARRAY::TYPE pivot...
        pivot = pivot_strat->get_pivot (array, lo, hi);
        // Partition array[lo, hi] relative to pivot...
    }
}

void quicksortCormen(int vetor[], int inicio, int fim, int &quantidadeComparacao) {
    if (inicio < fim) {
        int posicaoPivo = partitionCormen(vetor, inicio, fim, quantidadeComparacao);
        quicksortCormen(vetor, inicio, posicaoPivo - 1, quantidadeComparacao);
        quicksortCormen(vetor, posicaoPivo + 1, fim, quantidadeComparacao);
    }
}






