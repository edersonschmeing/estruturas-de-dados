#include <stdio.h>
#include <iostream>
#include <string>
#include "../include/genArrayQueue.h"

int main() {
     
   ArrayQueue<int, 10> array_queue;
   
   puts("empty elements");
   array_queue.printAll();

   puts("enqueue elements");  
   array_queue.enqueue(1);
   array_queue.enqueue(2);
   array_queue.enqueue(3);
   array_queue.enqueue(4);
   array_queue.enqueue(5);
   array_queue.enqueue(6);
   array_queue.enqueue(7);
   array_queue.enqueue(8);
   array_queue.enqueue(9);
   array_queue.enqueue(10);
   
  
   puts("All element");
   array_queue.printAll();
  
   puts("1 dequeue e enqueue element");
   array_queue.dequeue();
   array_queue.enqueue(11);
   array_queue.printAll();
   
   puts("2 dequeue e enqueue element");
   array_queue.dequeue();
   array_queue.enqueue(13);
   array_queue.printAll();
  
   puts("3 dequeue element");
   array_queue.dequeue();
   array_queue.printAll();
   
   puts("4 dequeue element");
   array_queue.dequeue();
   array_queue.printAll();
  
   puts("5 enqueue element");  
   array_queue.enqueue(15);
   array_queue.printAll();

   return 0;
}