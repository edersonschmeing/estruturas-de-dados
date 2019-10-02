#ifndef VERTICE_HPP
#define VERTICE_HPP

#include<iostream>

#include "../include/Aresta.hpp"
#include "../include/Lista.hpp"

using namespace std;

const int BRANCA = 0;
const int CINZA = 1;
const int PRETA = 2;

class Aresta;

class Vertice {
    private:
        int id;
        int cor;
        string nome;   

        Lista<Aresta*>* arestas;

    protected:
    
    public:
    
         Vertice();
        ~Vertice();

        int getId();
        void setId(int id);

        int getCor();
        void setCor(int cor);   

        string getNome();
        void setNome(string nome);

        Lista<Aresta*>* getArestas();

    
        bool adicionarAresta(Aresta* aresta);
        //bool excluirrAresta(Aresta* aresta);
        
        void imprimirArestas();
    
};

#endif