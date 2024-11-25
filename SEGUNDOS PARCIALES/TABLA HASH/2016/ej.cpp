/*Considere la siguiente especificación del TAD Tabla (funciones parciales) entre enteros (dominio) y strings
(codominio):*/

// Crea y devuelve una Tabla vacía
Tabla crearT();

// Asocia a d el valor s en t; si ya tenía un valor asociado, lo redefine
void insertarT(int d, string s, Tabla &t);

// Devuelve true si t esta vacía y false en caso contrario
bool esVaciaT(Tabla t);

/* Devuelve true si el elemento d tiene asociado un elemento en t y false en caso
contrario */
bool estaDefinidaEnT(int d, Tabla t);

/* Devuelve el elemento del codominio asociado a d en t
Pre: estaDefinidaEnT(d,t) */
string recuperarT(int d, Tabla t);

/* Modifica t de modo que d no tenga un elemento asociado.
Si !estaDefinidaEnT(d,t), la operación no tiene efecto */
void borrarT(int d, Tabla &t);

/*Proponga una implementación del TAD Tabla, sin usar TADs auxiliares y asumiendo que:
i) es igualmente probable que se desee asociar un valor a cualquier elemento del dominio y que
ii) la cantidad de asociaciones a almacenar en la tabla puede estimarse en un valor N.
Las operaciones selectoras y la operación de inserción deben tener O(1) de tiempo de ejecución en el caso
promedio. Defina el tipo en C* para la representación elegida del TAD y accediendo directamente a la
representación, desarrolle el código de las operaciones crearT y recuperarT*/

struct nodoHash{
    int dom;
    float img;
    nodoHash* sig;
}

struct repTabla{
    nodoHash** tabla;
}

typedef repTabla* Tabla;


// Crea y devuelve una Tabla vacía
Tabla crearT(){
    Tabla res = new repTabla;
    res -> tabla = new nodoHash*[N]; // N aquí sería una variable global
    for (int i = 0; i < N; i++){
        res -> tabla[i] = NULL;
    }
    return res;
}

/* Devuelve el elemento del codominio asociado a d en t
Pre: estaDefinidaEnT(d,t) */
string recuperarT(int d, Tabla t){
    int pos = d % N; // hash
    nodoHash* aux = Tabla[pos];
    while (aux != NULL && aux -> dom!= d){
        aux = aux -> sig;
    }
    // nota: no necesito chequear si lo encontró pues ya lo se por pre-cond.
    return aux -> img;
}


/*Usando las operaciones del TAD Tabla, definidas anteriormente, implemente la operación buscar que,
dado un string s y una lista ordenada en forma ascendente de enteros li, devuelve el mayor de los enteros al
cual le corresponde s.

Utilice la función strEq (que se asume implementada) para comparar strings; strEq retorna true si
y sólo si dos strings son iguales. También debe utilizar el TAD ListaEnt con las siguientes operaciones
básicas (asuma que están implementadas):

*/

ListaEnt vaciaLEnt();
ListaEnt insertarInicioLEnt(ListaEnt l, int x);
int obtenerPrimeroLEnt(ListaEnt l);
ListaEnt restoLEnt(ListaEnt l);
bool EsVaciaLEnt(ListaEnt l);



/* Dados un string s, una lista ordenada de forma ascendente de enteros li y
una Tabla t, devuelve el mayor de los enteros que tiene imagen s en t.
Pre: existe al menos un elemento d en li tal que estaDefinidaEnT(d,t) y el
resultado de recuperarT(d,t)es el string s */
int buscar(string s, ListaEnt li, Tabla t){

    // debo recorrer la lista e ir actualizando el máximo

    int candidato, resultado;
    while (!vaciaLEnt(li)){
        candidato = obtenerPrimeroLEnt(li);
        li = restoLEnt(li);
        if (estaDefinidaEnT(candidato, t) && strEq(recuperarT(candidato,t), s)){
            resultado = candidato;
        }
    };
    return resultado;
};