//----------------------CLASSE LISTA HPP--------------- 

#ifndef LISTAS_HPP
#define LISTAS_HPP


#include <iostream>

#include "../include/No.hpp"

using namespace std;

template  <class T>

class Lista {

    No<T>* cabeca;
    No<T>* cauda;
    
    public:
    Lista();
  
    void adicionaNaCabeca(T);
    void adicionaNaCauda(T);
    T removeDaCabeca();
    T removeDaCauda();
    void removeNo(T);
    T primeiroElemento(); 

};

#endif;