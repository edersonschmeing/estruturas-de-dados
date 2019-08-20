//**********************  genListStack.h  *************************
//     generic stack defined as a doubly linked list

#ifndef LL_STACK
#define LL_STACK

#include <list>

using namespace std;

template<class T>
class LLStack {
public:
    LLStack() { 
    }
    void clear() {
        lst.clear();
    }
    bool isEmpty() const { 
        return lst.empty();  
    }
    T& topEl() { 
        return lst.back();
    }
    T pop() { 
        T el = lst.back();
        lst.pop_back();  
        return el;
    }
    void push(const T& el) { 
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
