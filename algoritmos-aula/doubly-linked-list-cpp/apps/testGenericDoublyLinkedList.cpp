#include <stdio.h>
#include <iostream>
#include "../include/GenericDoublyLinkedList.hpp"

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
     
   DoublyLinkedList<int> doublyLinkedList;

   puts("add to head 10 11 12");
   doublyLinkedList.addToHead(10);
   doublyLinkedList.addToHead(11);
   doublyLinkedList.addToHead(12);
   
   doublyLinkedList.printAllAsc();
   doublyLinkedList.printAllDesc();
   
   puts("add to tail 9 8 7");
   doublyLinkedList.addToTail(9);
   doublyLinkedList.addToTail(8);
   doublyLinkedList.addToTail(7);

   doublyLinkedList.printAllAsc();
   doublyLinkedList.printAllDesc();
  
   puts("Delete head");
   doublyLinkedList.deleteFromHead();
  
   puts("Delete tail");
   doublyLinkedList.deleteFromTail();
   doublyLinkedList.printAllAsc();
   doublyLinkedList.printAllDesc();

   return 0;
}