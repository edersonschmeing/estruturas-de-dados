
 #include "../include/Grafo.hpp"
 #include "../include/Vertice.hpp"
 
 
using namespace std;

/*
void menuGrafos() { 
   
   int operacao = 1;
   while (operacao < 10 && operacao > 0) {
      cout << "---------------------------------------" << endl;   
      cout << "          GRAFOS                       " << endl;       
      cout << "---------------------------------------" << endl;
      cout << "01 - Adicionar Vertice" << endl;
      cout << "02 - Excluir Vertice" << endl;
      cout << "03 - Imprimir Vertice" << endl;
      cout << "04 - Adicionar Aresta " << endl;
      cout << "05 - Excluir Aresta" << endl;
      cout << "06 - Imprimir Aresta" << endl;
      cout << "07 - bsf" << endl;
      cout << "08 - dfs" << endl;
      cout << "09 - Carregar de Arquivo" << endl;
      cout << "Escolha uma opção: ";
      cin >> operacao;
    
      switch (operacao)       {
      case 1: 
         cout << "01 - Adicionar Vertice" << endl;
            insertionsort(data, size);
         break;
      case 2:
         cout << "02 - Excluir Vertice" << endl;
         //selectionsort(data, size);
         printAll(data);
         break;
      case 3:
         cout << "03 - Imprimir Vertice" << endl;
         //shellsort(data, size);
         break;
      case 4:
         cout << "04 - Adicionar Aresta" << endl;
         mergesort(data, size);
         break;
      case 5:
         cout << "05 - Excluir Aresta" << endl;
         quicksort(data, size);
         printAll(data);
         break;
      case 6:
         cout << "06 - Imprimir Arestas" << endl;
         quicksort2(data, size);
         printAll(data);
         break;   
      case 7:
         cout << "07 - heapsort" << endl;
         heapsort(data, size);
         printAll(data);
         break;
      case 8:
         cout << "08 - heapsort min" << endl;
         heapsort(data, size);
         printAll(data);
         break;
      case 9:
         cout << "09 - bucketsort" << endl;
         //quicksort(data, size);
         cout << "Not implemented" << endl;
         break;
      case 10:
         cout << "10 - Exit" << endl;
         break;   
       default:
         break;
      }         
   } 
} */

int main() {
    
   Grafo* grafo;
   grafo = new Grafo();

   grafo->adicionarVertice("V1");
   grafo->adicionarVertice("V2");
   grafo->adicionarVertice("V3");
   grafo->adicionarVertice("V4");
   grafo->adicionarVertice("V5");
   grafo->adicionarVertice("V6");
   grafo->adicionarVertice("V7");
   grafo->adicionarVertice("V8");
   grafo->adicionarVertice("V9");
   grafo->adicionarVertice("V10");

   grafo->imprimirVertices();

   grafo->excluirVertice("V8");

   grafo->imprimirVertices();

   //Vertice *primeiroVertice = grafo->getPrimeiroVertice();
   //Vertice *ultimoVertice = grafo->getUltimoVertice();

   Vertice *vertice1 = grafo->getVertice("V1");
   Vertice *vertice2 = grafo->getVertice("V2");
   Aresta *aresta = new Aresta();
   aresta->SetPeso(2);
   aresta->setVerticeX(vertice1);
   aresta->setVerticeY(vertice2);
   vertice1->adicionarAresta(aresta);
   vertice2->adicionarAresta(aresta);
      
   Vertice *vertice3 = grafo->getVertice("V3");
   
   Aresta *aresta3 = new Aresta();
   aresta3->SetPeso(2);
   aresta3->setVerticeX(vertice2);
   aresta3->setVerticeY(vertice3);
   vertice2->adicionarAresta(aresta3);
   vertice3->adicionarAresta(aresta3);
   
   Vertice *vertice4 = grafo->getVertice("V4");
   Aresta *aresta1 = new Aresta();
   aresta1->SetPeso(1);
   aresta1->setVerticeX(vertice3);
   aresta1->setVerticeY(vertice4);
   vertice3->adicionarAresta(aresta1);
   vertice4->adicionarAresta(aresta1);
   
   vertice1->imprimirArestas(); 
   vertice2->imprimirArestas();
   vertice3->imprimirArestas();
   vertice4->imprimirArestas();

   grafo->bfs(vertice3);

   grafo->imprimirVertices();

   return 0;
   
} 
