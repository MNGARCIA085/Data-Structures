#include <stdio.h>

typedef unsigned int uint;

/**
 Algoritmo horner(coeficientes, n, x)
    Entrada:
        coeficientes: lista de coeficientes del polinomio [a_n, a_{n-1}, ..., a_0]
        n: índice del coeficiente más alto (n = grado del polinomio)
        x: valor en el que se evalúa el polinomio

    Si n == 0 Entonces
        Retornar coeficientes[0]
    Sino
        Retornar horner(coeficientes, n - 1, x) * x + coeficientes[n]
    FinSi
FinAlgoritmo

 */




// Función recursiva para evaluar un polinomio usando la regla de Horner
int horner(int coeficientes[], uint n, int x) {
    if (n == 0) {
        return coeficientes[0];
    } else {
        return horner(coeficientes, n - 1, x) * x + coeficientes[n];
    }
}

int main() {
    // Coeficientes del polinomio: a_n, a_{n-1}, ..., a_0
    int coeficientes[] = {3, -2, 5, 1}; // Representa el polinomio: x^3 + 5x^2 - 2x + 3
    uint grado = sizeof(coeficientes) / sizeof(coeficientes[0]) - 1; // Grado del polinomio
    int x = 1; // Valor en el que se evalúa el polinomio
    
    int resultado = horner(coeficientes, grado, x);
    printf("El valor del polinomio en x = %d es %d\n", x, resultado);
    
    return 0;
}




// g++ 7.polinomios.cpp -o polinomios