
#include <stdio.h>
#include <iostream>
//#include <string>
#include "menuGenericSinglyLnkedList.hpp"
#include "menuGenericDoublyLnkedList.hpp"

//#include <new>

using namespace std;


//Fazer o usuário escolher o tipo de dados da lista Int, String, Float etc.
void dataStructureMenu() {
   int dataStructure = 1;
   while (dataStructure < 3 && dataStructure > 0) {
      cout <<"--------------------------------------------"<< endl;   
      cout <<"               DATA STRUCTURE               "<< endl;
      cout <<"--------------------------------------------"<< endl;
      cout << "Data Structure" << endl;
      cout << "01 - Singly Linked List" << endl;
      cout << "02 - Doubly Linked List" << endl;
      cout << "03 - Stack" << endl;
      cout << "04 - Queues" << endl;
     
      cout << "15 - Sorts" << endl;
      cout << "99 - Exit" << endl;
      cout << "Choose an option" << endl;
      cin >> dataStructure;

      switch (dataStructure)       {
      case 1:
         cout << "01 - Singly Linked List" << endl;
          menuGenericSinglyLInkedList();
         break;
      case 2:
         cout << "02 - Doubly Linked List" << endl;
         menuGenericDoublyLInkedList();
         break;
      case 3:
         cout << "03 - Stack - not implemented " << endl;
         //menuGenericStack();
         break;
      case 4:
         cout << "04 - Queues - not implemented " << endl;
         //menuGenericQueues();
         break;
      case 15:
         cout << "15 - Sorts " << endl;
         //menuSorts();
         break;
   
      case 99:
         cout << "99 - Exit" << endl;
         //menuGenericQueues();
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