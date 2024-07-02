#include <stdio.h>

#define FILAS 4
#define COLUMNAS 4

// Funcion para imprimir los elementos que no estan en las esquinas
void imprimirNoEsquinas(int matriz[FILAS][COLUMNAS]) {
    printf("Elementos que no estan en las esquinas: ");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (!((i == 0 || i == FILAS - 1) && (j == 0 || j == COLUMNAS - 1))) {
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

    imprimirNoEsquinas(matriz);
    return 0;
}
