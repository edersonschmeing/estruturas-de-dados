#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

using namespace std;

template<class T>
class DoublyLinkedListNode {
public:
    DoublyLinkedListNode() {
        next = prev = 0;
    }
    DoublyLinkedListNode(const T& e, DoublyLinkedListNode<T> *n = 0, DoublyLinkedListNode<T> *p = 0) {
        element = e; next = n; prev = p;
    }
    T element;
    DoublyLinkedListNode<T> *next, *prev;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = tail = 0;
    }
    ~DoublyLinkedList() {
        clear();
    }
    bool isEmpty() const {
        return head == 0;
    }
    void clear();
    void setToNull() {
        head = tail = 0;
    }
    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(const T&); 

    T& firstElement();
    T* searchByKey(const T&) const;

    void printAllAsc() const;
    void printAllDesc() const;

protected:
    DoublyLinkedListNode<T> *head, *tail;
    
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {
        for (DoublyLinkedListNode<T> *tmp = doublyLinkedList.head; tmp != 0; tmp = tmp->next)
            out << tmp->element << ' ';
        return out;
    }
};

template<class T>
void DoublyLinkedList<T>::addToHead(const T& element) {
    if (head != 0) {
         head = new DoublyLinkedListNode<T>(element,head,0);
         head->next->prev = head;
    }
    else head = tail = new DoublyLinkedListNode<T>(element);
}

template<class T>
void DoublyLinkedList<T>::addToTail(const T& element) {
    if (tail != 0) {
         tail = new DoublyLinkedListNode<T>(element,0,tail);
         tail->prev->next = tail;
    }
    else head = tail = new DoublyLinkedListNode<T>(element);
}

template<class T>
T DoublyLinkedList<T>::deleteFromHead() {
    T element = head->element;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
         head = head->next;
         delete head->prev;
         head->prev = 0;
    }
    return element;
}

template<class T>
T DoublyLinkedList<T>::deleteFromTail() {
    T el = tail->element;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
         tail = tail->prev;
         delete tail->next;
         tail->next = 0;
    }
    return el;
}


template<class T>
void DoublyLinkedList<T>::deleteNode(const T& element) {
    if (head != 0) {                    // if non-empty list;
        if (head == tail && element == head->element) { // if only one
            delete head;                       // node on the list;
            head = tail = 0;
        }else if (element == head->element) {  // if more than one node on the list
            DoublyLinkedListNode<T> *tmp = head;
            head = head->next;
            delete tmp;              // and old head is deleted;
        }else {                        // if more than one node in the list
            DoublyLinkedListNode<T> *pred, *tmp;
            for (pred = head, tmp = head->next; // and a non-head node
                tmp != 0 && !(tmp->element == element);// is deleted;
                pred = pred->next, tmp = tmp->next);
                if (tmp != 0) {
                    pred->next = tmp->next;
                    if (tmp == tail)
                        tail = pred;
                    delete tmp;
            }
        }
    }    
}


template <class T>
T* DoublyLinkedList<T>::searchByKey(const T& element) const {
    DoublyLinkedListNode<T> *tmp = head;
    for ( ; tmp != 0 && !(tmp->element == element);  // overloaded ==
         tmp = tmp->next);
    if (tmp == 0)
         return 0;
    else return &tmp->element;
}

template<class T>
T& DoublyLinkedList<T>::firstElement() {
    return head->element;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    for (DoublyLinkedListNode<T> *tmp; head != 0; ) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<class T>
void DoublyLinkedList<T>::printAllAsc() const {
    cout << " Order ASC - HEAD->";
    for (DoublyLinkedListNode<T> *tmp = head; tmp != 0; tmp = tmp->next)
        cout << tmp->element << "->";
	cout << "TAIL" << endl;
}

template<class T>
void DoublyLinkedList<T>::printAllDesc() const {
   cout << " Order DESC TAIL->";
   for (DoublyLinkedListNode<T> *tmp = tail; tmp != 0; tmp = tmp->prev)
        cout << tmp->element << "->";
	cout << "HEAD" << endl;
}

#endif
