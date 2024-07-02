#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

// Funcion para multiplicar dos matrices
void multiplicacionMatrices(int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int resultado[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < COLUMNAS; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz1[FILAS][COLUMNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int matriz2[FILAS][COLUMNAS] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    int resultado[FILAS][COLUMNAS];
    multiplicacionMatrices(matriz1, matriz2, resultado);

    printf("Resultado de la multiplicacion de matrices:\n");
    imprimirMatriz(resultado);

    return 0;
}
