#include <stdio.h>

struct nodo {
    int elem ;
    nodo * sig ;
};
typedef nodo * lista ;

struct nodoABB {
    int dato ;
    nodoABB * izq ;
    nodoABB * der ;
};
typedef nodoABB * ABB;


/*Implemente un procedimiento iterativo concat que, dadas dos listas l y p, agregue al final de la lista l
los elementos de p, en el mismo orden. La lista l resultante comparte memoria con p.*/

void concat (lista &l , lista p){
    if (p != NULL){
        if (l == NULL){
            l = p;
        }
        else {
            // me ubico al final de l
            lista iter = new nodo;
            while (iter -> sig != NULL){
                iter = iter -> sig;
            }
            // enlazo con p
            iter -> sig = p;
        }
    }
}

/*Defina una función aplanar que dado un ABB A retorne una lista ordenada de menor a mayor que
contenga a todos los elementos de A. Si el árbol es vacío, la función debe retornar la lista vacía.*/
lista aplanar(ABB t){

    lista res = NULL;

    if (t != NULL){

        lista aplanarD = aplanar(t->der);

        lista medio = new nodo;
        medio -> elem = t -> dato;
        medio -> sig = aplanarD;

        lista res = aplanar(t -> izq); // res viene siendo aplanarI

        concat(res, medio);


    }

    return res;

}



