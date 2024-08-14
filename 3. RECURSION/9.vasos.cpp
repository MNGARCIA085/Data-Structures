#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint;

// Función recursiva para alternar los vasos
void vasos(bool *V, uint n) {
    // Caso base: si no hay vasos, no hacer nada
    if (n == 0) {
        return;
    }

    // Procesar el vaso en la posición actual (n-1)
    // Si el índice es impar (posición en 0-based), lo dejamos lleno (true)
    // Si el índice es par, lo vaciamos (false)
    if ((n - 1) % 2 == 0) {
        V[n - 1] = true;  // Vaso lleno
    } else {
        V[n - 1] = false; // Vaso vacío
    }

    // Llamada recursiva para el siguiente vaso
    vasos(V, n - 1);
}

void imprimirVasos(bool *V, uint n) {
    for (uint i = 0; i < n; i++) {
        printf("%s ", V[i] ? "Lleno" : "Vacío");
    }
    printf("\n");
}

int main() {
    uint n = 6; // Número de vasos, debe ser par
    bool vasosArray[n];
    
    // Inicializar el array de vasos (la primera mitad llena, la segunda mitad vacía)
    for (uint i = 0; i < n; i++) {
        vasosArray[i] = i < n / 2; // Los primeros n/2 vasos están llenos (true), el resto están vacíos (false)
    }

    printf("Estado inicial de los vasos:\n");
    imprimirVasos(vasosArray, n);

    // Llamada a la función para alternar los vasos
    vasos(vasosArray, n);

    printf("Estado final de los vasos:\n");
    imprimirVasos(vasosArray, n);

    return 0;
}

// g++ 9.vasos.cpp -o vasos