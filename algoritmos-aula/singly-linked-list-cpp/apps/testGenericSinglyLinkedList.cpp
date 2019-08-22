#include <stdio.h>
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
   cout << endl;

   return 0;
}