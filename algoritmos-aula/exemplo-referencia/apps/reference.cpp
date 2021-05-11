#include <iostream>

using namespace std;

int main() {
  
   int x, y;
   int& rx = x;
   int& ry = y;

   x = 13; 
   y = 10;
   rx = 42;
   ry++;

   cout << "x:  " << x << endl;
   cout << "y:  " << y << endl;
   cout << "rx:  " << rx << endl;
   cout << "ry:  " << ry << endl;
   cout << "rx&:  " << &rx << endl;
   cout << "x&:  " << &x << endl;   
   cout << "ry&:  " << &ry << endl;
   cout << "y&:  " << &y << endl;

   cout << "Example reference" << endl;
   
   
   return 0;
}