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
    int peso;
    Vertice* verticeX; 
    Vertice* verticeY;

public:

    Aresta(); 
    ~Aresta(); 

    int getId();
    void SetId(int id);

    int getPeso();
    void SetPeso(int peso);

    void setVerticeX(Vertice *vertice);
    void setVerticeY(Vertice *vertice);
    
    Vertice* getVerticeX();
    Vertice* getVerticeY();

    
};

#endif