

 #include "../include/GenericDoublyLinkedList.hpp"
 
 void menuGenericDoublyLInkedList() { 
   DoublyLinkedList<int> doublyLinkedList;

   int operation = 1;
   while (operation < 11 && operation > 0) {
      cout << "---------------------------------------" << endl;   
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
      cout << "10 - Print All Asc" << endl;
      cout << "11 - Print All Desc" << endl;
      cout << "12 - Exit" << endl;
      cout << "Choose an Operation: ";
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "01 - Add Head" << endl; 
         cout << "Enter number: "; 
         cin >> element;
         doublyLinkedList.addToTail(element);
         doublyLinkedList.printAllAsc();        
         break;
      case 2:
         cout << "02 - Add Tail" << endl; 
         cout << "Enter number: ";
         cin >> element;
         doublyLinkedList.addToHead(element);
         doublyLinkedList.printAllAsc();        
         break;
      case 3:
         cout << "03 - Add Sorted" << endl; 
         cout << "Enter number: ";
         cin >> element;
         //singlyLinkedList.addToHead(element);
         doublyLinkedList.printAllAsc();        
         break;      
      case 4:
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
        /* if (doublyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;   */      
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
         cout << "10 - Print All Asc" << endl;
         doublyLinkedList.printAllAsc();
         break;
      case 11:
         cout << "11 - Print All Desc" << endl;
         doublyLinkedList.printAllDesc();
         break;
      case 12:
         cout << "12 - Exit" << endl;
         break;   
       default:
         break;
      }        
   } 
}
