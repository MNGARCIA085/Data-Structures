/**/
#include <iostream>

bool esPalindromeConSeparador(Pila p){
    Pila aux=crearPila();
    while(!esVacia(p)&& cima(p)!="-") {
        char c=cima(p);
        apilar(c,aux);
        desapilar(p);
    }
    if (esVacia(p)){
        return false;
    }
    desapilar(p); // saco el separador
    while (!esVacia(p) && !esVacia(aux) && cima(p)==cima(aux)){
        desapilar(p);
        desapilar(aux);
    }
    bool res= esVacia(p) && esVacia(aux);
    liberar(p);
    liberar(aux);
    return res;
}