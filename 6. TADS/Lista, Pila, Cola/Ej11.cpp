/**/
#include <iostream>


Pila maximosRelativos(Pila p){
    Pila r=CrearPila();
    while (!esVacia(p)){
        int c = cima(p);
        desapilar(p);
        while(!esVacia(r) && cima(r)<=c){
            desapilar(r);
        }
        apilar(r,c);
    }
}