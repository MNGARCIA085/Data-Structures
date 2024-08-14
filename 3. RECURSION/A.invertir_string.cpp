#include <stdio.h>
#include <string.h>


/**
 * Algoritmo invertirCadena(cadena, inicio, fin)
    Entrada:
        cadena: la cadena de caracteres a invertir
        inicio: el índice del primer carácter a procesar
        fin: el índice del último carácter a procesar

    Si inicio >= fin Entonces
        // Caso base: si el inicio es igual o mayor que el fin, la cadena está invertida
        Retornar
    FinSi

    // Intercambiar los caracteres en las posiciones inicio y fin
    Intercambiar(cadena[inicio], cadena[fin])

    // Llamada recursiva para el resto de la cadena
    invertirCadena(cadena, inicio + 1, fin - 1)
FinAlgoritmo
 */


void invertir(char * cadena, int inicio, int fin){

    if (inicio >= fin){
        return;
    }

    // swap
    char temp = cadena[inicio];
    cadena[inicio] = cadena[fin];
    cadena[fin] = temp;

    // llamada recursiva
    invertir(cadena, inicio + 1, fin -1);

}

// test con main
int main(){

    char cadena[] = "cadenadetexto";
    int longitud = strlen(cadena);
    int inicio = 0;
    int fin = longitud - 1;

    invertir(cadena, inicio, fin);

    printf("%s\n", cadena);
}

// g++ A.invertir_string.cpp -o invertir_string