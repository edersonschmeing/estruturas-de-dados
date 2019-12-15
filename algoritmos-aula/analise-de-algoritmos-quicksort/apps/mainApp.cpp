
#include <iostream>
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

void carregarVetorDoArquivo(string diretorioArquivo, int estrategia)
{

    int elemento = 0, posicao = 0, tamanho = 0;

    //Pega o tamanho do vetor do nome do arquivo.
    sscanf(diretorioArquivo.c_str(), "%*[^0-9]%d", &tamanho);
    int vetor[tamanho];

    ifstream arquivo;

    //tratar exceção de abertura de arquivo
    arquivo.open(diretorioArquivo);
    if (arquivo.is_open())
    {
        //Faz a leitura do arquivo texto e armazena em um vetor
        while (!arquivo.eof())
        {
            arquivo >> elemento;
            vetor[posicao] = elemento;
            posicao++;
        }
        arquivo.close();

        quicksort(vetor, tamanho, estrategia);

        //printArray(vetor, tamanho);
    }
    else
    {
        cout << "Não foi possível acessar o arquivo do vetor." << endl;
        exit(0);
    }
}

vector<string> lerDiretorio(string caminhoDiretorio)
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

int main()
{

    //string diretorio = "./arquivos-vetores-ordenacao/Decrescentes";
    //string diretorio = "./arquivos-vetores-ordenacao/Aleatórios";
    //string diretorio = "./arquivos-vetores-ordenacao/ParcialmenteOrdenados";
    string diretorio;
    string dirSelecionado;
    string pivot;
    int opcao;
    int estrategia;
    cout << "Informe 1 para Aleatorios..." << endl;
    cout << "Informe 2 para Decrescentes..." << endl;
    cout << "Informe 3 para Parcialmente ordenados..." << endl;
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        diretorio = "./arquivos-vetores-ordenacao/Aleatórios";
        dirSelecionado = "Aleatórios";
        break;
    case 2:
        diretorio = "./arquivos-vetores-ordenacao/Decrescentes"; //"./arquivos-vetores-ordenacao/test"
        dirSelecionado = "Decrescentes";
        break;
    case 3:
        diretorio = "./arquivos-vetores-ordenacao/Parcialment1eOrdenados";
        dirSelecionado = "Parcialmente Ordenados";
        break;
    default:
        break;
    }

    cout << "Informe 1 para Estratégia do Cormen" << endl;
    cout << "Informe 2 para Estratégia do Hoare" << endl;
    cout << "Informe 3 para escolha do pivot aleatória" << endl;
    cout << "Informe 4 para escolha do pivot mediana de três" << endl;
    cin >> estrategia;

    switch (estrategia)
    {
    case 1:
        pivot = "Cormen";
        break;
    case 2:
        pivot = "Hoare";
        break;
    case 3:
        pivot = "Aleatória";
        break;
    case 4:
        pivot = "Mediana de Três";
        break;
    default:
        pivot = "Cormen";
        break;
    }

    vector<string> listaDeArquivos;
    listaDeArquivos = lerDiretorio(diretorio);
    cout << "Tipo de Ordenação: " << dirSelecionado << endl;
    cout << "Tipo de escolha pivot: " << pivot << endl;
    cout << "Tamanho Vetor;Coparações;Tempo (ms);Tempo(ms d)" << endl;
    for (int i = 0; i < listaDeArquivos.size(); i++)
    {
        carregarVetorDoArquivo(diretorio + "/" + listaDeArquivos[i], estrategia);
    }

    return 0;
}