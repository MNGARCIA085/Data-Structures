#include "cola.h"

// Crear una cola vacía
Cola crearCola(){
    Cola c = new CabeceraC;
    c->primero = nullptr;
    c->ultimo = nullptr;
    return c;
}

// Encolar un árbol binario en la cola
void encolar(Cola& c, ABB x){
    NodoC* nuevo = new NodoC;
    nuevo->dato = x;
    nuevo->sig = nullptr;
    
    if (esVaciaCola(c)){
        c->primero = nuevo;
    } else {
        c->ultimo->sig = nuevo;
    }
    c->ultimo = nuevo;
}

// Verificar si la cola está vacía
bool esVaciaCola(Cola c){
    return c->primero == nullptr;
}

// Obtener el primer elemento de la cola
ABB frente(Cola c){
    if (!esVaciaCola(c)){
        return c->primero->dato;
    }
    return nullptr; // Return null if the queue is empty
}

// Desencolar (quitar) el primer elemento de la cola
void desencolar(Cola& c){
    if (!esVaciaCola(c)){
        NodoC* aBorrar = c->primero;
        c->primero = c->primero->sig;
        if (c->primero == nullptr) {
            c->ultimo = nullptr; // If queue becomes empty
        }
        delete aBorrar;
    }
}

// Liberar toda la memoria de la cola
void liberar(Cola& c){
    while (!esVaciaCola(c)){
        desencolar(c);
    }
    delete c;
    c = nullptr;
}
