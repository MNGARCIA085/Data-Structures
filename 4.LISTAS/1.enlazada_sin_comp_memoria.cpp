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
float promedio(lista &l){
    lista temp = l;
    int suma = 0;
    int total = 0; // total de elementos en la lista
    while (temp != NULL){
        suma += temp -> elem;
        total++;
        temp = temp -> sig;
    }
    return suma/total;
}


// insertar al final
void insUltimo(int x, lista &l) {
    lista nuevo = new nodo;
    nuevo -> elem = x;
    nuevo -> sig = NULL;

    // If the list is empty, make the new node the head of the list
    if (l == NULL) {
        l = nuevo;
    } else {
        lista temp = l;
        while (temp -> sig != NULL) {
            temp = temp -> sig;
        }
        temp -> sig = nuevo;
    }
}




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


// remover todas las apariciones de un elemento en una lista (si es que las hay)
void removerTodas(int x, lista &l) {
    // Si la lista es vacía, salgo
    if (l == NULL) {
        return;
    }

    // Borro todas las apariciones al inicio
    while (l != NULL && l->elem == x) {
        lista aBorrar = l;
        l = l->sig;
        delete aBorrar;
    }
    // cuando salgo o bien quedo en NULL (termina la lista)
    // o en un valor que es diferente a x

    // Borro el resto de las apariciones
    lista actual = l;
    while (actual != NULL && actual->sig != NULL) {
        if (actual->sig->elem == x) {
            lista aBorrar = actual->sig;
            actual->sig = actual->sig->sig;
            delete aBorrar;
        } else {
            actual = actual->sig;
        }
    }
}



// es sub-lista
bool esSubLista(lista &l1, lista &l2){
    // punteros auxiliares para que no salgan apuntando a cualquier lado después
    lista temp1 = l1;
    lista temp2 = l2;

    lista temp1_aux = NULL;

    while ( temp1 != NULL){
        temp1_aux = temp1;
        while ( (temp2 != NULL) && (temp1_aux -> elem == temp2 -> elem) ){
            temp1_aux = temp1_aux -> sig;
            temp2 = temp2 -> sig;
        }
        // si llego al final de temp2 es sub-lista
        if (temp2 == NULL){
            return true;
        }
        else {
            // me muevo en l1 y reseteo el puntero a l2 de vuelta al inicio
            temp1 = temp1 -> sig;
            temp2 = l2;
        }
    }
    // si salió por temp1 no se encuentra
    return false;
}




// imprimir lista
void imprimirLista(lista l){
    //  defino un nuevo puntero
    lista temp = l;
    while ( temp !=  NULL){
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
    insOrd(e4, l);



    printf("\nPrueba de remover todas:\n");
    removerTodas(6, l);
    imprimirLista(l);


    printf("\nPrueba de es sub-lista:\n");
    lista l2 = NULL;
    insOrd(7, l2);
    insOrd(9, l2);
    bool aux = esSubLista(l, l2);
    if (aux) {
        printf("El booleano es verdadero.\n");
    } else {
        printf("El booleano es falso.\n");
    }


    
    printf("\nPrueba de insertar último (puede desordenar la lista):\n");
    imprimirLista(l);
    insUltimo(2, l);
    imprimirLista(l);
    

    printf("\nPrueba de último:\n");
    imprimirLista(l);
    int ult = ultimo(l);
    printf("El último es: %d\n", ult);


    printf("\nPrueba de promedio:\n");
    imprimirLista(l);
    float prom = promedio(l);
    printf("El promedio es: %f\n", prom);




    liberarLista(l);

}

// g++ 1.enlazada_sin_comp_memoria.cpp -o ej1