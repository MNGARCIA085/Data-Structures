#include <stdio.h>


struct nodoABB {
    int dato ;
    nodoABB * izq ;
    nodoABB * der ;
};
typedef nodoABB * ABB;

/*Defina una función recursiva copiarMayores que dados un árbol binario de búsqueda de enteros A
de tipo ABB (sin elementos repetidos) y un entero x, retorne una copia de A que contenga a todos
los elementos del árbol cuyos datos son mayores estrictos a x. Si A es vacío (NULL) o no hay elementos
estrictamente mayores a x en A, el resultado debe ser el árbol vacío (NULL). La función debe retornar
un árbol binario de búsqueda que no comparta memoria con el árbol parámetro. El procedimiento debe
tener O(n) de tiempo de ejecución en el peor caso (siendo n la cantidad de nodos de A) y debe evitar
recorrer todo el árbol, de ser posible.*/

ABB copiarMayores(ABB t , int x) {

    ABB res = NULL;

    if (t != NULL){

        if (t -> dato > x){
            // copio
            res = new nodoABB;
            res -> dato = t -> dato;
            res -> izq = copiaMayores(t->izq, x);
            res -> der = copiaMayores(t->der, x);

        
        } else { // si no es mayor busco en el derecho
            res = copiaMayores(t->der, x);
        }


    }

    return res;
}

/*nota: podría minimizar la cantidad de llamadas recursivas guardando la
copia del derecho en una variable*/

