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
    Vertice* vertice; 

public:

    Aresta(); 
    ~Aresta(); 

    int getId();
    void SetId(int id);

    int getPeso();
    void SetPeso(int peso);

    void setVertice(Vertice *vertice);
    
    Vertice* getVertice();
       
};

#endif