#include <stdio.h>

typedef unsigned int uint;


void insertarOrdenado(int *A, uint n, int e) {
    if (n == 0 || A[n-1] <= e) {
        // Inserta el elemento en la posición correcta
        A[n] = e;
    } else {
        // Desplaza el elemento y llama a la función recursivamente
        A[n] = A[n-1];
        insertarOrdenado(A, n-1, e);
    }
}


void ordenar(int *A, uint n) {
    // para n = 0 y n = 1 no modifico el arreglo
    if (n > 1) {
        ordenar(A, n-1);
        insertarOrdenado(A, n-1, A[n-1]);
    }
}

void insertarOrdenadoIter(int *A, uint n, int e) {
    int i = n - 1;
    while (i >= 0 && A[i] > e) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = e;
}

void imprimir(int *A, uint n) {
    for (uint i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}





int main() {
    int A[10] = {1, 3, 7, 5};  // Arreglo de ejemplo
    uint n = 4;  // Tamaño actual del arreglo

    printf("Antes de ordenar:\n");
    imprimir(A, n);

    // Ordenar el arreglo
    ordenar(A, n);

    printf("Después de ordenar:\n");
    imprimir(A, n);

    // Insertar un elemento ordenado
    int nuevoElemento = 4;
    insertarOrdenadoIter(A, n, nuevoElemento);
    n++;  // Incrementar el tamaño del arreglo

    printf("Después de insertar %d:\n", nuevoElemento);
    imprimir(A, n);

    return 0;
}

