#include <stdio.h>

typedef unsigned int uint;


/**
 Algoritmo TorresDeHanoi(n, origen, destino, auxiliar)
    Entrada: 
        n: número de discos
        origen: la torre de donde se mueven los discos
        destino: la torre a la que se mueven los discos
        auxiliar: la torre auxiliar

    Si n == 1 entonces
        Imprimir "Mover disco 1 de ", origen, " a ", destino
    Sino
        TorresDeHanoi(n - 1, origen, auxiliar, destino)  // Mover n-1 discos de origen a auxiliar usando destino
        Imprimir "Mover disco ", n, " de ", origen, " a ", destino
        TorresDeHanoi(n - 1, auxiliar, destino, origen)  // Mover n-1 discos de auxiliar a destino usando origen
    FinSi
FinAlgoritmo
*/



void hanoi(uint n, char origen, char destino, char auxiliar){

    if ( n == 1){
        printf("Mover disco %d de %c a %c\n", n, origen, destino);
    }
    else {
        // muevo n-1 discos de origen a auxiliar usando destino
        hanoi(n-1, origen, auxiliar, destino);
        // imprimo
        printf("Mover disco %d de %c a %c\n", n, origen, destino);
        // muevo n-1 discos de auxiliar a destino usando origen
        hanoi(n-1, auxiliar, destino, origen);
    }

}

int main() {
    uint n = 3; // Número de discos
    hanoi(n, 'A', 'C', 'B'); // A: origen, C: destino, B: auxiliar
    return 0;
}

// g++ 5.hanoi.cpp -o hanoi



