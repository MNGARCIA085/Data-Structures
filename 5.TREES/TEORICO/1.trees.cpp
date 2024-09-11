#include <stdio.h>

typedef unsigned int uint ;

struct nodoAB {
    uint elem ;
    nodoAB * izq , * der;
};
typedef nodoAB * AB;


struct nodo{
    uint dato;
    nodo* sig;
};

typedef nodo* Lista;



/* Espejo. Obs: No comparte memoria*/
AB espejo(AB t){
    if (t == NULL){
        return NULL;
    }

    AB res = new nodoAB;
    res -> elem = t -> elem;
    res -> izq = espejo(t -> der);
    res -> der = espejo(t -> izq);
    return res; 

}

/*Fn. auxiliar que concatena 2 listas*/
Lista concat(Lista l1, Lista l2){
    // TODO
    return NULL;
}

/* Lista de hojas */
Lista hojas(AB t){

    Lista p;

    if (t == NULL){
        return NULL;
    }

    // si es una hoja la agrego
    if (t -> izq == NULL && t -> der == NULL){
        p = new nodo;
        p -> dato = t -> elem;
        p -> sig = NULL;
        return p;
    }
    else{
        return concat(hojas(t->izq), hojas(t->der));
    }


}