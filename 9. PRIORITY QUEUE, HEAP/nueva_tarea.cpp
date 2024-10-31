#include <stdio.h>


struct tipo_h{
    int dato; // el dato es la prioridad; menor implica más prioridad; no hay 2 iguales
};

struct rep_cola_prio{
    int tope;
    int tamanio;
    tipo_h* arreglo;
};

typedef struct rep_cola_prio* TcolaPrio;

// crear una nueva cola
TcolaPrio crearCola(int N){
    TcolaPrio nueva = new rep_cola_prio;
    nueva -> tope = 0;
    nueva -> tamanio = N;
    nueva -> arreglo = new tipo_h[N+1]; // el 0 no lo usamos
    return nueva;
}


// filtrado Ascendente
void filtradoAscendente(tipo_h* arreglo, int pos) {
    while ((pos > 1) && (arreglo[pos / 2].dato > arreglo[pos].dato)) {
        tipo_h aux = arreglo[pos];
        arreglo[pos] = arreglo[pos / 2];
        arreglo[pos / 2] = aux;
        pos /= 2;
    }
}

// encolar 
void encolar(TcolaPrio& colaPrio, int dato) {
    if (colaPrio->tope < colaPrio->tamanio) {
        tipo_h nuevo;
        nuevo.dato = dato;
        colaPrio->tope++;
        colaPrio->arreglo[colaPrio->tope] = nuevo;
        filtradoAscendente(colaPrio->arreglo, colaPrio->tope);
    }
}



// filtrado descendente
void filtradoDescendente(tipo_h* arreglo, int n, int pos){
   while (2*pos<=n){
       int pos_hijo = 2*pos;
       if ( (pos_hijo+1 <= n) && (arreglo[pos_hijo].dato > arreglo[pos_hijo+1].dato)){
           pos_hijo = pos_hijo + 1;
       }
       if (arreglo[pos_hijo].dato < arreglo[pos].dato){
           tipo_h aux = arreglo[pos_hijo];
           arreglo[pos_hijo] = arreglo[pos];
           arreglo[pos] = aux;
           pos = pos_hijo;
       }
   }
}


// desencolar
int desencolar(TcolaPrio &colaPrio){
    int aux = 0;
    if (colaPrio -> tope > 0){
        aux = colaPrio -> arreglo[1].dato;
        colaPrio -> arreglo[1] = colaPrio -> arreglo[colaPrio -> tope];
        colaPrio->tope--;
        if (colaPrio -> tope > 0){
            filtradoDescendente(colaPrio->arreglo, colaPrio->tope, 1);
        }
    }
    return aux;
}




// liberar memoria
void liberar(TcolaPrio &colaPrio) {
    if (colaPrio != NULL){
        delete[] colaPrio->arreglo;
        colaPrio -> arreglo = NULL;
        delete colaPrio;
        colaPrio = NULL;
    }
}

// imprimir (imprime el arreglo linealmente)
void imprimir(TcolaPrio colaPrio) {
    if (colaPrio != NULL){
        for (int i = 1; i <= colaPrio -> tope; i++){
            printf("%d ", colaPrio -> arreglo[i].dato);           
        }
    }
    printf("\n"); 
}




// imprimir el heap (que en realidad es un árbol) por niveles
void imprimirHeapPorNiveles(TcolaPrio colaPrio) {
    if (colaPrio == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    
    int nivel = 0;
    int elementosEnNivel = 1; // Cantidad de elementos en el nivel actual
    int cont = 0; // Contador de elementos impresos

    printf("Heap por niveles:\n");
    for (int i = 1; i <= colaPrio->tope; i++) {
        printf("%d ", colaPrio->arreglo[i].dato);
        cont++;

        // Si hemos impreso todos los elementos de este nivel
        if (cont == elementosEnNivel) {
            printf("\n"); // Salto de línea para el siguiente nivel
            nivel++;
            elementosEnNivel = 1 << nivel; // 2^nivel (número de elementos en el siguiente nivel)
            cont = 0; // Reiniciar contador
        }
    }
    printf("\n");
}



// Función para invertir la prioridad en el heap
void invertirPrioridad(TcolaPrio colaPrio) {
    if (colaPrio == NULL) {
        printf("La cola está vacía.\n");
        return;
    }

    for (int i = 1; i <= colaPrio->tope; i++) {
        colaPrio->arreglo[i].dato = -colaPrio->arreglo[i].dato; // Invertir la prioridad
    }

    // Reajustar el heap para mantener la propiedad del heap
    for (int i = colaPrio->tope / 2; i >= 1; i--) {
        filtradoDescendente(colaPrio->arreglo, colaPrio->tope, i);
    }
}



// main
int main() {
    int tamanio = 5;
    TcolaPrio cola = crearCola(tamanio);

    // Encolar elementos
    printf("Encolando elementos:\n");
    encolar(cola, 10);
    encolar(cola, 5);
    encolar(cola, 20);
    encolar(cola, 1);
    encolar(cola, 15);
    
    // Imprimir cola después de encolar
    printf("Cola después de encolar: ");
    imprimir(cola);

    imprimirHeapPorNiveles(cola);

    // invierto la prioridad
    invertirPrioridad(cola);
    imprimirHeapPorNiveles(cola);

    // Desencolar elementos y mostrar el estado de la cola
    printf("Desencolando elementos:\n");
    printf("Elemento desencolado: %d\n", desencolar(cola));
    printf("Elemento desencolado: %d\n", desencolar(cola));

    // Imprimir cola después de desencolar
    printf("Cola después de desencolar: ");
    imprimir(cola);

    // Liberar memoria
    liberar(cola);

    return 0;
}


// g++ nueva_tarea.cpp -o aux