//----------------------CLASSE ARESTA HPP--------------- 

#ifndef ARESTA_HPP
#define ARESTA_HPP

#include<iostream>

#include "../include/Vertice.hpp"


using namespace std;

class Vertice;

class Aresta {
private:
    int id;
    Vertice* verticeX; //verificar se coloca o nome origem
    Vertice* verticeY; //verificar se coloca o nome destino


public:

    Aresta(); 

    int getId();
    void SetId(int id);

    void setVerticeX(Vertice *vertice);
    void setVerticeY(Vertice *vertice);
    
    Vertice* getVerticeX();
    Vertice* getVerticeY();

    
};

#endif