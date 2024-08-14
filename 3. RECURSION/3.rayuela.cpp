#include <stdio.h>

/*
Al principio del juego los niños se ubican en el adoquín 0.
De un adoquín numerado i se puede saltar al adoquín numerado i + 1.
De un adoquín numerado i se puede saltar al adoquín numerado i + 2 (sin pasar por el adoquín i + 1).

Para ir al 0 -> cant=1
Para ir al 1 -> cant=1 (0,1)
Para ir al 2 -> cant=2 (0,1,2)     (0,2)
Para ir al 3 -> cant=3 (0,1,2,3)   (0,2,3)    (0,1,3)
Para ir al 4-> cant=5  (0,1,2,3,4) (0,2,3,4)  (0,1,3,4)  (0,2,4) (0,1,2,4)

Para llegar a n sumo los caminos posibles para llegar a n-1 y los caminos posibles para llegar a n-2
con n>1 -> Fibonacci
*/


typedef unsigned int uint;

int rayuela(uint n){
    // caso base
    if ( (n==0) || (n==1)){
        return 1;
    }
    else {
        return rayuela(n-1) + rayuela(n-2);
    }
}


int main()
{
    for (int i=1; i<=10; i++){
        printf("El numero de caminos posibles es %d para n = %d \n", rayuela(i),i);
    }
    return 0;
}

// g++ 3.rayuela.cpp -o rayuela