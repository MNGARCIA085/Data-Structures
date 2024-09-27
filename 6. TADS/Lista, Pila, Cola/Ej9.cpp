#include <stdio.h>
#include "cola.h" // Import the queue
#include "nodoABB.h" // Import your ABB node structure



/*
Si a no es vacío, encolar a en una cola c inicialmente vacía de árboles binarios. 
Mientras la cola c no sea vacía: 
    Obtener el primer (en orden fifo) árbol de c; 
    Imprimir el dato de su raíz; 
    Para sus subárboles izquierdo y derecho, si no son vacíos entonces encolarlos en c.
    o Desencolar de c.
*/




void imprimirNiveles(ABB t){
    if (t!=NULL){
        Cola c = crearCola();
        encolar(c,t);
        
        while(!esVaciaCola(c)){
            t=frente(c);
            printf("% d", t->elem);
            
            
            if (t->izq!=NULL){
                encolar(c,t->izq);
            }
            if (t->der!=NULL){
                encolar(c,t->der);
            }

            desencolar(c);
            
        }
        liberar(c);
    }
}



// imprimir por niveles con el nivel al lado y un salto de línea por nivel
void imprimirporNivelesII(ABB t) {
    if (t != NULL) {
        Cola c = crearCola();
        int nivelcont = 1;
        encolar(c, t);
        encolar(c, NULL); // Marker for level end
        printf("%d - ", nivelcont);
        
        while (!esVaciaCola(c)) {
            t = frente(c);
            desencolar(c);
            if (t == NULL && !esVaciaCola(c)) { // End of current level
                encolar(c, NULL);  // Insert new level marker
                nivelcont++;
                printf("\n%d - ", nivelcont);
            } else if (t != NULL) { // Print node and enqueue children
                printf("%d ", t->elem);
                if (t->izq != NULL) {
                    encolar(c, t->izq);
                }
                if (t->der != NULL) {
                    encolar(c, t->der);
                }
            }
        }
        liberar(c);
    }
}


// Helper function to create a new node in the ABB
ABB crearNodo(uint valor) {
    ABB nuevo = new nodoABB;
    nuevo->elem = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Main function to test imprimirNiveles and imprimirporNivelesII
int main() {
    // Create a simple binary tree
    ABB raiz = crearNodo(1);
    raiz->izq = crearNodo(2);
    raiz->der = crearNodo(3);
    raiz->izq->izq = crearNodo(4);
    raiz->izq->der = crearNodo(5);
    raiz->der->izq = crearNodo(6);
    raiz->der->der = crearNodo(7);

    // Test imprimirNiveles (prints tree level by level)
    printf("Imprimir niveles (sin niveles marcados):\n");
    imprimirNiveles(raiz);
    printf("\n\n");

    // Test imprimirporNivelesII (prints tree level by level with levels marked)
    printf("Imprimir niveles (con niveles marcados):\n");
    imprimirporNivelesII(raiz);
    printf("\n");

    // Free the allocated memory (not implemented, but should be done properly)
    // You would need to implement a function to recursively free the binary tree.
    
    return 0;
}


// g++ Ej9.cpp cola.cpp -o ej9