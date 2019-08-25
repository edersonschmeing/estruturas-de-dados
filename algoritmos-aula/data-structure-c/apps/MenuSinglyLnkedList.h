#ifndef MENU_SINGLY_LINKED_LIST
#define MENU_SINGLY_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>


#include "../include/SinglyLinkedList.h"
 
 void menuSinglyLInkedList() { 
   SinglyLinkedList *singlyLinkedList = createSinglyLinkedList();

   int operation = 1;
   while (operation < 11 && operation > 0) {
      printf("---------------------------------------\n");   
      printf("               DATA STRUCTURE          \n");
      printf("             SINGLY LINKED LIST        \n");
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

      switch (operation)       {
      case 1:
         printf("01 - Add Head \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         addToHeadSinglyLinkedList(singlyLinkedList, element); 
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 2:
         printf("02 - Add Tail \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         addToTailSinglyLinkedList(singlyLinkedList, element);       
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 3:
         printf("03 - Add Sorted \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         addSortedSinglyLinkedList(singlyLinkedList, element);
         printAllSinglyLinkedList(singlyLinkedList);         
         break;      
      case 4:
         printf("04 - Delete Head \n"); 
        // deleteFromHeadSinglyLinkedList(singlyLinkedList, element);;        
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 5:         
         printf("05 - Delete Tail \n"); 
        // deleteFromTailSinglyLinkedList(singlyLinkedList, element);;        
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 6:         
         printf("06 -Delete Node \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
        // deleteNodeSinglyLinkedList(singlyLinkedList, element);
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 7:         
         printf("07 -Delete Position \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         //deleteNodeFromSinglyLinkedList(singlyLinkedList, element);
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 8:   
         printf("08 - Search By Key \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
        /* if (findByElementSinglyLinkedList.(singlyLinkedList, element)) 
            printf("The element "<< element <<" in the Singly Linked List" << endl; 
         else
            printf("The element "<< element <<" not in the Singly Linked List" << endl;     */   

         break;
      case 9:   
         printf("09 - Search By Position \n"); 
         printf("Enter number: ");
         scanf("%d", &element);
         /*  if (findByElementSinglyLinkedList.(singlyLinkedList, element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;    */    
         break;
      case 10:
         printf("10 - Print All \n");
         printAllSinglyLinkedList(singlyLinkedList);
         break;
      case 11:
         printf("11 - Exit \n");
         break;   
       default:
         break;
      }  
   } 
}
#endif
