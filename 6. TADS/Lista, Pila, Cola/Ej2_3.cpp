#include <iostream>

// Definiciones generales
struct NodoQ {
    int dato;
    NodoQ* sig;
};

struct Cabecera {
    NodoQ* primero;
    NodoQ* ultimo;
    int max;
    int cant;
    int* datos;
    int primeroIdx;
    int ultimoIdx;
};

typedef Cabecera* QEnt;



QEnt crearCola(int max){
    QEnt q = new Cabecera;
    q -> max = max;
    q -> cant = 0;
    q->primeroIdx = 0;
    q->ultimoIdx = max - 1;
    q->datos = new int[max]; // arreglo que almacena los valores enteros de la cola
    return q;
}


bool estaLlenaCola(QEnt q){
    return q -> cant == q -> max; 
}

void encolar(int x, QEnt& q) {
    q->ultimoIdx = (q->ultimoIdx + 1) % q->max;
    q->datos[q->ultimoIdx] = x;
    q->cant++;
}

int primero(QEnt q){
    return q ->datos[q->primeroIdx];
}

void desencolar(QEnt &q){
    q->primeroIdx = (q->primeroIdx + 1) % q->max;
    q->cant--;
}


void eraseQ(QEnt &q){
    delete[] q -> datos;
    delete q;
}




