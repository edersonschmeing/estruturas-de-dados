#include <iostream>
#include "../include/Grafo.hpp"

Grafo::Grafo() {
    this->vertices = new Lista<Vertice*>();
}

Grafo::~Grafo() {
    delete this->vertices;
}

bool Grafo::adicionarVertice(string nome) {

    //verificar se vertice existe

    Vertice *vertice = new Vertice();
    vertice->setNome(nome);
    this->vertices->adicionarNaCauda(vertice);
    return true;
};

bool Grafo::excluirVertice(string nome) {
    Vertice *vertice = this->getVertice(nome);
    if (vertice == NULL)
        return false;
    this->vertices->excluirNo(vertice);
    return true;
};

Vertice *Grafo::getPrimeiroVertice() {
    Vertice *vertice = this->vertices->getPrimeiroElemento();
    if (vertice != NULL)
        return vertice;
    return NULL;
}

Vertice *Grafo::getUltimoVertice() {
    Vertice *vertice = this->vertices->getUltimoElemento();
    if (vertice != NULL)
        return vertice;
    return NULL;
}

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
        cout << vertice->getNome() << " -> ";
    }
    cout << endl;
}
/*
void bfs(struct node *graph, int size, int node_search)
{
    int i;
    for (i = 0; i < size; i++)  {
        if (i != node_search)  {
            graph[i].color = WHITE;
            graph[i].distance = 0;
        }
    }
    graph[node_search].color = GRAY;
    graph[node_search].distance = 0;
    graph[node_search].pi = NULL;
    push_queue(node_search);
    while (in != out)
    {
        int u = pop_queue();
        struct node *v = graph[u].next;
        while (v != NULL)
        {
            if (graph[v->key].color == WHITE)
            {
                graph[v->key].color = GRAY;
                graph[v->key].distance = graph[u].distance + 1;
                graph[v->key].pi = &graph[u];
                push_queue(v->key);
            }
            v = v->next;
        }
        graph[u].color = BLACK;
    }
}*/

/*
void visit_dfs(struct node *graph, int size, int u){
    int t;
    tempo++;
    graph[u].distance=tempo;
    graph[u].color= GRAY;
    for (int v=0; v < size; v++){
        if ((v!=u) && (isAdjacent(graph, u,v)) && (graph[v].color==WHITE)){
            graph[v].pi=&graph[u];
            visit_dfs(graph, size,v);   
          }
    }
    graph[u].color=BLACK;
    tempo++;
    graph[u].f= tempo;
}


void dfs(struct node *graph, int size){
    for (int i=0; i < size; i++ ){
        graph[i].color= WHITE;
        graph[i].pi= NULL;
        graph[i].distance=0;
    }
    tempo=0;
    in=0; out=0;n_queue=0;
    for (int i=0; i < size; i++ ){
        if (graph[i].color== WHITE){
            visit_dfs(graph, size, i);
        }
    }
}
*/