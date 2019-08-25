#include <stdio.h>
#include <iostream>
#include <string>
//#include <new>

using namespace std;

void clearScreen() {
  system("tput reset"); //linux
}

void operationMenu() {
   
   int operation = 1;
   while (operation < 10 && operation > 0) {
      cout << "Operation" << endl;
      cout << "1 - Create List" << endl;
      cout << "1 - Add Head" << endl;
      cout << "2 - Add Tail" << endl;
      cout << "3 - Delete From Head" << endl;
      cout << "4 - Delete From Tail" << endl;
      cout << "5 - Delete Node" << endl;
      cout << "6 - Delete Node" << endl;
      cout << "7 - Search Key" << endl;
      cout << "8 - Search Position" << endl;
      cout << "10 - Print All" << endl;
      cout << "99 - Exit" << endl;
      cout << "Choose an Operation" << endl;
      cin >> operation;
      switch (operation)       {
      case 1:
         cout << "1 - Create List" << endl;
         break;
      case 2:
         cout << "2 - Add Head" << endl;
         break;
       default:
         break;
      }   
   } 
}   

int main() {

   int dataStructure = 1;
   while (dataStructure < 3 && dataStructure > 0) {
      cout << "Data Structure" << endl;
      cout << "1 - Singly Linked List" << endl;
      cout << "2 - Doubly Linked List" << endl;
      cout << "99 - Exit" << endl;
      cout << "Choose an option" << endl;
      cin >> dataStructure;
      //clearScreen();
      switch (dataStructure)       {
      case 1:
         operationMenu();
         cout << "Data Structure choose 1 - Singly Linked List" << endl;

         break;
      case 2:
         cout << "Data Structure choose 2 - Doubly Linked List" << endl;
         break;
      case 99:
         cout << "Exit" << endl;
         break;
        default:
         break;
      }
   } 
     
   return 0;
}