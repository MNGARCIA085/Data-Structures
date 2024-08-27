#include <stdio.h>

typedef unsigned int uint ;

struct nodoAB {
    uint elem ;
    nodoAB * izq , * der;
};
typedef nodoAB * AB;


// el árbol es el puntero a la raíz
AB vacio(){
    return NULL;
}

// Función para crear un nuevo nodo
AB crearNodo(uint valor) {
    AB nuevo = new nodoAB;
    nuevo->elem = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}


// construir un árbol a partir de otros dos
AB consArbol(uint elem, AB izq, AB der){
    AB res = new nodoAB;
    res -> elem = elem;
    res -> izq = izq;
    res -> der = der;
    return res;
}


// Function to add a left child to a node
void agregarIzq(AB padre, unsigned int elem) {
    if (padre->izq == NULL) {
        padre->izq = crearNodo(elem);
    } else {
        printf("El nodo izquierdo ya existe.\n");
    }
}

// Function to add a right child to a node
void agregarDer(AB padre, unsigned int elem) {
    if (padre->der == NULL) {
        padre->der = crearNodo(elem);
    } else {
        printf("El nodo derecho ya existe.\n");
    }
}



// Contar elementos
/*
    Arbol vacío -> 0 elementos
    no vacío: 1 + cant(izq) + cant(der)
*/
int contarElementos(AB t){
    if (t == NULL){
        return 0;
    }
    else {
        return 1 + contarElementos(t->izq) + contarElementos(t->der);
    }
}



// Contar hojas
/**
 * Arbol vacío: 0 hojas
 * No vacío: si t->iq y t-> der son vacíos sumo 1
 */
int contarHojas(AB t) {
    if (t == NULL) {
        return 0;
    }
    if (t->izq == NULL && t->der == NULL) {
        return 1;
    }
    return contarHojas(t->izq) + contarHojas(t->der);
}

// altura
/*
    Arbol vacío: tiene altura 0
    No vacío: 1 + max(alt(izq), max(alt(der)))
*/
int altura(AB t) {
    if (t == NULL) {
        return 0;
    }
    int altut1q = altura(t->izq);
    int alturaDer = altura(t->der);

    if (alturaDer > altut1q) {
        return 1 + alturaDer;
    } else {
        return 1 + altut1q;
    }
}

// copia de un árbol
AB copia (AB t){
    if (t == NULL){
        return NULL;
    }
    AB nuevo = new nodoAB;
    nuevo -> elem = t-> elem;
    nuevo -> izq = copia(t-> izq);
    nuevo -> der = copia(t -> der);
    return nuevo;
}


// liberar memoria
void liberarArbol(AB t) {
    if (t != NULL) {
        liberarArbol(t->izq); // Free the left subtree
        liberarArbol(t->der); // Free the right subtree
        delete t;             // Free the current node
    }
}


// Función para imprimir el árbol en recorrido en-orden (in-order)
void enOrden(AB t1) {
    if (t1 != nullptr) {
        enOrden(t1->izq);
        printf("%d ", t1->elem);
        //std::cout << t1->elem << " ";
        enOrden(t1->der);
    }
}



// main para testing
int main(){

    AB t1 = crearNodo(1);

    // Adding nodes
    agregarIzq(t1, 2);
    agregarDer(t1, 3);
    agregarIzq(t1->izq, 4);
    agregarDer(t1->izq, 5);
    agregarIzq(t1->der, 6);
    agregarDer(t1->der, 7);

    // Printing the tree in pre-order
    printf("Árbol en pre-orden: ");
    enOrden(t1);
    printf("\n");


    // nuevo árbol
    AB t2 = crearNodo(11);
    // Adding nodes
    agregarIzq(t2, 12);
    agregarDer(t2, 13);
    agregarIzq(t2->izq, 14);
    agregarDer(t2->izq, 15);
    agregarIzq(t2->der, 16);
    agregarDer(t2->der, 17);
    // Printing the tree in pre-order
    printf("Árbol en pre-orden: ");
    enOrden(t2);
    printf("\n");


    // Prueba de construir árbol
    printf("\nPrueba de construir árbol\n");
    AB t3 = consArbol(30, t1, t2);
    enOrden(t3);

    // Prueba de contar elementos
    printf("\nPrueba de contar elementos\n");
    int cantElem = contarElementos(t1);
    printf("Cantidad de elementos: %d", cantElem);

    // Prueba de contar hojas
    printf("\nPrueba de contar hojas\n");
    int cantHojas = contarHojas(t1);
    printf("Cantidad de hojas: %d", cantHojas);


    // Prueba de altura
    printf("\nPrueba de altura\n");
    int alt = altura(t1);
    printf("Altura: %d", alt);

    
    // Prueba de copia
    printf("\nPrueba de copia\n");
    AB t4 = copia(t1);
    enOrden(t1);
    printf("\n");
    enOrden(t4);

    // liberar memoria
    liberarArbol(t1);
    liberarArbol(t2);
    liberarArbol(t4);
    // t3 da error pues ya borré t1 y t2 y se construía a partir de ellos
    

    


}


// g++ 1.Ej1.cpp -o ej1


