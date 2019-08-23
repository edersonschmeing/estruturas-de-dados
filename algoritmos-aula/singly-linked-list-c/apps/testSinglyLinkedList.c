#include <stdio.h>
#include "../include/SinglyLinkedList.h"

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

//CTRL + K + C add line comment 
//CTRL + K + U remove line comment


int main() {

   SinglyLinkedList *singlyLinkedList = createSinglyLinkedList();

   addToHeadSinglyLinkedList(singlyLinkedList, 1);
   addToHeadSinglyLinkedList(singlyLinkedList, 4);
   addToHeadSinglyLinkedList(singlyLinkedList, 5);
   addToHeadSinglyLinkedList(singlyLinkedList, 6);
   
   printAllSinglyLinkedList(singlyLinkedList);

   addToTailSinglyLinkedList(singlyLinkedList, 1);
   addToTailSinglyLinkedList(singlyLinkedList, 4);
   addToTailSinglyLinkedList(singlyLinkedList, 5);
   addToTailSinglyLinkedList(singlyLinkedList, 6);

   printAllSinglyLinkedList(singlyLinkedList);

   destroySinglyLinkedList(&singlyLinkedList);
   
  // addToHeadDoublyLinkedList(doublyLinkedList, 4);
  // addToHeadDoublyLinkedList(doublyLinkedList, 2);
  // addToHeadDoublyLinkedList(doublyLinkedList, 10);

  //  addToTailDoublyLinkedList(doublyLinkedList, 10);
  //  addToTailDoublyLinkedList(doublyLinkedList, 8);
  //  addToTailDoublyLinkedList(doublyLinkedList, 14);
  //  addToTailDoublyLinkedList(doublyLinkedList, 7);

  //  printAllAscDoublyLinkedList(doublyLinkedList);
  //  printAllDescDoublyLinkedList(doublyLinkedList);
  
  //  printf("deletando the element 4");
  //  deleteFromDoublyLinkedListNode(doublyLinkedList, 14);
  //  printf("\n");

  //  printAllAscDoublyLinkedList(doublyLinkedList);
  //  printAllDescDoublyLinkedList(doublyLinkedList);

  //  printf("deletando the element 7");
  //  deleteFromDoublyLinkedListNode(doublyLinkedList, 7);
   
  //  printf("\n");

  //  printAllAscDoublyLinkedList(doublyLinkedList);
  //  printAllDescDoublyLinkedList(doublyLinkedList);

   
  //  destroyDoublyLinkedList(&doublyLinkedList);
   

   return 0;
}