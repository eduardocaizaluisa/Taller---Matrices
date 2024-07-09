#include <stdio.h>

#define N 4

// Estructura para representar valores en formato sexagesimal
typedef struct {
    int grados;
    int minutos;
    int segundos;
} Sexagesimal;

// Funcion para convertir valores sexagesimales a decimal
double sexagesimal_a_decimal(Sexagesimal s) {
    return s.grados + s.minutos / 60.0 + s.segundos / 3600.0;
}

// Funcion para convertir valores decimales a sexagesimales
Sexagesimal decimal_a_sexagesimal(double d) {
    Sexagesimal s;
    s.grados = (int)d;
    s.minutos = (int)((d - s.grados) * 60);
    s.segundos = (int)((((d - s.grados) * 60) - s.minutos) * 60);
    return s;
}

// Funcion para sumar dos matrices en formato sexagesimal
void sumar_matrices(Sexagesimal matriz1[N][N], Sexagesimal matriz2[N][N], Sexagesimal resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double decimal1 = sexagesimal_a_decimal(matriz1[i][j]);
            double decimal2 = sexagesimal_a_decimal(matriz2[i][j]);
            double suma = decimal1 + decimal2;
            resultado[i][j] = decimal_a_sexagesimal(suma);
        }
    }
}

// Funcion para imprimir una matriz en formato sexagesimal
void imprimir_matriz(Sexagesimal matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d° %d' %d\" ", matriz[i][j].grados, matriz[i][j].minutos, matriz[i][j].segundos);
        }
        printf("\n");
    }
}

int main() {
    // Definicion de dos matrices en formato sexagesimal
    Sexagesimal matriz1[N][N] = {
        {{1, 30, 0}, {2, 45, 30}, {3, 0, 15}, {4, 15, 45}},
        {{5, 30, 30}, {6, 45, 15}, {7, 0, 30}, {8, 15, 0}},
        {{9, 30, 45}, {10, 45, 0}, {11, 0, 15}, {12, 15, 30}},
        {{13, 30, 30}, {14, 45, 15}, {15, 0, 0}, {16, 15, 45}}
    };
    
    Sexagesimal matriz2[N][N] = {
        {{16, 30, 0}, {15, 45, 30}, {14, 0, 15}, {13, 15, 45}},
        {{12, 30, 30}, {11, 45, 15}, {10, 0, 30}, {9, 15, 0}},
        {{8, 30, 45}, {7, 45, 0}, {6, 0, 15}, {5, 15, 30}},
        {{4, 30, 30}, {3, 45, 15}, {2, 0, 0}, {1, 15, 45}}
    };

    Sexagesimal resultado[N][N];

    // Sumar las matrices
    sumar_matrices(matriz1, matriz2, resultado);

    // Imprimir el resultado
    printf("Suma de matrices en formato sexagesimal:\n");
    imprimir_matriz(resultado);

    return 0;
}
