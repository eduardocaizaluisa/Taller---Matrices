#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

void imprimirImpares(int matriz[FILAS][COLUMNAS]) {
    printf("Elementos impares de la matriz: ");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] % 2 != 0) {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    imprimirImpares(matriz);
    return 0;
}
