#include <stdio.h>

#define N 2 // Tamano de la matriz (NxN)

// Funcion para calcular la inversa de una matriz 2x2
void inversaMatriz2x2(double matriz[N][N], double inversa[N][N]) {
    double determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    if (determinante != 0) {
        inversa[0][0] = matriz[1][1] / determinante;
        inversa[0][1] = -matriz[0][1] / determinante;
        inversa[1][0] = -matriz[1][0] / determinante;
        inversa[1][1] = matriz[0][0] / determinante;
    } else {
        printf("La matriz no tiene inversa.\n");
    }
}

// Funcion para multiplicar dos matrices
void multiplicacionMatrices(double matriz1[N][N], double matriz2[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < N; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void imprimirMatriz(double matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double matriz1[N][N] = {
        {1, 2},
        {3, 4}
    };

    double matriz2[N][N] = {
        {2, 0},
        {1, 2}
    };

    double inversa[N][N];
    inversaMatriz2x2(matriz2, inversa);

    double resultado[N][N];
    multiplicacionMatrices(matriz1, inversa, resultado);

    printf("Resultado de la division de matrices (multiplicacion de la primera matriz por la inversa de la segunda):\n");
    imprimirMatriz(resultado);

    return 0;
}
