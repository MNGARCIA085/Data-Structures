/* Considere el TAD Cola de Prioridad acotada de enteros, con operaciones crear, esVacia, insertar, prioritario,
eliminarPrioritario y estaLlena. La prioridad de cada elemento está dada por su valor y el elemento prioritario
es el entero de menor valor. Puede haber elementos (prioridades) repetidos.*/

/* Considere la siguiente implementación de heap, donde max es la cantidad máxima de elementos que
puede almacenar, los elementos se almacenan en las posiciones 1..tope y tope ≤ max: */

struct rep_heap{
    int max;
    int tope;
    int* elems;
};

typedef struct rep_heap* heap;


/ * Implemente la función filtradoAscendente de heap */

// filtra de forma ascendente el elemento en la posición i del heap
// Pre: 1 <=i <= h->tope
void filtradoAscendente(int i, heap &h){
    // tengo que subirlo hasta que el de arriba tenga mayor prioridad (menor valor)
    // o haya llegado a la cima (posición 1)

    while (i > 1 && h->elems[i] < h->elems[i/2]){
        // swap
        int aux = h->elems[i/2];
        h->elems[i/2] = h->elems[i];
        h->elems[i] = aux;
        // actualizo i
        i = i/2;
    }
}



/*Dada la siguiente representación de Cola Prioridad mediante heap, implemente la operación insertar */

typedef heap ColaPrioridad;

// Inserta el elemento p en la cola de prioridad
// pre: cp no está llena
void insertar(int p, colaPrioridad &cp){
    // lo pongo al final
    cp -> tope++;
    cp -> array[tope] = p;
    // aplico el filtrado ascendente
    filtradoAscendente(cp->tope, cp);
} 

