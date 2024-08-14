#include <stdio.h>

typedef unsigned int uint;


/**
 * Algoritmo de euclides
 * 
 * Si uno de los números es cero, el MCD es el otro número.
 * De lo contrario, calcula el MCD del menor número y 
        el residuo de la división del mayor número entre el menor número.
 */


/** a y b no pueden ser ambos 0 pues no está definido mcd(0,0) */
int mcd(uint a, uint b){
    if (b==0){
        return a;
    }else if (a==0){
        return b;
    }else{
        if (a<b){
            return mcd(a, b%a);
        }else{
            return mcd(b, a%b);
        }
    }
}


int main() {
    int a = 56, b = 98;
    printf("El MCD de %d y %d es %d\n", a, b, mcd(a, b));
    return 0;
}

// g++ 4.mcd.cpp -o mcd