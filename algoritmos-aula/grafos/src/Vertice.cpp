#include<iostream>
#include "../include/Vertice.hpp"

Vertice::Vertice() {
    this->arestas = new Lista<Aresta*>();
    this->nome = "";
};