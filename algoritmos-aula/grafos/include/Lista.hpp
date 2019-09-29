//----------------------CLASSE LISTA HPP (Lista Simples, Lista Dupla, Deque, Fila, Pilha)--------------- 

#ifndef LISTAS_HPP
#define LISTAS_HPP

#include <iostream>

#include "../include/No.hpp"

using namespace std;

template  <class T>
class Lista {
    private:
        int tamanho;
        No<T> *cabeca;
        No<T> *cauda;
  
        void Limpa();
    
    protected:
    
    public:
        Lista();
        ~Lista();

        bool adicionarNaCabeca(const T& elemento);
        bool adicionarNaCauda(const T& elemento);
        bool adicionarNaPosicao(const T& elemento, int posicao);

        T excluirDaCabeca();
        T excluirDaCauda();
        T excluirDaPosicao(int posicao);
        void excluirNo(const T&);
         
        bool estaVazia() const; 
        
        int getTamanho();
        T& getElemento(int posicao);    
        T& getPrimeiroElemento(); 
        T& getUltimoElemento();

        T* buscarElemento(const T& elemento) const; 
   
};

template <class T>
Lista<T>::Lista() {
   this->cabeca = NULL;
   this->cauda = NULL;
   this->tamanho = 0;
}

template <class T>
Lista<T>::~Lista() {
   Limpa();
}

template <class T>
void Lista<T>::Limpa() {
   for (No<T> *objeto; cabeca != 0; ) {
       objeto = cabeca;
       cabeca = cabeca->proximo;
       delete objeto;
   }
}

template  <class T>
bool Lista<T>::adicionarNaCabeca(const T& elemento) {
    if (cabeca != 0) {
        cabeca = new No<T>(elemento,cabeca,0);
        cabeca->proximo->anterior = cabeca;
    }else { 
        No<T> *no = new No<T>(elemento);
        cauda = no;
        cabeca = no;           
    }
    tamanho++;
}

template  <class T>
bool Lista<T>::adicionarNaCauda(const T& elemento) {
    if (cauda != 0) {
       cauda = new No<T>(elemento,0,cauda);
       cauda->anterior->proximo = cauda;
    } else {
        No<T> *no = new No<T>(elemento); 
        cauda = no;
        cabeca = no;       
    }
    tamanho++;  
}

template<class T>
bool Lista<T>::adicionarNaPosicao(const T& elemento, int posicao) {
    //implementar
    return false;
}


template<class T>
T Lista<T>::excluirDaCabeca() {
    T elemento = cabeca->elemento;
    if (cabeca == cauda) { 
         delete cabeca;
         cabeca = 0; 
         cauda = 0;
    }else {              
         cabeca = cabeca->proximo;
         delete cabeca->anterior;
         cabeca->anterior = 0;
    }
    return elemento;
}

template<class T>
T Lista<T>::excluirDaCauda() {
    T elemento = cauda->elemento;
    if (cabeca == cauda) {
         delete cabeca;
         cabeca = 0; 
         cauda = 0;
    }else {              
         cauda = cauda->anterior;
         delete cauda->proximo;
         cauda->proximo = 0;
    }
    return elemento;
}

template<class T>
T Lista<T>:: excluirDaPosicao(int posicao) {
    //implementar
    return NULL;
}

template<class T>
void Lista<T>::excluirNo(const T& elemento) {
    if (cabeca != 0) {                   
        tamanho--;
        if (cabeca == cauda && elemento == cabeca->elemento) {
            delete cabeca;                      
            cabeca = 0;
            cauda = 0;
        }else if (elemento == cabeca->elemento) {  
            No<T> *objeto = cabeca;
            cabeca = cabeca->proximo;
            delete objeto;              
        }else {                        
            No<T> *antecessor, *objeto;
            antecessor = cabeca;
            objeto = cabeca->proximo;
            while ((objeto != 0) && !(objeto->elemento == elemento)) {
                antecessor = antecessor->proximo; 
                objeto = objeto->proximo;
            }
            if (objeto != 0) {
                antecessor->proximo = objeto->proximo;
                if (objeto == cauda)
                    cauda = antecessor;
                delete objeto;
            }
        }
    }    
}


template<class T> 
bool Lista<T>::estaVazia() const {
    return cabeca == 0;
}

template<class T>
int Lista<T>::getTamanho(){
    return this->tamanho;
}


//custo alto, verificar
template<class T>
T& Lista<T>::getElemento(int posicao) {
    No<T> *objeto = cabeca;
    for(int i = 0; i < posicao; i++) {
        objeto = objeto->proximo;
    }
    return objeto->elemento;
}

template<class T>
T& Lista<T>::getPrimeiroElemento() {
    return cabeca->elemento;
}

template<class T>
T& Lista<T>::getUltimoElemento() {
    return cauda->elemento;
} 

//verficiar como fazer para funcinar para objetos abstratos.
template <class T>
T* Lista<T>::buscarElemento(const T& elemento) const {
    No<T> *objeto = cabeca;
    cout << "A " << elemento << endl; 
    while (objeto != 0 && !(objeto->elemento == elemento)) {
        cout <<  "B " << objeto->elemento << endl; 
        objeto = objeto->proximo;
    }
    if (objeto == 0)
         return 0;
    else 
       return &objeto->elemento;
}  
 
#endif      