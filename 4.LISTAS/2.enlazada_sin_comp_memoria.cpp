#include <stdio.h>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo * lista;





// imprimir la lista
void imprimirLista(lista l) {
    lista temp = l;
    while (temp != NULL) {
        printf("%d ", temp->elem);
        //printf("%x ", temp->sig);
        temp = temp->sig;
    }
    printf("\n");
}


// crea una lista con ordenada con enteros del 1 al n (para n=10 da 1 2 3...10)
void crearLista(int n, lista &l) { // pasaje por referencia
    l = NULL;
    for (int i = n; i > 0; --i) {
        //nodo *nuevo = new nodo;
        lista nuevo = new nodo; // ídem a lo de arriba
        nuevo->elem = i;
        nuevo->sig = l;
        // que l apunte al nuevo
        l = nuevo;
    }
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


// devuelve los primeros i elementos de una lista no vacía
lista primeros(int i, lista l){
    
    // lista auxiliar q que va a guardar los primeros i elementos de l
    lista q = NULL;

    // puntero que se va moviendo en q para ir insertando
    lista actual = q;

    int aux = 0;
    while (aux < i && l != NULL) {
        // inserto al final
        lista nuevo = new nodo;
        nuevo -> elem = l -> elem;
        nuevo -> sig = NULL; // siempre va al final

        if (q == NULL) {
            q = nuevo;       // inicializa q en el primer elemento
            actual = q;      // actual también apunta al primer elemento
        } else {
            actual -> sig = nuevo; // agrega nuevo al final de q
            actual = actual -> sig; // actual avanza al último elemento
        }

        // me muevo en l
        l = l -> sig;
        aux++;
    }

    return q;
}



// devuelve la lista sin los primeros i elementos
lista sinprimeros(int i, lista l){
    
    for (int aux = 0; aux < i && l != NULL; aux++){
        l = l -> sig;
    }

    // ahora inserto cada elemento al final en una nueva lista q
    lista q = NULL;
    lista actual = NULL;

    while (l != NULL){
        // inserto al final
        lista nuevo = new nodo;
        nuevo -> elem = l -> elem;
        nuevo -> sig = NULL;

        if ( q == NULL){
            q = nuevo; // ahora la lista no apunt a NULL sino al primer elemento
            actual = nuevo;
        }
        else {
            actual -> sig = nuevo;
            actual = actual -> sig;
        }

        // me muevo en l
        l = l -> sig;

    }

    return q;

}



// intercala ordenadamente l y p
// voy 1 a 1 hasta llegar al final de una
// después meto todos los que quedan de la que no llegó al final
// se hace sin funciones auxiliares (sería mejor y más fácil con insFinal)
lista intercalado(lista &l1, lista &l2){
    
    lista r = NULL;
    lista temp = NULL;

    while ( l1 != NULL && l2 != NULL){
        // inserto el elemento de l1
        lista nuevo1 = new nodo;
        nuevo1 -> elem = l1 -> elem;
        nuevo1 -> sig = NULL;
        if (r == NULL){
            r = nuevo1;
            temp = nuevo1;
        }
        else {
            temp -> sig = nuevo1;
            temp = temp -> sig;
        }
        // inserto el elemento de l2
        lista nuevo2 = new nodo;
        nuevo2 -> elem = l2 -> elem;
        nuevo2 -> sig = NULL;
        if (r == NULL){ // esta primera parte es innecesaria pues ya se que l1 no es null
            r = nuevo2;
            temp = nuevo2;
        }
        else {
            temp -> sig = nuevo2;
            temp = temp -> sig;
        }
        // muevo los punteros
        l1 = l1 -> sig;
        l2 = l2 -> sig;
    }


    // si quedan elementos de l1
    while ( l1 != NULL){
        lista nuevo1 = new nodo;
        nuevo1 -> elem = l1 -> elem;
        nuevo1 -> sig = NULL;
        if (r == NULL){
            r = nuevo1;
            temp = nuevo1;
        }
        else {
            temp -> sig = nuevo1;
            temp = temp -> sig;
        }
        
        l1 = l1 -> sig;
    }

    // si quedan elementos en l2
    while ( l2 != NULL){
        lista nuevo2 = new nodo;
        nuevo2 -> elem = l2 -> elem;
        nuevo2 -> sig = NULL;
        if (r == NULL){
            r = nuevo2;
            temp = nuevo2;
        }
        else {
            temp -> sig = nuevo2;
            temp = temp -> sig;
        }
        l2 = l2 -> sig;
    }

    //
    return r;

}




// merge: intercalar pero según el orden
// comparo el elemento de l1 y l2, si el de l es <= inserto el de l1 y me muevo en l1
// sino inserto el de l2 y me muevo en l2
lista MergeSort(lista l, lista p) { // paso por valor; no comparto memoria con los params
    lista res = NULL;  // Lista resultante
    lista dummy = new nodo; // Nodo dummy para simplificar la construcción
    lista temp = dummy; // Nodo temporal para construir la lista resultante

    // Intercalado
    while (l != NULL && p != NULL) {
        // Se crea un nuevo nodo y se establece el puntero 'sig' del anterior a él
        temp -> sig = new nodo;
        temp = temp -> sig;

        if (l -> elem < p -> elem) {
            temp -> elem = l -> elem;
            l = l -> sig;
        } else {
            temp -> elem = p -> elem;
            p = p -> sig;
        }
    }

    // En este punto me pueden quedar elementos restantes en alguna de las dos listas

    // Si quedan en l
    while (l != NULL) {
        temp -> sig = new nodo;
        temp = temp -> sig;
        temp -> elem = l -> elem;
        l = l -> sig;
    }

    // Si quedan en p
    while (p != NULL) {
        temp -> sig = new nodo;
        temp = temp -> sig;
        temp -> elem = p -> elem;
        p = p -> sig;
    }

    // Para retornar apropiadamente; si no lo hago, me retorna el último elemento solamente
    temp -> sig = NULL; // El nodo ahora es el último de la lista
    lista result = dummy -> sig; // Hago que apunte al primer elemento de la lista
    delete dummy; // Elimina el nodo dummy

    // Return
    return result;
}


/**
 * En resumen, el nodo dummy simplifica la construcción de la lista al evitar la 
 * necesidad de manejar el caso especial del primer nodo de la lista. 
 * Sin él, necesitas implementar lógica adicional para asegurar que el primer nodo 
 * se maneje correctamente y que los nodos se conecten de manera adecuada.
 */




// versión recursiva de merge sort
// Función recursiva para fusionar dos listas ordenadas
lista mergeRecursive(lista l1, lista l2) {
    if (l1 == NULL) return l2; // Si l1 está vacía, retorna l2
    if (l2 == NULL) return l1; // Si l2 está vacía, retorna l1

    // Crear un nuevo nodo para la lista resultante
    lista result = NULL;

    // Comparar los elementos en la cabeza de l1 y l2
    if (l1->elem < l2->elem) {
        result = l1; // El primer nodo de l1 es el menor
        result->sig = mergeRecursive(l1->sig, l2); // Recursión con el resto de l1 y todo l2
    } else {
        result = l2; // El primer nodo de l2 es el menor
        result->sig = mergeRecursive(l1, l2->sig); // Recursión con el resto de l2 y todo l1
    }

    return result;
}






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
    lista l = NULL;
    crearLista(8, l);


    printf("Prueba de obtener primeros:\n");
    imprimirLista(l);
    lista prim = primeros(3, l);
    imprimirLista(prim);

    printf("\nPrueba de obtener los últimos:\n");
    imprimirLista(l);
    lista sin = sinprimeros(4, l);
    imprimirLista(sin);



    printf("\nPrueba de concatenar:\n");
    lista l2 = NULL;
    crearLista(3, l2);
    lista inter = intercalado(l, l2);
    imprimirLista(inter);



    printf("\nPrueba de merge:\n");
    lista l3 = NULL;
    insUltimo(14, l3);
    insUltimo(17,l3);
    lista l4 = NULL;
    insUltimo(2, l4);
    insUltimo(117,l4);
    insUltimo(223,l4);
    imprimirLista(l3);
    imprimirLista(l4);
    lista mer = MergeSort(l4, l3);
    imprimirLista(mer);


    printf("\nPrueba de merge recursivo:\n");
    lista mer_recursive = mergeRecursive(l4, l3);
    imprimirLista(mer_recursive);



    liberarLista(l);
    liberarLista(l2);
    liberarLista(inter);
    liberarLista(l3);
    liberarLista(l4);
    liberarLista(mer);
    liberarLista(mer_recursive);


}


// g++ 2.enlazada_sin_comp_memoria.cpp -o ej2
