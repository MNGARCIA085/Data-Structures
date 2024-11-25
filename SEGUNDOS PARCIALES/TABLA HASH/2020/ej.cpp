/* Considere la siguiente especificación del TAD Tabla no acotada de int (dominio) en float (codominio):*/

struct RepresentacionTabla;
typedef RepresentacionTabla* Tabla;

/* 
Devuelve la Tabla vacía no acotada, donde `cant` es una estimación de la 
cantidad de correspondencias a almacenar.
*/
Tabla crearTabla(int cant);

/*
Agrega la correspondencia (d, c) en `t`, si `d` no tenía imagen en `t`. 
En caso contrario, actualiza la imagen de `d` con `c`.
*/
void insertarTabla(int d, float c, Tabla& t);

/*
Devuelve `true` si y solo si `d` tiene imagen en `t`.
*/
bool estaDefinidaTabla(int d, Tabla t);

/*
Retorna la imagen de `d` en `t`.
Precondición: `estaDefinidaTabla(d, t)` debe ser `true`.
*/
float recuperarTabla(int d, Tabla t);

/*
Elimina de `t` la correspondencia que involucra a `d`, si `d` está definida en `t`. 
En otro caso, la operación no tiene efecto.
*/
void eliminarTabla(int d, Tabla& t);


/*
Implemente el TAD Tabla anterior utilizando dispersión abierta (con listas de nodos encadenados) co-
mo estructura de datos. Defina el tipo de dato RepresentacionTabla e implemente las operaciones
crearTabla e insertarTabla. Omita el código del resto de las operaciones del TAD, que puede asumir
implementadas. Considere como función de hash la que realiza la operación módulo entre el valor del
dominio y el tamaño de la tabla.
*/


struct nodoHash{
    int dom;
    float img;
    nodoHash* sig;
}

struct repTabla{
    nodoHash** tabla;
    int cota;
}




/* 
Devuelve la Tabla vacía no acotada, donde `cant` es una estimación de la 
cantidad de correspondencias a almacenar.
*/
Tabla crearTabla(int cant){
    Tabla res = new repTabla;
    res -> cota = cant;
    res -> tabla = new nodoHash*[cant];
    for (int i = 0; i < cant; i++){
        res->tabla[i] = NULL;
    }
    return res;
}



/*
Agrega la correspondencia (d, c) en `t`, si `d` no tenía imagen en `t`. 
En caso contrario, actualiza la imagen de `d` con `c`.
*/
void insertarTabla(int d, float c, Tabla& t){
    int pos = d % t -> cota; // fn. de hash
    // debo insertar solamente si no estaba ya!!; sino edito
    nodoHash* aux = t -> tabla[pos];

    while (aux != NULL && aux -> dom == d){
        aux = aux -> sig;
    }

    // si aux es NULL no estaba -> inserto (al inicio por ejemplo)
    if (aux == NULL){
        nodoHash* nuevo = new nodoHash;
        nuevo -> dom = d;
        nuevo -> img = i;
        nuevo -> sig = tabla[pos];
        tabla[pos] = nuevo;
    }
    else {
        // edito
        aux -> img = i;
    }

}