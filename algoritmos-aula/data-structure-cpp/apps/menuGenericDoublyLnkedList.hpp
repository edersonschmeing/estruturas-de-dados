

 #include "../include/GenericDoublyLinkedList.hpp"
 
 void menuGenericDoublyLInkedList() { 
   DoublyLinkedList<int> doublyLinkedList;

   int operation = 1;
   while (operation < 11 && operation > 0) {
      cout << "Operation" << endl;
      cout << "1 - Add Head" << endl;
      cout << "2 - Add Tail" << endl;
      cout << "3 - Add Sorted " << endl;
      cout << "4 - Delete From Head" << endl;
      cout << "5 - Delete From Tail" << endl;
      cout << "6 - Delete Node" << endl;
      cout << "7 - Delete Position" << endl;     
      cout << "8 - Search Key" << endl;
      cout << "9 - Search Position" << endl;
      cout << "10 - Print All Asc" << endl;
      cout << "11 - Print All Desc" << endl;
      cout << "12 - Exit" << endl;
      cout << "Choose an Operation" << endl;
      cin >> operation;
      
      int element;  

      switch (operation)       {
      case 1:
         cout << "Chosen operation - 1 - Add Head" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         doublyLinkedList.addToTail(element);        
         break;
      case 2:
         cout << "Chosen operation - 2 - Add Tail" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         doublyLinkedList.addToHead(element);        
         break;
      case 3:
         cout << "Chosen operation - 3 - Add Sorted" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         //singlyLinkedList.addToHead(element);        
         break;      
      case 4:
         cout << "Chosen operation - 4 - Delete Head" << endl; 
         doublyLinkedList.deleteFromHead();        
         break;
      case 5:         
         cout << "Chosen operation - 5 - Delete Tail" << endl; 
         doublyLinkedList.deleteFromTail();        
         break;
      case 6:         
      cout << "Chosen operation - 6 -Delete Node" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         doublyLinkedList.deleteNode(element);        
         break;
      case 7:         
         cout << "Chosen operation - 7 -Delete Position" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         //singlyLinkedList.deleteNode(element);        
         break;
      case 8:   
         cout << "Chosen operation - 8 - Search By Key" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
        /* if (doublyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;   */      
         break;
      case 9:   
         cout << "Chosen operation - 8 - Search By Position" << endl; 
         cout << "Enter number" << endl;
         cin >> element;
         /*if (singlyLinkedList.searchByKey(element)) 
            cout << "The element "<< element <<" in the Singly Linked List" << endl; 
         else
            cout << "The element "<< element <<" not in the Singly Linked List" << endl;    */    
         break;
      case 10:
         cout << "Chosen operation -  10 - Print All Asc" << endl;
            doublyLinkedList.printAllAsc();
         break;
      case 11:
         cout << "Chosen operation -  11 - Print All Desc" << endl;
            doublyLinkedList.printAllDesc();
         break;
      case 12:
          cout << "Chosen operation -  12 - Exit" << endl;
          system("tput reset");
         break;   
       default:
         break;
      } 
        
   } 
}
