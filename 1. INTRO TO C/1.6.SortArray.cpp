#include <stdio.h>

/**
 *  Declaración e inicialización del arreglo
        Declarar un arreglo de n elementos .
        Para cada entrada i del arreglo :
            Leer un entero de la entrada estándar .
            Almacenarlo en la entrada i del arreglo .
    Algoritmo de ordenamiento
        Para cada entrada i del arreglo :
            Buscar el mínimo elemento e_min de las entradas i en adelante .
            Intercambiar dicho elemento e_min con el de la posición i .
    Impresión de resultado
        Para cada entrada i del arreglo :
        Imprimir el elemento en la entrada i
 */


// ordeno
void ordenar_ascendente(int arreglo[], int n){
    for (int i = 0; i < n -1; i++){ // para cada elemento i del arreglo (Nota.)
        for (int j = i+1; j < n; j++){ // entradas i en adelante
            if (arreglo[j] < arreglo[i]){ // si es menor intercambio
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}

/**: Nota. Recorre cada elemento del arreglo, excepto el último. Esto es porque, 
con cada pasada del bucle interno, el elemento más pequeño se coloca en su posición correcta.
*/


// imprimir arreglo
void imprimir_arreglo(int arreglo[], int m){
    for (int i = 0; i < m; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}



int main(){
    // leer la entrada y guardar los datos en un arreglo
    int m = 5; // largo del arreglo
    int n = 4; // calificaciones a considerar
    int arreglo[m];
    printf("Ingrese %d elementos: \n", m);
    for (int i = 0; i < m; i++){
        scanf("%d", &arreglo[i]);
    }

    // imprimo antes de ordenar
    imprimir_arreglo(arreglo, m);

    // ordeno el arreglo
    ordenar_ascendente(arreglo, m);

    // imprimo nuevamente
    imprimir_arreglo(arreglo, m);

}

// g++ 1.6.SortArray.cpp -o sort