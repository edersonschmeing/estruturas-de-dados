

#include <stdio.h>
#include <iostream>
#include <string>
#include "menuGenericSinglyLnkedList.hpp"
#include "menuGenericDoublyLnkedList.hpp"

//#include <new>

using namespace std;


void clearScreen() {
  system("tput reset"); //linux
}

void dataStructureMenu() {
   int dataStructure = 1;
   while (dataStructure < 3 && dataStructure > 0) {
      cout << "Data Structure" << endl;
      cout << "1 - Singly Linked List" << endl;
      cout << "2 - Doubly Linked List" << endl;
      cout << "3 - Stack" << endl;
      cout << "4 - Queues" << endl;
      
      cout << "99 - Exit" << endl;
      cout << "Choose an option" << endl;
      cin >> dataStructure;
      //clearScreen();
      switch (dataStructure)       {
      case 1:
         cout << "Data Structure choose 1 - Singly Linked List" << endl;
          menuGenericSinglyLInkedList();
         break;
      case 2:
         cout << "Data Structure choose 2 - Doubly Linked List" << endl;
         menuGenericDoublyLInkedList();
         break;
      case 3:
         cout << "Data Structure choose 3 - Stack - not implemented " << endl;
         //menuGenericStack();
         break;
      case 4:
         cout << "Data Structure choose 4 - Queues - not implemented " << endl;
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