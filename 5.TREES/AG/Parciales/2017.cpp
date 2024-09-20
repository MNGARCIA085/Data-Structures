#include <stdio.h>

struct nodoAG {
    int dato;
    nodoArbGen * pH;
    nodoArbGen * sH;
};
typedef nodoAG * AG;


/*Defina una función recursiva copiaParcial en C/C++ que dados un árbol A de tipo ArbGen y un entero
positivo k, retorne una copia de A, sin compartir memoria con éste, con todos los nodos que están en un
nivel menor o igual a k. Si A es vacío o k es cero, el resultado debe ser el árbol vacío. Tenga en cuenta que
en un árbol no vacío la raíz está en el nivel 1 y asuma que A->sH es NULL. No use operaciones auxiliares
propias en la implementación de copiaParcial.*/


AG copiaParcial (AG t, unsigned int k){

    AG res = NULL;

    // Controlo que no haya llegado al limite de k y que el arbol no sea vacio
    if (t != NULL && k > 0){
        // copio
        res = new nodoAG;
        res -> dato = t -> dato;
        res -> pH = copiaParcial(t->pH, k-1);
        res -> sH = copiaParcial(t -> sH, k);
    }

    return res;

}