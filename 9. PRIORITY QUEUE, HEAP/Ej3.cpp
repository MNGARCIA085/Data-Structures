#include <stdio.h>

//parte a)



typedef unsigned int uint;
typedef unsigned int T; // so it compiles



// Forma recursiva
void filtradoAscendenteRec(T* arreglo, int pos){
    if ((pos>1) && arreglo[pos/2] > arreglo[pos]){ // condicion para ver si hago el switcheo 
        T aux= arreglo[pos];
        arreglo[pos]=arreglo[pos/2];
        arreglo[pos/2]=aux;
        filtradoAscendenteRec(arreglo, pos/2);
    }
}

// Forma iterativa
// PRE: pos es válida (está entre 1 y n)
void filtradoAscendente(T* arreglo, int pos){
    while ( (pos > 1) && arreglo[pos/2] > arreglo[pos]){ // mientras no esté en el inicio y el padre sea mayor
        // swapeo
        T aux = arreglo[pos];
        arreglo[pos] = arreglo[pos/2];
        arreglo[pos/2] = aux;
        // actualizo la posición
        pos/=2;
    }
}

//parte b)

// Forma recursiva

void filtradoDescendenteRec(T* arreglo, int n, int pos){
    if (2*pos<=n){ //verifico que tenga hijos para comparar
        int pos_hijo=2*pos;
        if ((pos_hijo + 1 <= n) && (arreglo[pos_hijo]>arreglo[pos_hijo+1])) { // si el hijo der existe y a su vez es mas prioritario que el izq, entonces tengo que switchear con ese
            pos_hijo=pos_hijo+1;
        }
        if (arreglo[pos_hijo]<arreglo[pos]){
            T aux= arreglo[pos_hijo];
            arreglo[pos_hijo]=arreglo[pos];
            arreglo[pos]=aux;
            filtradoDescendenteRec(arreglo, n, pos_hijo);
        }
    }
}

// Forma iterativa
// PRE: pos es válida
void filtradoDescendente(T* arreglo, int n, int pos){
    while (2*pos <= n){ // verifico que tenga hijos para comparar
        int pos_hijo = 2*pos;
        if ((pos_hijo+1 <= n) && (arreglo[pos_hijo] > arreglo[pos_hijo+1])){ // si el hijo derecho existe y a su vez
                // es más prioritario que el izquierdo tengo que switchear con ese
                pos_hijo = pos_hijo+1;
        }
        if (arreglo[pos_hijo] < arreglo[pos]){
            // swap
            T aux = arreglo[pos_hijo];
            arreglo[pos_hijo] = arreglo[pos];
            arreglo[pos] = aux;
            // actualizo la posición
            pos = pos_hijo;
        }
    }
}



// Estructura de un heap
struct heap_t{
    int tope;
    T* arreglo;
}


// insertar
void insertar(heap_t heap, T dato){
    heap.tope++;
    heap.arreglo[heap.tope] = dato;
    filtradoAscendente(heap.arreglo, heap.tope);
}

// eliminar el mínimo (que es la raíz)
// cambia la raíz por el tope y aplico filtrado descendente
void eliminarMin(heap_t heap){
    if (heap.tope > 0){
        heap.arreglo[1] = heap.arreglo[heap.tope];
        heap.tope--;
        if (heap.tope > 0){
            filtradoDescendente(heap.arreglo, heap.tope, 1);
        }
    }
}


