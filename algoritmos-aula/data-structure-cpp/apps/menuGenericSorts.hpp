
 #include "../include/GenericSorts.hpp"
  #include "../include/GenericInsertionSort.hpp"
 
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
   for(int i = 0; i < 100; i++){
        cout<< data[i]<<" - ";
    }
    cout <<  endl;
}

void menuGenericSorts() { 
   
   int limit = 1000;
   int size = 100;
   int data[size];
   generateRandomNumbers(data, size, limit);

   //quicksort(data, size); //ordenar antes de chamar o algoritmos de ordenação para testar 
   //bubblesortDesc(data, size);
   
  
   int operation = 1;
   while (operation < 16 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "             ORDINATION METHODS        " << endl;   
      cout << "                 SORTS                 " << endl;    
      cout << "---------------------------------------" << endl;
      cout << "01 - insertionsort" << endl;
      cout << "02 - selectionsort" << endl;
      cout << "03 - bubblesort" << endl;
      cout << "04 - combsort" << endl;
      cout << "05 - Shellsort" << endl;
      cout << "06 - heapsort" << endl;
      cout << "07 - quicksort first and last" << endl;
      cout << "08 - quicksort" << endl;
      cout << "09 - quicksort2 first and last" << endl;
      cout << "10 - quicksort2" << endl;
      cout << "11 - radixsort" << endl;
      cout << "12 - radixsort2" << endl;
      cout << "13 - countingsort" << endl;
      cout << "14 - bitRadixsort" << endl;
      cout << "15 - bitRadixsort2" << endl;
      cout << "99 - Exit" << endl;
      cout << "Choose an Operation: ";
      cin >> operation;
      
      int element;  
      
      cout << "Random Numbers" << endl;
      printAll(data); 
      
      switch (operation)       {
      case 1:
         cout << "01 - insertionsort" << endl;
         insertionsort(data, size);
         //InsertionSort<int> insertionSort (data, size);
         //insertionSort.sort();

         //printAll(data);
         break;
      case 2:
         cout << "02 - selectionsort" << endl;
         selectionsort(data, size);
         //printAll(data); 
         break;
      case 3:
         cout << "03 - bubblesort" << endl;
         bubblesort(data, size);
         printAll(data); 
         break;
      case 4:
         cout << "04 - combsort" << endl;
         combsort(data, size);
         printAll(data);
         break;
      case 5:
         cout << "05 - Shellsort" << endl;
         Shellsort(data, size);
         //printAll(data);
         break;
      case 6:
         cout << "06 - heapsort" << endl;
         heapsort(data, size);
         printAll(data);
         break;
      case 7:
         cout << "07 - quicksort first and last" << endl;
         quicksort(data, 0, size-1);
         printAll(data);
         break;
      case 8:
         cout << "08 - quicksort" << endl;
         quicksort(data, size);
         printAll(data);
         break;
      case 9:
         cout << "09 - quicksort2 first and last" << endl;
         quicksort2(data, size);
         printAll(data);
         break;
      case 10:
         cout << "10 - quicksort2" << endl;
         quicksort2(data, size);
         printAll(data);
         break;
      case 11:
         cout << "11 - radixsort" << endl;
         radixsort(data, size);
         printAll(data);
         break;
      case 12:
         cout << "12 - radixsort2" << endl;
         //radixsort2(data, size);
         printAll(data);
         break;
      case 13:
         cout << "13 - countingsort" << endl;
         //countingsort(data, size);
         printAll(data);
         break;
      case 14:
         cout << "14 - bitRadixsort" << endl;
         //bitRadixsort(data, size, 5);
         printAll(data);
         break;
      case 15:
         cout << "15 - bitRadixsort2" << endl;
         //bitRadixsort2(data, size, 5);
         printAll(data);
         break;
      case 99:
         cout << "99 - Exit" << endl;
         break;   
       default:
         break;
      } 
        
   } 
}
