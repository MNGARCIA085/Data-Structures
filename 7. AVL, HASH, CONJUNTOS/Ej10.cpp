#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de nodo para la lista
struct nodo {
    int elem;
    struct nodo* sig;
};
typedef struct nodo* lista;

// Definición de la tabla hash
struct tablaTDA {
    lista* arreglo; // Arreglo de listas
    int tamanio;
};

typedef struct tablaTDA* TDA;

// Función hash
int hash(int elem, int tamanio) {
    return abs(elem) % tamanio; // Módulo para obtener un índice válido
}

// Crear la tabla hash
TDA crearTabla(int tamanio) {
    TDA tabla = (TDA)malloc(sizeof(struct tablaTDA));
    tabla->arreglo = (lista*)malloc(tamanio * sizeof(lista));
    tabla->tamanio = tamanio;
    for (int i = 0; i < tamanio; i++) {
        tabla->arreglo[i] = NULL; // Inicializar cada lista como NULL
    }
    return tabla;
}

// Insertar en la tabla hash
void insertar(TDA tabla, int elem) {
    int idx = hash(elem, tabla->tamanio);
    lista nuevo = (lista)malloc(sizeof(struct nodo));
    nuevo->elem = elem;
    nuevo->sig = tabla->arreglo[idx]; // Encadenamiento
    tabla->arreglo[idx] = nuevo;
}

// Verificar si un elemento pertenece a la tabla hash
int pertenece(TDA tabla, int elem) {
    int idx = hash(elem, tabla->tamanio);
    lista actual = tabla->arreglo[idx];
    while (actual != NULL) {
        if (actual->elem == elem) {
            return 1; // Elemento encontrado
        }
        actual = actual->sig;
    }
    return 0; // Elemento no encontrado
}

// Liberar la memoria de la tabla hash
void liberarTabla(TDA tabla) {
    for (int i = 0; i < tabla->tamanio; i++) {
        lista actual = tabla->arreglo[i];
        while (actual != NULL) {
            lista temp = actual;
            actual = actual->sig;
            free(temp); // Liberar cada nodo
        }
    }
    free(tabla->arreglo); // Liberar el arreglo de listas
    free(tabla); // Liberar la tabla
}

// Crear una lista dinámica para los resultados
lista crearLista() {
    return NULL; // Inicializar lista vacía
}

// Insertar en la lista de resultados
void insertarEnLista(lista* l, int elem) {
    lista nuevo = (lista)malloc(sizeof(struct nodo));
    nuevo->elem = elem;
    nuevo->sig = *l; // Insertar al principio
    *l = nuevo; // Actualizar la lista
}

// Función para calcular la intersección de dos listas A y B
lista intersección(int* A, int lenA, int* B, int lenB) {
    TDA tabla = crearTabla(10007); // Crear tabla hash
    lista resultado = crearLista(); // Inicializar lista de resultados

    // Insertar todos los elementos de A en la tabla hash
    for (int i = 0; i < lenA; i++) {
        insertar(tabla, A[i]);
    }

    // Verificar si los elementos de B están en la tabla hash
    for (int i = 0; i < lenB; i++) {
        if (pertenece(tabla, B[i])) {
            insertarEnLista(&resultado, B[i]); // Agregar a la lista de resultados
        }
    }

    // Liberar la memoria de la tabla hash
    liberarTabla(tabla);
    return resultado; // Retornar lista de intersección
}

// Función para imprimir la lista
void imprimirLista(lista l) {
    while (l != NULL) {
        printf("%d ", l->elem);
        l = l->sig;
    }
    printf("\n");
}

// Ejemplo de uso
int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {3, 4, 5, 6, 7};

    lista resultado = intersección(A, 5, B, 5); // Obtener la intersección

    // Imprimir los resultados
    printf("Intersección: ");
    imprimirLista(resultado);

    // Liberar memoria de la lista resultado
    while (resultado != NULL) {
        lista temp = resultado;
        resultado = resultado->sig;
        free(temp); // Liberar cada nodo
    }
    
    return 0;
}
