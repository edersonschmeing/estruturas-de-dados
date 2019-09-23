#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char**argv) {
    int matriz[5][5];
    int i, j;
    int soma = 0;

    /* gerando a matriz */
    printf( "Matriz:\n" );
    for( i = 0; i < 5; i++ ) {
        for( j = 0; j < 5; j++ ) {
            matriz[i][j] = 5 + rand() % 5;
            printf( "%3d", matriz[i][j] );
        }
        printf( "\n" );
    }

    /* fazendo a soma utilizando somente o i */
    for( i = 0; i < 5; i++ ) {
        soma += matriz[i][i];
    }
    printf("Soma da diagonal principal usado somente o i: %d\n", soma );
    
    /* fazendo a soma utilizando somente o i  e o j*/
    soma = 0;
    for( i = 0; i < 5; i++ ) {
        for( j = 0; j < 5; j++ ) {
            if (i == j)
             soma += matriz[i][j];
        }
    }

    printf("Soma da diagonal principal usando o i e o j: %d", soma);

    return 0;
}