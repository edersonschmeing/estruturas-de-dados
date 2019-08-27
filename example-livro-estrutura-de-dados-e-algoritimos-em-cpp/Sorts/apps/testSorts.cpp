#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "../include/Sorts.hpp"

using namespace std;

bool exist(int data[],int tam, int valor){
    for(int i = 0;i<tam;i++){
        if(data[i]==valor)
            return true;
    }
    return false;
}

void generateRandomNumbers(int data[],int n,int limit){
    srand(time(NULL));
    int v;
    for(int i=0;i<n;i++){
        v = rand() % limit;
        while(exist(data,i,v)){
            v = rand() % limit;
        }
        data[i] = v;
    }
}

int main(){
    int data[100];
    generateRandomNumbers(data,100,100);
    
    cout << "Random Numbers" << endl;
    for(int i = 0;i<100;i++){
        cout<<data[i]<<" - ";
    }
    cout << endl;

    //fazer menu para escolher o método
    //Executar todos para os mesmos dados e calcular o tempo de cada um e aprestar
    
    //cout << "Sort with insertionsort" << endl;
    //insertionsort(data, 100);
    
    //cout << "Sort with selectionsort" << endl;
    //selectionsort(data, 100);

    //cout << "Sort with bubblesort" << endl;
    //bubblesort(data, 100);

    //cout << "Sort with combsort" << endl;
    //combsort(data, 100);
    
    //cout << "Sort with Shellsort" << endl;
    //Shellsort(data, 100);
    
    // cout << "Sort with heapsort" << endl;
    // heapsort(data, 100);

    // cout << "Sort with quicksort first and last" << endl;
    //quicksort(data, 0, 99);
    
    //  cout << "Sort with quicksort n" << endl;
    //  quicksort(data, 100);

    //  cout << "Sort with quicksort2 first and last" << endl;
    //  quicksort2(data, 0, 99);

//    cout << "Sort with quicksort2 n" << endl;
//    quicksort2(data, 100);

      
     // radixsort2(data, 100);

    // cout << "Sort with countingsort n" << endl;
    // long longNumber[5] = { 5, 2, 1, 4, 3};
    // countingsort(longNumber, (long)5);

    for(int i = 0;i<100;i++){
        cout<<data[i]<<" - ";
    }
    cout << endl;

    return 0;
}
