
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <ctime>
#include <ratio>
#include <chrono>

#include <RBTree.h>
#include <genericBST.h>

using namespace std;
using namespace std::chrono;

/*#include <map>
#include <ctime>
#include <cstdlib> */

void printArray(int A[], int n)
{
    printf("[%d", A[0]);
    int i;
    for (i = 1; i < n; i++)
    {
        printf(", %d", A[i]);
    }
    printf("]\n");
}

void carregarVetorDoArquivo(int *vetor, string diretorioArquivo)
{

    int elemento = 0;
    int posicao = 0;
    ifstream arquivo;

    //tratar exceção de abertura de arquivo
    arquivo.open(diretorioArquivo);
    if (arquivo.is_open())
    {
        while (!arquivo.eof())
        {
            arquivo >> elemento;
            vetor[posicao] = elemento;
            posicao++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível acessar o arquivo do vetor." << endl;
        exit(0);
    }
}

vector<string> leDiretorio(string caminhoDiretorio)
{

    vector<string> listaDeArquivos;
    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(caminhoDiretorio.c_str());
    while ((lsdir = readdir(dir)) != NULL)
    {
        if (strstr(lsdir->d_name, ".txt") != NULL)
        {
            listaDeArquivos.push_back(string(lsdir->d_name));
        }
    }
    closedir(dir);

    //ordenação considerando string, verificar para ordenar pelo tamanho do vetor.
    sort(listaDeArquivos.begin(), listaDeArquivos.end());
    return listaDeArquivos;
}

int retornaTamanhoVetor(string nomeArquivo)
{
    int pos = nomeArquivo.find(".");
    string sub = nomeArquivo.substr(0, pos);
    return stoi(sub);
}


int main() {

    string diretorio = "./arquivos-arvore/construir/conjunto-04";
    string diretorioConsulta = "./arquivos-arvore/consultar/conjunto-04";
    //string diretorio = "./arquivos-arvore/test-construir/conjunto";

    vector<string> listaDeArquivos;
    vector<string> listaDeArquivosConsulta;
    
    listaDeArquivos = leDiretorio(diretorio);
    listaDeArquivosConsulta = leDiretorio(diretorioConsulta);

    cout << "Tamanho Vetor  - Coparações - Tempo (ms) " << endl; 

    for (int i = 0; i < listaDeArquivos.size(); i++)   {
         
        BST<int> bst;
        RBTree rbtree;

        int tamanho = retornaTamanhoVetor(listaDeArquivos[i]);
        int vetor[tamanho];

        carregarVetorDoArquivo(vetor, diretorio + "/" + listaDeArquivos[i]);
        
        //printArray(vetor, tamanho);

        long quantidadeComparacao = 0;

        auto tempoInicial = high_resolution_clock::now();
        for (int i = 0; i < tamanho; i++)         {
            //bst.insert(vetor[i], quantidadeComparacao);
            //bst.recursiveInsert(vetor[i], quantidadeComparacao);
            rbtree.insert(vetor[i], quantidadeComparacao );
        }

        auto tempoFinal = std::chrono::high_resolution_clock::now();
        auto i_millis = duration_cast<nanoseconds>(tempoFinal - tempoInicial);
        auto f_secs = duration_cast<duration<double>>(tempoFinal - tempoInicial);

        cout <<  "INSERÇÃO: ;" <<tamanho << ";" << quantidadeComparacao << ";" << i_millis.count() << ";" << f_secs.count() << endl;
        
        
     /*   for (int j = 0; j < listaDeArquivosConsulta.size(); j++) {
        
            int tamanhoConsulta = retornaTamanhoVetor(listaDeArquivosConsulta[j]);
            int vetorConsulta[tamanhoConsulta];

            
            if (tamanho == tamanhoConsulta) {           
               long quantidadeComparacaoConsulta = 0;
               carregarVetorDoArquivo(vetorConsulta, diretorio + "/" + listaDeArquivosConsulta[j]);

               auto tempoInicialConsulta = high_resolution_clock::now();
               for (int i = 0; i < tamanhoConsulta; i++)         {
                    //bst.search(vetorConsulta[i], quantidadeComparacaoConsulta);
                    bst.recursiveSearch(vetor[i], quantidadeComparacaoConsulta);
                    //rbtree.searchTree(vetor[i], quantidadeComparacaoConsulta );
               }
               auto tempoFinalConsulta = std::chrono::high_resolution_clock::now();
               auto i_millisConsulta = duration_cast<nanoseconds>(tempoFinalConsulta - tempoInicialConsulta);
               auto f_secsConsulta = duration_cast<duration<double>>(tempoFinalConsulta - tempoInicialConsulta);

               //cout << "CONSULTA: ;" << tamanhoConsulta << ";" << quantidadeComparacaoConsulta << ";" << i_millisConsulta.count() << ";" << f_secsConsulta.count() << endl;
               break;
            }              
        } */

    } 
        //bst.postorder();
        //rbtree.prettyPrint();

    return 0;
}