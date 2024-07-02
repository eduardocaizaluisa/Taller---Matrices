#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

// Funcion para contar las filas y columnas de una matriz
void contarFilasColumnas(int matriz[FILAS][COLUMNAS], int* filas, int* columnas) {
    *filas = FILAS;
    *columnas = COLUMNAS;
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int filas, columnas;
    contarFilasColumnas(matriz, &filas, &columnas);

    printf("Numero de filas: %d\n", filas);
    printf("Numero de columnas: %d\n", columnas);

    return 0;
}
