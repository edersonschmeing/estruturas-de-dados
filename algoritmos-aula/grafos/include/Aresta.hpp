//----------------------CLASSE ARESTA HPP--------------- 

#ifndef ARESTA_HPP
#define ARESTA_HPP

#include<iostream>

#include "../include/Vertice.hpp"


using namespace std;

class Vertice;

class Aresta {
public:
    Vertice* verticeX; //verificar se coloca o nome origem
    Vertice* verticeY; //verificar se coloca o nome destino

    Aresta(); 
};

#endif