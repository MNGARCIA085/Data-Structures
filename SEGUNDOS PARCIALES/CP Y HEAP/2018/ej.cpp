/*Especifique el TAD Cola de Prioridad no acotada de enteros. Además de las operaciones estándar
debe incluir una operación que devuelve la cantidad de elementos de la cola. La prioridad de cada
elemento está determinada por su valor y el elemento prioritario es el que tiene menor valor. Debe
incluir precondiciones y poscondiciones.*/


// Crea una cola de priridad no acotada de enteros, vacía
ColaPrio crearColaPrio();

// Encola un entero en la cola de prioridad
void encolar(ColaPrio & cp, int valor);

// Devuelve el elemento prioritario
// PRE: cantElems(cp) > 0
int min(ColaPrio cp);

// Desencola el elemento prioritario
// PRE: cantElems(cp) > 0
void desencolar(ColaPrio & cp);

// Devuelve la cantidad de elementos
int cantElems(ColaPrio cp);

// Destruye la memoria asociada a la cola, pero no la asociada a sus elementos
void destruirColaPrio(ColaPrio &cp);



/*La presencia de la operación que devuelve la cantidad de elementos hace opcional la operación
que indica si la cola de prioridad está vacía*/


/*Implemente el TAD anterior, de tal manera que todas las operaciones, excepto la operación para elimi-
nar, tengan tiempo de ejecución O(1) en el peor caso.*/

/*

La implementaré con una lista enlazada; es NO acotada, insertando al inicio cumplo

*/

struct nodo{
    int elem;
    nodo* sig;
}

struct repCola{
    int cant; // cant en O(1)
    int min; // min en O(1)
    nodo *primero;
}

typedef repCola* ColaPrio;



// Crea una cola de priridad no acotada de enteros, vacía
ColaPrio crearColaPrio(){
    ColaPrio nueva = new ColaPrio;
    nueva -> cant = 0;
    nueva -> primero = NULL;
    return nueva;
}



// Encola un entero en la cola de prioridad
void encolar(ColaPrio & cp, int valor){
    // creo el nuevo nodo
    nodo* nuevo = new nodo;
    nodo -> elem = valor;
    // inserto al inicio
    nodo->sig= cp->primero;
    cp->primero = nodo;
    // actualizo el resto de las variables
    cp-> cant++;
    if (cp-> cant == 0 || cp->min > valor){
        cp->min = valor;
    }
}



// Devuelve el elemento prioritario
// PRE: cantElems(cp) > 0
int min(ColaPrio cp){
    return cp->min;
}


// Desencola el elemento prioritario
// PRE: cantElems(cp) > 0
void desencolar(ColaPrio & cp){
    // con esta estructura, primero tengo que encontralo, 
    // pero puedo hacerlo porque llevo el mínimo en la estrcutura
    // casos: es el primero; no es el primero
    if (cp->primero->elem == cp->min){
        nodo* aBorrar = cp->primero;
        cp->primero = cp->primero->sig; // puede ser NULL (queda vacía)
        delete aBorrar;
        aBorrar = NULL;
    }
    else {
        nodo* temp = cp->primero;
        while (temp -> sig -> elem != cp->min){ // no hace falta chequear el null porque sé que el mínimo está
            temp = temp -> sig;
        } 
        nodo* aBorrar  = temp->sig;
        temp = temp -> sig -> sig; // puede ser NULL
        delete aBorrar;
        aBorrar = NULL;
    }

    // actualizo la cantidad
    cp -> cantidad--;

    // actualizo el mínimo
    if (cp -> cant > 0){
        cp -> min = cp->primero->elem;
        nodo* aux = cp->primero->sig;
        while (aux != NULL){
            if (aux->elem < min){
                cp->min = aux -> elem;
            }
            aux = aux -> sig;
        }
    }
}




// Devuelve la cantidad de elementos
int cantElems(ColaPrio cp){
    return cp->cantidad;
}



// Destruye la memoria asociada a la cola, pero no la asociada a sus elementos
void destruirColaPrio(ColaPrio &cp){
    nodo* aux = cp -> primero;
    while (aux != NULL){
        nodo* temp = aux;
        aux = aux -> sig;
        delete temp;
        temp = NULL;
    }
    delete cp;
}


