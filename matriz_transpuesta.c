#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

// Funcion para calcular la transpuesta de una matriz
void transpuestaMatriz(int matriz[FILAS][COLUMNAS], int transpuesta[COLUMNAS][FILAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            transpuesta[j][i] = matriz[i][j];
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

    int transpuesta[COLUMNAS][FILAS];
    transpuestaMatriz(matriz, transpuesta);

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    printf("Matriz transpuesta:\n");
    imprimirMatriz(transpuesta);

    return 0;
}
