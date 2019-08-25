#ifndef MENU_SINGLY_LINKED_LIST
#define MENU_SINGLY_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>


#include "../include/SinglyLinkedList.h"
 
 void menuSinglyLInkedList() { 
   SinglyLinkedList *singlyLinkedList = createSinglyLinkedList();

   int operation = 1;
   while (operation < 11 && operation > 0) {
     
      printf("Operation \n");
      printf("1 - Add Head \n");
      printf("2 - Add Tail \n");
      printf("3 - Add Sorted \n");
      printf("4 - Delete From Head \n");
      printf("5 - Delete From Tail \n");
      printf("6 - Delete Node \n");
      printf("7 - Delete Position \n");      
      printf("8 - Search Key \n");
      printf("9 - Search Position \n");
      printf("10 - Print All  \n");
      printf("11 - Exit \n");
      printf("Choose an Operation \n");
      scanf("%d", &operation);

      int element;  

      switch (operation)       {
      case 1:
         printf("Chosen operation - 1 - Add Head \n"); 
         printf("Enter number \n");
         scanf("%d", &element);
         addToHeadSinglyLinkedList(singlyLinkedList, element); 
         break;
      case 2:
         printf("Chosen operation - 2 - Add Tail \n"); 
         printf("Enter number \n");
         scanf("%d", &element);
         addToTailSinglyLinkedList(singlyLinkedList, element);       
         break;
      case 3:
         printf("Chosen operation - 3 - Add Sorted \n"); 
         printf("Enter number \n");
         scanf("%d", &element);
         addSortedSinglyLinkedList(singlyLinkedList, element);         
         break;      
      case 4:
         printf("Chosen operation - 4 - Delete Head \n"); 
        // deleteFromHeadSinglyLinkedList(singlyLinkedList, element);;        
         break;
      case 5:         
         printf("Chosen operation - 5 - Delete Tail \n"); 
        // deleteFromTailSinglyLinkedList(singlyLinkedList, element);;        
         break;
      case 6:         
         printf("Chosen operation - 6 -Delete Node \n"); 
         printf("Enter number \n");
         scanf("%d", &element);
        // deleteNodeSinglyLinkedList(singlyLinkedList, element);
         break;
      case 7:         
         printf("Chosen operation - 7 -Delete Position \n"); 
         printf("Enter number \n");
         scanf("%d", &element);
         //deleteNodeFromSinglyLinkedList(singlyLinkedList, element);
         break;
      case 8:   
         printf("Chosen operation - 8 - Search By Key \n"); 
         printf("Enter number");
         scanf("%d", &element);
        /* if (findByElementSinglyLinkedList.(singlyLinkedList, element)) 
            printf("The element "<< element <<" in the Singly Linked List" << endl; 
         else
            printf("The element "<< element <<" not in the Singly Linked List" << endl;     */   

         break;
      case 9:   
         printf("Chosen operation - 8 - Search By Position \n"); 
         printf("Enter number");
         scanf("%d", &element);
         /*  if (findByElementSinglyLinkedList.(singlyLinkedList, element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;    */    
         break;
      case 10:
         printf("Chosen operation -  10 - Print All \n");
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 11:
         system("clear");
         break;   
       default:
         break;
      } 
        
   } 
}
#endif
