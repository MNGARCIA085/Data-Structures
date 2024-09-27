
/*
Entrada:
    Pila p
    Cola c
Salida
    booleano que dice si tienen los mismos elementos insertados en el mismo orden

Pila aux; // contendrá los elementos de la cola
Mientras c no sea vacía:
    apilar en p el elemento de c
    desencolar c

Mientras p y aux no sean vacías y las cimas sean iguales
    desapilar p
    desapilar aux

si al final p y aux son ambas vacías retorno true, en otro caso false

liberar memoria


*/


bool mismosElementos (Pila &p , Cola &c){

    Pila aux = crearPila();

    // pila auxiliar para ir guardando los elementos de la cola
    while (!esVacia(c)){
        apilar(aux, frente(c));
        desencolar(c)
    }

    // comparo
    while (!esVacia(p) && !esVacia(aux) && cima(p) == cima(aux)){
        desapilar(p);
        desapilar(aux);
    }

    bool res = esVacia(p) && esVacia(paux);
    

    // liberar memoria
    while(!esVacia(p)){
        desapilar(p);
    }
    
    while(!esVacia(aux)){ //liberamos la memoria de la pila auxiliar 
        desapilar(aux);
    }

    // retorno
    return res;

}

