#include <stdio.h>

typedef unsigned int uint ;

// Árbol
struct nodoAB {
    uint elem ;
    nodoAB * izq , * der;
};
typedef nodoAB * AB;


// Lista
struct nodoLista {
    uint elem;
    nodoLista * sig;
};
typedef nodoLista * Lista;



// Pre-orden
void preOrden(AB t1, Lista &l) {
    if (t1 != nullptr) {
        // Create a new node for the list
        Lista newNode = new nodoLista;
        newNode->elem = t1->elem;
        newNode->sig = l;  // Insert at the front of the list
        l = newNode;       // Update the list head

        preOrden(t1->izq, l);
        preOrden(t1->der, l);
    }
}



// Función para imprimir el árbol en recorrido en-orden (in-order)
void enOrden(AB t1) {
    if (t1 != nullptr) {
        enOrden(t1->izq);
        printf("%d ", t1->elem);
        enOrden(t1->der);
    }
}


// Post-orden
void postOrden(AB t1) {
    if (t1 != nullptr) {
        postOrden(t1->izq);
        postOrden(t1->der);
        printf("%d ", t1->elem);
    }
}



/**
 * esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino
desde la raíz a un hoja de b.
function esCamino(tree, list):
    // Base Case 1: Both tree and list are empty
    if tree is NULL and list is NULL:
        return TRUE

    // Base Case 2: One is empty and the other is not
    if tree is NULL or list is NULL:
        return FALSE

    // Check if the current elements of tree and list match
    if tree.element == list.element:
        // Check if this is a leaf node in the tree and the end of the list
        if tree.left is NULL and tree.right is NULL and list.next is NULL:
            return TRUE
        
        // Recur on the left and right subtrees with the next list element
        return esCamino(tree.left, list.next) OR esCamino(tree.right, list.next)

    // If the current elements don't match
    return FALSE
 */
bool esCamino(AB b, Lista l) {
    if (b == NULL && l == NULL) {
        return true; // Both tree and list are empty
    }
    if (b == NULL || l == NULL) {
        return false; // Either tree or list is empty, but not both
    }
    if (b->elem == l->elem) {
        if (b->izq == NULL && b->der == NULL && l->sig == NULL) {
            return true; // Both reached the end, and it's a leaf
        }
        return esCamino(b->izq, l->sig) || esCamino(b->der, l->sig);
    }
    return false; // Elements don't match
}



/* lista con los elementos del camino más largo */








// Helper function to create a new tree node
AB nuevoNodoAB(uint elem) {
    AB nuevo = new nodoAB;
    nuevo->elem = elem;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

// Helper function to create a new list node
Lista nuevoNodoLista(uint elem) {
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = nullptr;
    return nuevo;
}



// helper: print list
void imprimirLista(Lista l){
    while (l != NULL){
        printf("%d ", l -> elem);
        l = l -> sig;
    }
    printf("\n");
}



// Test
int main() {
    // Create a tree
    AB raiz = nuevoNodoAB(1);
    raiz->izq = nuevoNodoAB(2);
    raiz->der = nuevoNodoAB(3);
    raiz->izq->izq = nuevoNodoAB(4);
    raiz->izq->der = nuevoNodoAB(5);
    raiz->der->izq = nuevoNodoAB(6);
    raiz->der->der = nuevoNodoAB(7);

    
    // Create a list that matches a path in the tree (e.g., 1 -> 2 -> 4)
    Lista camino = nuevoNodoLista(1);
    camino->sig = nuevoNodoLista(2);
    camino->sig->sig = nuevoNodoLista(4);

     // Print if the list is a valid path in the tree
    printf(esCamino(raiz, camino) ? "El camino es válido." : "El camino no es válido.");


    //
    printf("\nPrueba de pre-orden");
    Lista l1 = NULL;
    preOrden(raiz, l1);
    imprimirLista(l1);


    printf("\nPrueba camino más largo\n");
    AB raiz2 = nuevoNodoAB(1);               // Root node
    raiz2->izq = nuevoNodoAB(2);             // Left subtree
    raiz2->der = nuevoNodoAB(3);             // Right subtree
    raiz2->izq->izq = nuevoNodoAB(4);        // Left-left
    raiz2->izq->der = nuevoNodoAB(5);        // Left-right
    raiz2->der->der = nuevoNodoAB(6);        // Right-right
    raiz2->izq->izq->izq = nuevoNodoAB(7);   // Left-left-left

    // Find the longest path
    //Lista caminoMLargo = caminoMasLargo(raiz);

    // Print the longest path
    //printf("Camino más largo: ");
    //imprimirLista(caminoMLargo);

}

// g++ 2.Ej2.cpp -o ej2