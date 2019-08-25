/*#include <iostream>
#include <new>
#include <string>
#include <stdio.h>
#include <stdlib.h> */

#include "../include/GenericSinglyLinkedList.hpp"

/*- Cria lista
- Insere elemento 1
- Insere elemento 4
- Insere elemento 5
- Insere elemento 6
- Mostra elementos da lista
- Busca elemento 7
- Remove elemento 5
- Mostra elementos da lista
- Busca elemento 6
- Remove elemento 1
- Busca elemento 1
- Mostra elementos da lista 
*/

int main() {
   
   SinglyLinkedList<int> singlyLinkedList;

   int operation = 1;
   while (operation < 11 && operation > 0) {
      cout << "Operation" << endl;
      cout << "1 - Add Head" << endl;
      cout << "2 - Add Tail" << endl;
      cout << "3 - Add Sorted " << endl;
      cout << "4 - Delete From Head" << endl;
      cout << "5 - Delete From Tail" << endl;
      cout << "6 - Delete Node" << endl;
      cout << "7 - Delete Position" << endl;     
      cout << "8 - Search Key" << endl;
      cout << "9 - Search Position" << endl;
      cout << "10 - Print All" << endl;
      cout << "11 - Exit" << endl;
      cout << "Choose an Operation" << endl;
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "Chosen operation - 1 - Add Head" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         singlyLinkedList.addToTail(element);        
         break;
      case 2:
         cout << "Chosen operation - 2 - Add Tail" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         singlyLinkedList.addToHead(element);        
         break;
      case 3:
         cout << "Chosen operation - 3 - Add Sorted" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         //singlyLinkedList.addToHead(element);        
         break;      
      case 4:
         cout << "Chosen operation - 4 - Delete Head" << endl; 
         singlyLinkedList.deleteFromHead();        
         break;
      case 5:         
         cout << "Chosen operation - 5 - Delete Tail" << endl; 
         singlyLinkedList.deleteFromTail();        
         break;
      case 6:         
      cout << "Chosen operation - 6 -Delete Node" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         singlyLinkedList.deleteNode(element);        
         break;
      case 7:         
         cout << "Chosen operation - 7 -Delete Position" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         //singlyLinkedList.deleteNode(element);        
         break;
      case 8:   
         cout << "Chosen operation - 8 - Search By Key" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         if (singlyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;        

         break;
      case 9:   
         cout << "Chosen operation - 8 - Search By Position" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         /*if (singlyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;        
         break; */
      case 10:
         cout << "Chosen operation -  10 - Print All" << endl;
            singlyLinkedList.printAll();
         break;
       default:
         break;
      } 
        
   } 

  /* 
   
   SinglyLinkedList<int> singlyLinkedList;
  
   puts("add to head 1 4 5");
   singlyLinkedList.addToHead(1);
   singlyLinkedList.addToHead(4);
   singlyLinkedList.addToHead(5);
   singlyLinkedList.printAll();
   cout << endl;

   puts("add to tail 4 5 6");
   singlyLinkedList.addToTail(4);
   singlyLinkedList.addToTail(5);
   singlyLinkedList.addToTail(6);
   singlyLinkedList.printAll();
   cout << endl;  

   puts("Delete head");
   singlyLinkedList.deleteFromHead();
  
   cout << endl;
   puts("Delete tail");
   singlyLinkedList.deleteFromTail();
   singlyLinkedList.printAll();
   cout << endl; */

   return 0;
}