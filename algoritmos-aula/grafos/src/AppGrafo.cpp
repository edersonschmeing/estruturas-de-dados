
 #include "../include/AppGrafo.hpp"

 #include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

AppGrafo::AppGrafo() {
    this->grafo = new Grafo();
}

AppGrafo::~AppGrafo() {
    delete this->grafo;
}
   
void AppGrafo::carregarGrafoDoArquivo(string diretorioArquivo) { 

    string origem, destino; 
	 int peso;

    ifstream arquivo;
    //tratar exception de abertura de arquivo
    arquivo.open(diretorioArquivo);
        
    if(arquivo.is_open()){
         while (!arquivo.eof()) {         
           arquivo >> origem >> peso >> destino;
           cout << origem << " - " << peso << " - " << destino << endl;
        
           grafo->adicionarVertice(origem);
           grafo->adicionarVertice(destino);
           
           Vertice *verticeOrigem = grafo->getVertice(origem);
           Vertice *verticeDestino = grafo->getVertice(destino);
           Aresta *aresta = new Aresta();
           aresta->SetPeso(peso);
           aresta->setVertice(verticeDestino);
           verticeOrigem->adicionarAresta(aresta);

         }  
        arquivo.close();
    }
    else{
        cout << "Não foi possível acessar o arquivo do grafo." << endl;
        exit(0);
    }
}

void AppGrafo::mostrarMenu() { 
   
   int operacao = 1;
   while (operacao < 10 && operacao >= 0) {
      cout << "                                       " << endl;
      cout << "---------------------------------------" << endl;   
      cout << "          TEORIA DOS GRAFOS                       " << endl;       
      cout << "---------------------------------------" << endl;
      cout << "01 - Carregar de Arquivo" << endl;
      cout << "02 - Adicionar Vertice" << endl;
      cout << "03 - Excluir Vertice" << endl;
      cout << "04 - Imprimir Vertice" << endl;
      cout << "05 - Adicionar Aresta " << endl;
      cout << "06 - Excluir Aresta" << endl;
      cout << "07 - Imprimir Aresta" << endl;
      cout << "08 - BFS" << endl;
      cout << "09 - Dijkstra" << endl;
      cout << "10 - Sair" << endl;
 
      cout << "Escolha uma opção: ";
      cin >> operacao; 
    
      string nome;
      
     Vertice *vertice = NULL;

     switch (operacao) { 
     case 1:
            cout << "01 - Carregar de Grafo de Arquivo " << endl;
            cout << "Nome do arquivo: ";
            cin >> nome;
           // this->grafo = NULL;
            this->carregarGrafoDoArquivo(nome);
         break;
      case 2:
            cout << "02 - Nome do Vertice: " << endl;
            cout << "Nome do Vertice: ";
            cin >> nome;
            this->grafo->adicionarVertice(nome);
         break;
      case 3:
         cout << "03 - Nome do Vertice: " << endl;
         cout << "Nome do Vertice: ";
         cin >> nome;
         grafo->excluirVertice(nome);
         break;
      case 4:
         cout << "04 - Imprimir Vertice" << endl;
         grafo->imprimirVertices();
         break;
      case 5:
         cout << "05 - Adicionar Aresta" << endl;
         break;
      case 6:
         cout << "06 - Excluir Aresta" << endl;
         break;
      case 7:
         cout << "07 - Imprimir Arestas" << endl;
         carregarGrafoDoArquivo("grafo.txt");
         break;
      case 8:
         cout << "BFS - Escolha um vertice inicial: ";
         cin >> nome;
         vertice = grafo->getVertice(nome);
         grafo->bfs(vertice);
         break;
      case 9:
         cout << "Dijkstra - Escolha um vertice inicial: ";
         cin >> nome;
         vertice = grafo->getVertice(nome);
         grafo->dijkstra(vertice);
         break;
      case 10:
         cout << "10 - Exit" << endl;
         break;
            
      }  
   }       
} 