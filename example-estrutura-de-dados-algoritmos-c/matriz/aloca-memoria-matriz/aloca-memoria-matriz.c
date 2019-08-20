#include <stdio.h>
#include <stdlib.h>

int** matrizAlloc(int colunas,int linhas){
  int i;
  int **matriz;
  matriz = malloc(linhas*sizeof(int*));
    for (i = 0; i < linhas; i++) {
       matriz[i]= malloc(colunas*sizeof(int));
   }
   return matriz;
}

int main(int argc, char**argv) {

    int linhas = 7;
    int colunas = 7;
    
    int **matrizAlocada = matrizAlloc(colunas, linhas);
    int i, j;
    int soma = 0;

    /* gerando a matriz */
    printf( "Matriz:\n" );
    for( i = 0; i < linhas; i++ ) {
        for( j = 0; j < colunas; j++ ) {
            matrizAlocada[i][j] = 7 + rand() % 5;
            printf( "%3d", matrizAlocada[i][j] );
        }
        printf( "\n" );
    }

    /* fazendo a soma utilizando somente o i */
    for( i = 0; i < linhas; i++ ) {
        soma += matrizAlocada[i][i];
    }
    printf("Soma da diagonal principal usado somente o i: %d\n", soma ); 
    
    /* fazendo a soma utilizando somente o i  e o j*/
     soma = 0;
    for( i = 0; i < linhas; i++ ) {
        for( j = 0; j < colunas; j++ ) {
            if (i == j)
             soma += matrizAlocada[i][j];
        }
    }

    printf("Soma da diagonal principal usando o i e o j: %d", soma); 

    return 0;
}