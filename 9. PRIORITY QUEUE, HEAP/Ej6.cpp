#include <iostream>

#define M 100


typedef unsigned int uint;

// tipo de datos que tendrá el heap
struct tipo_h{
    uint dato;
    int orden;
}



// necesito saber las posiciones para cumplir con el requisito de orden



struct estructura_h{
    uint tope;
    tipo_h heap[M+1]; // arreglo con elementos de tipo tipo_h ordenado según "orden". La pos. 0 NO se utiliza
    uint posiciones[M]; // posición en el heap que está el dato, ej: en el índice 0 está la posición en el heap 
                //del dato 0
}


// filtrado ascendente
void filtradoAscendente(estructura_h &h, uint pos){
    while ((pos > 1) && h.heap[pos/2].orden > h.heap[pos].orden){ // en el arreglo hay 2 campos, me interesa el orden
        // swap
        T aux = h.heap[pos];
        h.heap[pos] = h.heap[pos/2];
        h.posiciones[h.heap[pos].dato] = pos/2;
        h.heap[pos/2] = aux;
        h.posiciones[h.heap[pos/2].dato] = pos;
        pos/=2;
    } 
}



// filtrado descendente
void filtradoDescendente(estructura_h &h, uint pos){
    while (2*pos<=h.tope){ //verifico que tenga hijos para comparar
        int pos_hijo=2*pos;
        if ((pos_hijo + 1 <= h.tope) && (h.heap[pos_hijo].orden>(h.heap[pos_hijo+1].orden)) { // si el hijo der existe y a su vez es mas prioritario que el izq, entonces tengo que switchear con ese
            pos_hijo=pos_hijo+1;
        }
        if (h.heap[pos_hijo].orden<(h.heap[pos].orden){
            T aux= h.heap[pos];
            h.heap[pos]=h.heap[pos_hijo];
            h.posiciones[h.heap[pos].dato]=pos_hijo
            h.heap[pos_hijo]=aux;
            h.posiciones[h.heap[pos_hijo].dato]=pos;
            pos=pos_hijo;
        }
    }
}



//Ver que no este lleno y checkear que el elemento no exista 
void insertar(estructura_h &h, tipo_h elem){
    if (h.tope < M && h.posiciones[elem.dato]==0){ // si la pos. es 0 (no se usa en el heap) -> no existe en el heap
        h.tope++;
        h.heap[h.tope]=elem;
        h.posiciones[elem.dato]=h.tope;
        filtradoAscendente(h, h.tope);
    }
}


// eliminar el mínimo
void eliminarMin(estructura_h &h){
    if (h.tope > 0){ // que haya elementos
        posiciones[h.heap[1].dato] = 0; // ponemos en 0 la pos. para que sepa que ya no pertenece al heap
        h.heap[1] = h.heap[h.tope];
        h.posiciones[h.heap[1].dato]=1;
        h.tope--;
        if (h.tope > 0){ // si no quedó vacío despueś de eliminar el mínimo
            filtradoDescendente(h, 1);
        }

    }
}


// iniciar
void iniciarEstructura(estructura_h &h){
    h.tope = 0;
    for (int i=0; i<M; i++){ // al principio ningún elemento pertenece al heap
        h.posiciones[i] = 0;
    }
}


// modificar orden
void modificarOrden(estructura_h &h, uint dato, int orden){
    uint pos = h.posiciones[dato];
    int orden_anterior = h.heap[pos].orden;
    h.heap[pos].orden = orden;
    if (orden_anterior < orden){
        filtradoDescendente(h, pos);
    } else if (orden_anterior > orden){
        filtradoAscendente(h, pos);
    }
}


