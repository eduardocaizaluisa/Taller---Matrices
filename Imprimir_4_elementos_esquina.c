#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

void imprimirEsquinas(int matriz[FILAS][COLUMNAS]) {
    printf("Elementos de las esquinas: %d, %d, %d, %d\n", 
           matriz[0][0], matriz[0][COLUMNAS-1], matriz[FILAS-1][0], matriz[FILAS-1][COLUMNAS-1]);
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    imprimirEsquinas(matriz);
    return 0;
}
