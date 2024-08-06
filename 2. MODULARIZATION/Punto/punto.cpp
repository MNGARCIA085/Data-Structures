#include "punto.h"

struct rep_punto {
    double x;
    double y;
};


/* Devuelve un 'Punto ' de coordenadas 'x' e 'y '. */
Punto crearPunto ( double x , double y ){
    Punto punto = new rep_punto;
    punto -> x = x;
    punto -> y = y;
    return punto;
};

/* Devuelve la coordenada 'x' de 'punto '. */
double coordX ( Punto punto ){
    return punto -> x;
};

/* Devuelve la coordenada 'y' de 'punto '. */
double coordY ( Punto punto ){
    return punto -> y;
};



