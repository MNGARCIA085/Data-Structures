/* Considere un TAD Cola de Prioridad (CP) no acotada de elementos de un tipo genérico T donde las
prioridades están dadas por números naturales. Se admiten prioridades y elementos repetidos.*/

struct representacionCP;
typedef representacionCP * CP;

// Devuelve la cola de prioridad vacía
CP crear();

// Agrega x con prioridad p a cp
void agregar(T x, unsigned int p, CP & cp);


// Retorna true si y solo si cp es vacía
bool esVacia (CP cp);


/* Retorna el elemento con mayor prioridad (valor más
grade) ingresado en cp. Ante igual prioridad retorna el
primero en ingresar */
// Precondición: !esVacia(cp)
T prioritario(CP cp);

// Agrega x con prioridad p a cp
/* Remueve el elemento con mayor prioridad (valor más
grande) ingresado en cp. Ante igual prioridad elimina el
primero en ingresar */
// Precondición: !esVacia(cp)
void eliminar(CP & cp);


/*Defina una representación para el TAD CP (representacionCP) de tal manera que las operaciones crear,
agregar, esVacia y prioritario tengan O(1) de tiempo de ejecución en el peor caso.*/

/*

La representación es una lista simplemente encadenada con un puntero al inicio y un 
puntero al prioritario.

Insertando siempre al inicio es que agregar verifica ser O(1). (también actualizo el prioritario si amerita)

*/

typedef unsigned int nat;

struct nodoLista{
    T dato;
    nat prioridad;
    nodoLista* sig;
}

struct representacionCP{
    nodoLista* inicio;
    nodoLista* prioritario;
}

typedef cabezal* CP;



// Devuelve la cola de prioridad vacía
CP crear(){
    CP nueva = new representacionCP;
    nueva -> inicio = NULL;
    nueva -> prioriitario = NULL;
    return nueva;
}


// agregar
// Agrega x con prioridad p a cp
void agregar(T x, unsigned int p, CP & cp){
    // inserto al inicio de la lista y actualizo el prioritario si amerita
    nodoLista* nodo = new nodoLista;
    nodo -> dato = x;
    nodo prioridad = p;
    // inserto al inicio
    nodo -> sig = cp -> inicio;
    cp -> inicio = nodo;
    // actualizo el prioritario
    if (cp->prioritario == NULL || p > cp->prioritario->prioridad){
        cp -> prioritario = nodo;
    }
}


/*
Sin considerar la anterior, defina ahora una representación para el TAD CP (representacionCP) de tal
manera que las operaciones crear, esVacia, prioritario y eliminar tengan O(1) de tiempo de ejecución en
el peor caso.*/


/*

Una lista simplemente encadenada (de nodos de tipo nodoLista, de la Parte a) ordenada por prioridad (de
mayor a menor) permitiría tener al elemento prioritario al inicio. Las inserciones serían ordenadas y en
caso de prioridades repetidas, al agregar un elemento debería ir al final de los que tienen la misma
prioridad. De esta manera, obtener el elemento prioritario y eliminarlo es O(1) peor caso, al igual que
crear la lista vacía y chequear si está vacía. Esto es crear, esVacia, prioritario y eliminar tendrían O(1) de
tiempo de ejecución en el peor caso.

-> el que pasa a ser O(n) es agregar.


*/