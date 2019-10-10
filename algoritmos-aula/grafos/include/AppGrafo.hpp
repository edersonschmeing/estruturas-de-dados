//----------------------CLASSE APP_GRAFO HPP--------------- 

#ifndef APP_GRAFO_HPP
#define APP_GRAFO_HPP

#include<iostream>
#include "../include/Vertice.hpp"
#include "../include/Grafo.hpp"


using namespace std;

class Grafo;

class AppGrafo {

private:

protected:

public:
    Grafo* grafo; 

    AppGrafo(); 
    ~AppGrafo(); 

    void mostrarMenu();
    void carregarGrafoDoArquivo(string diretorioArquivo);
       
};

#endif