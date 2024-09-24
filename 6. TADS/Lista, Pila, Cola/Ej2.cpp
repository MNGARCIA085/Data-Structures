#include <iostream>

// Definiciones generales
struct NodoQ {
    int dato;
    NodoQ* sig;
};

struct Cabecera {
    NodoQ* primero;
    NodoQ* ultimo;
};

typedef Cabecera* QEnt;

// Crear una cola
QEnt crearCola(){
    QEnt q = new Cabecera;
    q -> primero = NULL;
    q -> ultimo = NULL;
    return q; 
}


void encolar(int x, QEnt& q){
    // inserto al final
    NodoQ* nuevo  = new NodoQ;
    nuevo -> dato = x;
    nuevo -> sig = NULL; // voy a insertar al final
    if (esVaciaCola(q)){
        q -> primero = nuevo;
    }
    else {
        q->ultimo->sig = nuevo;
    }
    q -> ultimo = nuevo;
}


bool esVaciaCola(QEnt q){
    return q -> primero == NULL;
}

int primero(QEnt q){
    return q -> primero -> dato;
}


// pre: no es vacía
void desencolar(QEnt& q){
    // saco del principio
    NodoQ* aBorrar = q -> primero;
    q -> primero = q -> primero -> sig;
    delete aBorrar;
    aBorrar = NULL;
}


// liberar memoria
void eraseQ(QEnt& q){
    // borro los nodos
    while (q -> primero != NULL){
        NodoQ* aBorrar = q -> primero;
        q -> primero = q -> primero -> sig;
        delete aBorrar;
        aBorrar = NULL;
    }
    // borro la cola
    delete q;
    q = NULL;
}

