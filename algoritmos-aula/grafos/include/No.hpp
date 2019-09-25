#ifndef NO_HPP
#define NO_HPP

template <class T>

class No {
public:
    T elemento;
    No* proximo;
    No* anterior;
    
    No();
    No(T elemento);    
    No(T elemento, No<T> *proximo = 0, No<T> *anterior = 0) {
   
};

No<T>::No() {
    this->elemento = NULL;
    this->anterior  = NULL;
    this->proximo = NULL;
};

No<T>::No(T elemento ) {
    this->elemento = elemento;
    this->anterior  = NULL;
    this->proximo = NULL;
};

No<T>::No(T elemento, No<T> *proximo = 0, No<T> *anterior = 0) {
    this->elemento = elemento;
    this->anterior  = anterior;
    this->proximo = proximo;
};

#endif;