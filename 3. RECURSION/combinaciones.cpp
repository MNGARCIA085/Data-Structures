#include <stdio.h>

typedef unsigned int uint;

int combinaciones(uint m, uint n){
    if ( (m == n) || (n==0)){
        return 1;
    }
    else if (n==1){
        return m;
    }
    else{
        return combinaciones(m-1, n) + combinaciones(m-1, n-1);
    }
}


int main() {
    uint m = 5;
    uint n = 3;
    printf("C(%u, %u) = %d\n", m, n, combinaciones(m, n));
    return 0;
}

// g++ combinaciones.cpp -o combinaciones

