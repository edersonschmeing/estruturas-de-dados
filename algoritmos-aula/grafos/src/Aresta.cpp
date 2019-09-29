//----------------------CLASSE ARESTA CPP---------------

#include<iostream>
#include "../include/Aresta.hpp"

Aresta::Aresta() {
    id = 0;
    this->verticeX = NULL;
    this->verticeY = NULL;
}

Aresta::~Aresta() {
    id = 0;
    this->verticeX = NULL;
    this->verticeY = NULL;
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

void Aresta::setVerticeX(Vertice *vertice) {
    this->verticeX = vertice;
}

Vertice* Aresta::getVerticeX() {
    return this->verticeX;
}

void Aresta::setVerticeY(Vertice *vertice) {
    this->verticeY = vertice;
}

Vertice* Aresta::getVerticeY() {
    return this->verticeY;
}



