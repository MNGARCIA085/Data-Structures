#include <stdio.h>
#include <tabla_20242.h>

/*
Implemente el TAD Tabla usando árboles AVL como estructura de datos.
Desarrolle la representación del TAD (repTabla) y el código de las operaciones recuperar y copia, solamente.
Asuma implementadas las otras operaciones del TAD. La representación elegida debería asegurar que la
operación cantidad sea O(1) peor caso, recuperar O(log 2(n)) peor caso, y copia de O(n) peor caso, siendo n
la cantidad de correspondencias.
*/



struct nodoAVL{
    int dom;
    float img;
    int altura; // altura del árbol cuya raíz es (dom,img)
    nodoAVL* izq, der;
}


struct repTabla{
    nodoAVL * arbol;
    int cantidad; // cantidad de correspondencias, para que cantidad sea O(1)
    int cota; // cantidad estimada de correspondencias
}



tabla crear(int cota){
    /* TODO */
}



// PRE: pertenece (d,t). POS: Retorna la imagen de d en t.
float recuperar (int d, Tabla t){
    // como un AVL es un ABB lo puedo buscar iterativamente
    //assert (pertenece(d,t)); //opcional
    nodoAVL* arb = t -> arbol;
    while (d!= arb -> dom){
        if (d > arb -> dom){
            arb = arb -> der;
        }
        else {
            arb = arb -> izq;
        }
    }
    return arb-> img;
}


// POS: Retorna una copia de la tabla t, sin compartir memoria, para la cual se estiman cota correspondencias.
// debo copiar el árbol (para ello usaré una función auxiliar)
Tabla copia (Tabla t, int cota){
    Tabla res = crear(cota);
    res -> arbol = copiaAVL(t -> arbol);
    res -> cantidad = t -> cantidad;
    res -> cota = t -> cota;
    return res;
}


nodoAVL* copiaAVL(nodoAVL* arb){
    // lo haré recursivo
    if (arb == NULL){
        return NULL;
    }
    else {
        nodoAVL* res = NULL;
        res -> dom = arb -> dom;
        res -> img = arb -> img;
        res -> altura = arb -> altura;
        res -> izq = copiaAVL(arb->izq);
        res -> der = copiaAVL(arb->der);
        return res;
    }



}