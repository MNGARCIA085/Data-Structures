#include <stdio.h>

struct nodoABB {
    int dato ;
    nodoABB * izq ;
    nodoABB * der ;
};
typedef nodoABB * ABB;



/* Un árbol perfecto es un árbol en el cual todos los nodos interiores tienen dos hijos y todos las hojas
están en el mismo nivel. Un árbol vacío y un árbol con un sólo nodo son árboles perfectos.
Implemente una función recursiva maxAlturalPerfecto que, dado un árbol t devuelve la altura del
subárbol máximo perfecto con la misma raíz que t. Notar que la altura del subárbol máximo perfecto
está determinada por el nodo más cercano a la raíz que no tenga alguno de los hijos. */

int maxAlturaPerfecto (AB t){
    int res = 0 ;
    if ( t ! = NULL ) {
        int hizq = maxAlturaPerfecto ( t-> izq ) ;
        int hder = maxAlturaPerfecto ( t-> der ) ;
        res = 1 + ( ( hizq <= hder ) ? hizq : hder ); // 1+min ( hizq , hder ) ;
    }
    return res;
}



/*Implemente un procedimiento recursivo borrarRecursivo que, dado un árbol t lo elimina completa-
mente, liberando la memoria ocupada.*/
void borrarRecursivo (AB &t){
    if (t != NULL){
        borrarRecursivo(t->izq);
        borrarRecursivo(t->der);
        delete t;
        t = NULL;
    }
}

/*Implemente un procedimiento que, dado un árbol t borra todos los nodos necesarios para obtener el
subárbol máximo perfecto con la misma raíz que t*/


/*Borra los nodos que están a un nivel mayor que altura
PRE: los niveles desde 1 hasta altura están completos*/
void podar(int altura, AB  & t){
    if (altura == 0){
        borrarRecusrvio(t);
    }
    else {
        podar(altura-1, t ->izq);
        podar(altura-1, t -> der);
    }
}

void obtenerPerfecto(AB & t){
    podar(maxAlturaPerfecto(t), t);
}




