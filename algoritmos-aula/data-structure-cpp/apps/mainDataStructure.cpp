
#include <stdio.h>
#include <iostream>
//#include <string>
#include "menuGenericSinglyLnkedList.hpp"
#include "menuGenericDoublyLnkedList.hpp"
#include "menuGenericArrayQueue.hpp"
#include "menuGenericArrayStack.hpp"
#include "menuGenericSorts.hpp"

//#include <new>

using namespace std;

//Fazer o usuário escolher o tipo de dados da lista Int, String, Float etc.
void dataStructureMenu() {
   int dataStructure = 1;
   while (dataStructure < 12 && dataStructure > 0) {
      cout <<"--------------------------------------------"<< endl;   
      cout <<"               DATA STRUCTURE               "<< endl;
      cout <<"--------------------------------------------"<< endl;
      cout << "01 - Singly Linked List - Queue - Stack" << endl;
      cout << "02 - Doubly Linked List - Deque" << endl;
      cout << "03 - Array Queues" << endl;
      cout << "04 - Array Stack" << endl;      
      cout << "05 - Sorts" << endl;
      cout << "99 - Exit" << endl;
      cout << "Choose an option" << endl;
      cin >> dataStructure;

      system("clear"); 

      switch (dataStructure)       {
      case 1:
         cout << "01 - Singly Linked List - Queue - Stack" << endl;
          menuGenericSinglyLInkedList();
         break;
      case 2:
         cout << "02 - Doubly Linked List - Deque" << endl;
         menuGenericDoublyLInkedList();
         break;
      case 3:
         cout << "03 - Array Queues" << endl;
         menuGenericArrayQueue();
         break;
      case 4:
         cout << "04 - Array QueuesStack " << endl;
         menuGenericArrayStack();
         break;
      case 5:
         cout << "10 - Sorts " << endl;
         menuGenericSorts();
         break;
   
      case 99:
         cout << "99 - Exit" << endl;
         break;      
      default:
         break;
      }
   }
}

int main() {
    
   dataStructureMenu();
     
   return 0;
   
}