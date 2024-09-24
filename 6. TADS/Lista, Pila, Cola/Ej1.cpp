#include <stdio.h>

// Dé una implementación completa (tipo y operaciones) para el TAD Lista no ordenada que garantice
//que el tiempo de ejecución de las operaciones sea O(1)

typedef struct nodo {
    int elem;
    nodo * sig;
};

typedef nodo *LEnt;



/* Crea la lista vacía. */ 
LEnt crearL(){
    return NULL;
}

/* Verifica si la lista est á vac ía. */ 
bool esVacia(LEnt l){
    return l == NULL;
}


/* Inserta el entero x al principio de la lista . */ 
void insertar(int x , LEnt &l ){
    LEnt nuevo = new nodo;
    nuevo->elem=x;
    nuevo->sig=l;
    l=nuevo;
}


/* Devuelve el primer elemento de una lista . Pre : ! esVacia (l) */ 
int primero(LEnt l){
    return l -> elem;
}

/* Devuelve la lista l sin su primer elemento . Pre : ! esVacia (l) */ 
void resto (LEnt &l){
    LEnt aBorrar = l;
    l = l -> sig;
    delete aBorrar;
    aBorrar = NULL;
}
