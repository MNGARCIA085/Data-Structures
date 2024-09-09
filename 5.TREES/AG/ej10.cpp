#include <stdio.h>

struct nodoAG {
    int dato;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG;

/*
Implemente la función AG padre(AG a, int x) que retorne un puntero al nodo padre en a del nodo que tenga a x
como dato. Asumimos que a no tiene elementos repetidos. Si x no está en a o si x es la raíz de a, la función
padre deberá retornar el puntero NULL. No se pueden definir operaciones auxiliares para implementar padre. 
*/

AG padre(int x, AG t){
    // si el árbol es null o está en la raíz retorno NULL
    if (t == NULL || t -> dato == x){
        return NULL;
    }

    // busco en el primer hijo
    AG hijo = t -> pH;
    while (hijo != NULL && hijo->dato != x){
        hijo = hijo -> sH;
    }
    if (hijo != NULL){ // lo encontró
        return t;
    }
    else {
        // busco en el siguiente nivel
        AG nhijo = padre(x, t -> pH);
        if (nhijo != NULL){
            return nhijo;
        }
        else { // busco en el siguiente hermano
            return padre(x, t -> sH);
        }
    }
    
}





