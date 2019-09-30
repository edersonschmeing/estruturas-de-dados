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
    int id;

public:
    
    Lista<Vertice*> *vertices;

    Grafo();
    ~Grafo();

    bool adicionarVertice(string nome);

    Vertice* getVertice(string nome);

    bool excluirVertice(string nome);

    void imprimirVertices();

    Vertice* getPrimeiroVertice();
    Vertice* getUltimoVertice();

    void bfs(Vertice* verticeInicial);

    //bsf(); busca por largura
    //dsf(); busca por profundidade

};


#endif