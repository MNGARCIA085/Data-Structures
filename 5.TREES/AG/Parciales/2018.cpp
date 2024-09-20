#include <stdio.h>

struct nodoAG {
    int dato;
    nodoArbGen * pH;
    nodoArbGen * sH;
};
typedef nodoAG * AG;

/*Implemente una función recursiva buscar que dado un árbol general t sin elementos repetidos y dado
un entero x, retorne un puntero al nodo del árbol que tenga a x como dato, si x pertenece a t, o NULL
en caso contrario. No se permite definir operaciones auxiliares.*/

AG buscar(AG t , int x){
    if (t != NULL){
        if (t -> dato == x){ // lo encontró
            return t;
        } else {
            // veo si está en el sH
            AG estaSH = buscar(t->sH, x);
            if (estaSH != NULL){
                return estaSH;
            } else { // busco en el primer hijo
                return buscar(t-> pH, x);
            }
        }
    } else {
        return NULL;
    }
}

/* Hacerlo con la variable res */


/*Implemente, utilizando la función buscar, un procedimiento insertar que dado un árbol general t
sin elementos repetidos y dados enteros v y w, inserte a v como primer hijo de w en t (hijo más a la
izquierda), siempre que w pertenezca al árbol y v no pertenezca al árbol. En caso contrario, la operación
no tendrá efecto.*/

void insertar (AG & t , int v , int w ){

    if (t != NULL){
        esta_w = buscar(t, w);
        esta_v = buscar(t, v);

        if ( esta_w != NULL && esta_v == NULL){ // w está y v no
            AG nuevo = new nodoAG;
            nuevo -> dato = v;
            nuevo -> pH = NULL;
            nuevo -> sH = t -> pH;
            t -> pH = nuevo;
        }
    }
}

