#include <stdio.h>
#include "../include/intSLList.hpp"

int main() {
     
   IntSLList intSLList;

   puts("add to head 9 8 7");
   intSLList.addToHead(9);
   intSLList.addToHead(8);
   intSLList.addToHead(7);
   intSLList.printAll();
   
   puts("add to tail 4 5 6");
   intSLList.addToTail(4);
   intSLList.addToTail(5);
   intSLList.addToTail(6);
   intSLList.printAll();
  
   puts("Delete head");
   intSLList.deleteFromHead();
  
   puts("Delete tail");
   intSLList.deleteFromTail();
   intSLList.printAll();

   return 0;
}