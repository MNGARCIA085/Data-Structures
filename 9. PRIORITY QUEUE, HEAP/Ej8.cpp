/*
Desarrolle implementaciones completas del TAD Cola de Prioridad, utilizando:
Árboles Parcialmente Ordenados implementados sobre un arreglo (Montículo o Heap) para la versión acotada del TAD.
*/

// estructura
struct tipo_h{
    T dato;
    int orden;
}

struct heap{
    int tope;
    int tamano_max; // es acotada
    tipo_h* arreglo; // arreglo de elementos del tipo del heap
}

typedef heap* ColaPrio;

// cola de prioridad de tamaño máximo M elementos
ColaPrio CrearCP(int M){
    ColaPrio nuevo = new heap;
    nuevo -> tope = 0;
    nuevo -> tamano_max = M;
    nuevo -> arreglo = new tipo_h[M+1]; // la primera pos. no la usamos
}

// si está llena
bool estaLlenaCP(ColaPrio cp){
    return cp->tamano_max==cp->tope; 
}

// si es vacía
bool esVaciaCP(ColaPrio cp){
    return cp->tope==0;
}

// filtrado ascendente
void filtradoAscendente(tipo_h* arreglo, int pos){
    while ( (pos>1) && arreglo[pos/2].orden > arreglo[pos].orden){
        // swap
        tipo_h aux = arreglo[pos];
        arreglo[pos] = arreglo[pos/2];
        arreglo[pos/2] = aux;
        pos/=2;
    }
}


// filtrado descendente
void filtradoDescendente(tipo_h* arreglo, int n, int pos){
    while (2*pos<=n){ // verifico tenga hijos
        int pos_hijo = 2*pos;
        if ( (pos_hijo+1 <= n) && (arreglo[pos_hijo].orden > arreglo[pos_hijo+1].orden)){
            pos_hijo = pos_hijo + 1;
        }
        if (arreglo[pos_hijo].orden < arreglo[pos].orden){
            // swap
            tipo_h aux = arreglo[pos_hijo];
            arreglo[pos_hijo] = arreglo[pos];
            arreglo[pos] = aux;
            // actualizo la pos.
            pos = pos_hijo;
        }
    }
}

// insertar
void insertarCP(ColaPrio &p, int p, T elemento){
    if (!estaLlenaCP(cp)){
        tipo_h nuevo;
        nuevo.dato = elemento;
        nuevo.orden = p;
        cp -> tope++;
        cp->arreglo[cp->tope] = nuevo;
        filtradoAscendente(cp->arreglo, cp->tope);
    }
}


//PRE: !esVaciaCP(cp)
T prioritarioCP(ColaPrio cp){ // es el primer elemento
    return cp->arreglo[1].elemento;
}


// eliminar el + prioritario
void eliminarPrioritario(ColaPrio &cp){
    if (!estaVacia(cp)){
        cp->arreglo[1] = cp -> arreglo[cp->tope];
        cp->tope--;
    }
    if (!estaVaciaCP(cp)){ //dada nuestra implementacion de filtradoDescendente no hay problema si estuviera vacia CP, por lo cual no seria necesario el if
        filtradoDescendente(cp->arreglo, cp->tope, 1);
    }

}


