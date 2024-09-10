#include <stdio.h>

typedef unsigned int uint;


/* GENERAL TREE */
struct nodoAG {
    int dato;
    struct nodoAG * pH;  // Pointer to the first child
    struct nodoAG * sH;  // Pointer to the next sibling
};

typedef struct nodoAG * AG;

/* LIST */
struct nodoLista {
    uint elem;
    nodoLista * sig;
};
typedef nodoLista * Lista;


/*
Defina una función recursiva esPrefijo que dada una lista de enteros y un árbol general de enteros, retorne
TRUE si y sólo si la lista es un prefijo de algún camino del árbol general, comenzando desde la raíz. Se dice
que la secuencia x es prefijo de la secuencia z si z es xy, esto es, la concatenación de x e y. Cualquiera
de las secuencias x, y, z pueden ser vacías. En particular si x es vacía es prefijo de cualquier secuencia, y
toda secuencia es prfijo de de sí misma. No se deben usar funciones o procedimientos auxiliares en este
ejercicio.
*/

/*
Approach:
If the list l is empty, it is trivially a prefix of any path, so return TRUE.
If the tree t is NULL but the list is not empty, return FALSE.
If the first element of the list does not match the current tree node's data, return FALSE.
If the first element matches, recursively check if the remaining list matches any path starting from the 
first child (pH) or any of the siblings (sH).
*/

bool esPrefijo(Lista l, AG t){
    if (l == NULL){
        return true;
    }
    else if (t==NULL){
        return false;
    }

    if (l -> elem != t -> dato){
        return false;
    }
    else {
        return esPrefijo(l -> sig, t -> pH) || (esPrefijo(l, t -> sH));
                                                // I do not advance the list for the sH
    }
}


int main() {
    // Create a sample tree using new (1 -> 2, 1 -> 3, 2 -> 4)
    AG root = new nodoAG{1, nullptr, nullptr};          // Root node 1
    root->pH = new nodoAG{2, nullptr, new nodoAG{3, nullptr, nullptr}};  // Child 2 with sibling 3
    root->pH->pH = new nodoAG{4, nullptr, nullptr};    // Child of 2 is 4

    // Create a sample list: 1 -> 2 -> 4 -> NULL
    Lista lista = new nodoLista{1, new nodoLista{2, new nodoLista{4, nullptr}}};

    // Check if the list is a prefix of any path in the tree
    if (esPrefijo(lista, root)) {
        printf("La lista es un prefijo de algún camino del árbol.\n");
    } else {
        printf("La lista no es un prefijo de ningún camino del árbol.\n");
    }

    // Free the dynamically allocated memory (manually freeing nodes)
    delete root->pH->pH;      // Node 4
    delete root->pH->sH;      // Node 3
    delete root->pH;          // Node 2
    delete root;              // Root node 1

    delete lista->sig->sig;   // Node 4 in the list
    delete lista->sig;        // Node 2 in the list
    delete lista;             // Node 1 in the list


}

// g++ ej7.cpp -o ej7