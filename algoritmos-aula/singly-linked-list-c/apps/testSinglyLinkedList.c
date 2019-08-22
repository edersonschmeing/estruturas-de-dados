#include <stdio.h>
#include "../include/DoublyLinkedList.h"

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