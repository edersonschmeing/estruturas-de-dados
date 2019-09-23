#include <stdio.h>
#include <iostream>
#include <string>
#include "../include/genQueue.h"

int main() {
     
   Queue<string> queue;

   puts("enqueue elements");
   // queue.enqueue(9);
   // queue.enqueue(8);
   // queue.enqueue(7);
   // queue.enqueue(6);
   // queue.enqueue(5);
   // queue.enqueue(4);
   // queue.enqueue(3);
   // queue.enqueue(2);
   // queue.enqueue(1);
   // queue.enqueue(0);

   queue.enqueue("A");
   queue.enqueue("B" );
   queue.enqueue("C");


   puts("All element");
   queue.printAll();
   cout << endl;
  
   puts("dequeue element");
   queue.dequeue();
   queue.printAll();
   cout << endl;

   puts("dequeue element");
   queue.dequeue();
   queue.printAll();
  
   return 0;
}