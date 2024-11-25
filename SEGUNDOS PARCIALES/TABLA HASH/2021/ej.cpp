/*Considere una implementación del TAD Conjunto de reales usando hashing abierto, con la siguiente representación:*/

struct nodoHash {
    float dato;
    nodoHash* sig;
};

struct representacionConjunto {
    nodoHash ** tabla; // tabla de hash
    int cota; // tamaño de la tabla de hash
    int cantidad; // cantidad actual de elementos en el conjunto
};

typedef representacionConjunto * Conjunto;

/* Se pide implementar las operaciones eliminar y copia, considerando la representación previa (donde no se
permiten nodos con datos repetidos) y asumiendo la existencia de una función de hash: unsigned int h (float x). */


unisgned int h(float x);


/* elimina el elemento x del conjunto c, si está. En caso
contrario, la operación no tendrá efecto.*/
void eliminar (Conjunto & c, float x){
    unsigned int posicion = h (x) % c->cota;
    eliminado = eliminar_iterativo(c->tabla[posicion], x);
    if (eliminado) c->cantidad--;
}

/* NOTA: no hace falta recorrer la tabla y la lista pues si está sí o sí debe
estar en la posición dada por la función de hash*/

void eliminar_iterativo(nodoHash * & indice, float x){
    bool eliminado = false;

    if (indice ! NULL){
        // si es el primero
        if (indice -> dato == x){
            nodoHash* aBorrar = indice;
            indice = indice -> sig;
            delete aBorrar;
            aBorrar = NULL;
            eliminado = true;
        }
        else { // puede estar en el medio
            nodoHash* aux = indice;
            while (aux->sig != NULL && !eliminado){
                if (aux->sig->dato == x){
                    nodoHash* aBorrar = aux -> sig;
                    aux->sig = aBorrar->sig;
                    delete aBorrar;
                    aBorrar = NULL;
                    eliminado = true;
                }
                else {
                    aux = aux -> sig;
                }
            }

        }
    }
}




/* Retorna una copia del conjunto c sin compartir memoria con éste y sin modificar c.*/
/* Iterativo tengo que recorrer y copiar cada lista SIN compartir memoria; recursivo es más fácil*/

Conjunto copia(Conjunto c){
    //Copio el cabezal
    Conjunto c_copia = new representacionConjunto;
    c_copia->cota = c->cota;

    c_copia->cantidad = c->cantidad;
    c_copia->tabla = new nodoHash*[c_copia->cota];
    //recorro la estructura y copio cada una de las entradas
    for (int i = 0; i < c_copia->cota; i++)
        copiar_recursivo (c->tabla [i], c_copia->tabla [i])
    }
    return c_copia;

void copiar_recursivo (nodoHash * indice, nodoHash * & copia_indice){
    if (indice == NULL) copia_indice = NULL;
    else
    {
        copia_indice = new nodoHash;
        copia_indice->dato = indice->dato
        copiar_recursivo(indice->sig, copia_indice->sig);
    }
}






/* versión iterativa */
Conjunto copia_iterativa(Conjunto c) {
    Conjunto res = new representacionConjunto;
    res->cota = c->cota;
    res->cantidad = c->cantidad;

    // Crear una nueva tabla de hash
    res->tabla = new nodoHash*[c->cota];
    for (int i = 0; i < c->cota; i++) {
        nodoHash* actual = c->tabla[i];
        nodoHash* anterior = NULL;

        // Copiar la lista enlazada del bucket `i`
        while (actual != NULL) {
            nodoHash* nuevoNodo = new nodoHash;
            nuevoNodo->dato = actual->dato;
            nuevoNodo->sig = NULL;

            if (anterior == NULL) {
                // Primer nodo en la nueva lista
                res->tabla[i] = nuevoNodo;
            } else {
                // Enlazar el nodo al anterior
                anterior->sig = nuevoNodo;
            }

            anterior = nuevoNodo;   // Avanzar en la nueva lista
            actual = actual->sig;  // Avanzar en la lista original
        }

        if (anterior == NULL) {
            // Si el bucket está vacío, la tabla apunta a NULL
            res->tabla[i] = NULL;
        }
    }

    return res;
}
