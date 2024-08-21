#include <stdio.h>

struct nodo_doble {
    int elem;
    nodo_doble * sig;
    nodo_doble * ant;
};
typedef nodo_doble * lista;


// retorna una lista vacía
// O(1)
lista vacia(){
    return NULL;
}

// dada una lista l, verifica si l esta vacia.
// O(1)
bool esVacia(lista l){
    return l == NULL;
}

// dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.
// O(1)
void insPrincipio(int x, lista &l){
    //creamos el nodo y lo inicializamos
    lista nuevo = new nodo_doble;
    nuevo->elem=x;
    nuevo->sig=l;
    nuevo->ant=NULL;
    
    //nos fijamos si no es vacia para que el primer elemento quede enlazado
    if (!esVacia(l)){
        l->ant=nuevo;
    }
    l=nuevo;
}


// dados un entero x y una lista l, verifica si x pertenece a l.
// peor caso O(n)
// mejor caso O(1)
bool pertenece(int x, lista l){
    while (l != NULL && l -> elem != x){
        l = l -> sig;
    }
    return l != NULL;
}



// removerTodos: dados un entero x y una lista l, retorna el resultado de eliminar todas las ocurrencias
//de x de l.
// en el peor caso O(n)
// en el mejor caso O(n)
void removerTodos(int x, lista &l) {
    lista aux = l;
    while (aux != NULL) {
        if (aux->elem == x) {
            // Si el nodo a eliminar es el primero
            if (aux->ant == NULL) {
                l = aux->sig;
                if (aux->sig != NULL)
                    aux->sig->ant = NULL;
            } else {
                // Si el nodo a eliminar no es el primero
                aux->ant->sig = aux->sig;
                if (aux->sig != NULL) {
                    aux->sig->ant = aux->ant;
                }
            }
            lista aborrar = aux;
            aux = aux->sig;
            delete aborrar;
        } else {
            aux = aux->sig;   
        }
    }
}

// insOrd: dados un entero x y una lista l ordenada, retorna el resultado 
// de insertar x en l ordenadamente
void insOrd(int x, lista &l){
    if (esVacia(l) || l->elem >=x){
        insPrincipio(x,l);
    }else{
        
        lista nuevo = new nodo_doble;
        nuevo->elem=x;
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        
        lista aux=l;
        while(aux->sig!=NULL && aux->elem < x){
            aux=aux->sig;
        }
        if (aux->elem >= x){
            nuevo->sig=aux;
            nuevo->ant=aux->ant;
            aux->ant->sig=nuevo;
            aux->ant=nuevo;
        }else{ //caso de inserción al final de la lista
            nuevo->ant=aux;
            aux->sig=nuevo;
        }
    }
}


//remomverUltimo: dada una lista l ordenada, retorna el resultado de eliminar el último elemento de l
// es O(n) pues recorre todo
void removerUltimo(lista & l){
    
    if (l == NULL) {
        return;  // La lista está vacía, no hay nada que remover
    }
    
    lista temp = l;
    while (temp->sig != NULL){
        temp = temp -> sig;
    }
    
    // Si solo hay un nodo en la lista
    if (temp->ant == NULL) {
        l = NULL;
    } else {
        temp->ant->sig = NULL;
    }
    
    delete temp;
}



// removerUltimo: dada una lista l ordenada, retorna el resultado de eliminar el último elemento de
//l. Analice el orden del tiempo de ejecución. Proponga una representación con la que el orden del
//tiempo de ejecución sea O(1).
//Falta hacer

/*struct cabezal {
    nodo_doble * inicio ;
    nodo_doble * fin ;
};

lista listaVacia(){
    cabezal* nuevo = new cabezal;
    nuevo->inicio=nuevo->final=NULL;
}
*/




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


int main(){

    lista l1 = NULL;

    printf("Prueba de insertar: \n");
    insPrincipio(7, l1);
    insPrincipio(14, l1);
    insPrincipio(21, l1);
    insPrincipio(7, l1);
    insPrincipio(28, l1);
    imprimir(l1);

    printf("\nPrueba de es elemento: \n");
    bool esta = pertenece(14, l1);
    bool noesta  = pertenece(121, l1);
    printf("%s\n", esta ? "true" : "false");
    printf("%s\n", noesta ? "true" : "false");


    printf("\nPrueba de remover todos: \n");
    removerTodos(7, l1);
    imprimir(l1);


    printf("\nPrueba de insertar ordenado: \n");
    lista l2 = NULL;
    insPrincipio(21, l2);
    insPrincipio(14, l2);
    insPrincipio(7, l2);
    imprimir(l2);
    insOrd(16, l2);
    imprimir(l2);


    printf("\nPrueba de remover el último: \n");
    removerUltimo(l2);
    imprimir(l2);

    liberarLista(l1);
    liberarLista(l2);

}



// g++ 3.doblemente_enlazada.cpp -o ej3