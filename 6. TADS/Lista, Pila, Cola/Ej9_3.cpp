
/*
Para un árbol general
*/


void imprimirNiveles(ABB t){
    if (t!=NULL){
        Cola c = crearCola();
        encolar(c,t);
        
        while(!esVaciaCola(c)){
            t=frente(c);
            printf("% d", t->elem);
            
            
            t = t -> pH;
            while (t != NULL){
                encolar(c, t);
                t = t -> sH;
            }

            desencolar(c);
            
        }
        liberar(c);
    }
}


