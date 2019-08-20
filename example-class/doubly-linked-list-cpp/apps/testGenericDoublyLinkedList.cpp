#include <stdio.h>
#include <iostream>
#include "../include/GenericDoublyLinkedList.hpp"

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