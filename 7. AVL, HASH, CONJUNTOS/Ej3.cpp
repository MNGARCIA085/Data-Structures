

/*Sabiendo que los elementos que puede contener un Conjunto están en el rango [1,n], desarrolle una im-
plementación completa del TAD Conjunto acotado de naturales usando una estructura de memoria estática, 
de tal manera que el tiempo de ejecución de las operaciones de unión, intersección y diferencia sea O(n) en el peor caso*/

/*TAD Conjunto acotado*/


struct rep_conjunto{
    bool* arreglo;
    int cota;
    int cantidad;
};

typedef rep_conjunto* Conjunto;



// Crea un Conjunto vacío de tamano n
Conjunto crearConjunto(int n){
    Conjunto nuevo = new rep_conjunto;
    nuevo -> cota = n;
    nuevo -> cantidad = 0;
    nuevo-> arreglo= new bool[n];
    for (int i = 0; i < n; i++){
        nuevo -> arreglo[i] = false;
    }
    return nuevo;
}

// Devuelve true si solo si el Conjunto esta lleno, en otro caso devuelve false
bool llenoConjunto(Conjunto c){
    return c->cantidad == c -> cota;
}

//Incluye un elemento x en un conjunto c
//PRE: el elemento x no pertenece al conjunto c 
//PRE: el conjunto no esta lleno (no es necesaria esta pre porque si no pertenece el elemento es que hay al menos un lugar)
void insertarConjunto(int x, Conjunto &c){
    if (x >= 0 && x < c->cota) {  // Ensure x is in range
        if (!c->arreglo[x]) {       // Only insert if not already present (although is a pre-condition)
            c->arreglo[x] = true;
            c->cantidad++;
        }
    }
}

// Devuelve true si solo si un Conjunto es vacío, en otro caso devuelve false
bool esVacioConjunto(Conjunto c){
    return c->cantidad == 0;
}

//Excluye un elemento x de un conjunto c
//PRE: el elemento x pertenece al conjunto c
void excluirConjunto(int x, Conjunto &c){
    if (x >=0 && x < c->cota){
        c -> arreglo[x] = false;
        c -> cantidad--;
    }
}

//Devuelve true si el elemento x pertenece al conjunto c
bool perteneceConjunto(int x, Conjunto c){
    if (x >=1 && x <= c->cota){
        return c -> arreglo[x];
    }
    else {
        return false;
    }
}

//Recibe dos conjuntos c1 y c2 y retorna la uniendo de ambos
Conjunto unionConjuntos(Conjunto c1, Conjunto c2) {
    // Determine the maximum cota between the two sets
    int max_cota = (c1->cota > c2->cota) ? c1->cota : c2->cota;

    // Create a new set with the maximum cota
    Conjunto nuevo = crearConjunto(max_cota);
    
    // Perform the union operation
    for (int i = 0; i < max_cota; i++) {
        bool val_c1 = (i < c1->cota) ? c1->arreglo[i] : false; // Handle out-of-bounds for c1
        bool val_c2 = (i < c2->cota) ? c2->arreglo[i] : false; // Handle out-of-bounds for c2
        nuevo->arreglo[i] = val_c1 || val_c2;

        // Update the count if the new element is in the union
        if (nuevo->arreglo[i]) {
            nuevo->cantidad++;
        }
    }
    return nuevo;
}

//Recibe dos conjuntos c1 y c2 y retorna la interseccion de ambos
Conjunto interseccionConjuntos(Conjunto c1, Conjunto c2) {
    // Determine the maximum cota between the two sets
    int max_cota = (c1->cota > c2->cota) ? c1->cota : c2->cota;

    // Create a new set with the maximum cota
    Conjunto nuevo = crearConjunto(max_cota);
    
    // Perform the intersection operation
    for (int i = 0; i < max_cota; i++) {
        bool val_c1 = (i < c1->cota) ? c1->arreglo[i] : false; // Handle out-of-bounds for c1
        bool val_c2 = (i < c2->cota) ? c2->arreglo[i] : false; // Handle out-of-bounds for c2
        nuevo->arreglo[i] = val_c1 && val_c2;  // Logical AND for intersection

        // Update the count if the element is in the intersection
        if (nuevo->arreglo[i]) {
            nuevo->cantidad++;
        }
    }
    return nuevo;
}


//Recibe dos conjuntos c1 y c2 y retorna la diferencia de ambos
Conjunto diferenciaConjuntos(Conjunto c1, Conjunto c2) {
    // Determine the maximum cota between the two sets
    int max_cota = (c1->cota > c2->cota) ? c1->cota : c2->cota;

    // Create a new set with the same cota as c1
    Conjunto nuevo = crearConjunto(c1->cota);
    
    // Perform the difference operation (c1 - c2)
    for (int i = 0; i < c1->cota; i++) {
        bool val_c1 = c1->arreglo[i];                // Value in c1, here i dont have to loop throgh c2
        bool val_c2 = (i < c2->cota) ? c2->arreglo[i] : false; // Value in c2, false if out-of-bounds

        // Element is in c1 but not in c2
        nuevo->arreglo[i] = val_c1 && !val_c2;

        // Update the count if the element is in the difference
        if (nuevo->arreglo[i]) {
            nuevo->cantidad++;
        }
    }
    return nuevo;
}


void destruir (Conjunto &c){
    delete [] c->arreglo;
    delete c;
}