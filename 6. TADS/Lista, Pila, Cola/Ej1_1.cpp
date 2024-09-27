#include <stdio.h>

//b) ¿Qué cambios realizaría si insFinal fuera parte del TAD?
//se agrega un cabezal

struct nodo{
    int elem ;
    nodo * sig;
};

struct cabezal{
    nodo * ini , * fin;
};
typedef cabezal * LEnt;



/* Crea la lista vacía. */
LEnt crearL(){
    LEnt nuevo = new cabezal; //cabezal * nueva = new cabezal;
    nuevo -> ini = NULL;
    nuevo -> fin = NULL;
    return nuevo;
}

/* Verifica si la lista est á vac ía. */
bool esVacia ( LEnt l){
    return l -> ini == NULL;
}


/* Inserta el entero x al principio de la lista . */
void insertar (int x , LEnt &l){
    nodo* nuevo = new nodo;
    nuevo -> elem = x;
    if (esVacia(l)){
        nuevo -> sig = NULL; // aquí en realidad es lo mismo que l->ini  y lo puedo sacar afuera
        l -> ini = l -> fin = nuevo; 
    }
    else {
        nuevo -> sig = l -> ini;
        l -> ini = nuevo;
    }

}


void insFinal(int x, LEnt &l) {
    nodo* nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;

    if (l->fin != NULL) {  // If the list is not empty
        l->fin->sig = nuevo;
        l->fin = nuevo;  // Update the tail of the list
    } else {  // If the list is empty
        l->ini = l->fin = nuevo;
    }
}






/* Devuelve el primer elemento de una lista .
Pre : ! esVacia (l) */
int primero (LEnt l){
    return l -> ini -> elem;
}



/* Devuelve la lista l sin su primer elemento .
Pre : ! esVacia (l) */
void resto(LEnt &l) {
    nodo* aBorrar = l->ini;
    
    if (l->ini == l->fin) {  // If there was only one element
        l->ini = l->fin = NULL;
    } else {
        l->ini = l->ini->sig;  // Move the head to the next element
    }

    delete aBorrar;  // Free the memory of the removed node
    aBorrar = NULL;  // Not strictly necessary, but good practice
}



