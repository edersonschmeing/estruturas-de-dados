
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

template<class T>
void bubblesortDesc(T data[], const int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; --j)
            if (data[j] > data[j-1])
                swap(data[j],data[j-1]);
}

void menuGenericSorts() { 
   
   int limit = 100;
   int size = 20;
   int data[size];
   generateRandomNumbers(data, size, limit);

   //bubblesortDesc(data)

   int operation = 1;
   while (operation < 10 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "          MÉTODOS DE ORDENAÇÃO         " << endl;       
      cout << "---------------------------------------" << endl;
      cout << "01 - insertionsort" << endl;
      cout << "02 - selectionsort" << endl;
      cout << "03 - shellsort" << endl;
      cout << "04 - mergesort " << endl;
      cout << "05 - quicksort" << endl;
      cout << "06 - quicksort2" << endl;
      cout << "07 - heapsort" << endl;
      cout << "08 - heapsort min" << endl;
      cout << "09 - bucketsort" << endl;
      cout << "Escolha um método: ";
      cin >> operation;
    
      switch (operation)       {
      case 1:
         cout << "01 - insertionsort" << endl;
         insertionsort(data, size);
         //printAll(data);
         break;
      case 2:
         cout << "02 - selectionsort" << endl;
         //selectionsort(data, size);
         printAll(data);
         break;
      case 3:
         cout << "03 - shellsort" << endl;
         //shellsort(data, size);
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
      case 8:
         cout << "08 - heapsort min" << endl;
         heapsort(data, size);
         printAll(data);
         break;
      case 9:
         cout << "09 - bucketsort" << endl;
         //quicksort(data, size);
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
