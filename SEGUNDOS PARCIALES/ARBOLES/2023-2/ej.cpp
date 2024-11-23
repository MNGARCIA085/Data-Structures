#include <stdio.h>
#include <tabla.h>

/*

Defina una representación del TAD Tabla no acotada (RepTabla), en la que las operaciones:

- crear, cantidad, minDominio y maxDominio tengan O(1) de tiempo de ejecución en el peor caso;
- insertar, definida, recuperar y eliminar tengan O(log2(n)) de tiempo de ejecución en el caso promedio, siendo n la cantidad de correspondencias en la tabla);
- imprimir tenga O(n) de tiempo de ejecución en el peor caso, siendo n la cantidad de correspondencias en la tabla.

Explique brevemente cada campo de la representación elegida, que NO debe incluir un árbol AVL. 
Luego,escriba los códigos de crear, insertar e imprimir; asuma implementadas las restantes operaciones especificadas del TAD 
(no escriba sus códigos). Considere también que existe la operación impCorrespondencia
(nat d, float c), que imprime la correspondencia (d,c)
*/


struct nodoABB{
    int dom;
    float img;
    nodoABB* izq,der;
}

struct repTabla{
    nodoABB* arbol;
    int cantidad; // que cantidad sea o(1)
    nodoABB* minDom; // para que minDom sea O(1)
    nodoABB* maxDom; // para que maxDom sea O(1)
}


// POS: Devuelve la Tabla vacía, sin correspondencias.
Tabla crear(){
    Tabla res = new repTabla;
    res -> arbol = NULL;
    res -> cantidad = 0;
    res -> minDom = NULL;
    res -> maxDom = NULL;
    return res;
}



/* POS: Agrega la correspondencia (d,c) en t, si d no tenía imagen en t. En caso contrario actualiza la imagen de d
con c. */
void insertar (nat d, float c, Tabla & t){
    // donde debo insertar es en el árbol, para eso uso una función auxiliar
    // además debo actualizar la cantidad y los valores para el mínimo y el máximo
    // la cantidad aumenta sólo si es inserción
    nodoABB* arb = insertarABB(t->arbol);
    if (arb != NULL){ // inserta
        // sumo 1 a cantidad y actualizo máximo y mínimo si hace falta
        t -> cantidad++;
        if (t -> minDom == NULL || d < t -> minDom){
            t -> minDom = arb;
        }
        if (t -> maxDom == NULL || d > t -> maxDom){
            t -> maxDom = arb;
        }
    }
}


/* Inserta o actualiza un nodo en el ABB. Retorna el puntero al nodo o NULL
si es una actualización */
nodoABB* insertarABB(nat d, float c, nodoABB* & a){
    // recursivo
    if (a == NULL){
        nodoABB* nuevo = new nodoABB;
        nuevo -> dom = d;
        nuevo -> img = c;
        nuevo -> izq = NULL;
        nuevo -> der = NULL;
        return nuevo;
    }
    else if (a -> dom == d){ // edito
            a -> img = c;
            return NULL;
    } else if (a -> dom > c){
        return insertarABB(d, c, a->izq);
    } else {
        return insertarABB(d, c, a->der);
    }
}



//POS: Imprime las correspondencias (d,c) de t, ordenadas de mayor a menor por los valores del dominio (d).
void imprimir(Tabla t){
    // uso una función auxiliar para imprimir el árbol
    imprimirABB(t->arbol);
}

// imprime de mayor a menor
void imprimirABB(nodoABB* arb){
    if (arb != NULL){
        imprimirABB(arb -> der);
        impCorrespondencia(arb -> dom, arb -> img);
        imprimirABB(arb -> izq);
    }
}