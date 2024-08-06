#include <stdio.h>

// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int f ; // AAAAMMDD
};


// ordenar
void ordenar_arreglo(rep_fecha fecha[], unsigned int n){
    for (unsigned int i = 0; i < n -1; i++){
        unsigned int min_idx = i;
        for (unsigned int j = i + 1; j < n; j++){
            if (fecha[j].f < fecha[min_idx].f){
                min_idx = j;
            }
        }
        rep_fecha temp = fecha[min_idx];
        fecha[min_idx] = fecha[i];
        fecha[i] = temp;
    }
};

// imprimir fechas
void imprimir_fecha(rep_fecha fecha){
    printf("%d/%d/%d\n", fecha.f%100, fecha.f%10000/100, fecha.f/10000);
};



// main 
int main(){
    // creo e inicializo un arreglo de fechas
    unsigned int n = 3;
    rep_fecha fechas[n] = {{20221004},{20230515},{20221107}};


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


// g++ fechas_dos.cpp -o fecha_dos







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