#include <stdio.h>
#include <iostream>
#include "../include/genStack.h"

int main() {
     
   Stack<int, 10> stack;

   puts("push elements");
   stack.push(9);
   stack.push(8);
   stack.push(7);
   stack.push(6);
   stack.push(5);
   stack.push(4);
   stack.push(3);
   stack.push(2);
   stack.push(1);
   stack.push(0);

   puts("All element");
   stack.printAll();
   cout << endl;
  
   puts("Pop element");
   stack.pop();
   stack.printAll();
   cout << endl;

   puts("Pop element");
   stack.pop();
   stack.printAll();
  
   return 0;
}