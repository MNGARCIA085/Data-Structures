/* Considere la siguiente representación de árboles binarios de búsqueda de enteros (ABB), con información
de la altura en cada nodo:*/

struct nodoABB{
    int dato;
    unsigned int altura; // altura del árbol que tiene al nodo como raíz
    nodoABB * izq, * der;
}


typedef nodoABB * ABB;

/* Notar que en estos árboles la altura puede calcularse en O(1) peor caso:*/

unsigned int altura (ABB t){
    if (t==NULL) return 0; else return t->altura;
}


/*
Adaptar la función vista en el curso que inserta un elemento x en un árbol binario de búsqueda t, de tal
manera que además de agregar x en t:
 -actualice el campo altura en los nodos en que corresponda, y
- asumiendo que t cumple la condición de AVL, devuelva true si y solo si el árbol sigue cumpliendo
esa condición después de la inserción. Notar que NO se pide balancear el árbol.*/

/*
La función insertar debe ser recursiva y no puede usar funciones ni procedimientos auxiliares, excepto la
función altura dada y operaciones entre enteros como max (que retorna el máximo entre dos enteros) y
abs (que retorna el valor absoluto de un entero), que se asumen implementadas.
*/

// pre: x no pertenece a t
bool insertar(ABB & t, int x){ // pasaje x referencia!!
    if (t == NULL){
        t = new nodoABB;
        t -> dato = x;
        t -> altura = 1;
        t -> izq = t -> der = NULL;
        return true;
    }
    else{
        bool res;
        if (x > t -> dato){
            res = insertar(t->der, x);
        }
        else {
            res = insertar(t->izq, x);
        }
        // la nueva altura es el máximo entre las alturas del derecho y el izquierdo + 1
        t->altura = max(altura(t->izq), altura(t->der)) + 1; // chequear!!
        // chequeo la condición
        // debe seguir siendo ABB (ya está por cómo lo hicimos) y la diferencia de alturas
        // entre izquierdo y derecho puede diferir a lo sumo en 1
        return res && (abs(altura(t->der) - altura(t->izq)) <= 1); 
    }
}