
#include<iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <quicksort.h>


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

    //Pega o tamanho do vetor do nome do arquivo.
    sscanf(diretorioArquivo.c_str(), "%*[^0-9]%d", &tamanho);
    int vetor[tamanho];

    ifstream arquivo;
   
    //tratar exceção de abertura de arquivo 
    arquivo.open(diretorioArquivo);
    if(arquivo.is_open()){
        //Faz a leitura do arquivo texto e armazena em um vetor
        while (!arquivo.eof()) {         
            arquivo >> elemento;
            vetor[posicao] = elemento;
            posicao++;
        }  
        arquivo.close();

        //chama metódo de ordenação, verificar para chamar de fora da função que faz a leitura do arquivo.
        
        //cout << "CORMEN" << endl;
        //quicksortCormen(vetor, 0, tamanho-1);
        
        //cout << "HOARE" << endl;
        //quicksortHoare(vetor, 0, tamanho-1);
        
        //cout << "ALEATORIO" << endl;
        //quicksortAleatorio(vetor, 0, tamanho-1);

        cout << "MEDIANA DE TRES" << endl;
        quicksortMedianaDeTres(vetor, 0, tamanho-1);
        
        printArray(vetor, tamanho);

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
    
    //string diretorio = "./arquivos-vetores-ordenacao/Aleatórios";  
    //string diretorio = "./arquivos-vetores-ordenacao/Aleatórios";  
    //string diretorio = "./arquivos-vetores-ordenacao/ParcialmenteOrdenados";  
    string diretorio = "./arquivos-vetores-ordenacao/test";  
    


    vector<string> listaDeArquivos;
    listaDeArquivos = leDiretorio(diretorio);

    cout << "Tamanho Vetor  - Coparações - Tempo (ms) " << endl;
    for (int i = 0; i < listaDeArquivos.size(); i++)   {
      carregarVetorDoArquivo( diretorio + "/" + listaDeArquivos[i]);
    }
   
    return 0;
   
}