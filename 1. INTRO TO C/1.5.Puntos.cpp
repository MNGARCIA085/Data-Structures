#include <stdio.h>

typedef struct rep_punto {
    int coordX , coordY ;
} Punto ;

// es un array con tope
typedef struct rep_colPuntos {
    int capacidad ;
    int cantidad ;
    Punto * arregloPuntos;
} ColPuntos ;



// insertar un punto
void insertarPunto(ColPuntos &colPtos, Punto pto) { // & indica una dirección de memoria
    // Verificar si hay espacio
    if (colPtos.cantidad == colPtos.capacidad) {
        // Manejar error: la colección está llena
        printf("Error: La colección de puntos está llena.\n");
        return;
    }
    // Incrementar la cantidad de puntos
    colPtos.cantidad++;
    // Agregar el nuevo punto al arreglo
    colPtos.arregloPuntos[colPtos.cantidad - 1] = pto;
}


// mínimo x
int menor_x(ColPuntos colPtos){
    /** val. extra
     * if (colPtos.cantidad == 0) {
        // Manejar caso de colección vacía
        return INT_MIN; // O cualquier valor indicativo de error
        }
     */
    int min = colPtos.arregloPuntos[0].coordX; 
    for(int i = 1; i < colPtos.cantidad; i++){
        if (colPtos.arregloPuntos[i].coordX < min){
            min = colPtos.arregloPuntos[i].coordX;
        }
    }
    return min;
}


// promedio de 2 puntos
Punto punto_medio(Punto p1, Punto p2){
    int x = (p1.coordX + p2.coordX)/2;
    int y = (p1.coordY + p2.coordY)/2;

    Punto p = {x, y};

    return p;

}


// imprimir
void imprimirPuntos(ColPuntos colPtos) {
    for (int i = 0; i < colPtos.cantidad; i++) {
        printf("Punto %d: (%d, %d)\n", i + 1, colPtos.arregloPuntos[i].coordX, colPtos.arregloPuntos[i].coordY);
    }
}



int main(){

    // creo mi colección
    ColPuntos col;
    col.capacidad = 10;
    col.cantidad = 0;
    col.arregloPuntos = new Punto[col.capacidad];

    // creo algunos puntos
    Punto p1 = {2, 3};
    Punto p2 = {5, 1};
    Punto p3 = {1, 9};

    // inserto algunos puntos
    insertarPunto(col, p1);
    insertarPunto(col, p2);
    insertarPunto(col, p3);


    // imprimo
    imprimirPuntos(col);

    // mínimo
    int menor = menor_x(col);
    printf("El mínimo de la colección es %d\n", menor);

    // punto medio
    Punto p_medio = punto_medio(p1, p3);
    printf("El punto medio es x: %d y: %d\n", p_medio.coordX, p_medio.coordY);


   

}


// g++ 1.5.Puntos.cpp -o punto