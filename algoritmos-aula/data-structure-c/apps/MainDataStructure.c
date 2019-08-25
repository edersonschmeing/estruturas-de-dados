#include <stdio.h>
#include <stdlib.h>

#include "MenuDoublyLnkedList.h"
#include "MenuSinglyLnkedList.h"

int menu() {
   int dataStructure = 99;
   printf("--------------------------------------------\n");   
   printf("               DATA STRUCTURE               \n");
   printf("--------------------------------------------\n");
   printf("01 - Singly Linked List \n");
   printf("02 - Doubly Linked List \n");
   printf("03 - Stack \n");
   printf("04 - Queues \n");
   printf("05 - Sorts \n");
   printf("99 - Exit \n");
   printf("Choose an option: "); 
   scanf("%d", &dataStructure);
   return (int)dataStructure;
}


void dataStructureMenu() {
   int dataStructure = 1;
   while (dataStructure < 10 && dataStructure > 0) {
     
      dataStructure = menu();
           
      system("clear");

      switch (dataStructure)       {
      case 1:
         printf("01 - Singly Linked List \n");
          menuSinglyLInkedList();
         break;
      case 2:
         printf("02 - Doubly Linked List \n");
         menuDoublyLInkedList();
         break;
      case 3:
         printf("03 - Stack - not implemented \n");
         //menuStack();
         break;
      case 4:
         printf("04 - Queues - not implemented \n");
         //menuQueues();
         break;
      case 15:
         printf("15 - Sorts - not implemented  \n");
         //menuSorts();
         break;   
      case 99:
         printf("99 - Exit  \n");
         //menuSorts();
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