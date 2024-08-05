#include <stdio.h>



// Función para ordenar un arreglo de enteros en orden descendente
void ordenar_descendente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


float calcular_promedio(int arreglo[], int m, int n){
    /*
    Dado un arreglo de enteros y un entero n, calcula el promedio de los
    n primeros valores.
    Args:
        - arreglo: arreglo ordenado de enteros
        - m : largo del arreglo
        - n: cantidad de elementos para tomar el promedio
    Returns
        - promedio: float
    */
   float suma = 0;
   for (int i = 0; i < n; i++){
        suma += arreglo[i];
   }
   return suma/n;
}

// imprimir arreglo
void imprimir_arreglo(int arreglo[], int m){
    for (int i = 0; i < m; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}



// MAIN
int main(){
    // leer la entrada y guardar los datos en un arreglo
    int m = 5; // largo del arreglo
    int n = 4; // calificaciones a considerar
    int calificaciones[m];
    printf("Ingrese %d calificaciones: \n", m);
    for (int i = 0; i < m; i++){
        printf("Calificación %d: ", i + 1);
        if (scanf("%d", &calificaciones[i]) != 1) {
            fprintf(stderr, "Error al leer la calificación. Asegúrese de ingresar un número válido.\n");
            return 1;
        }
    }

    // ordeno el arreglo
    ordenar_descendente(calificaciones, m);

    // calcular promedio
    float promedio = calcular_promedio(calificaciones, m, n);

    // devuelvo la salida
    printf("El promedio es: %f", promedio);

    return 0;

}


// g++ 1.1. Average.cpp -o average

