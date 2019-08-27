#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include <iostream>

using namespace std;
 
template<class T, int size = 100>
class ArrayQueue {
public:
    ArrayQueue() { 
		first = last = -1; 
	}
    void enqueue(T);
    T dequeue();
    bool isFull()  { 
		return ((first == 0) && (last == size-1)) || (first == last + 1); 
	}
    bool isEmpty() { 
		return first == -1; 
	}
    void printAll();

private:
    int first, last;
    T storage[size];
};

template<class T, int size>
void ArrayQueue<T,size>::enqueue(T element) {
   if (!isFull())
        if (last == size-1 || last == -1) {
            storage[0] = element;
            last = 0;
            if (first == -1)
                first = 0;
        }
        else 
           storage[++last] = element;
   else 
      cout << "Full queue." << endl;
}

template<class T, int size>
T ArrayQueue<T,size>::dequeue() {   
	T tmp;
    tmp = storage[first];
    storage[first] = 0;
    if (first == last)
        last = first = -1;
    else if (first == size-1)
        first = 0;
    else
        first++; 
    return tmp;
}

template<class T, int size>
void ArrayQueue<T,size>::printAll() {
    for (unsigned i = 0; i < size; i++)   {
        cout << storage[i] << " - ";
    } 
    cout << "First: " << first << " Last: " << last << endl;
} 

#endif
