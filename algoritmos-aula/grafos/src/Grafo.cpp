#include <iostream>
#include "../include/Grafo.hpp"
#include "../include/Lista.hpp"


Grafo::Grafo() {
    this->vertices = new Lista<Vertice*>();
}

Grafo::~Grafo() {
    delete this->vertices;
}

Lista<Vertice*>* Grafo::getVertices() {
   return this->vertices;
};


bool Grafo::adicionarVertice(string nome) {

    if (this->getVertice(nome) == NULL) { 
        Vertice *vertice = new Vertice();
        vertice->setNome(nome);
        this->vertices->adicionarNaCauda(vertice);
        return true;
    }
    return false;

};

bool Grafo::excluirVertice(string nome) {
    Vertice *vertice = this->getVertice(nome);
    if (vertice == NULL)
        return false;
    this->vertices->excluirElemento(vertice);
    return true;
};

Vertice *Grafo::getPrimeiroVertice() {
    Vertice *vertice = this->vertices->getPrimeiroElemento();
    if (vertice != NULL)
        return vertice;
    return NULL;
};

Vertice *Grafo::getUltimoVertice() {
    Vertice *vertice = this->vertices->getUltimoElemento();
    if (vertice != NULL)
        return vertice;
    return NULL;
};

/*Vertice* Grafo::getVertice(string nome) {
    Vertice *vertice = new Vertice();
    vertice->setNome(nome);
    Vertice **v = this->vertices->buscarElemento(vertice);
    if (v == NULL)
        return NULL;
    return *v;
}*/

Vertice *Grafo::getVertice(string nome) {

    for (int i = 0; i < this->vertices->getTamanho(); i++) {
       Vertice *vertice = this->vertices->getElemento(i);
       if (vertice->getNome() == nome)
           return vertice;
    }
    return NULL;
}

void Grafo::imprimirVertices() {
    for (int i = 0; i < this->vertices->getTamanho(); i++) {
        Vertice *vertice = this->vertices->getElemento(i);
        //cout << vertice->getNome() << " - " << vertice->getCor() << " -> ";
        cout << vertice->getNome() << " -> ";        
    }
    cout << endl;
}
 
void Grafo::bfs(Vertice* verticeInicial) {
    //já esta com as variaveis incializadas
    for (int i = 0; i < this->vertices->getTamanho(); i++) {
        Vertice *vertice = this->vertices->getElemento(i);
        vertice->setCor(BRANCA);
    }
    //ja esta com as variaveis inicializadas
    verticeInicial->setCor(CINZA);

    Lista<Vertice*>* filaVertice = new Lista<Vertice*>();
    filaVertice->adicionarNaCauda(verticeInicial);

    cout << "BSF VERTICE INICIAL: " << verticeInicial->getNome() << " ->> ";
    while (!filaVertice->estaVazia()) {
        Vertice *vertice = filaVertice->excluirDaCabeca();
        Lista<Aresta*>* arestas = vertice->getArestas();  
        for (int i = 0; i < arestas->getTamanho(); i++) {
            Aresta *aresta = arestas->getElemento(i);
            Vertice *verticeDestino = aresta->getVertice();
            if (verticeDestino->getCor() == BRANCA) {
                verticeDestino->setCor(CINZA);
                cout << verticeDestino->getNome() << " -> "; 
                filaVertice->adicionarNaCauda(verticeDestino);
                //cout << &verticeVisitado << " -> ";
            } 
        } 
        vertice->setCor(PRETA);
    }
    delete filaVertice;               
}


void Grafo::dijkstra(Vertice *verticeInicial) {
    
    Lista<Vertice *> *filaPrioridade = new Lista<Vertice *>();
    verticeInicial->setDistancia(0);
    filaPrioridade->adicionarNaCauda(verticeInicial);
    
    while (!filaPrioridade->estaVazia()) {
        Vertice *visitado = filaPrioridade->getPrimeiroElemento();
        filaPrioridade->excluirDaCabeca();
        Lista<Aresta *> *arestas = visitado->getArestas();
        
        for (int i = 0; i < arestas->getTamanho(); i++) {
            Aresta *aresta = arestas->getElemento(i);
            Vertice *vizinho = aresta->getVertice();
            int peso = aresta->getPeso();
            int minimaDistancia = visitado->getDistancia() + peso;
            cout << "Visitado: " << visitado->getNome() << endl;
            cout << "Minima Distancia: " << minimaDistancia << " Distancia Vizinho: " << vizinho->getDistancia() << endl;

            if (minimaDistancia < vizinho->getDistancia() || vizinho->getDistancia() == -1) {
                filaPrioridade->excluirElemento(visitado);
                vizinho->setAntecessor(visitado);
                vizinho->setDistancia(minimaDistancia);
                filaPrioridade->adicionarNaCauda(vizinho);
                cout << "Vizinho: " << vizinho->getNome() << " Distancia " << vizinho->getDistancia() << endl;
            }
        }
    }
    delete filaPrioridade; 
    for (int i = 0; i < this->vertices->getTamanho(); i++)     {
        Vertice *vertice = this->vertices->getElemento(i);
        cout << vertice->getNome() << " -> " << vertice->getDistancia() << endl;
    }
}