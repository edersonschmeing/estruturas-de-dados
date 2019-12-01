
#include<iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <shellsort.h>

using namespace std;

/*#include <map>
#include <ctime>
#include <cstdlib> */


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
        //shellSort_Knuth(vetor, tamanho );
        shellSort_Donald(vetor, tamanho );
        
        //shellsort_Knuth_Drozek(vetor, tamanho );
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
    string diretorio = "./arquivos-vetores-ordenacao/ParcialmenteOrdenados";  


    vector<string> listaDeArquivos;
    listaDeArquivos = leDiretorio(diretorio);

    cout << "Tamanho Vetor  - Coparações - Tempo (ms) " << endl;
    for (int i = 0; i < listaDeArquivos.size(); i++)   {
      carregarVetorDoArquivo( diretorio + "/" + listaDeArquivos[i]);
    }
   
    return 0;
   
}