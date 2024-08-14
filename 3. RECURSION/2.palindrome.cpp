#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Función esPalindromo(palabra):
    Si longitud(palabra) <= 1:
        Retornar Verdadero

    Si primerCaracter(palabra) != ultimoCaracter(palabra):
        Retornar Falso

    Subcadena = obtenerSubcadena(palabra, desde=1, hasta=longitud(palabra) - 2)
    Retornar esPalindromo(Subcadena)
 */



bool palindrome(char *palabra, int inicio, int fin){
    if (inicio > fin){
        return true;
    };

    if (palabra[inicio] != palabra[fin]){
        return false;
    };

    return palindrome(palabra, inicio+1, fin-1);
};


// MAIN
int main() {
    // Definir algunas palabras para probar
    char palabra1[] = "radar";
    char palabra2[] = "woo young woo";
    char palabra3[] = "madam";
    
    // Calcular las longitudes de las palabras
    int longitud1 = strlen(palabra1);
    int longitud2 = strlen(palabra2);
    int longitud3 = strlen(palabra3);

    // Probar si cada palabra es un palíndromo
    if (palindrome(palabra1, 0, longitud1 - 1)) {
        printf("\"%s\" es un palíndromo.\n", palabra1);
    } else {
        printf("\"%s\" no es un palíndromo.\n", palabra1);
    }

    if (palindrome(palabra2, 0, longitud2 - 1)) {
        printf("\"%s\" es un palíndromo.\n", palabra2);
    } else {
        printf("\"%s\" no es un palíndromo.\n", palabra2);
    }

    if (palindrome(palabra3, 0, longitud3 - 1)) {
        printf("\"%s\" es un palíndromo.\n", palabra3);
    } else {
        printf("\"%s\" no es un palíndromo.\n", palabra3);
    }

    return 0;
}

// g++ 2.palindrome.cpp -o palindrome

