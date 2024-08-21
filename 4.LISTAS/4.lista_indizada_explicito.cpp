#include <stdio.h>

struct nodo_doble {
    int elem;
    nodo_doble * sig;
    nodo_doble * ant;
};
typedef nodo_doble * lista;

//dados un natural p y una lista l, retorna verdadero si, y solamente si, existe un elemento
//en esa posición.
bool estaDefinido(int p, lista &l){

    if (p < 0) {
        return false; // Posiciones negativas no son válidas
    }

    int iter = 0;
    lista temp = l;
    while ( (temp != NULL) && (p != iter) ){
        iter++;
        temp = temp -> sig;

    }
    return temp != NULL;

}




/*
dados un entero x, un natural p y una lista l de longitud m, inserta a x en la lista. Si p no
esta definida, inserta a x en la posición m. En otro caso, inserta a x en la posición p y desplaza en una
posición los elementos que estuvieran en las posiciones siguientes.
*/
void insertar(int x, int p, lista &l, int m) {

    // Si la posición es mayor que la longitud, se debe insertar al final
    if ( !estaDefinido(p, l) ){
        p = m;
    }

    // Crear el nuevo nodo
    lista nuevo = new nodo_doble;
    nuevo->elem = x;

    // Caso especial: insertar al principio
    if (p == 0) {
        nuevo->sig = l;
        nuevo->ant = NULL;
        if (l != NULL) {
            l->ant = nuevo;
        }
        l = nuevo;
        return;
    }

    lista temp = l;
    for (int i = 0; i < p - 1; ++i) {
        if (temp == NULL) {
            delete nuevo; // En caso de que la lista esté mal formada
        }
        temp = temp->sig;
    }

    // Inserción en la posición p
    if (temp != NULL) {
        nuevo->sig = temp->sig;
        nuevo->ant = temp;
        if (temp->sig != NULL) {
            temp->sig->ant = nuevo;
        }
        temp->sig = nuevo;
    }
}


/*
dados un natural p y una lista l, elimina de la lista el elemento que se encuentra en la posición
p. Si la posición no está definida, la operación no tiene efecto. Si la posición está definida, elimina el
elemento en dicha posición y desplaza en una posición los elementos que estuvieran en las posiciones
posteriores a p (contrae la lista).
*/
void eliminar(int p, lista &l, int m) {

    // Verificar si la posición es válida
    if (p < 0 || p >= m) {
        return; // La posición no está definida, no hacer nada
    }

    lista temp = l;

    // Caso especial: eliminar al principio
    if (p == 0) {
        l = l->sig; // Actualiza el inicio de la lista
        if (l != NULL) {
            l->ant = NULL;
        }
        delete temp; // Elimina el nodo
        return;
    }

    // Recorrer hasta el nodo en la posición p
    for (int i = 0; i < p; ++i) {
        if (temp == NULL) {
            return; // La posición no está definida
        }
        temp = temp->sig;
    }

    // Caso especial: eliminar el último nodo
    if (temp->sig == NULL) {
        temp->ant->sig = NULL;
    } else {
        // Conectar el nodo anterior con el siguiente nodo
        temp->ant->sig = temp->sig;
        temp->sig->ant = temp->ant;
    }

    delete temp; // Elimina el nodo
}


// retorna el elemento en la posición p
// pre-cond: la posición p está definida
int elemento(int p, lista &l){
    int iter = 0;
    lista temp = l;
    while ( temp != NULL && iter < p){
        iter++;
        temp = temp -> sig;
    }
    return temp -> elem;
}



// imprimir
void imprimir(lista l){
    lista aux=l;
    while (aux!=NULL){
        printf("%d ", aux->elem);
        aux=aux->sig;
    }   
    printf("\n");
}


// liberar memoria
void liberarLista(lista &l) {
    while (l != NULL) {
        lista aBorrar = l;
        l = l->sig;  // Avanza al siguiente nodo
        delete aBorrar;  // Libera el nodo actual
    }
}



// MAIN
int main(){

    printf("Prueba de insertar:\n");
    lista l1 = NULL;
    insertar(7, 0, l1, 0);
    insertar(17, 1, l1, 1);
    insertar(21, 2, l1, 2);
    imprimir(l1);
    insertar(1, 1, l1, 3);
    imprimir(l1);

    printf("\nPrueba de elemento:\n");
    imprimir(l1);
    int i = 2;
    int elem = elemento(i, l1);
    printf("El elemento en la pos %d es % d\n", i, elem);


    printf("\nPrueba de está definido:\n");
    bool esta = estaDefinido(2, l1);
    bool noesta = estaDefinido(7, l1);
    printf("%s\n", esta ? "true" : "false");
    printf("%s\n", noesta ? "true" : "false");

    printf("\nPrueba de eliminar:\n");
    imprimir(l1);
    eliminar(2, l1, 4);
    imprimir(l1);



    // liberar memoria
    liberarLista(l1);

}

// g++ 4.lista_indizada_explicito.cpp -o ej4