/* Una empresa desea administrar su stock de productos. Los productos son identificados por un entero no negativo,
de tipo unsigned int, y poseen un precio, de tipo float. Cada producto en el stock puede contener varias unidades.
Por ejemplo, del producto 9, cuyo precio es 7.50, hay 20 unidades; del producto 2871, cuyo precio es 9.99, hay 43
unidades; etc. Para administrar el stock se define el TAD Stock que contiene, entre otras, las siguientes
operaciones:

- Stock crear (int cantidadEsperada), que crea un stock vacío para el cual se estiman hasta
cantidadEsperada de productos diferentes.

- void insertar (Stock & s, unsigned int id, float precio, int cant), que incorpora cant unidades del
producto con identificador id, cuyo valor por unidad es precio, al stock s. Si id ya estaba en s, suma a las
unidades existentes el valor cant y reemplaza su valor (por unidad) con precio. Se asume como precondición
que la cantidad de productos diferentes en s es menor a la cantidad esperada, definida cuando se creó s.

- int unidades (Stock s, unsigned int id), que retorna la cantidad de unidades del producto con
identificador id en el stock s (0 si id no está en s).

- void listado (Stock s), que imprime los productos del stock s ordenados de menor a mayor según su
identificador (id). Asuma que existe un procedimiento “void imprimirProducto (unsigned int id)” que
imprime la información del producto identificado con id.

- int cantidad (Stock s), que retorna la cantidad de productos diferentes del stock s (0 si s está vacío).
*/

/* Defina una representación del TAD Stock (llamada representacionStock), de tal manera que:

- la operación cantidad sea O(1) peor caso, 
- insertar sea O(log(n)) peor caso
- listado sea O(n) peor caso, 

donde n es la cantidad de productos diferentes en s y asumiendo que
imprimirProducto es O(1) peor caso; b-2) justifique brevemente por qué la representación elegida cumple los
órdenes exigidos; y b-3) implemente la operación listado, solamente.
*/


/* con árboles AVL para que el insertar sea O(log(n)) */

struct nodoAVL{
    unsigned int id; // id de producto
    int cantUnidades; // cantidad de unidades de ese producto
    int altura; // altura del árbol con este nodo como raíz
    float precio;
    nodoAVL* izq, der;
}

struct repStock{
    nodoAVL* arbol;
    int cantidad; // que cantidad sea O(1), cant. es la cantidad de productos diferentes en el stock
    int cantEsperada; // cantidad esperada de prods. diferentes
}

typedef repStock* Stock;

// imprimir
void listado(Stock s){
    imprimirArbol(s->arbol);
}

void imprimirArbol(nodoAVL* arbol){
    if (arbol != NULL){
        imprimirArbol(arbol -> izq);
        imprimirProducto(arbol -> id);
        imprimirArbol(arbol -> der);
    }

}
