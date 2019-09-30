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
 private:   
    int id;
    Lista<Vertice*> *vertices;

public:
    
    Grafo();
    ~Grafo();

    Lista<Vertice*>* getVertices();

    bool adicionarVertice(string nome);

    Vertice* getVertice(string nome);

    bool excluirVertice(string nome);

    void imprimirVertices();

    Vertice* getPrimeiroVertice();
    Vertice* getUltimoVertice();

    void bfs(Vertice* verticeInicial); //busca em largura

    //dsf(); busca por profundidade
     //- Detecção de ciclos
     //- Ordenação topológica
    //tarjan(); Componentes fortemente conectados, baseado em busca de profundiade, utiliza pilha.
    //kruskal(); Árvore geradora mínima, conjutos sets.
    //prim();  Árvore geradora mínima, utilzar o HEAPs(binário e Fibonacci) para otimização.
    //dijkstra(); Caminho minímo, utilizar heap para otimizar a distancia mínima
    //ford_fulkerson(); fluxo de máximo
    

};

#endif