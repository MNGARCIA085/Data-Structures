#include "punto.h" 
#include <cstdio>
#include <math.h>

double distancia(Punto p1, Punto p2) {
    return sqrt(pow((coordX(p1) - coordX(p2)), 2) +
                pow((coordY(p1) - coordY(p2)), 2));
}

int main() {
    Punto A, B, C;
    A = crearPunto(3.0, 5.5);
    B = crearPunto(0, 9.5);
    C = crearPunto(-2.0, 17.5);



    printf("La distancia entre A y B es: %.2f.\n", distancia(A, B));
    printf("La distancia entre A y C es: %.2f.\n", distancia(A, C));
    printf("La distancia entre B y C es: %.2f.\n", distancia(B, C));

    return 0;
}


// g++ main.cpp punto.cpp -o punto