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

// Funcion para calcular la potencia de una matriz
void potenciaMatriz(int matriz[FILAS][COLUMNAS], int resultado[FILAS][COLUMNAS], int exponente) {
    int temporal[FILAS][COLUMNAS];
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            resultado[i][j] = (i == j) ? 1 : 0; // Inicializar resultado como matriz identidad
        }
    }
    for (int exp = 0; exp < exponente; exp++) {
        multiplicacionMatrices(resultado, matriz, temporal);
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                resultado[i][j] = temporal[i][j];
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
    int matriz[FILAS][COLUMNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int resultado[FILAS][COLUMNAS];
    int exponente = 2; // Cambiar este valor para la potencia deseada
    potenciaMatriz(matriz, resultado, exponente);

    printf("Resultado de la matriz elevada a la potencia %d:\n", exponente);
    imprimirMatriz(resultado);

    return 0;
}
