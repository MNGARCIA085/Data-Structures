/*Considere un TAD Conjunto de elementos de un tipo T.
Considere además una implementación del TAD Conjunto usando hashing abierto, que tiene la siguiente
representación:*/

struct nodoHash {
    T dato;
    nodoHash* sig;
}


struct representacionConjunto {
    nodoHash** tabla; // tabla de hash
    int cota; // tamaño de la tabla de hash
    int cantidad; // cantidad actual de elementos en el conjunto
}

typedef representacionConjunto * Conjunto;

/* Los elementos de tipo T se pueden manipular con los operadores básicos:*/

/* Fn. de hash; retorna un número natural que puede exceder el valor definido para el tamaño de una tabla de hash.*/
unsigned int h(T e);



/* Retorna true si y solo si el elemento e está en el conjunto c*/
bool pertenece (Conjunto c, T e){
    // ubico la posición
    int pos = h(e)%c->cota;
    // busco
    nodoHash* aux = c->tabla[pos];
    while (aux != NULL && aux->dato != e){
        aux = aux -> sig;
    }
    return aux != NULL;
}



/* Retorna el mínimo elemento de un conjunto c no vacío (precondición)*/
T minimo (Conjunto c){
    // debo recorrer la tabla y cada lista en cada posición de la tabla
    nodoHash* min = NULL; // lo hago con nodo hash xq sino debería saber cómo inicializar el mínimo
    //
    for (int i = 0; i < c -> cota; i++){
        nodoHash* aux = c -> tabla[i];
        while (aux != NULL){
            if (min==NULL || aux -> dato < min -> dato){ // la 1era condición es para la primera vez
                min = aux;
            }
            aux = aux -> sig;
        }
    }
    return min->dato;
}


/*
Bajo las condiciones establecidas, la operación pertenece tiene tiempo de ejecución promedio O(1) (la lista
en cada posición de la tabla tiene en promedio un nodo), en tanto que la operación minimo tiene O(n), siendo
n la cantidad de elementos, ya que debe recorrer toda la tabla (todas las listas) para encontrar el menor (en la
tabla de hash no hay un orden). Por otra parte, ambas operaciones tienen O(n) peor caso: minimo por las
razones ya expuestas y, pertenece si se tiene un mal diseño del hash (la función h no dispersa bien y/o la tabla
de hash posee un valor muy pequeño en relación a la cantidad de elementos).*/


