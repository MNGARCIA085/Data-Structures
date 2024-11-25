/*Implemente el TAD Tabla anterior usando dispersión abierta (open hashing) como estructura de datos.
Desarrolle la representación del TAD (repTabla) y el código de las operaciones crear, insertar y minimo,
solamente. Asuma implementadas las otras operaciones del TAD y la existencia de una función de hash:
int h (int clave, int cota), que distribuye de manera uniforme las claves de tipo int sobre el rango [0:cota-1]. La
operación minimo debe tener O(1) peor caso.
*/

struct nodoHash{
    int dom;
    float img;
    nodoHash* sig;
};

struct repTabla{
    nodoHash** tabla;
    int cota; // tamaño de la tabla de hash; cantidad estimada de correspondencias
    int cantidad; // cantidad de correspondencias
    int min; // que mínimo sea O(1) 
}



int h(int clave, int cota){};


// PRE: cota > 0. POS: Devuelve la Tabla vacía, para la cual se estiman cota correspondencias.
Tabla crear (int cota){
    Tabla nueva = new repTabla;
    nueva -> tabla = new nodoHash*[cota];
    for (int i=0; i < cota; i++){
        nueva -> tabla[i] = NULL;
    }
    nueva -> cota = cota;
    nueva -> cantidad = 0;
    return nueva;
}
// no creamos el mínimo pues no está definido para una tabla vacía; se considera al insertar


// POS: Agrega la correspondencia (d,i) en t, si d no tenía imagen en t; en caso contrario, no se modifica t.
void insertar (int d, float i, Tabla & t){
    // si ya pertenece no modifico t
    if (pertenece(d, i)){
        return;
    }
    // obtengo la posición de inserción
    int pos = (d, t->cota);
    // nuevo nodo
    nodoHash* nuevo = new nodoHash;
    nuevo -> dom = d;
    nuevo -> img = i;
    // inserto al inicio de la lista
    nuevo -> sig = t -> tabla[pos];
    t -> tabla[pos] -> sig = nuevo;
    // actualizo la cantidad y el mínimo (si corresponde)
    t -> cantidad++;
    if (t-> cantidad==0  || d < t -> min){
        t -> min = d;
    }
}

// PRE: cantindad(t) > 0. POS: Retorna el mínimo valor del dominio presente en una correspondencia de t.
int minimo (Tabla t){
    return t-> min;
}