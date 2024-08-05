#include <stdio.h>

// saber si un número es primo
bool es_primo(int n) {
    if (n <= 1) {
        return false; // 0 y 1 no son primos
    }
    if (n == 2) {
        return true; // 2 es el único número primo par
    }
    if (n % 2 == 0) {
        return false; // Todos los números pares mayores que 2 no son primos
    }
    
    // Verificar divisores desde 3 hasta la raíz cuadrada de n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; // Encontrado un divisor, no es primo
        }
    }
    
    return true; // No se encontraron divisores, es primo
}


void imprimir_primos(int m){
    /**
     * Imprime los primos hasta una cota m
     */
    for (int i = 1; i <= m; i++){
        if (es_primo(i)){
            printf("%d es primo\n", i);
        }
    }
}


// MAIN
int main(){
    int n = 17;
    imprimir_primos(n);

    return 0;
}

// g++ 1.2.Primos.cpp -o primos