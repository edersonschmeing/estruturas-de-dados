#include <stdio.h>
#include "../include/GenericSinglyLinkedList.hpp"

int main() {
     
   SinglyLinkedList<int> singlyLinkedList;

   puts("add to head 9 8 7");
   singlyLinkedList.addToHead(9);
   singlyLinkedList.addToHead(8);
   singlyLinkedList.addToHead(7);
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