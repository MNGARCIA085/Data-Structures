#include <stdio.h>

// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int d ;
    unsigned int m ;
    unsigned int a ;
};


// ordenar el arreglo
void ordenar_arreglo(rep_fecha fechas[], int n){
    for (unsigned int i = 0; i < n-1; i++){
        int min_idx = i; // índice del mínimo
        for (unsigned int j = i+1; j < n; j++){
            // es menor que el mínimo actual? para saber si una fecha es menor debo comparar año, mes, día en ese orden
            if ( (fechas[i].a < fechas[min_idx].a) 
                    || ((fechas[i].a == fechas[min_idx].a) && (fechas[i].m < fechas[min_idx].m))
                    || ((fechas[i].a == fechas[min_idx].a) && (fechas[i].m == fechas[min_idx].m) && (fechas[i].d == fechas[min_idx].d))
             ){
                // actualizo el índice del mínimo
                min_idx = j;
             }
        }
        // intercambio
        rep_fecha temp = fechas[min_idx];
        fechas[min_idx] = fechas[i];
        fechas[i] = temp;
    }
};



// imprimir fechas
void imprimir_fecha(rep_fecha fecha){
    printf("Day/month/year: %d/%d/%d\n", fecha.d, fecha.m, fecha.a);
}



// main 
int main(){
    // creo e inicializo un arreglo de fechas
    int n = 3;
    rep_fecha fechas[n] = {{10,10,2022},{15,5,2023},{20,11,1992}};


    // imprimir la fecha
    for (int i = 0; i < n; i++){
        imprimir_fecha(fechas[i]);
    }

    printf("\n");

    // ordenar e imprimir nuevamente
    ordenar_arreglo(fechas, n);
    for (int i = 0; i < n; i++){
        imprimir_fecha(fechas[i]);
    }

}


// g++ fecha_uno.cpp -o fecha_uno






/**
 * Selection sort
 * 
 * 
 * 
 * for(int i = 0; i < n-1 ; i++){
      int minimo = i;
      for(int j = i + 1 ; j < n ; j++){
            if(lista[j] < lista[minimo]){
                  minimo = j;
            }
      }
      intercambiar(lista , i , minimo);
}
 */