//----------------------CLASSE ARESTA CPP---------------

#include<iostream>
#include "../include/Aresta.hpp"

Aresta::Aresta() {
    id = 0;
    this->vertice = NULL;
}

Aresta::~Aresta() {
    id = 0;
    this->vertice = NULL;
}

int Aresta::getId() {
    return this->id;
}

void Aresta::SetId(int id) {
    this->id = id;
}

int Aresta::getPeso() {
    return this->peso;
}

void Aresta::SetPeso(int peso) {
    this->peso = peso;
}

void Aresta::setVertice(Vertice *vertice) {
    this->vertice = vertice;
}

Vertice* Aresta::getVertice() {
    return this->vertice;
}



