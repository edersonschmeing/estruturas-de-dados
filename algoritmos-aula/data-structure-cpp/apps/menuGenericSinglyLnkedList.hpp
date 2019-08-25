
 #include "../include/GenericSinglyLinkedList.hpp"
 
using namespace std;

 void menuGenericSinglyLInkedList() { 
   SinglyLinkedList<int> singlyLinkedList;

   int operation = 1;
   while (operation < 11 && operation > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "             DATA STRUCTURE            " << endl;   
      cout << "           SINGLY LINKED LIST          " << endl;   
      cout << "               OPERATION               " << endl;
      cout << "---------------------------------------" << endl;
      cout << "01 - Add Head" << endl;
      cout << "02 - Add Tail" << endl;
      cout << "03 - Add Sorted " << endl;
      cout << "04 - Delete From Head" << endl;
      cout << "05 - Delete From Tail" << endl;
      cout << "06 - Delete Node" << endl;
      cout << "07 - Delete Position" << endl;     
      cout << "08 - Search Key" << endl;
      cout << "09 - Search Position" << endl;
      cout << "10 - Print All" << endl;
      cout << "11 - Exit" << endl;
      cout << "Choose an Operation: ";
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "01 - Add Head" << endl; 
         cout << "Enter number: ";
         cin >> element;
         singlyLinkedList.addToHead(element);
         singlyLinkedList.printAll();        
         break;
      case 2:
         cout << "02 - Add Tail" << endl; 
         cout << "Enter number: ";
         cin >> element;
         singlyLinkedList.addToTail(element);
         singlyLinkedList.printAll();        
         break;
      case 3:
         cout << "03 - Add Sorted" << endl; 
         cout << "Enter number: ";
         cin >> element;
         //singlyLinkedList.addToHead(element);
         singlyLinkedList.printAll();       
         break;      
      case 4:
         cout << "04 - Delete Head" << endl; 
         singlyLinkedList.deleteFromHead();
         singlyLinkedList.printAll();        
         break;
      case 5:         
         cout << "05 - Delete Tail" << endl; 
         singlyLinkedList.deleteFromTail(); 
         singlyLinkedList.printAll();       
         break;
      case 6:         
         cout << "06 -Delete Node" << endl; 
         cout << "Enter number: ";
         cin >> element;
         singlyLinkedList.deleteNode(element);
         singlyLinkedList.printAll();        
         break;
      case 7:         
         cout << "07 -Delete Position" << endl; 
         cout << "Enter number: " ;
         cin >> element;
         //singlyLinkedList.deleteNode(element);
         singlyLinkedList.printAll();        
         break;
      case 8:   
         cout << "08 - Search By Key" << endl; 
         cout << "Enter number: " ;
         cin >> element;
         if (singlyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;        
         singlyLinkedList.printAll();  
         break;
      case 9:   
         cout << "08 - Search By Position" << endl; 
         cout << "Enter number: ";
         cin >> element;
         /*if (singlyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;    */    
         break;
      case 10:
         cout << "10 - Print All" << endl;
            singlyLinkedList.printAll();
         break;
      case 11:
         cout << "11 - Exit" << endl;
         break;   
       default:
         break;
      } 
        
   } 
}
