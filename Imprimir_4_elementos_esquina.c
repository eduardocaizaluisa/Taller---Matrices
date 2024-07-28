#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define FILAS 4
#define COLUMNAS 4

void imprimirEsquinas(int matriz[FILAS][COLUMNAS]) {
    printf("Elementos de las esquinas: %d, %d, %d, %d\n", 
           matriz[0][0], matriz[0][COLUMNAS-1], matriz[FILAS-1][0], matriz[FILAS-1][COLUMNAS-1]);
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    printf("Matriz: \n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int matriz[FILAS][COLUMNAS] = {};

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = random() % 10;
        }
    }

    imprimirMatriz(matriz);
    imprimirEsquinas(matriz);
    return 0;
}

