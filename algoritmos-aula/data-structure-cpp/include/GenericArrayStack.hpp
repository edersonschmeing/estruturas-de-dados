#ifndef ARRAY_STACK
#define ARRAY_STACK

#include <iostream>

using namespace std;
 
template<class T, int size = 100>
class ArrayStack {
public:
    ArrayStack() { 
		top = -1; 
	}
    void push(T);
    T pop();
    bool isFull()  { 
		return (top == size-1); 
	}
    bool isEmpty() { 
		return top == -1; 
	}
    void printAll();

private:
    int top;
    T storage[size];
};

template<class T, int size>
void ArrayStack<T,size>::push(T element) {
    if(!isFull()) {
       top++;
       storage[top] = element; 
    }else {
       cout << "Full stack." << endl;
    }
}

template<class T, int size>
T ArrayStack<T,size>::pop() {   
    if(!isEmpty()) {
       int element = storage[top];
       storage[top] = 0;
       top--;
       return element; 
    }else {
       cout << "Empty stack." << endl;
    }
}  
	
template<class T, int size>
void ArrayStack<T,size>::printAll() {
    
    for (unsigned i = 0; i < size; i++)   {
        cout << storage[i] << " -> ";
    } 
    cout << "Top: " << top << endl;
} 

#endif
