//**********************  genQueue.h  *************************
//     generic queue implemented with doubly linked list 

#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>

using namespace std;


template<class T>
class Queue {
public:
    
    Queue() { 
    }
    void clear() {
        lst.clear();
    }
    bool isEmpty() const { 
        return lst.empty();  
    }
    T& front() { 
        return lst.front();  
    }
    T dequeue() {
        T el = lst.front();
        lst.pop_front();
        return el;
    }
    void enqueue(const T& el) {
        lst.push_back(el);
    }
    
    void printAll() {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            cout <<  *it << " - ";
        } 
    }
    
    
private:
    list<T> lst;
};

#endif
