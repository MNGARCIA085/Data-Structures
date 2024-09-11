#include <stdio.h>

struct nodoAG {
    int dato;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG;

/* Contar nodos */
int cantNodos(AG t){
    if (t == NULL){
        return 0;
    }
    return 1 + cantNodos(t -> pH) + cantNodos(t -> sH);
}
/*si se invoca a nodos con un bosque t (t->sH!=NULL),
se tiene la cantidad de nodos del bosque*/



/* Altura */
int altura(AG t){
    if (t == NULL){
        return 0;
    }

    int altPH = altura(t -> pH);
    int altSH = altura(t -> sH);
    if (1 + altPH > altSH){
        return 1 + altPH;
    }
    else {
        return altSH;
    }
}
/*Si se invoca a la función altura con un bosque t
(t->sH!=NULL), se tiene la altura del bosque*/


/* Altura de un sub-árbol */
int alturaSubArbol(AG t){
    if (t == NULL){
        return 0;
    }
    return 1 + altura(t -> pH);
}


/*Imprime los elementos en el nivel k de un
árbol general, asumiendo que la raíz de un
árbol general no vacío está en el nivel 1
(recordar que la raíz no tiene hermanos)*/
void imprimirK(AG t, int k){
    if (t != NULL && k == 0){
        if (k == 1){
            // imprimo
            printf("%d ", t -> dato);
        }
        else {
            imprimirK(t -> pH, k-1); // bajo un nivel
            imprimirK(t -> sH, k); // acá no debo bajar
        }
    }
}



/*Dados un árbol general (pH-sH) y un elemento,
retorna un puntero al nodo del árbol que tiene
dicho elemento o NULL si no está. Asumimos que
el árbol no tiene repetidos*/
AG buscar(int x, AG t){
    if (t == NULL){
        return NULL;
    }
    if (t -> dato == x){
        return t;
    }
    else {
        AG estaSH = buscar(x, t -> sH); // busco en el siguiente hermano
        if (estaSH != NULL){
            return estaSH;
        }
        else {
            return buscar(x, t -> pH); // si no estaba en el siguiente hermano busco en el primer hijo
        }
    }
}