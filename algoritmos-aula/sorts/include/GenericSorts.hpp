//--------------------METHODS SORTS----------------------------- 
  

#ifndef GENERIC_SORTS
#define GENERIC_SORTS

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int cout1 = 0;
int cout2 = 0;

template<class T>
void printAll2(T data) { 
   for(int i = 0; i < 20; i++){
        cout<< data[i]<<" - ";
    }
    cout <<  endl;  
}

template<class T>
void insertionsort(T data[], const int n) {
    
     cout << "Vetor original "<< endl;
    printAll2(data);
    
    int coutFor1 =0, coutFor2 = 0;
    
    for (int i = 0, j; i < n; i++) {
        T tmp = data[i];
        coutFor1++;
        for (j = i; j > 0 && tmp < data[j-1]; j--) { 
            data[j] = data[j-1];
            coutFor2++;
        }
        data[j] = tmp;
    }
    
    cout << "Vetor ordenado "<< endl;
    printAll2(data);
    cout << "cout For 1: " << coutFor1 << endl;
    cout << "cout For 2: " <<  coutFor2 << endl;    
}

template<class T>
void selectionsort(T data[], const int n) {
    int cout1, cout2 = 0;
    for (int i = 0, least, j; i < n-1; i++) {
        cout1++;
        for (j = i+1, least = i; j < n; j++) {
             cout2++;
            if (data[j] < data[least])
                least = j;
        }
        swap(data[least],data[i]); //stl
    }

    printAll2(data);
}


//begin shellsort
//exemplo professor marcio passou passou shellsort
template<class T>
void insert2(T v[], int n, int incr){
    for (int i=incr; i<n; i +=incr)
        for (int j=i; (j >=incr) && (v[j] < v[j-incr]); j-=incr)
        swap(v, j, j-incr);
}

template<class T>
void shell_sort(T v[], int n) {
    for (int i= n/2; i>2; i/=2) {
        for (int j=0; j <i; j++) { 
            insert2(&v[j], n-j, i);
        }            
    }
    insert2(v, n, 1);
}
//END shell_short professor

template<class T>
void shellsort(T data[], const int n) {
    register int i, j, hCnt, h;
    int increments[20], k;
//  create an appropriate number of increments h
    for (h = 1, i = 0; h < n; i++) {
        increments[i] = h;
        h = 3*h + 1;
    }
 // loop on the number of different increments h
    for (i--; i >= 0; i--) {
        h = increments[i];
     // loop on the number of subarrays h-sorted in ith pass
        for (hCnt = h; hCnt < 2*h; hCnt++) {
         // insertion sort for subarray containing every hth element of array data
            for (j = hCnt; j < n; ) {
                T tmp = data[j];
                k = j;
                while (k-h >= 0 && tmp < data[k-h]) {
                    data[k] = data[k-h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }
        }
    }
}
//end shellsort

//begin heapsort
template<class T>
void moveDown (T data[], int first, int last) {
    int largest = 2*first + 1;
    while (largest <= last) {
        if (largest < last && // first has two children (at 2*first+1 and
            data[largest] < data[largest+1]) // 2*first+2) and the second
             largest++;                      // is larger than the first;

        if (data[first] < data[largest]) {   // if necessary,
             swap(data[first],data[largest]);// swap child and parent,
             first = largest;                // and move down;
             largest = 2*first+1;
        } else 
             largest = last+1;  // to exit the loop: the heap property
    }                           // isn't violated by data[first];
}

template<class T>
void heapsort(T data[], const int n) {
    int i;
    for (i = n/2 - 1; i >= 0; --i) // create the heap;
        moveDown (data,i,n-1);
    for (i = n-1; i >= 1; --i) {
        swap(data[0],data[i]);     // move the largest item to data[i];
        moveDown(data,0,i-1);      // restore the heap property;
    }
}
//end heapsort


//begin quicksort exemplo professor


//end quicksort exemplo professor

//begin quicksort
template<class T>
void quicksort(T data[], int first, int last) {
    int lower = first+1, upper = last;
    swap(data[first],data[(first+last)/2]);
    T bound = data[first];
    while (lower <= upper) {
        while (data[lower] < bound)
             lower++;
        while (bound < data[upper])
             upper--;
        if (lower < upper)
             swap(data[lower++],data[upper--]);
        else lower++;
    }
    swap(data[upper],data[first]);
    if (first < upper-1)
        quicksort (data,first,upper-1);
    if (upper+1 < last)
        quicksort (data,upper+1,last);
}

template<class T>
void quicksort(T data[], const int n) {
    int i, max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++)// find the largest
        if (data[max] < data[i])    // element and put it
            max = i;                // at the end of data[];
    swap(data[n-1],data[max]); // largest el is now in its
    quicksort(data,0,n-2);     // final position;
}
//end quicksort

//begin quicksort2
template<class T>
void insertionsort(T data[], int first, int last) {
    for (int i = first, j; i <= last; i++) {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }
}

template<class T>
void quicksort2(T data[], int first, int last) {
    if (last - first < 30)
         insertionsort(data,first,last);
    else {
         int lower = first+1, upper = last;
         swap(data[first],data[(first+last)/2]);
         T bound = data[first];
         while (lower <= upper) {
             while (data[lower] < bound)
                 lower++;
             while (bound < data[upper])
                 upper--;
             if (lower < upper)
                 swap(data[lower++],data[upper--]);
             else lower++;
         }
         swap(data[upper],data[first]);
         if (first < upper-1)
             quicksort2(data,first,upper-1);
         if (upper+1 < last)
             quicksort2(data,upper+1,last);
    }
}

template<class T>
void quicksort2(T data[], const int n) {
    int i, max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++)// find the largest
        if (data[max] < data[i])    // element and put it
            max = i;                // at the end of data[];
    swap(data[n-1],data[max]);  // largest el is now in its
    quicksort2(data,0,n-2);     // final position;
}
//end  quicksort2


//begin mergesort
template<class T>
void merge(T array1[], T temp[], int first, int last) {
    int mid = (first + last) / 2;
    int i1 = 0, i2 = first, i3 = mid + 1;
    while (i2 <= mid && i3 <= last)
        if (array1[i2] < array1[i3])
             temp[i1++] = array1[i2++];
        else temp[i1++] = array1[i3++];
    while (i2 <= mid)
        temp[i1++] = array1[i2++];
    while (i3 <= last)
        temp[i1++] = array1[i3++];
    for (i1 = 0, i2 = first; i2 <= last; array1[i2++] = temp[i1++]);
}

template<class T>
void mergesort(T data[], T temp[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergesort(data, temp, first, mid);
        mergesort(data, temp, mid+1, last);
        merge(data, temp, first, last);
    }
}

template<class T>
void mergesort(T data[], const int n) {
    T *temp = new T[n];
    mergesort(data,temp,0,n-1);
}
//end mergesort


#endif