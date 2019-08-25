#include <stdio.h>
#include <stdlib.h>

#include "MenuDoublyLnkedList.h"
#include "MenuSinglyLnkedList.h"

void clearScreen() {
  //system("tput reset"); //linux
}

void dataStructureMenu() {
   int dataStructure = 1;
   while (dataStructure < 3 && dataStructure > 0) {

      printf("Operation \n");
      printf("Data Structure \n");
      printf("1 - Singly Linked List \n");
      printf("2 - Doubly Linked List \n");
      printf("3 - Stack \n");
      printf("4 - Queues \n");
      printf("99 - Exit \n");
      printf("Choose an option \n"); 
      scanf("%d", &dataStructure);
      //clearScreen();
      switch (dataStructure)       {
      case 1:
         printf("Data Structure choose 1 - Singly Linked List \n");
          menuSinglyLInkedList();
         break;
      case 2:
         printf("Data Structure choose 2 - Doubly Linked List \n");
         menuDoublyLInkedList();
         break;
      case 3:
         printf("Data Structure choose 3 - Stack - not implemented \n");
         //menuStack();
         break;
      case 4:
         printf("Data Structure choose 4 - Queues - not implemented \n");
         //menuQueues();
         break;   
      default:
         break;
      }
   }
}

int main() {
    
   dataStructureMenu();
     
   return 0;
}