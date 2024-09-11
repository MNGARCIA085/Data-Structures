#include <stdio.h>


typedef unsigned int uint ;

struct nodoABB {
    uint elem ;
    nodoABB * izq , * der;
};

typedef nodoABB * ABB;


struct nodo{
    uint dato;
    nodo* sig;
};

typedef nodo* Lista;



/*lista ordenada
con los elementos de un ABB, implementando
aplanarEnLista, de tal manera que el árbol se recorra solo una
vez y que la lista no se recorra al agregar cada elemento
*/


/* Inserta al inicio de una lista */
Lista insInicio(uint x, Lista &l){
    // TODO
    return NULL;
}

Lista aplanarEnLista(ABB t, Lista &l){
    aplanarEnLista(t -> izq, l);
    insInicio(t-> elem, l);
    aplanarEnLista(t -> der, l);
}


Lista aplanar(ABB t){
    Lista l;
    aplanarEnLista(t, l);
    return l;
}