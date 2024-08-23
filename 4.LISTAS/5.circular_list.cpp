#include <stdio.h>

struct nodo {
    int elem;
    nodo * sig;
};
typedef nodo * lista;



// devuelve una lista vacía
lista empty(){
    return NULL;
}


//
bool isEmpty(lista l){
   return  l == NULL;
}

// crear un nodo
lista createNode(int data){
    lista nuevo  = new nodo;
    nuevo -> elem = data;
    nuevo -> sig = NULL;
    return nuevo;
}


// devuelve una lista que es copia de la otra sin su primer elemento
lista resto(lista l) {
    if (isEmpty(l)) {
        return NULL; // Return NULL if the list is empty
    }

    // If the list has only one element, return NULL because there's no "rest"
    if (l->sig == l) {
        return NULL;
    }

    // Create a new list to store the elements after the first
    lista nuevo = NULL;
    lista last = NULL;

    // Start from the second element
    lista temp = l->sig;
    
    do {
        lista nuevoNodo = createNode(temp->elem);
        if (nuevo == NULL) {
            nuevo = nuevoNodo;  // Set the new list head
            last = nuevo;
        } else {
            last->sig = nuevoNodo; // Append to the new list
            last = nuevoNodo;
        }
        temp = temp->sig;
    } while (temp != l); // Stop when we loop back to the original head

    // Close the new list into a circular list
    last->sig = nuevo;

    return nuevo;
}





// devuelve el último elemento de una lista no vacía
int last(lista l){
    while (l->sig != l){
        l = l -> sig;
    }
    return l -> elem;
}




// INSERTS

// insert in an empty list
void insertInEmptyList(int data, lista &l) {
    if (l != NULL) return;
    // Create a new node
    lista nuevo = createNode(data);
    // Make the new node circular
    nuevo->sig = nuevo;
    // Update last to point to the new node
    l = nuevo; // que el último apunte a sí mismo
}


// insert at the beggining
/*
Creamos el nodo.
Si la lista es vacía (el último puntero es NULL) hacemos que el nodo apunte a sí mismo.
Si no es vacía:
    - El puntero "sig" del nuevo nodo debe apuntar al head actual (que es last->next).
    - Se debe actualizar el puntero sig del último nodo para que apunte al nuevo.
*/
void insertAtBeginning(int data, lista &l){
    // creamos el nodo
    lista nuevo = createNode(data);

    // si es vacía
    if (isEmpty(l)){
        nuevo->sig = nuevo; // Point to itself, circular reference
        l = nuevo;
    } else { // <-- Add this else clause

        // no es vacío
        // encuentro el último elemetno de la lista
        lista temp = l;
        while (temp->sig != l) {
            temp = temp->sig;
        }

        // actualizo los punteros   
        nuevo -> sig = l;
        temp -> sig = nuevo;
        l = nuevo; // la lista comienza ahora en el nuevo
    }

}


// insert at the end

/*
Creamos el nuevo nodo.
Si la lista es vacía (el último puntero es NULL) hacemos que el nodo apunte a sí mismo.
Si la lista no es vacía:
 - Establecemos el puntero sig del nuevo nodo al head actual (que es tail->next).
 - Actualizamos el puntero del tail actual para que apunte al nuevo nodo.
*/
void insertAtEnd(int data, lista &l){
    lista nuevo = createNode(data);

    // si es vacía
    if (isEmpty(l)){
        l = nuevo;
        l->sig = l; // Point to itself, circular reference
    } else {

        // no es vacío
        // encuentro el último elemetno de la lista
        lista temp = l;
        while (temp->sig != l) {
            temp = temp->sig;
        }

        // actualizo los punteros   
        temp -> sig = nuevo;
        nuevo -> sig = l;
    }
}


/* insOrd */
void insOrd(int data, lista &l){
    if (isEmpty(l)){
        insertInEmptyList(data, l);
    }
    else{
        lista temp = l;
        if (temp->elem >= data){
            insertAtBeginning(data, l);
        }

        // no es al inicio, pero cuidado de si es al final
        while ( temp -> sig != l && temp -> sig -> elem < data){
            temp = temp -> sig;
        }

        // si es el último
        if (temp -> sig == l){
            insertAtEnd(data, l);
        }
        else {
            // si no es el último
            lista nuevo = createNode(data);
            nuevo -> sig = temp -> sig;
            temp -> sig = nuevo;
        }
    }

}





// auxiliares
void imprimir(lista &l) {
    if (isEmpty(l)) {
        printf("Lista vacía");
        return;
    }
    
    lista temp = l;
    bool bandera = true;

    while (bandera){
        printf("%d ", temp->elem);
        temp = temp->sig;
        if (temp == l){
            bandera = false;
        }
    }
    printf("\n");

}


void freeList(lista &l) {
    if (isEmpty(l)) return; // If the list is empty, there's nothing to free

    lista current = l;
    lista next;

    // Traverse the list and delete nodes
    do {
        next = current->sig; // Save the next node
        delete current;      // Free the current node
        current = next;      // Move to the next node
    } while (current != l); // Continue until we loop back to the head

    // After freeing all nodes, set the list head to nullptr
    l = nullptr;
}


int main(){

    lista l1 = empty();

    // prueba de insertar ordenado
    printf("Prueba de insertar ordenado: \n");
    insOrd(3, l1);
    insOrd(7, l1);
    insOrd(4, l1);
    imprimir(l1);

    // último
    //int aux = last(l1);
    //printf("%d ", aux);

    // resto
    printf("\nPrueba de resto: \n");
    lista l2 = empty();
    l2 = resto(l1);
    imprimir(l1);
    imprimir(l2);
    

    

    // liberar memoria
    freeList(l1);
    freeList(l2);

}


// g++ 5.circular_list.cpp -o ej5