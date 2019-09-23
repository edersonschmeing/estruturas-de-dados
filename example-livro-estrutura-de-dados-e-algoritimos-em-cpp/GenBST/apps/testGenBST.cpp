#include <stdio.h>
#include <iostream>
#include <string>
#include "../include/genBST.h"

using namespace std;


int main() {
     
   BST<int> bst;
   puts("test BST");

   int operation = 1;
   while (operation < 11 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "             DATA STRUCTURE            " << endl;   
      cout << "                  BST                  " << endl;   
      cout << "               OPERATION               " << endl;
      cout << "---------------------------------------" << endl;
      cout << "01 - Insert" << endl;
      cout << "02 - In Order" << endl;
      cout << "03 - Pre Order " << endl;
      cout << "04 - Pos Order" << endl;
      cout << "05 - Search" << endl;
      /*cout << "06 - Delete Node" << endl;
      cout << "07 - Delete Position" << endl;     
      cout << "08 - Search Key" << endl;
      cout << "09 - Search Position" << endl;
      cout << "10 - Print All Asc" << endl;
      cout << "11 - Print All Desc" << endl; */
      cout << "12 - Exit" << endl;
      cout << "Choose an Operation: ";
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "01 - Insert" << endl; 
         cout << "Enter number: "; 
         cin >> element;
         bst.insert(element);
         break;
      case 2:
         cout << "02 - In Order" << endl; 
         bst.MorrisInorder();      
         cout << endl;    
         break;
      case 3:
         cout << "03 - Pos Order" << endl; 
         bst.preorder();      
         cout << endl;    
         break;
      case 4:
         cout << "04 - Pos Order" << endl; 
         bst.postorder();      
         cout << endl;    
         break;
      case 5:
         cout << "03 - Search" << endl; 
         cout << "Enter number: ";
         cin >> element;
         //BST<int>* node = bst.search(NULL, element);        
         break;      
      /*case 4:
         cout << "04 - Delete Head" << endl; 
         doublyLinkedList.deleteFromHead();
         doublyLinkedList.printAllAsc();        
         break;
      case 5:         
         cout << "05 - Delete Tail" << endl; 
         doublyLinkedList.deleteFromTail();
         doublyLinkedList.printAllAsc();        
         break;
      case 6:         
      cout << "06 -Delete Node" << endl; 
         cout << "Enter number: ";
         cin >> element;
         doublyLinkedList.deleteNode(element);
         doublyLinkedList.printAllAsc();        
         break;
      case 7:         
         cout << "07 -Delete Position" << endl; 
         cout << "Enter number: ";
         cin >> element;
         //singlyLinkedList.deleteNode(element);
         doublyLinkedList.printAllAsc();        
         break;
      case 8:   
         cout << "08 - Search By Key" << endl; 
         cout << "Enter number: ";
         cin >> element;
         if (doublyLinkedList.searchByKey(element) == NULL) 
            cout << "The element "<< element <<" not in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" in the Singly Linked List" << endl;   
         doublyLinkedList.printAllAsc();
         break;
      case 9:   
         cout << "08 - Search By Position" << endl; 
         cout << "Enter number: ";
         cin >> element;
         /*if (singlyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;        
         break;
      case 10:
         cout << "10 - Print All Asc" << endl;
         doublyLinkedList.printAllAsc();
         break; 
      case 11: 
         cout << "11 - Print All Desc" << endl;
         bst.printAllDesc();
         break; */
      case 12:
         cout << "12 - Exit" << endl;
         break;   
       default:
         break;
      }        
   } 

   return 0;
}