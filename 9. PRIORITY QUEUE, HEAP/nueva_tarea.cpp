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
void filtradoDescendente2(tipo_h* arreglo, int n, int pos){
   while (2*pos<=n){
       int pos_hijo = 2*pos;
       if ( pos_hijo+1 <= n && arreglo[pos_hijo].dato > arreglo[pos_hijo+1].dato){
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


void filtradoDescendente(tipo_h* arreglo, int n, int pos) {
    while (2 * pos <= n) {
        int pos_hijo = 2 * pos;
        if (pos_hijo + 1 <= n && arreglo[pos_hijo].dato > arreglo[pos_hijo + 1].dato) {
            pos_hijo++;
        }

        // Imprimir los valores antes del intercambio
        printf("Antes del intercambio: pos = %d, pos_hijo = %d, arreglo[pos] = %d, arreglo[pos_hijo] = %d\n",
               pos, pos_hijo, arreglo[pos].dato, arreglo[pos_hijo].dato);

        if (arreglo[pos].dato > arreglo[pos_hijo].dato) {
            tipo_h aux = arreglo[pos];
            arreglo[pos] = arreglo[pos_hijo];
            arreglo[pos_hijo] = aux;
            pos = pos_hijo;

            // Imprimir los valores después del intercambio
            printf("Después del intercambio: pos = %d, arreglo[pos] = %d\n", pos, arreglo[pos].dato);
        } else {
            break;
        }
    }
}



// desencolar
int desencolar(TcolaPrio &colaPrio) {
    int aux = 0;
    if (colaPrio->tope > 0) {
        aux = colaPrio->arreglo[1].dato;  // Guardar el dato con mayor prioridad
        colaPrio->arreglo[1] = colaPrio->arreglo[colaPrio->tope];  // Mover el último al tope
        colaPrio->tope--;  // Reducir el tope

        // Llamar a filtrado descendente si hay elementos restantes
        if (colaPrio->tope > 0) {
            printf("Antes de filtradoDescendente: tope = %d, arreglo[1] = %d\n", colaPrio->tope, colaPrio->arreglo[1].dato);
            filtradoDescendente(colaPrio->arreglo, colaPrio->tope, 1);
            printf("Después de filtradoDescendente: tope = %d, arreglo[1] = %d\n", colaPrio->tope, colaPrio->arreglo[1].dato);

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


// imprime el heap por niveles (recuerdo que el heap es un árbol)
void imprimirCola(TcolaPrio colaPrio) {
    if (colaPrio == NULL || colaPrio->tope == 0) {
        printf("\n");
        return;
    }

    int nivel = 1;             // Nivel actual
    int elementosEnNivel = 1;   // Cantidad de elementos en el nivel actual
    int cont = 0;               // Contador de elementos impresos en el nivel actual
    int num_envio = 1;          // Contador de número de envíos

    // Imprimir el primer nivel
    printf("\nNivel %d\n", nivel);

    for (int i = 1; i <= colaPrio->tope; i++) {
        // Imprimir el número de envío
        printf("%d) ", num_envio);
        //imprimirTEnvio(colaEnvios->arreglo[i].envio);
        printf("%d \n", colaPrio -> arreglo[i].dato);
        num_envio++;
        cont++;

        // Verificar si se han impreso todos los elementos del nivel actual
        if (cont == elementosEnNivel) {
            // Pasar al siguiente nivel solo si quedan más elementos por imprimir
            if (i < colaPrio->tope) {
                printf("\n"); // Salto de línea para el siguiente nivel
                nivel++;
                printf("Nivel %d\n", nivel);
                
                elementosEnNivel = 1 << (nivel - 1); // Cantidad de elementos en el siguiente nivel
                cont = 0;                            // Reiniciar contador para el nuevo nivel

            }
        }
    }
    printf("\n"); // Salto de línea final
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
    int tamanio = 6;
    TcolaPrio cola = crearCola(tamanio);

    // Encolar elementos
    printf("Encolando elementos:\n");
    encolar(cola, 10);
    encolar(cola, 5);
    encolar(cola, 20);
    encolar(cola, 1);
    encolar(cola, 15);
    encolar(cola, 17);
    
    // Imprimir cola después de encolar
    printf("Cola después de encolar: ");
    imprimir(cola);

    imprimirCola(cola);

    // invierto la prioridad
    //invertirPrioridad(cola);
    //imprimirCola(cola);

    // Desencolar elementos y mostrar el estado de la cola
    printf("\nDesencolando elementos:\n");
    printf("Elemento desencolado: %d\n", desencolar(cola));
    printf("Elemento desencolado: %d\n", desencolar(cola));

    // Imprimir cola después de desencolar
    printf("Cola después de desencolar: ");
    imprimir(cola);
    imprimirCola(cola);

    // Liberar memoria
    liberar(cola);

    return 0;
}


// g++ nueva_tarea.cpp -o aux