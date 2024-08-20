#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int elem;
    nodo * sig;
};
typedef nodo * lista;



// ultimo (pre-cond: lista no vacía)
int ultimo(lista &l){
    lista temp = l; // para no modificr el puntero original, que es la lista
    while (temp -> sig != NULL){
        temp = temp -> sig;
    };
    return temp -> elem;
}

// promedio de una lista no vacía








// insOrd
void insOrd(int e, lista &l) {
    // Creo el nuevo nodo a insertar
    lista nuevo = new nodo;
    nuevo->elem = e;
    nuevo->sig = NULL; // Inicialización

    // Si la lista es null, simplemente inserto
    if (l == NULL) {
        l = nuevo;
    } else {
        // Inserción al inicio
        if (l->elem > e) {
            nuevo->sig = l;
            l = nuevo;
        } else {
            // Inserción en el medio o al final
            lista lactual = l;
            while (lactual->sig != NULL && lactual->sig->elem < e) {
                lactual = lactual->sig;
            }
            // Insertar el nuevo nodo en la posición correcta
            nuevo->sig = lactual->sig;
            lactual->sig = nuevo;
        }
    }
}




// versión recursiva de insertar
void insOrdRec(int e, lista &l) {
    // Caso base: lista vacía o insertar al inicio
    if (l == NULL || l->elem > e) {
        // Crear nuevo nodo
        lista nuevo = new nodo;
        nuevo->elem = e;
        nuevo->sig = l;  // Inserta al inicio o en la posición correcta
        l = nuevo;
    } else {
        // Recursión para encontrar la posición correcta
        insOrdRec(e, l->sig);
    }
}





// imprimir lista
void imprimirLista(lista l){
    //  defino un nuevo puntero
    lista temp = l;
    while ( temp -> sig !=  NULL){
        printf("%d ", temp -> elem);
        temp = temp -> sig;
    };
    printf("\n");
}


// liberar memoria
// hay que recorrer la lista y liberar cada nodo individualmente
void liberarLista(lista &l) {
    while (l != NULL) {
        lista temp = l;  // Guardar el puntero al nodo actual
        l = l->sig;      // Avanzar al siguiente nodo
        delete temp;     // Liberar la memoria del nodo actual
    }
    l = NULL;  // Asegurar que el puntero a la lista quede en NULL
}




int main(){
    
    // prueba de insertar
    lista l = NULL;
    int e1 = 7;
    int e2 = 9;
    int e3 = 4;
    int e4 = 6;

    printf("Prueba de insertar ordenado:\n");
    insOrd(e1, l);
    imprimirLista(l);
    insOrd(e2, l);
    imprimirLista(l);
    insOrd(e3, l);
    imprimirLista(l);
    insOrd(e4, l);
    insOrdRec(12, l);
    imprimirLista(l);

    liberarLista(l);

}

// g++ 1.enlazada_sin_comp_memoria.cpp -o ej1