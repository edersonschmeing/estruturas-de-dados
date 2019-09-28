#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>

#include "../include/Vertice.hpp"
#include "../include/Aresta.hpp"
#include "../include/Lista.hpp"
#include "../include/No.hpp"

using namespace std;

class Aresta;
class Vertice;

class Grafo {
public:
    
    Lista<Vertice*> *vertices;
    
    Grafo();

    bool adicionarVertice(string nome);

    Vertice* getPrimeiroVertice();

    Vertice* imprimirVertices();

    void printAllAsc();

};


#endif