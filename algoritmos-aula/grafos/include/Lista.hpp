//----------------------CLASSE LISTA HPP--------------- 

#ifndef LISTAS_HPP
#define LISTAS_HPP


#include <iostream>

#include "../include/No.hpp"

using namespace std;

template  <class T>
class Lista {
  protected:
    No<T> *cabeca;
    No<T> *cauda;
    int quantidade;
    
    public:
    Lista();
  
    bool adicionarNaCabeca(const T&);
    bool adicionaNaCauda(T elemento);
    T removeDaCabeca();
    T removeDaCauda();
    void removeNo(T);
    T primeiroElemento(); 

    No<T>* getCabeca();

    void printAllAsc();

};


template <class T>
Lista<T>::Lista() {
   this->cabeca = NULL;
   this->cauda = NULL;
   this->quantidade = 0;
}

template  <class T>
bool Lista<T>::adicionarNaCabeca(const T& elemento) {
    if (cabeca != 0) {
        cabeca = new No<T>(elemento,cabeca,0);
        cabeca->proximo->anterior = cabeca;
    }else { 
        cabeca = cauda = new No<T>(elemento); 
        //cauda = tmp;
        //cabeca = tmp;
        //head = tail = new DoublyLinkedListNode<T>(element);   
    }
    quantidade++;
}

template  <class T>
bool Lista<T>::adicionaNaCauda(T elemento) {
    if (cauda != 0) {
       cauda = new No<T>(elemento,0,cauda);
       cauda->anterior->proximo = cauda;
    } else {
        No<T> *tmp = new No<T>(elemento); 
        cauda = tmp;
        cabeca = tmp;       
    }
    quantidade++;  
}

template<class T>
No<T>* Lista<T>::getCabeca() {
    return this->cabeca;
}

template<class T>
void Lista<T>::printAllAsc()  {
    cout << " Ordem ASC - CABEÇA->"; 
    No<T> *tmp = cabeca;
    while (tmp != 0) {
        T v  = (T)tmp->elemento;
        cout << v << " -> ";
        tmp = tmp->proximo;
    }
    cout << "CAUDA" << endl;  
}


#endif