/*
Ejercicio 1 Tabla de dispersión
Implemente una tabla de dispersión que puede contener hasta n enteros resolviendo los conflictos mediante
listas simplemente enlazadas. Se debe poder insertar, remover y buscar elementos. El tiempo de ejecución
de las inserciones debe ser O(1) en peor caso.
*/
#include <stdio.h>

struct nodoTDA{
    int dato;
    nodoTDA *sig;
};

//El arreglo contiene punteros a los nodos
struct tablaTDA{
    nodoTDA** arreglo;
    int tamanio;
};

typedef tablaTDA* TDA;


// Fn. de hash
// puedo hacerlo todo en ella si le paso la cota
// pero aquí, para no pasarla de antemano voy a devolver
// un entero y devuelvo el módulo después
int h(int i){
    return i;
}



// crear tabla
TDA CrearTDA(int n){
    TDA tabla = new tablaTDA;
    tabla -> tamanio = n;
    tabla -> arreglo = new nodoTDA *[n]; // nuevo arreglo de nodos de tamaño n
    for (int i = 0; i < n; i ++){
        tabla -> arreglo[i] = NULL;
    }
    return tabla;
}


//Inserta un elemento x en la tabla t 
void insertarTDA(int x, TDA &t){
    // obtengo la posición en la que debo insertar
    int indice = h(x) % t -> tamanio;
    // inserto al inicio
    nodoTDA* nuevo = new nodoTDA;
    nuevo -> dato = x;
    nuevo -> sig = t->arreglo[indice];
    t -> arreglo[indice] = nuevo;
}


//Remueve un elemento x en la tabla t (todas sus apariciones)
void removerTDA(int x, TDA &t){
    // encuentra la posición
    int indice = h(x) % t -> tamanio;
    // ahora lo busco en la lista que se encuentra en esa posición
    nodoTDA* temp = new nodoTDA;
    temp = t->arreglo[indice];
    // borro todas las ocurrencias al inicio
    while(temp != NULL && temp->dato == x){
        t->arreglo[indice] = temp->sig;
        delete temp;
        temp = t->arreglo[indice];
    }
    // borro las que quedan (de haberlas)
    if (temp != NULL){
        while (temp != NULL){
            if (temp->sig->dato == x){
                nodoTDA* aBorrar= temp->sig;
                temp->sig= temp->sig->sig;
                delete aBorrar;
            }
            else {
                temp = temp -> sig;
            }
        }
    }
}


// si un elemento pertenece a la tabla
bool perteneceTDA(int x, TDA t){
    // encuentro la posición
    int indice = h(x) % t -> tamanio;
    // recorro la lista
    nodoTDA* temp = t->arreglo[indice];
    while (temp != NULL && x != temp->dato){
        temp = temp -> sig;
    }
    // si sale con temp!=NULL lo encontró
    return temp != NULL;
}











