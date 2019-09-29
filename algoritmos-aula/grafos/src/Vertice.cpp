#include<iostream>
#include "../include/Vertice.hpp"

Vertice::Vertice() {
    id = 0;
    this->arestas = new Lista<Aresta*>();
    this->nome = "";
};

Vertice::~Vertice() {
   delete this->arestas;
}

string Vertice::getNome() {
   return this->nome;
};

void Vertice::setNome(string nome) {
   this->nome = nome;
};


bool Vertice::adicionarAresta(Aresta* aresta) {
    
    //if(existeVertice(nombreVertice))
      //  return false;

    this->arestas->adicionarNaCauda(aresta);
    
    return true;
}

void Vertice::imprimirArestas() {
   for (int i = 0; i < this->arestas->getTamanho(); i++) {
        Aresta *aresta = this->arestas->getElemento(i); 
        cout << aresta->getVerticeX()->getNome()  << " -> ";
        cout << aresta->getVerticeY()->getNome()  << " -> ";       
   }
   cout << endl;
}



/*void Vertice::imprimirArestas() {
   cout << " ARESTAS -> ";
   No<Vertice*>* tmp = this->arestas->getCabeca();
   while(tmp != NULL) {
        Aresta* v  = (Aresta*)tmp->elemento; 
        cout << v->nome  << " -> ";
        tmp = tmp->proximo;
   }  
   cout << endl;  
}*/