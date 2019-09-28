#include<iostream>
#include "../include/Grafo.hpp"

Grafo::Grafo() {
   this->vertices = new Lista<Vertice*>();
}

bool Grafo::adicionarVertice(string nome) {
    
    //if(existeVertice(nombreVertice))
      //  return false;

    Vertice* vertice = new Vertice();
    vertice->nome = nome;
    this->vertices->adicionarNaCabeca(vertice);
    return true;
};

void Grafo::printAllAsc()  {
    this->vertices->printAllAsc();
    
};

Vertice* Grafo::getPrimeiroVertice()
{
    No<Vertice*>* tmp = this->vertices->getCabeca();
    if(tmp != NULL)
        return tmp->elemento;
    return NULL;
}

Vertice* Grafo::imprimirVertices() {
   No<Vertice*>* tmp = this->vertices->getCabeca();
   while(tmp != NULL)
   {
        Vertice* v  = (Vertice*)tmp->elemento; 
        cout << v->nome  << " -> " << endl;
        tmp = tmp->proximo;
   }    
}