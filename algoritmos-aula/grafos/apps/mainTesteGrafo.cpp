
 #include "../include/Grafo.hpp"
 #include "../include/Vertice.hpp"

 #include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
 
 
using namespace std;

int main() {
    
   Grafo* grafo;
   grafo = new Grafo();

   grafo->adicionarVertice("V0");
   grafo->adicionarVertice("V1");
   grafo->adicionarVertice("V2");
   grafo->adicionarVertice("V3");
   grafo->adicionarVertice("V4");
   grafo->adicionarVertice("V5");
   grafo->adicionarVertice("V6");
   grafo->adicionarVertice("V7");
   grafo->adicionarVertice("V8");
   
   grafo->imprimirVertices();

   //grafo->excluirVertice("V5");
   //grafo->imprimirVertices();

   //Vertice *primeiroVertice = grafo->getPrimeiroVertice();
   //Vertice *ultimoVertice = grafo->getUltimoVertice();

   Vertice *vertice1 = grafo->getVertice("V0");
   Vertice *vertice1 = grafo->getVertice("V1");
   Vertice *vertice2 = grafo->getVertice("V2");
   Vertice *vertice3 = grafo->getVertice("V3");
   Vertice *vertice3 = grafo->getVertice("V4");
   Vertice *vertice3 = grafo->getVertice("V5");
   Vertice *vertice3 = grafo->getVertice("V6");
   Vertice *vertice3 = grafo->getVertice("V7");
   Vertice *vertice3 = grafo->getVertice("V8");

   
   Aresta *aresta1 = new Aresta();
   Aresta *aresta2 = new Aresta();
   Aresta *aresta3 = new Aresta();
   Aresta *aresta4 = new Aresta();
   Aresta *aresta5 = new Aresta();
   Aresta *aresta6 = new Aresta();
   Aresta *aresta7 = new Aresta();
   Aresta *aresta8 = new Aresta();
   Aresta *aresta9 = new Aresta();
   Aresta *aresta10 = new Aresta();
   Aresta *aresta11 = new Aresta();
   Aresta *aresta12 = new Aresta();
   Aresta *aresta13 = new Aresta();
   Aresta *aresta14 = new Aresta();
   
   
   aresta->SetPeso(2);
   aresta->setVertice(vertice2);
   vertice1->adicionarAresta(aresta);
      
   
   Aresta *aresta3 = new Aresta();
   aresta3->SetPeso(2);
   aresta3->setVertice(vertice3);
   vertice2->adicionarAresta(aresta3);


   Vertice *vertice4 = grafo->getVertice("V4");
   Aresta *aresta1 = new Aresta();
   aresta1->SetPeso(1);
   aresta1->setVertice(vertice4);
   vertice3->adicionarAresta(aresta1);
  
   Aresta *aresta4 = new Aresta();
   aresta4->SetPeso(1); 
   aresta4->setVertice(vertice1);
   vertice4->adicionarAresta(aresta4);
      
   vertice1->imprimirArestas(); 
   vertice2->imprimirArestas();
   vertice3->imprimirArestas();
   vertice4->imprimirArestas(); 

   grafo->bfs(vertice4);

   cout << endl;
   
   grafo->imprimirVertices();

    Vertice *vertice = grafo->getVertice("V2");
    
    cout << vertice->getNome() << " -> " << endl; 

    grafo->bfs(vertice);
 
   return 0;
    
} 
