#ifndef GENERIC_SINGLY_LINKED_LIST
#define GENERIC_SINGLY_LINKED_LIST

#include <iostream>

using namespace std;

template<class T>
class SinglyLinkedListNode {
public:
    SinglyLinkedListNode() {
        next = 0;
    }
    SinglyLinkedListNode(const T& e, SinglyLinkedListNode<T> *n = 0) {
        element = e;
        next = n;
    }
    T element;
    SinglyLinkedListNode<T> *next;
};

template<class T>
class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
   
    bool isEmpty() const; 
    
    void addToHead(const T&);
    void addToTail(const T&);
    
    void addSorted(const T&);

    T deleteFromHead(); 
    T deleteFromTail(); 
    
    void deleteNode(const T&);
    bool searchByKey(const T&) const;
    bool searchByPosition(int position);
 
    //int size();
    
    void printAll() const;
   

private:
    SinglyLinkedListNode<T> *head, *tail;
};


template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = 0, tail = 0;
    cout << "Constructor class" << endl;
}


template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    cout << "Destructor class" << endl;
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
void SinglyLinkedList<T>::addToHead(const T& element) {
    head = new SinglyLinkedListNode<T>(element, head);
    if (tail == 0)
       tail = head;
}

template<class T>
void SinglyLinkedList<T>::addToTail(const T& element) {
    if (tail != 0) {      // if list not empty;
       tail->next = new SinglyLinkedListNode<T>(element);
       tail = tail->next;
    }
    else 
       head = tail = new SinglyLinkedListNode<T>(element); //verificar
}

template<class T>
T SinglyLinkedList<T>::deleteFromHead() {
    T element = head->element;
    SinglyLinkedListNode<T> *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return element;
}

template<class T>
T SinglyLinkedList<T>::deleteFromTail() {
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
void SinglyLinkedList<T>::deleteNode(const T& element) {
    if (head != 0) {                     // if non-empty list;
        if (head == tail && element == head->element) { // if only one
            delete head;                       // node on the list;
            head = tail = 0;
        }else if (element == head->element) {  // if more than one node on the list
            SinglyLinkedListNode<T> *tmp = head;
            head = head->next;
            delete tmp;              // and old head is deleted;
        } else {  
            SinglyLinkedListNode<T> *pred, *tmp;
            pred = head;
            tmp = head->next;
            while ((tmp != 0) && !(tmp->element == element)) {
                pred = pred->next; 
                tmp = tmp->next;
                                  // if more than one node in the list
           /* SinglyLinkedListNode<T> *pred, *tmp;
            for (pred = head, tmp = head->next; // and a non-head node
                 tmp != 0 && !(tmp->element == element);// is deleted;
                 pred = pred->next, tmp = tmp->next); */
            } 
            if (tmp != 0) {
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
    }
}

template<class T>
bool SinglyLinkedList<T>::searchByKey(const T& element) const {
    SinglyLinkedListNode<T> *tmp;
    for (tmp = head; tmp != 0 && !(tmp->element == element); tmp = tmp->next);
    return tmp != 0;
}

/*template<class T>
bool SinglyLinkedList<T>::searchByPosition(int position) {
    SinglyLinkedListNode<T> *tmp;
    for (tmp = head; tmp != 0 && !(tmp->element == element); tmp = tmp->next);
    return tmp != 0;
}*/


template<class T>
void SinglyLinkedList<T>::printAll() const {
    SinglyLinkedListNode<T> *tmp = head;
    cout << "HEAD-> ";
    while (tmp != 0) {
        cout << tmp->element << " -> ";
        tmp = tmp->next;
    }
    cout << "TAIL" << endl;  
   
    /*for (SinglyLinkedListNode<T>*tmp = head; tmp != 0; tmp = tmp->next)
        cout << tmp->element << " ";
	cout << endl; */
}


#endif
