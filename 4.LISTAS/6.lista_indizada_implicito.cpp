#include <stdio.h>

struct nodo {
    int elem ;
    nodo * sig;
};
struct cabezal {
    nodo * primero;
    nodo * actual;
};
typedef cabezal * lista;


/* 2 Implementaciones de lista vacía, que sea 
vacía o que tenga un cabezal con los punteros en null
La primera es más simple, pero sobrecarga por ejemplo
la operación de insertar, ya que al hacerlo debe crearse
el cabezal de ser necesario
*/

lista nullV1(){
    return NULL;
}

lista nullV2(){
    //cabezal *l = new cabezal;
    lista l = new cabezal;
    l -> primero = NULL;
    l -> actual = NULL;
    return l;
}


/* start me sirve pues puedo tener que recorrer la lista varias
veces, por lo que es útil resetear el puntero
*/

// dada una lista l no vacia, coloca la posición actual al inicio de l.
void start(lista &l){
    l -> actual = l -> primero;
}

// dada una lista l no vacia, mueve la posición actual al siguiente nodo (elemento). En caso
// de que la posición actual sea el final de la lista, coloca la posición actual al inicio de 
// la lista (tiene un comportamiento circular)
void next(lista &l){
    if (l -> actual -> sig == NULL){ // estoy en el último
        l -> actual = l -> primero;
    }
    else {
        l -> actual = l -> actual -> sig;
    }
}


// dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista.
// La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado
// es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.
// Su implementación depende de la implementación de null; aquí usaremos el simple
void insertar(int x, lista &l){
    nodo * nuevo = new nodo;
    nuevo -> elem = x;

    if ( l==NULL ){
        // encabezado
        l = new cabezal;
        l -> primero = nuevo;
        nuevo -> sig = NULL;
    }
    else { // inserto después del actual
        nuevo -> sig = l -> actual -> sig;
        l -> actual -> sig = nuevo;
    }
    l -> actual = nuevo;
}


// dada una lista l no vacia, retorna el elemento en la posición actual de l.
int element(lista l){
    return l -> actual -> elem;
}


// imprimir
void imprimirLista(lista l) {
    if (l == nullptr || l->primero == nullptr) {
        printf("Lista vacía");
        return;
    }
    for (nodo* temp = l->primero; temp != nullptr; temp = temp->sig) {
        printf("%d ", temp -> elem);
        if (temp->sig == l->primero) break; // Stop when reaching the last node
    }
}



void liberarLista(lista l) {
    nodo *aux, *actual;

    actual = l->primero;
    while (actual != NULL) {
        aux = actual;
        actual = actual->sig;
        delete aux;
    }

    l->primero = NULL;
    l->actual = NULL;
}




// main para probar
int main(){

    // creo una lista
    lista l1 = nullV1();


    printf("Prueba de insertar: \n");
    insertar(12, l1);
    insertar(17, l1);
    insertar(4, l1);
    insertar(12, l1);
    imprimirLista(l1);

    printf("Prueba de element: \n");
    int aux = element(l1);
    printf("Elemento actual: %d\n", aux);


    printf("Prueba de next: \n");
    next(l1);
    int aux2 = element(l1);
    printf("Elemento actual después de next: %d\n", aux2);
    next(l1);
    int aux3 = element(l1);
    printf("Elemento actual después de otro next: %d\n", aux3);
    next(l1);
    int aux4 = element(l1);
    printf("Elemento actual después de otro next: %d\n", aux4);


    liberarLista(l1);

}


// g++ 6.lista_indizada_implicito.cpp -o ej6