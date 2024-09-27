#include <iostream>

// Definiciones generales
struct NodoQ {
    int dato;
    NodoQ* sig;
};

struct Cabecera {
    NodoQ* primero;
    NodoQ* ultimo;
    int max;
    int cant;
};

typedef Cabecera* QEnt;

QEnt crearCola() {
    QEnt q = new Cabecera;
    q->primero = nullptr;
    q->ultimo = nullptr;
    q->cant = 0;
    return q;
}

void encolar(int x, QEnt& q) {
    NodoQ* nuevo = new NodoQ;
    nuevo->dato = x;
    nuevo->sig = nullptr;
    if (q->primero == nullptr) {
        q->primero = nuevo;
    } else {
        q->ultimo->sig = nuevo;
    }
    q->ultimo = nuevo;
    q->cant++;
}

bool estaLlenaCola(QEnt q) {
    return q->cant == q->max;
}

void desencolar(QEnt& q) {
    NodoQ* aBorrar = q->primero;
    q->primero = q->primero->sig;
    delete aBorrar;
    q->cant--;
}

void eraseQ(QEnt& q) {
    while (q->primero != nullptr) {
        NodoQ* aBorrar = q->primero;
        q->primero = q->primero->sig;
        delete aBorrar;
    }
    delete q;
}