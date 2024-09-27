#ifndef NODOABB_H
#define NODOABB_H

#include <stdio.h>

typedef unsigned int uint;

struct nodoABB {
    uint elem;
    nodoABB* izq;  // Pointer to the left child
    nodoABB* der;  // Pointer to the right child
};

typedef nodoABB* ABB;

#endif // NODOABB_H
