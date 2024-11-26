/* Describa brevemente las propiedades de Estructura y de Orden que debe cumplir un árbol binario de enteros, 
que admite elementos repetidos, para ser un heap*/

/*

- Propiedad de estructura : Un heap es un árbol binario completamente lleno, con la posible excepción
del nivel más bajo, el cual se llena de izquierda a derecha. Notar que se puede representar como un
arreglo donde para cualquier elemento en la posición i del arreglo, el hijo izquierdo está en la posición
2*i, el hijo derecho en la posición siguiente: 2*i+1 y el padre está en la posición parte_entera_baja(i / 2).

- Propiedad de orden: Para todo nodo X, la clave en el padre de X es: menor (o menor o igual) que la
clave en X, con la excepción obvia de la raíz (donde esta el mínimo elemento).

*/


/*Implemente una función iterativa esHeap que, dado un arreglo de enteros con tope que representa a un árbol
binario (que puede tener elementos repetidos), devuelva true si y solo si el arreglo cumple la propiedad
de Orden. En particular, si el arreglo no tiene elementos el resultado deberá ser true. Considere que en un
arreglo con tope no vacío, los elementos están entre las posiciones 1 y tope del arreglo. Asimismo, asuma
que el tope del arreglo es menor que el tamaño (tam) del arreglo. 
El tiempo de ejecución en el peor caso de
la función debe ser O(n), siendo n la cantidad de elementos en el arreglo.*/

struct cabezalArrayTope {
    int * arreglo; // arreglo
    int tope; // tope del arreglo
    int tam; // tamaño del arreglo
};
typedef cabezalArrayTope * ArrayTope;


bool esHeap(ArrayTope a){
    // chequeo que cada padre tenga mayor prioridad (menor valor) que sus hijos
    bool condicion = true;
    int indice = 1; // el heap arranca en 1
    // recorro
    while (2*indice <= a->arreglo->tope && condicion){ // recorro hasta el último padre válido; que haya un hijo izquierdo
        if (a->arreglo[indice] > a->arreglo[2*indice] || 
                (2*indice+1 <= a->tope && a->arreglo[indice] > a->arreglo[2*indice+1]){
            condicion = false;
        }
        indice++;
    }

    return condicion;

}

/*
La condición while (2*indice <= a->arreglo->tope) garantiza que solo se recorran los nodos que tienen al menos un hijo válido 
dentro del arreglo. Al multiplicar el índice actual por 2, obtenemos el índice del hijo izquierdo. 
Si este índice supera el tope del arreglo, significa que el nodo actual no tiene hijos válidos y, por lo tanto, 
no es necesario seguir recorriendo el árbol hacia abajo.

Volviendo al ejemplo:

En el heap de 7 elementos:

      1
     / \
    2   3
   / \ / \
  4  5 6  7

Iteración 1: indice = 1, se verifica el nodo 1.
Iteración 2: indice = 2, se verifica el nodo 2.
Iteración 3: indice = 3, se verifica el nodo 3. (Última iteración)
En la iteración 4, 2*indice = 8, lo cual supera el tope (7), por lo que el bucle se detiene correctamente.

-> puedo ver que verifiqué todos los padres: 1,2 y 3.





*/