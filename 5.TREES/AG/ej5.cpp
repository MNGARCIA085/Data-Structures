#include <stdio.h>

struct nodoAG {
    int dato;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG;

/*
Dado un entero x retorna un árbol que sólo contiene a x (como una hoja).
*/
AG arbolHoja(int x){
    AG arbol = new nodoAG;
    arbol -> dato = x;
    arbol -> pH = NULL;
    arbol -> sH = NULL;
    return arbol;
}

/*
Dado un árbol, retorna true si y solo si el árbol es un árbol hoja (tiene un solo elemento).
*/
bool esArbolHoja(AG t){
    // The node should not be null, and it shouldn't have children or siblings
    return (t != NULL) && (t->pH == NULL) && (t->sH == NULL);
}

/*
Dados un árbol y un entero x, retorna true si y solo si x pertenece al árbol.
*/
bool pertenece(int x, AG t){
    if (t==NULL){
        return false;
    }
    else if (t -> dato == x){
        return true;
    }
    else { 
        return ( pertenece(x, t->pH)  || pertenece (x, t->sH) );
    }

}


/*
fn. auxiliar para buscar si un elemento está en el árbol
*/
AG buscar(int x, AG t){
    if (t == NULL){
        return NULL;
    }

    if (t -> dato == x){
        return t;
    }
    else {
        AG buscar_hijos = buscar(x, t -> pH);
        AG buscar_hermanos = buscar(x, t -> sH);
        if (buscar_hijos != NULL){
            return buscar_hijos;
        }
        else {
            return buscar_hermanos;
        }
    }
}



/*
 Dados un árbol y dos enteros h y p, inserta a h como el primer hijo de p en el árbol (hijo más
a la izquierda) si p pertenece al árbol y h no pertenece al árbol. En caso contrario la operación no tiene
efecto
*/
void insertar(int p, int h, AG &t){
    if (t == NULL){
        return;
    }

    AG nodo_p = buscar(p, t); // if p is in the tree
    AG nodo_h = buscar(h, t); // if h is in the tree
    
    if (nodo_p != NULL && nodo_h == NULL){
        // node to insert
        AG nuevo = new nodoAG;
        nuevo->dato = h;       // h should be the data of the new node
        nuevo->pH = NULL;      // new node has no children
        nuevo->sH = nodo_p->pH; // insert as the first child (shift current children)
        
        // insert in the tree
        nodo_p->pH = nuevo;    // update p's first child to be the new node
    }

}


/*
Dados un árbol y un entero x, elimina a x del árbol si es una hoja del árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se debe liberar la
memoria asignada a él.
*/
void borrar(int x, AG &t){
    if (t == NULL) {
        return;
    }

    // Case when the root is the node to delete and should not be removed
    if (t->dato == x && t->pH == NULL && t->sH == NULL) {
        // It's a leaf, but it's the root, so do nothing
        return;
    }

    // Recursive case: check the first child
    if (t->pH != NULL) {
        if (t->pH->dato == x && t->pH->pH == NULL && t->pH->sH == NULL) {
            // Found node x as the first child and it's a leaf
            AG aBorrar = t->pH;
            t->pH = t->pH->sH;  // Remove the node by bypassing it
            delete aBorrar;
        } else {
            // Recurse on the first child
            borrar(x, t->pH);
        }
    }

    // Recursive case: check the siblings
    if (t->sH != NULL) {
        if (t->sH->dato == x && t->sH->pH == NULL && t->sH->sH == NULL) {
            // Found node x as a sibling and it's a leaf
            AG aBorrar = t->sH;
            t->sH = t->sH->sH;  // Remove the node by bypassing it
            delete aBorrar;
        } else {
            // Recurse on the sibling
            borrar(x, t->sH);
        }
    }
}



// liberar memoria
void liberarMemoria(AG &t){
    if (t != NULL){
        liberarMemoria(t -> pH);
        liberarMemoria(t -> sH);
        delete t;
        t = NULL;
    }
}


/*
Dados un árbol y un entero x, elimina a x del árbol, si pertenece al árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se deberá liberar la
memoria asignada a los elementos que están en el subárbol dependiente de éste.
Nota "borro lo que está para abajo, es como borrar una carpeta con todo lo que tiene dentro"
*/
void borrarSub(int x, AG &t){
    if (t != NULL){
        if (t-> dato == x){
            AG aBorrar = t;
            t = t -> sH;
            liberarMemoria(aBorrar -> pH); // borro todo el subárbol liberando memoria
            delete aBorrar;
            borrarSub(x, t); // si quiero borrar todas las ocurrencias
        }
        else {
            borrarSub(x, t -> pH);
            borrarSub(x, t -> sH);
        }
    }
}






// Función para imprimir el árbol en preorden
void imprimirPreorden(AG raiz) {
    if (raiz == NULL) return;
    printf("%d " ,raiz->dato);
    imprimirPreorden(raiz->pH);
    imprimirPreorden(raiz->sH);
}


// test with main
int main(){
    // crear árbol hoja
    printf("Crear árbol hoja\n");
    AG arbol = arbolHoja(17);

    // prueba de esArbolHoja
    printf("\nEs árbol hoja\n");
    bool es = esArbolHoja(arbol);
    printf("Es hoja: %s\n", es ? "true" : "false"); 

    // prueba de insertar y nuevo de chequeo respecto a si es hoja
    printf("\nInsertar y ver si es hoja\n");
    insertar(17, 5, arbol);
    bool noes = esArbolHoja(arbol);
    printf("Es hoja: %s\n", noes ? "true" : "false"); 

    // more inserts
    printf("\nInsert\n");
    imprimirPreorden(arbol);
    printf("\n");
    insertar(5, 25, arbol);
    printf("\n");
    imprimirPreorden(arbol);
    insertar(5, 12, arbol);
    printf("\n");
    imprimirPreorden(arbol);
    insertar(32, 4, arbol); // acá no debería insertar
    printf("\n");  
    imprimirPreorden(arbol);  
    printf("\n");


    // pertenece
    printf("\nPrueba de pertenece\n");
    bool per = pertenece(25, arbol);
    printf("Pertenece: %s\n", per ? "true" : "false"); 
    bool noper = pertenece(235, arbol);
    printf("Pertenece: %s\n", noper ? "true" : "false"); 




    // borrarSub
    printf("\nPrueba de borrar subárboles\n");
    imprimirPreorden(arbol);
    printf("\n");
    borrarSub(5, arbol);
    imprimirPreorden(arbol);
    printf("\n");


    // borrar (recuerdo sólo borro una hoja que no sea la raíz)
    printf("\nPrueba de borrar\n");
    imprimirPreorden(arbol);
    printf("\n");
    borrar(17, arbol); // no debería hacer nada, no hay que borrar la raíz
    imprimirPreorden(arbol);
    printf("\n");
    insertar(17, 12, arbol);
    imprimirPreorden(arbol);
    printf("\n");
    borrar(12, arbol);
    imprimirPreorden(arbol);
    printf("\n");


    
    // free memory
    liberarMemoria(arbol);


}


// g++ ej5.cpp -o ej5