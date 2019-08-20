#include <stdio.h>
#include <iostream>
#include "../include/genDLList.hpp"

int main() {
     
   DoublyLinkedList<int> doublyLinkedList;

   puts("add to head 10 11 12");
   doublyLinkedList.addToDLLHead(10);
   doublyLinkedList.addToDLLHead(11);
   doublyLinkedList.addToDLLHead(12);
   doublyLinkedList.printAllAsc();
   doublyLinkedList.printAllDesc();
   
   puts("add to tail 9 8 7");
   doublyLinkedList.addToDLLTail(9);
   doublyLinkedList.addToDLLTail(8);
   doublyLinkedList.addToDLLTail(7);

   doublyLinkedList.printAllAsc();
   doublyLinkedList.printAllDesc();
  
   puts("Delete head");
   doublyLinkedList.deleteFromDLLHead();
  
   puts("Delete tail");
   doublyLinkedList.deleteFromDLLTail();
   doublyLinkedList.printAllAsc();
   doublyLinkedList.printAllDesc();

   return 0;
}