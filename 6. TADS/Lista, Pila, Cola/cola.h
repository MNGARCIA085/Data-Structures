#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "nodoABB.h" // Include your ABB definition

// Definiciones generales
struct NodoC {
    ABB dato;       // Change to store ABB type
    NodoC* sig;
};

struct CabeceraC {
    NodoC* primero;
    NodoC* ultimo;
};

typedef CabeceraC* Cola;

// Funciones de la cola
Cola crearCola();
void encolar(Cola& c, ABB x);
bool esVaciaCola(Cola c);
ABB frente(Cola c);
void desencolar(Cola& c);
void liberar(Cola& c);

#endif // COLA_H
