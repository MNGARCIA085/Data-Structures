#include <stdio.h>


typedef unsigned int uint ;

struct nodoABB {
    uint elem ;
    nodoABB * izq , * der;
};

typedef nodoABB * ABB;


// insertar manteniendo la condición de árbol binario
// si ya estaba no hace nada
void insertar(uint x, ABB &arbol) {
    // si el árbol es vacío, inserto el nuevo nodo
    if (arbol == NULL) {
        arbol = new nodoABB;  // asignar el nuevo nodo al árbol
        arbol->elem = x;
        arbol->izq = NULL;
        arbol->der = NULL;
    } 
    // si no es vacío, dependiendo del elemento, inserto a la derecha o a la izquierda
    else if (x > arbol->elem) {
        insertar(x, arbol->der);
    } 
    else if (x < arbol->elem) {
        insertar(x, arbol->izq);
    }
}



// pertenece
bool pertenece(uint x, ABB arbol){
    // uso iteración para aproverchar la cualidad de orden de los árboles binarios
    if (arbol == NULL){
        return false;
    }
    while (arbol != NULL && x != arbol -> elem){
        if (x > arbol -> elem){
            arbol = arbol -> der;
        }
        else {
            arbol = arbol -> izq;
        }
    }

    return arbol != NULL;
}



// máximo, pre: árbol no vacío
int maximo(ABB arbol){
    // más a la derecha
    while (arbol-> der != NULL){
        arbol = arbol -> der;
    }
    return arbol -> elem;
}


// mínimo
int minimo(ABB arbol){
    // más a la derecha
    while (arbol-> izq != NULL){
        arbol = arbol -> izq;
    }
    return arbol -> elem;
}


// remover el máximo
void removerMaximoIter(ABB &arbol) {
    // si está vacío, no hay nada que hacer
    if (arbol == NULL) {
        return;
    }

    // si el máximo está en la raíz y no tiene subárbol derecho
    if (arbol->der == NULL) {
        ABB aBorrar = arbol;
        arbol = arbol->izq; // el subárbol izquierdo ocupa su lugar
        delete aBorrar;
        return;
    }

    // recorro hasta encontrar el nodo más a la derecha (el máximo)
    ABB temp = arbol;
    while (temp->der->der != NULL) {
        temp = temp->der;
    }

    // ahora `temp->der` es el nodo máximo
    ABB aBorrar = temp->der;
    temp->der = aBorrar->izq; // el subárbol izquierdo del nodo máximo ocupa su lugar
    delete aBorrar;
}


// remover máximo en versión recursiva
void removerMaximo(ABB &arbol) {
    if (arbol == NULL){
        return;
    }

    // si el derecho está vacío estoy en el nodo a eliminar
    if (arbol -> der == NULL){
        ABB aBorrar = arbol;
        arbol = arbol -> izq; // Reemplazamos árbol por su subárbol izquierdo
        delete aBorrar;
    }
    else { // en otro caso llamo a la recursión
        removerMaximo(arbol -> der);
    }

}


// remover máximo, versión función
ABB removerMaxABB(ABB t) {
    if (t == NULL) {
        return NULL;
    } else if (t->der == NULL) {
        // Si t->der es NULL, entonces t es el nodo con el valor máximo
        ABB temp = t;
        t = t->izq; // Reemplazamos t por su subárbol izquierdo
        delete temp; // Liberamos la memoria del nodo original
        return t;
    } else {
        // Recorremos hacia la derecha hasta encontrar el nodo máximo
        // y lo eliminamos
        t->der = removerMaxABB(t->der);
        return t;
    }
}


/*
Procedure REMOVE_NODE(tree, element):
    If tree is NULL:
        Return  // Element not found, nothing to remove

    If element < tree.value:
        REMOVE_NODE(tree.left, element)  // Search in the left subtree

    Else If element > tree.value:
        REMOVE_NODE(tree.right, element)  // Search in the right subtree

    Else:  // Element found, handle deletion

        // Case 1: No children (leaf node)
        If tree.left is NULL and tree.right is NULL:
            DELETE_NODE(tree)
            tree = NULL  // Remove the node

        // Case 2: One child
        Else If tree.left is NULL:
            temp = tree
            tree = tree.right  // Replace the node with its right child
            DELETE_NODE(temp)

        Else If tree.right is NULL:
            temp = tree
            tree = tree.left  // Replace the node with its left child
            DELETE_NODE(temp)

        // Case 3: Two children
        Else:
            successor = FIND_MIN(tree.right)  // Find the minimum node in the right subtree
            tree.value = successor.value  // Replace current node's value with the successor's value
            REMOVE_NODE(tree.right, successor.value)  // Remove the successor node recursively


Procedure FIND_MIN(tree, Output min_node):
    While tree.left is not NULL:
        tree = tree.left  // Keep going to the left to find the minimum value
    min_node = tree


Procedure DELETE_NODE(node):
    // Free the memory of the node (depends on the language used)
    // Example in C/C++: delete node


*/

void removerABB(uint x, ABB &arbol){
    if (arbol == NULL){
        return;
    }
    else if (x < arbol -> elem){
        removerABB(x, arbol -> izq);
    }
    else if (x > arbol -> elem){
        removerABB(x, arbol -> der);
    }
    else { // acá es x == arbol->elem
        // leaf node
        if ( arbol -> izq == NULL && arbol -> der == NULL){
            ABB aBorrar = arbol;
            arbol = NULL;
            delete aBorrar;
            aBorrar = NULL;
        }
        else if (arbol -> izq == NULL){ // left is null
            ABB aBorrar = arbol;
            arbol = arbol -> der;
            delete aBorrar;
            aBorrar = NULL;
        }
        else if (arbol -> der == NULL){ // right is null
            ABB aBorrar = arbol;
            arbol = arbol -> izq;
            delete aBorrar;
            aBorrar = NULL;
        }
        else { // none of the subtrees is null
            int sucesor = minimo(arbol -> der);
            arbol -> elem = sucesor;
            removerABB(sucesor, arbol -> der);
        }
    }
}


// contar nodos
int contarNodos(ABB arbol){
    if (arbol == NULL){
        return 0;
    }
    else {
        return 1 + contarNodos(arbol -> izq) + contarNodos(arbol -> der); 
    }
}

/*
Función k-esimo: que recibe un natural k y un ABB b y retorna el subárbol que tiene al k-ésimo menor
elemento de b como raíz. Si en b hay menos de k elementos o k es cero, la función debe retornar el
árbol vacío. Si k es 1, se refiere al menor elemento del árbol, si k es 2 al 2do elemento más pequeño
del árbol y así sucesivamente. La solución no puede visitar ningún nodo más de una vez.

básicamente debo encontrar el k-ésimo menor elemento


*/



ABB minimoABB(ABB arbol){
    // más a la derecha
    while (arbol-> izq != NULL){
        arbol = arbol -> izq;
    }
    return arbol;
}


ABB kesimo(uint k, ABB arbol) {
    if (arbol == NULL) {
        return NULL;
    }

    int numIzq = contarNodos(arbol->izq);  // Count nodes in the left subtree

    if (k == numIzq + 1) {
        return arbol;  // Current node is the k-th smallest
    }
    else if (k <= numIzq) {
        return kesimo(k, arbol->izq);  // k-th smallest is in the left subtree
    }
    else {
        return kesimo(k - numIzq - 1, arbol->der);  // k-th smallest is in the right subtree
    }
}


// print in order
void imprimir(ABB arbol){
    if (arbol == NULL){
        return;
    }
    imprimir(arbol -> izq);
    printf("%d ", arbol -> elem);
    imprimir(arbol -> der);
}



// free memory
void liberarMemoria(ABB &arbol){
    if (arbol == NULL){
        return;
    }
    liberarMemoria(arbol -> izq);
    liberarMemoria(arbol -> der);

    delete arbol;
    arbol == NULL;

}







// MAIN
int main(){

    // insertar
    printf("Prueba de insertar\n");
    ABB a1 = NULL;
    insertar(7, a1);
    insertar(4, a1);
    insertar(3, a1);
    insertar(14, a1);
    insertar(21, a1);

    imprimir(a1);
    printf("\n");


    // pertenece
    printf("\nPrueba de pertenece\n");
    bool esta = pertenece(7, a1);
    bool noesta = pertenece(65, a1);
    printf("EL 7 está: %s\n", esta ? "true" : "false");
    printf("EL 65 está: %s\n", noesta ? "true" : "false");


    // máximo
    printf("\nPrueba de máximo\n");
    int max1 = maximo(a1);
    printf("Máximo: %d\n", max1);

    // mínimo
    printf("\nPrueba de mínimo\n");
    int min1 = minimo(a1);
    printf("%d\n", min1);

    // prueba de k-ésimo
    printf("\nPrueba de k-ésimo\n");
    ABB a2  = kesimo(2, a1);
    imprimir(a2);
    printf("\n");
    ABB a3 = kesimo(1, a1);
    imprimir(a3);
    printf("\n");
    

    
    // remover
    printf("\nPrueba de remover\n");
    imprimir(a1);
    printf("\n");
    removerABB(7, a1);
    printf("Remuevo el 7: ");
    imprimir(a1);
    printf("\n");
    printf("Remuevo el 21: ");
    removerABB(21, a1);
    imprimir(a1);
    printf("\n");
    printf("Remuevo el 45 (que no está): ");
    removerABB(45, a1);
    imprimir(a1);
    printf("\n");


    

    // free memory
    liberarMemoria(a1);
    //liberarMemoria(a2);
    //liberarMemoria(a3);


}


// g++ Ej3.cpp -o ej3
