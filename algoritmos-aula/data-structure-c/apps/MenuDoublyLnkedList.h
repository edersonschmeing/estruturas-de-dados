#ifndef MENU_DOUBLY_LINKED_LIST
#define MENU_DOUBLY_LINKED_LIST

#include <stdio.h>
#include <stdio.h>

#include "../include/DoublyLinkedList.h"
 
 void menuDoublyLInkedList() { 
   DoublyLinkedList *doublyLinkedList = createDoublyLinkedList();

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
         printf("Chosen operation - 1 - Add Head"); 
         printf("Enter number");
         scanf("%d", &element);
         addToHeadDoublyLinkedList(doublyLinkedList, element); 
         break;
      case 2:
         printf("Chosen operation - 2 - Add Tail"); 
         printf("Enter number");
         scanf("%d", &element);
         addToTailDoublyLinkedList(doublyLinkedList, element);       
         break;
      case 3:
         printf("Chosen operation - 3 - Add Sorted"); 
         printf("Enter number");
         scanf("%d", &element);
         //addSortedLinkedList(doublyLinkedList, element);         
         break;      
      case 4:
         printf("Chosen operation - 4 - Delete Head"); 
         //deleteFromHeadDoublyLinkedList(doublyLinkedList, element);;        
         break;
      case 5:         
         printf("Chosen operation - 5 - Delete Tail"); 
         //deleteFromTailDoublyLinkedList(doublyLinkedList, element);;        
         break;
      case 6:         
         printf("Chosen operation - 6 -Delete Node"); 
         printf("Enter number");
         scanf("%d", &element);
         //deleteNodeDoublyLinkedList(singlyLinkedList, element);
         break;
      case 7:         
         printf("Chosen operation - 7 -Delete Position"); 
         printf("Enter number");
         scanf("%d", &element);
         //deleteNodeDoublyLinkedList(doublyLinkedList, element);
         break;
      case 8:   
         printf("Chosen operation - 8 - Search By Key"); 
         printf("Enter number");
         scanf("%d", &element);
        /* if (findByElementDoublyLinkedList.(doublyLinkedList, element)) 
            printf("The element "<< element <<" in the Doubly Linked List" << endl; 
         else
            printf("The element "<< element <<" not in the Doubly Linked List" << endl;     */   

         break;
      case 9:   
         printf("Chosen operation - 8 - Search By Position"); 
         printf("Enter number");
         scanf("%d", &element);
         /*  if (findByElementDoublyLinkedList.(singlyLinkedList, element)) 
            cout << "The element "<< element <<" in the Doubly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Doubly Linked List" << endl;    */    
         break;
      case 10:
         printf("Chosen operation -  10 - Print All Asc");
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 11:
         printf("Chosen operation -  11 - Print All Desc"); 
         printAllAscDoublyLinkedList(doublyLinkedList);
         break;
      case 12:
         // system("tput reset");
         break;   
       default:
         break;
      }  
        
   } 
}
#endif
