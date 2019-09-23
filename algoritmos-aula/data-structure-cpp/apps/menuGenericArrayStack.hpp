
 #include "../include/GenericArrayStack.hpp"
 
using namespace std;

 void menuGenericArrayStack() { 
   ArrayStack<int, 5> arrayStack;

   int operation = 1;
   while (operation < 10 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "             DATA STRUCTURE            " << endl;   
      cout << "              ARRAY STACK              " << endl;    
      cout << "               OPERATION               " << endl;
      cout << "---------------------------------------" << endl;
      cout << "01 - Push" << endl;
      cout << "02 - Pop" << endl;
      cout << "03 - Print All" << endl;
      cout << "11 - Exit" << endl;
      cout << "Choose an Operation: ";
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "01 - Push" << endl; 
         cout << "Enter number: ";
         cin >> element;
         arrayStack.push(element);
         arrayStack.printAll();        
         break;
      case 2:
         cout << "02 - Pop" << endl; 
         arrayStack.pop();
         arrayStack.printAll();        
         break;
      case 3:
         cout << "03 - Print All" << endl;
            arrayStack.printAll();
         break;
      case 11:
         cout << "11 - Exit" << endl;
         break;   
       default:
         break;
      } 
        
   } 
}
