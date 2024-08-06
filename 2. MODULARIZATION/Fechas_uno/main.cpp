#include <stdio.h>
#include "fechas.h"

int main(){
    TFecha fecha = crear_fecha(12, 07, 2024);
    imprimir_fecha(fecha);

    printf("\n");

    // día mes y anio
    unsigned int day = dia(fecha);
    printf("Día: %d\n", day);

    unsigned int month = mes(fecha);
    printf("Mes: %d\n", month);

    unsigned int year = anio(fecha);
    printf("Anio: %d\n", year);



}


//g++ main.cpp fechas.cpp -o fechas