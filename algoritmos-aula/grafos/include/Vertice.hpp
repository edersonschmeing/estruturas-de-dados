#ifndef VERTICE_HPP
#define VERTICE_HPP

#include<iostream>

#include "../include/Aresta.hpp"
#include "../include/Lista.hpp"

using namespace std;

class Aresta;

class Vertice {
private:
    int id;
    string nome;   
protected:
    //int id;
    //string nome;
public:
    
    Lista<Aresta*>* arestas;
    
    Vertice();
    ~Vertice();

    string getNome();
    void setNome(string nome); 
     
    
    bool adicionarAresta(Aresta* aresta);
    void imprimirArestas();
    
};

#endif