
#ifndef VERTICE_HPP
#define VERTICE_HPP

#include<iostream>

#include "../include/Aresta.hpp"
#include "../include/Lista.hpp"

using namespace std;

class Aresta;

class Vertice {
public:
    string nome;
    Lista<Aresta*>* arestas;
    
    Vertice();
    
};


#endif;