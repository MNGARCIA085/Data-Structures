#include <iostream>


struct nodoArbol{
    int dato;
    int ocurrencias; // ahora tengo un dato junto con la cantidad de veces que aparece en cada nodo del árbol
    nodoArbol* izq;
    nodoArbol* der;
};

typedef nodoArbol* ABB;

struct RepresentacionMultiset{
    int cantidad; // la cantidad de elementos del conjunto
    ABB min; // llevo el mínimo (que es un árbol) para poder cumplir con los requisitos de tiempo
    ABB max;
    ABB arbol;
};

typedef RepresentacionMultiset* Multiset;


// POS : Devuelve la cantidad de ocurrencias del elemento x del multiset m (0 si x no est á en m).
int ocurrencias(Multiset m, int x){
    return ocurrenciasAux(m->arbol, x); // no puedo usar directamente el multiconjunto
            // xq no es un árbol, el que lo es es m->arbol
}


int ocurrenciasAux(ABB arbol, int x){
    if (arbol == NULL){
        return 0;
    }
    else if (arbol->dato == x){
        return arbol -> ocurrencias;
    }
    else if (arbol-> dato  < x){
        return ocurrenciasAux(arbol->der, x);
    }
    else {
        return ocurrenciasAux(arbol->izq, x);
    }

}


// POS : Retorna el mí nimo elemento del multiset m ( independientemente del número de ocurrencias ). 
// PRE : m no vacío.
int min(Multiset m ){
    return m->min->dato;
}


// POS : Agrega n ocurrencias del elemento x al multiset m. PRE : n >0.
// tengo un único nodo en el árbol, es una pareja, con el elemento y su cantidad
void insertar ( Multiset & m , int x , int n) {
    ABB arbolAux = insertarAux(m->arbol, x, n);
    // actualizo min y máx
    if (m->min == NULL || x < m->min->dato){
        m->min = arbolAux;
    }
    if (m->max == NULL || x > m->max->dato){
        m->max = arbolAux;
    }
    m->cantidad+=n;
}


ABB insertarAux(ABB & arbol, int x, int n){
    if (arbol == NULL){
        ABB nuevo = new nodoArbol;
        nuevo -> dato = x;
        nuevo -> izq = NULL;
        nuevo -> der = NULL;
        nuevo -> ocurrencias = n;
        arbol = nuevo;
        return arbol;
    }
    else if (arbol->dato==x){ // ya está, sólo actualizo el n
        arbol->ocurrencias+=n;
        return;
    }
    else if (arbol->dato < x){
        return insertarAux(arbol->der, x, n);
    } else {
        return insertarAux(arbol->izq, x, n);
    }
}





