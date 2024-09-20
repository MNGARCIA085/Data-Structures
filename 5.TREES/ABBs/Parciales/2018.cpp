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
los elementos de p, en el mismo orden. La lista l resultante comparte memoria con p.
*/

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


/*
Implemente una función recursiva menores que dado un árbol binario de búsqueda t de tipo ABB y dado
un entero k, retorne una lista  que contenga a todos los elementos de
t menores (estrictos) a k y que esté ordenada de mayor a menor. Si no hay elementos en t menores a
k (en particular si t es vacío), la lista que se obtiene es vacía. La función menores debe evitar recorrer
nodos del árbol que no sean estrictamente necesarios. No se permite definir operaciones auxiliares,
aunque puede usarse el procedimiento concat implementado en la parte anterior.
*/

lista menores (ABB t , int k ){
    lista res = NULL;

    if (t != NULL){
        
        // si hago derecho - nodo - izquierdo recorro el árbol en forma ascendente
        lista menoresI = menores(t -> izq, k);

        if (t-> dato < k){ // debo agregar
            // lo agrego
            lista nuevo = new nodo;
            nuevo -> elem = t -> dato;
            nuevo -> sig = menoresI;
            res = menores(t->der, k); // lo guardo en result xq concat comparte memoria con el primer parámetro
            concat(res, nuevo);
        }

        else { // como quiero los menores busco en el izquierdo
            return menoresI; //menores(t->izq, k);
    }

    return res;

}


