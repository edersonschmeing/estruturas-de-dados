
#include<iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <genBST.h>

using namespace std;

/*#include <map>
#include <ctime>
#include <cstdlib> */


void printArray(int A[], int n) {
    printf("[%d", A[0]);
    int i;
    for (i = 1; i < n; i++) {
        printf(", %d",A[i]);
    }
    printf("]\n");
}


void carregarVetorDoArquivo(int *vetor, string diretorioArquivo) { 
    
    int elemento = 0;
    int posicao = 0;
    ifstream arquivo;
  
    //tratar exceção de abertura de arquivo 
    arquivo.open(diretorioArquivo);
    if(arquivo.is_open()){
        while (!arquivo.eof()) {         
            arquivo >> elemento;
            vetor[posicao] = elemento;
            posicao++;
        }  
        arquivo.close();  
    }
    else{
        cout << "Não foi possível acessar o arquivo do vetor." << endl;
        exit(0);
    }
}


vector<string> leDiretorio(string caminhoDiretorio) {
    
    vector<string> listaDeArquivos;
    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(caminhoDiretorio.c_str());
     while ((lsdir = readdir(dir) ) != NULL ) {
        if (strstr(lsdir->d_name, ".txt") != NULL) {
            listaDeArquivos.push_back( string( lsdir->d_name ) );
        }       
    }
    closedir(dir);
    
    //ordenação considerando string, verificar para ordenar pelo tamanho do vetor.
    sort( listaDeArquivos.begin(), listaDeArquivos.end() );
    return listaDeArquivos;
  
}

int retornaTamanhoVetor(string nomeArquivo ) {
   int pos = nomeArquivo.find("."); 
   string sub = nomeArquivo.substr(0, pos); 
   return  stoi(sub);
}


int main() {    
    
    //string diretorio = "./arquivos-arvore/construir/conjunto-04";  
    //string diretorio = "./arquivos-arvore/consultar/conjunto-04";  
    string diretorio = "./arquivos-arvore/test-construir/conjunto";  
    
    vector<string> listaDeArquivos;
    listaDeArquivos = leDiretorio(diretorio);

    cout << "Tamanho Vetor  - Coparações - Tempo (ms) " << endl;
    for (int i = 0; i < listaDeArquivos.size(); i++)   {
      
      int tamanho = retornaTamanhoVetor(listaDeArquivos[i]);
      int vetor[tamanho];

      carregarVetorDoArquivo(vetor, diretorio + "/" + listaDeArquivos[i]);

      printArray(vetor, tamanho);

      BST<int> bst;
      for (int i = 0; i < tamanho; i++) {
          bst.insert(vetor[i]);
      } 
      bst.postorder();

    }
    return 0; 
   
}