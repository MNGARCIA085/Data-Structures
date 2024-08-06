#include <stdio.h>
#include "fechas.h"


// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int d ;
    unsigned int m ;
    unsigned int a ;
};


// crear una nueva fecha
TFecha crear_fecha ( unsigned int d , unsigned int m , unsigned int a){
    TFecha nueva = new rep_fecha;
    nueva -> d = d;
    nueva -> m = m;
    nueva -> a = a;
    return nueva;
};


// comparar fechas
bool comparar_fechas(TFecha f1, TFecha f2) {
    if ((f1->a < f2->a) 
        || ((f1->a == f2->a) && (f1->m < f2->m))
        || ((f1->a == f2->a) && (f1->m == f2->m) && (f1->d < f2->d))) {
        return true;
    }
    return false;
};


// devolver día
unsigned int dia ( TFecha fecha ){
    return fecha -> d;
};


// devolver día
unsigned int mes ( TFecha fecha ){
    return fecha -> m;
};

// devolver día
unsigned int anio ( TFecha fecha ){
    return fecha -> a;
};



// imprimir fechas
void imprimir_fecha(TFecha fecha){
    printf("Day/month/year: %d/%d/%d\n", fecha -> d, fecha -> m, fecha -> a);
}




