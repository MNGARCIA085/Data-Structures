#include <stdio.h>

struct nodoAG {
    int dato;
    struct nodoAG * pH;  // Pointer to the first child
    struct nodoAG * sH;  // Pointer to the next sibling
};

typedef struct nodoAG * AG;

/*
amplitud: cantidad de hijos directos
*/

/* amplitud de un determinado nivel del árbol */
int amplitud(int n, AG t){
    if (t == NULL){
        return 0;
    }

    if (n == 0){ // estoy en el nivel que quiero
        AG hijo = t -> pH;
        int contador = 0;
        while (hijo != NULL){
            contador++;
            hijo = hijo -> sH;
        }
        return contador;
    } else {
        return amplitud(n - 1, t->pH);
    }
}

/* Implemente una función que retorne la amplitud del nodo del árbol de mayor amplitud. La amplitud de un
nodo se define como la cantidad de hijos (directos) que tiene. Si el árbol es vacío o la raíz no tiene hijos, la
función debe retornar 0.*/

// Función auxiliar para calcular la amplitud de un nodo
int calcularAmplitud(AG nodo) {
    int amplitud = 0;
    AG hijo = nodo->pH;
    while (hijo != NULL) {  // Use NULL in C instead of nullptr
        amplitud++;
        hijo = hijo->sH;
    }
    return amplitud;
}


int amplitudMaxima(AG t) {
    if (t == NULL){
        return 0;
    }

    int amplitudMax = calcularAmplitud(t);

    // Verificamos los nodos hijos (recursivamente)
    AG hijo = t->pH;
    while (hijo != NULL) {
        int amplitudHijo = amplitudMaxima(hijo);
        if (amplitudHijo > amplitudMax) {
            amplitudMax = amplitudHijo;
        }
        hijo = hijo->sH;
    }

    return amplitudMax;  // Return the calculated maximum amplitude
}


// Helper function to create a new node
AG nuevoNodo(int dato) {
    AG nuevo = new nodoAG;
    nuevo->dato = dato;
    nuevo->pH = NULL;
    nuevo->sH = NULL;
    return nuevo;
}

// liberar memoria
void liberarMemoria(AG &t){
    if (t==NULL){
        return;
    }
    liberarMemoria(t -> pH);
    liberarMemoria(t -> sH);

    delete t;
    t = NULL;
}


int main() {
    // Creating the root node
    AG root = nuevoNodo(1);

    // Adding children to root
    root->pH = nuevoNodo(2);
    root->pH->sH = nuevoNodo(3);
    root->pH->sH->sH = nuevoNodo(4);

    // Adding children to node 2
    root->pH->pH = nuevoNodo(5);
    root->pH->pH->sH = nuevoNodo(6);

    // Adding children to node 4
    root->pH->sH->sH->pH = nuevoNodo(7);

    // Display the maximum amplitude
    printf("Amplitud máxima del árbol: %d\n", amplitudMaxima(root));

    // free memory
    liberarMemoria(root);

}

// g++ ej8.cpp -o ej8