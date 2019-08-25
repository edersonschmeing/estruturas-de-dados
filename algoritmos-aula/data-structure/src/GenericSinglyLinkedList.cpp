//************************  GenericSinglyLinkedList.cpp  **************************

#include <iostream>
#include "GenericSinglyLinkedList.hpp"

using namespace std;

/*template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = 0;
    tail = 0;
    cout << "Constructor class";
}


template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    cout << "Destructor class";
    for (SinglyLinkedListNode<T> *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    } 
}

template<class T>
bool SinglyLinkedList<T>:: isEmpty() const {
     return head == 0;
}

template<class T>
void SinglyLinkedList<T>::addToHead(const T& element) const{
    head = new SinglyLinkedListNode<T>(element,head);
    if (tail == 0)
       tail = head;
}

template<class T>
void SinglyLinkedList<T>::addToTail(const T& element) const {
    if (tail != 0) {      // if list not empty;
       tail->next = new SinglyLinkedList<T>(element);
       tail = tail->next;
    }
    else 
       head = tail = new SinglyLinkedListNode<T>(element); //verificar
}

template<class T>
T SinglyLinkedList<T>::deleteFromHead() const{
    int el = head->info;
    SinglyLinkedListNode<T> *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

template<class T>
T SinglyLinkedList<T>::deleteFromTail() const {
    T element = tail->element;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else {                // if more than one node in the list,
         SinglyLinkedListNode<T> *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
    return element;
}

template<class T>
void SinglyLinkedList<T>::deleteNode(const T& element) const {
    if (head != 0)                     // if non-empty list;
         if (head == tail && element == head->element) { // if only one
              delete head;                       // node on the list;
              head = tail = 0;
         }
         else if (element == head->element) {  // if more than one node on the list
              SinglyLinkedListNode<T> *tmp = head;
              head = head->next;
              delete tmp;              // and old head is deleted;
         }
         else {                        // if more than one node in the list
              SinglyLinkedListNode<T> *pred, *tmp;
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

template<class T>
bool SinglyLinkedList<T>::isInList(const T& element) const {
    SinglyLinkedListNode<T> *tmp;
    for (tmp = head; tmp != 0 && !(tmp->element == element); tmp = tmp->next);
    return tmp != 0;
}


template<class T>
void SinglyLinkedList<T>::printAll() const {
    for (SinglyLinkedListNode<T>*tmp = head; tmp != 0; tmp = tmp->next)
        cout << tmp->element << " ";
	cout << endl;
} */

