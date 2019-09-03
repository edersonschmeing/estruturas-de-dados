
 #include "../include/GenericSorts.hpp"
 
using namespace std;

bool exist(int data[], int size, int value){
    for(int i = 0; i < size; i++){
        if(data[i] == value)
            return true;
    }
    return false;
}

template<class T>
void generateRandomNumbers(T data[], int n, int limit){
    srand(time(NULL));
    int v;
    for(int i = 0; i < n; i++){
        v = 1 + rand() % limit;
        while(exist(data, i, v)){
            v = 1 + rand() % limit;
        }
        data[i] = v;
    }
}

template<class T>
void printAll(T data) { 
   for(int i = 0; i < 20; i++){
        cout<< data[i]<<" - ";
    }
    cout <<  endl;
}
void menuGenericSorts() { 
   
   int limit = 100;
   int size = 20;
   int data[size];
   generateRandomNumbers(data, size, limit);

   //bubblesortDesc(data)

     
   int operation = 1;
   while (operation < 16 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "             ORDINATION METHODS        " << endl;   
      cout << "                 SORTS                 " << endl;    
      cout << "---------------------------------------" << endl;
      cout << "01 - insertionsort" << endl;
      cout << "02 - selectionsort" << endl;
      cout << "03 - shellsort" << endl;
      cout << "04 - mergesort " << endl;
      cout << "05 - quicksort" << endl;
      cout << "06 - quicksort2" << endl;
      cout << "07 - heapsort" << endl;
      cout << "08 - bucketsort" << endl;
      
     /* cout << "03 - bubblesort" << endl;
      cout << "04 - combsort" << endl;
      cout << "08 - quicksort" << endl;
      cout << "11 - radixsort" << endl;
      cout << "12 - radixsort2" << endl;
      cout << "13 - countingsort" << endl;
      cout << "14 - bitRadixsort" << endl;
      cout << "15 - bitRadixsort2" << endl;
      cout << "99 - Exit" << endl; */
      cout << "Choose an Operation: ";
      cin >> operation;
      
     // int element;  
      
      cout << "Random Numbers" << endl;
      printAll(data);     
      switch (operation)       {
      case 1:
         cout << "01 - insertionsort" << endl;
         insertionsort(data, size);
         //InsertionSort<int> insertionSort 7
         //insertionSort.sort();
         //printAll(data);
         break;
      case 2:
         cout << "02 - selectionsort" << endl;
         selectionsort(data, size);
         //printAll(data); 
         break;
      case 3:
         cout << "03 - shellsort" << endl;
         shellsort(data, size);
         printAll(data); 
         break;
      case 4:
         cout << "04 - mergesort" << endl;
         mergesort(data, size);
         printAll(data);
         break;
      case 5:
         cout << "05 - quicksort" << endl;
         quicksort(data, size);
         printAll(data);
         break;
      case 6:
         cout << "06 - quicksort2" << endl;
         quicksort2(data, size);
         printAll(data);
         break;   
      case 7:
         cout << "07 - heapsort" << endl;
         heapsort(data, size);
         printAll(data);
         break;
         printAll(data);
         break;
      case 8:
         cout << "08 - bucketsort" << endl;
         //quicksort(data, size);
         //printAll(data);
         cout << "Not implemented" << endl;
         break;
      case 10:
         cout << "10 - Exit" << endl;
         break;   
       default:
         break;
      }         
   } 
}

int main() {
    
   menuGenericSorts();
     
   return 0;
   
}
