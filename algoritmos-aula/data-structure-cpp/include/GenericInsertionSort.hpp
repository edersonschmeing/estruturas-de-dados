
/*#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template<class T>
class InsertionSort {
public:
    InsertionSort(&T &data[], int lenght) {
        this->data = data;
        this->lenght = lenght;
    }
    void sort();
    void printAll(); 
//public:
    int externalLoop = 0;
    int internalLoop = 0;
    int lenght;
    T data[];
};

template<class T>
void InsertionSort<T>::sort() {
    for (int i = 0, j; i < lenght; i++) {
        T tmp = data[i];
        externalLoop++;
        for (j = i; j > 0 && tmp < data[j-1]; j--) { 
            data[j] = data[j-1];
            internalLoop++;
        }
        data[j] = tmp;
    }
    InsertionSort<T>::printAll();
}

template<class T>
void InsertionSort<T>::printAll() { 
   for(int i = 0; i < lenght; i++){
        cout<< data[i]<<" - ";
    }
    cout <<  endl;
    cout << "External Loop: " << externalLoop << endl;
    cout << "Internal Loop: " <<  internalLoop << endl;
        
} */