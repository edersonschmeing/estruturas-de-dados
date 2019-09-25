#ifndef GRAFO_HPP
#define GRAFO_HPP

#include<iostream>

#include "../include/Aresta.hpp"
#include "../include/Lista.hpp"

using namespace std;

template  <class T>

class Aresta;
class Vertice;


class Grafo {
public:
    
    Lista<Vertice*>* vertices;
    
    Grafo();

};


#endif;