#include <stdio.h>

#define N 4

// Funcion para imprimir una matriz
void imprimir_matriz(double matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Funcion para copiar el contenido de una matriz a otra
void copiar_matriz(double origen[N][N], double destino[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

// Funcion para crear una matriz identidad
void identidad(double matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

// Funcion para calcular la inversa de una matriz 4x4 usando el metodo de Gauss-Jordan
int invertir_matriz(double matriz[N][N], double inversa[N][N]) {
    double temp[N][N];
    copiar_matriz(matriz, temp);
    identidad(inversa);

    for (int i = 0; i < N; i++) {
        double pivote = temp[i][i];
        if (pivote == 0) {
            return 0; // No se puede invertir
        }
        for (int j = 0; j < N; j++) {
            temp[i][j] /= pivote;
            inversa[i][j] /= pivote;
        }
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = temp[k][i];
                for (int j = 0; j < N; j++) {
                    temp[k][j] -= factor * temp[i][j];
                    inversa[k][j] -= factor * inversa[i][j];
                }
            }
        }
    }
    return 1;
}

// Funcion para multiplicar dos matrices 4x4
void multiplicar_matrices(double matriz1[N][N], double matriz2[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < N; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    double matriz1[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    double matriz2[N][N] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    double inversa[N][N];
    double resultado[N][N];

    // Calcular la inversa de la matriz2
    if (invertir_matriz(matriz2, inversa)) {
        // Multiplicar matriz1 por la inversa de matriz2 para obtener el resultado de la "division"
        multiplicar_matrices(matriz1, inversa, resultado);

        printf("Division de matrices (matriz1 / matriz2):\n");
        imprimir_matriz(resultado);
    } else {
        printf("La matriz no se puede invertir\n");
    }

    return 0;
}

