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

void imprimirMatriz(double matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double matriz[N][N] = {
        {4, 7},
        {2, 6}
    };

    double inversa[N][N];
    inversaMatriz2x2(matriz, inversa);

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    printf("Matriz inversa:\n");
    imprimirMatriz(inversa);

    return 0;
}
