
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


void carregarVetorDoArquivo(string diretorioArquivo) { 
    
    int elemento = 0, posicao = 0, tamanho = 0;

  
    sscanf(diretorioArquivo.c_str(), "%*[^0-9]%d", &tamanho);
    int vetor[tamanho];

    ifstream arquivo;

        cout << "tamanho " << tamanho << diretorioArquivo << endl;
    
    BST<int> bst;
   
    //tratar exceção de abertura de arquivo 
    arquivo.open(diretorioArquivo);
    if(arquivo.is_open()){
    
        while (!arquivo.eof()) {         
            arquivo >> elemento;
            vetor[posicao] = elemento;
            posicao++;
           
        }  
        arquivo.close();
      

        printArray(vetor, tamanho);

        for (int i = 0; i < tamanho; i++) {
           bst.insert(vetor[i]);
        } 
     
        bst.postorder();   
        
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


int main() {    
    
    //string diretorio = "./arquivos-arvore/construir/conjunto-04";  
    //string diretorio = "./arquivos-arvore/consultar/conjunto-04";  
    string diretorio = "./arquivos-arvore/test-construir/conjunto";  
    


    vector<string> listaDeArquivos;
    listaDeArquivos = leDiretorio(diretorio);



    cout << "Tamanho Vetor  - Coparações - Tempo (ms) " << endl;
    for (int i = 0; i < listaDeArquivos.size(); i++)   {
      carregarVetorDoArquivo( diretorio + "/" + listaDeArquivos[i]);
    }
   
    return 0; 
   
}