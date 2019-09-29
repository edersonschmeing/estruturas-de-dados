#ifndef NO_HPP
#define NO_HPP

#include<iostream>

using namespace std;

template <class T>
class No {


public:
    T elemento;
    No* proximo;
    No* anterior;
    
    No() {
        this->elemento = NULL;
        this->anterior  = NULL;
        this->proximo = NULL;
    };

    No(T elemento ) {
        this->elemento = elemento;
        this->anterior  = NULL;
        this->proximo = NULL;
    };

    No(T elemento, No<T> *proximo, No<T> *anterior) {
        this->elemento = elemento;
        this->anterior  = anterior;
        this->proximo = proximo;
    };

};

#endif