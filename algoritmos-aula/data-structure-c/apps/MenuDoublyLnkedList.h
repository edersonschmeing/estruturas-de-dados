#ifndef MENU_DOUBLY_LINKED_LIST
#define MENU_DOUBLY_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

#include "../include/DoublyLinkedList.h"
 
 void menuDoublyLInkedList() { 
   DoublyLinkedList *doublyLinkedList = createDoublyLinkedList();

   int operation = 1;
   while (operation < 11 && operation > 0) {
      printf("---------------------------------------\n");   
      printf("               DATA STRUCTURE          \n");
      printf("             DOUBLY LINKED LIST        \n");
      printf("               OPERATION               \n");
      printf("---------------------------------------\n");   
      printf("01 - Add Head \n");
      printf("02 - Add Tail \n");
      printf("03 - Add Sorted \n");
      printf("04 - Delete From Head \n");
      printf("05 - Delete From Tail \n");
      printf("06 - Delete Node \n");
      printf("07 - Delete Position \n");     
      printf("08 - Search Key \n");
      printf("09 - Search Position \n"); 
      printf("10 - Print All  \n");
      printf("11 - Exit \n");
      printf("Choose an Operation: ");
      scanf("%d", &operation);
 
      int element;  

      switch (operation) {
      case 1:
         printf("01 - Add Head \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         addToHeadDoublyLinkedList(doublyLinkedList, element); 
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 2:
         printf("02 - Add Tail \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         addToTailDoublyLinkedList(doublyLinkedList, element);
         printAllAscDoublyLinkedList(doublyLinkedList);       
         break;
      case 3:
         printf("03 - Add Sorted \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         //addSortedLinkedList(doublyLinkedList, element);
         printAllAscDoublyLinkedList(doublyLinkedList);         
         break;      
      case 4:
         printf("04 - Delete Head \n"); 
         //deleteFromHeadDoublyLinkedList(doublyLinkedList, element);
         printAllAscDoublyLinkedList(doublyLinkedList);        
         break;
      case 5:         
         printf("05 - Delete Tail \n"); 
         //deleteFromTailDoublyLinkedList(doublyLinkedList, element);
         printAllAscDoublyLinkedList(doublyLinkedList);        
         break;
      case 6:         
         printf("06 -Delete Node \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         //deleteNodeDoublyLinkedList(singlyLinkedList, element);
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 7:         
         printf("07 -Delete Position \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         //deleteNodeDoublyLinkedList(doublyLinkedList, element);
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 8:   
         printf("08 - Search By Key \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
        /* if (findByElementDoublyLinkedList.(doublyLinkedList, element)) 
            printf("The element "<< element <<" in the Doubly Linked List" << endl; 
         else
            printf("The element "<< element <<" not in the Doubly Linked List" << endl;     */   

         break;
      case 9:   
         printf("08 - Search By Position \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         /*  if (findByElementDoublyLinkedList.(singlyLinkedList, element)) 
            cout << "The element "<< element <<" in the Doubly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Doubly Linked List" << endl;    */    
         break;
      case 10:
         printf("10 - Print All Asc \n");
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 11:
         printf("11 - Print All Desc \n"); 
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 12:
         printf("12 - Exit \n"); 
         break;   
      default:
         break;
      }    
     
   } 
}
#endif
