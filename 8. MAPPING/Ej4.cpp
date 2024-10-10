#include <stdio.h>

/* Tabla hash resolvienco colisiones mediante
listas encadenadas*/


struct rep_grafica{
    int cantidad;
    int tamano;
    Lista* tabla; // es una tabla que contiene listas (que es una lista de puntos -> check)
    //int * elementos;
    //(nodoLista *)* tabla;
};

typedef rep_grafica* Grafica;



/* Devuelve una grá fica vacia que puede mantener hasta 'N'
asociaciones .
Precondición: N > 0. */
Grafica CrearGrafica(int N){
    Grafica nueva = new rep_grafica;
    nueva -> cantidad = 0;
    nueva -> tamano = N;
    nueva -> tabla= new Lista[N]; // tabla de listas
    // inicializo la tabla
    for (int i = 0; i < N; i++){
        nueva -> tabla[i] = crearLista();
        //nueva -> tabla[i] = NULL; // inicializo las listas como NULL
    }
    return nueva;
}



/* Si en 'g' hay menos de 'N' asociaciones , asigna 'y' como valor
asociado a 'x ';
en caso contrario la operaci ón no tiene efecto .
Precondición: x > 0 , y > 0 , Valor (x, g) == -1. */
void Asociar (int x , int y , Grafica & g){
    if (g->cantidad < g -> tamano){
        // encuentro el índice en la tabla (normalmente se hace con la función de hash)
        int pos = x % g->tamano;
        // si ya está edito sino inserto; no obstante valor(x, g) = -1 por lo que se de antemano que no está
        Punto pto = {x, y}
        Cons(pto, g->tabla[pos]); // agrega el punto a la tabla
        g->cantidad++;
    }
}



/* Si en 'g' existe asociación para 'x ', devuelve el valor
asociado a 'x ';
en otro caso devuelve -1.
Precondición: x > 0. */
int Valor (int x, Grafica g){
    // encuentro la posición
    int pos = x % g->tamano;
    // busco en la lista correspondiente; puedo hacerlo con ExisteX, pero por práctica recorreré la lista
    Lista aux = g->tabla[pos];
    // busco
    while (!esVaciaLista(aux) && Primero(aux).x!=x){
        aux = Resto(aux);
    }
    if (aux != NULL){
        return Primero(aux).y;
    }
    else {
        return -1;
    }
}


/* Elimina de 'g' la asociación para 'x ', si existe tal asociación
en caso contrario la operación no tiene efecto .
Precondición: x > 0. */
void Desasociar(int x , Grafica & g){
    int pos = x % g->tamano;
    if (ExisteX(x, g->tabla[pos])){ // si está desacio
        Remover(x, g->tabla[pos]);
        g->cantidad--;
    }
}