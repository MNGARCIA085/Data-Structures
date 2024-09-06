#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

struct EstInfo {
    uint nota; // dato
    int ci;    // clave
};

struct nodoABB {
    EstInfo info;
    nodoABB *izq, *der;
};

typedef nodoABB *ABB;

// Insert function for testing
ABB insertar(ABB a, uint nota, int ci) {
    if (a == NULL) {
        ABB nuevo = (ABB)malloc(sizeof(nodoABB));  // Correct allocation with malloc
        nuevo->info.nota = nota;
        nuevo->info.ci = ci;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }
    if (nota < a->info.nota) {
        a->izq = insertar(a->izq, nota, ci);
    } else {
        a->der = insertar(a->der, nota, ci);
    }
    return a;
}

// Maximum of an ABB
ABB maxABB(ABB t) {
    if (t == NULL) return NULL; // Added NULL check

    while (t != NULL && t->der != NULL) {
        t = t->der;
    }
    return t;
}

// Remove the maximum node from the tree
void removerMaxABB(ABB &nodo) {
    if (nodo == NULL) return; // Added NULL check

    if (nodo->der == NULL) {
        ABB temp = nodo;
        nodo = nodo->izq;
        free(temp); // Properly free memory
        return;
    }

    nodoABB *padre_maximo = nodo;
    nodoABB *nodo_maximo = nodo->der;

    while (nodo_maximo->der != NULL) {
        padre_maximo = nodo_maximo;
        nodo_maximo = nodo_maximo->der;
    }

    padre_maximo->der = nodo_maximo->izq;
    delete nodo_maximo; // Properly free memory
}

// Print the tree (in-order)
void imprimirABB(ABB arbol) {
    if (arbol != NULL) {
        imprimirABB(arbol->izq);
        printf("Nota: %u, CI: %d\n", arbol->info.nota, arbol->info.ci);
        imprimirABB(arbol->der);
    }
}

// Free memory
void liberarMemoria(ABB raiz) {
    if (raiz == NULL) return;

    liberarMemoria(raiz->izq);
    liberarMemoria(raiz->der);
    delete raiz;
}

// Filter tree by a given threshold (cota)
ABB filtrado(uint cota, ABB a) {
    ABB result = NULL; // Initialize result to NULL
    if (a == NULL) {
        return result;
    } else {
        ABB fizq = filtrado(cota, a->izq);
        ABB fder = filtrado(cota, a->der);

        // Include nodes with nota >= cota
        if (a->info.nota >= cota) {
            // Allocate new node for result
            result = new nodoABB;
            result->info = a->info;
            result->izq = fizq;
            result->der = fder;
        } else {
            // Connect the subtrees even if the current node doesn't meet the criteria
            if (fizq == NULL) {
                result = fder;
            } else if (fder == NULL) {
                result = fizq;
            } else {
                ABB mayor = maxABB(fizq);
                result = new nodoABB;
                result -> info = mayor -> info;
                result -> izq = fizq;
                result -> der = fder;
                removerMaxABB(fizq);
            }
        }
    }
    return result;
}

// Main function to test the code
int main() {
    // Create the tree
    ABB arbol = NULL;
    arbol = insertar(arbol, 50, 1234);
    arbol = insertar(arbol, 30, 2345);
    arbol = insertar(arbol, 70, 3456);
    arbol = insertar(arbol, 20, 4567);
    arbol = insertar(arbol, 40, 5678);
    arbol = insertar(arbol, 60, 6789);
    arbol = insertar(arbol, 80, 7890);

    printf("Árbol original:\n");
    imprimirABB(arbol);

    // Filter the tree with a cota (threshold) of 45
    uint cota = 45;
    ABB arbol_filtrado = filtrado(cota, arbol);

    printf("\nÁrbol filtrado (notas >= %d):\n", cota);
    imprimirABB(arbol_filtrado);


    // Filter the tree with a cota (threshold) of 45
    uint cota2 = 15;
    ABB arbol_filtrado2 = filtrado(cota2, arbol);

    printf("\nÁrbol filtrado (notas >= %d):\n", cota2);
    imprimirABB(arbol_filtrado2);

    // Free memory
    liberarMemoria(arbol);
    liberarMemoria(arbol_filtrado);
    liberarMemoria(arbol_filtrado2);

    return 0;
}
