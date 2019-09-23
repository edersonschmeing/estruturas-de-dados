
 #include "../include/GenericArrayQueue.hpp"
 
using namespace std;

 void menuGenericArrayQueue() { 
   ArrayQueue<int, 5> arrayQueue;

   int operation = 1;
   while (operation < 10 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "             DATA STRUCTURE            " << endl;   
      cout << "              ARRAY QUEUE              " << endl;    
      cout << "               OPERATION               " << endl;
      cout << "---------------------------------------" << endl;
      cout << "01 - Enqueue" << endl;
      cout << "02 - Dequeue" << endl;
      cout << "03 - Print All" << endl;
      cout << "11 - Exit" << endl;
      cout << "Choose an Operation: ";
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "01 - Enqueue" << endl; 
         cout << "Enter number: ";
         cin >> element;
         arrayQueue.enqueue(element);
         arrayQueue.printAll();        
         break;
      case 2:
         cout << "02 - Dequeue" << endl; 
         arrayQueue.dequeue();
         arrayQueue.printAll();        
         break;
      case 3:
         cout << "03 - Print All" << endl;
            arrayQueue.printAll();
         break;
      case 11:
         cout << "11 - Exit" << endl;
         break;   
       default:
         break;
      } 
        
   } 
}
