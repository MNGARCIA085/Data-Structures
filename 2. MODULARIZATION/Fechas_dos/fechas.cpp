#include <stdio.h>
#include "fechas.h"


// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int f ; // AAAAMMDD
};


// crear una nueva fecha
TFecha crear_fecha ( unsigned int f){
    TFecha nueva = new rep_fecha;
    nueva -> f = f;
    return nueva;
};


// comparar fechas
bool comparar_fechas(TFecha f1, TFecha f2) {
    if (f1->f < f2->f) {
        return true;
    }
    return false;
};


// devolver día
unsigned int dia ( TFecha fecha ){
    return (fecha -> f)% 100;
};


// devolver día
unsigned int mes ( TFecha fecha ){
    return (fecha -> f) % 100000/100;
};

// devolver día
unsigned int anio ( TFecha fecha ){
    return (fecha -> f)/10000;
};



// imprimir fechas
void imprimir_fecha(TFecha fecha){
    printf("%d/%d/%d\n", fecha -> f%100, fecha -> f%10000/100, fecha -> f/10000);
};




