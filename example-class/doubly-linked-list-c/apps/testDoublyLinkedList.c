#include <stdio.h>
#include "../include/DoublyLinkedList.h"

int main() {

   DoublyLinkedList *doublyLinkedList = createDoublyLinkedList();
   
 //  addToHeadDoublyLinkedList(doublyLinkedList, 4);
 //  addToHeadDoublyLinkedList(doublyLinkedList, 2);
 //  addToHeadDoublyLinkedList(doublyLinkedList, 10);

   addToTailDoublyLinkedList(doublyLinkedList, 10);
   addToTailDoublyLinkedList(doublyLinkedList, 8);
   addToTailDoublyLinkedList(doublyLinkedList, 14);
   addToTailDoublyLinkedList(doublyLinkedList, 7);

   printAllAscDoublyLinkedList(doublyLinkedList);
   printAllDescDoublyLinkedList(doublyLinkedList);
  
   printf("deletando the element 4");
   deleteFromDoublyLinkedListNode(doublyLinkedList, 14);
   printf("\n");

   printAllAscDoublyLinkedList(doublyLinkedList);
   printAllDescDoublyLinkedList(doublyLinkedList);

   printf("deletando the element 7");
   deleteFromDoublyLinkedListNode(doublyLinkedList, 7);
   
   printf("\n");

   printAllAscDoublyLinkedList(doublyLinkedList);
   printAllDescDoublyLinkedList(doublyLinkedList);

   
   destroyDoublyLinkedList(&doublyLinkedList);
   

   return 0;
}