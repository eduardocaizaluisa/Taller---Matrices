#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52

//  esta Estructura para representar una carta
typedef struct {
    char *palo;
    char *valor;
} Carta;

// Función para inicializar el mazo con cartas estándar
void inicializarMazo(Carta *mazo) {
    char *palos[] = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    char *valores[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jota", "Reina", "Rey"};

    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            mazo[index].palo = palos[i];
            mazo[index].valor = valores[j];
            index++;
        }
    }
}

// Función para intercambiar dos cartas en el mazo
void intercambiarCartas(Carta *mazo, int i, int j) {
    Carta temp = mazo[i];
    mazo[i] = mazo[j];
    mazo[j] = temp;
}

// Función para desordenar el mazo usando el algoritmo de Fisher-Yates
void desordenarMazo(Carta *mazo) {
    srand(time(NULL)); // Inicializar la semilla aleatoria

    for (int i = NUM_CARTAS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        intercambiarCartas(mazo, i, j);
    }
}

// Función para imprimir el mazo de cartas
void imprimirMazo(Carta *mazo) {
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("%s de %s\n", mazo[i].valor, mazo[i].palo);
    }
}

// Función para ordenar el mazo por valor (no es necesario en este caso porque ya está ordenado por defecto)

int main() {
    Carta mazo[NUM_CARTAS];

    // Inicializar y mostrar el mazo ordenado
    inicializarMazo(mazo);
    printf("Mazo inicial (ordenado):\n");
    imprimirMazo(mazo);
    printf("\n");

    // Desordenar el mazo
    desordenarMazo(mazo);
    printf("Mazo desordenado:\n");
    imprimirMazo(mazo);
    printf("\n");

    // Ordenar el mazo (para mostrar que se puede volver a ordenar)
    // Aquí podrías implementar un algoritmo de ordenación si lo deseas

    // Mostrar el mazo ordenado de nuevo
    printf("Mazo ordenado:\n");
    imprimirMazo(mazo);

    return 0;
}
