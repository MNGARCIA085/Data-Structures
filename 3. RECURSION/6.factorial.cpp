#include <stdio.h>

typedef unsigned int uint;

/**
 Algoritmo factAcum(n, acum)
    Entrada:
        n: número para calcular el factorial
        acum: acumulador que mantiene el resultado parcial

    Si n == 0 Entonces
        Retornar acum
    Sino
        Llamar factAcum(n - 1, acum * n)
    FinSi
FinAlgoritmo
*/


uint factorial(uint n, uint acum){
    if (n == 0){
        return acum;
    }
    else {
        return factorial(n-1, n*acum);
    }
}


// main para probar
int main(){
    uint n = 4;

    uint acum = 1; // debe ser así para el factorial; 1 es el neutro de la mult.

    uint fac = factorial(n, acum);

    printf("El factorial es %d\n", fac);
}

// g++ 6.factorial.cpp -o factorial