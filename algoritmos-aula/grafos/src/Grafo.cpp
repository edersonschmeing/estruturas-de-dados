#include<iostream>
#include "../include/Grafo.hpp"

Grafo::Grafo() {
   this->vertices = new Lista<Vertice*>();
}

bool Grafo::adicionarVertice(string nome) {
    
    //if(existeVertice(nombreVertice))
      //  return false;

    Vertice* vertice = new Vertice();
    vertice->setNome(nome);
    this->vertices->adicionarNaCauda(vertice);
    return true;
};

Vertice* Grafo::getPrimeiroVertice() {
    Vertice *vertice = this->vertices->getPrimeiroElemento();
    if(vertice != NULL)
        return vertice;
    return NULL;
}

Vertice* Grafo::getUltimoVertice() {
    Vertice *vertice = this->vertices->getUltimoElemento();
    if(vertice != NULL)
        return vertice;
    return NULL;
}

/*Vertice* Grafo::getVertice(string nome) {
    Vertice *vertice = new Vertice();
    vertice->setNome(nome);
    Vertice **v = this->vertices->buscarElemento(vertice);
    if (v == NULL)
        return NULL;
    return *v;
}*/

Vertice* Grafo::getVertice(string nome) {
    for (int i = 0; i < this->vertices->getTamanho(); i++) {
        Vertice *vertice = this->vertices->getElemento(i); 
        cout << vertice->getNome()  << " -> ";   
        if (vertice->getNome() == nome)
            return vertice;
    }
    return NULL;
}
 
void Grafo::imprimirVertices() {
   for (int i = 0; i < this->vertices->getTamanho(); i++) {
        Vertice *vertice = this->vertices->getElemento(i); 
        cout << vertice->getNome()  << " -> ";       
   }
   cout << endl;
}
   
   




