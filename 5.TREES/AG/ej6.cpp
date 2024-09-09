#include <stdio.h>

struct nodoAG {
    int dato;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG;

/*
Dado un árbol general (pH-sH) y un entero no
negativo k, retorna una copia del árbol, sin
compartir memoria, hasta el nivel k inclusive.
*/
AG copiaParcial(unsigned int k, AG t){
    if (k == 0 || t == NULL){
        return NULL;
    }
    else {
        AG nuevo = new nodoAG;
        nuevo -> dato = t -> dato;
        nuevo -> pH = copiaParcial(k-1, t -> pH); // bajo un nivel
        nuevo -> sH = copiaParcial(k, t -> sH); // acá no bajo un nivel!!
        return nuevo;
    }
}


// Fnes. auxiliares
// Function to create a new tree node
AG createNode(int value) {
    AG node = new nodoAG;
    node->dato = value;
    node->pH = NULL;
    node->sH = NULL;
    return node;
}

// Function to print tree in pre-order with indentation
void printTree(AG t, int level = 0) {
    if (t != NULL) {
        // Print the node value with indentation
        printf("%*s%d\n", level * 2, "", t->dato);
        
        // Recursively print the children
        printTree(t->pH, level + 1);
        
        // Recursively print the siblings
        printTree(t->sH, level);
    }
}

// liberar memoria
void liberarMemoria(AG &t){
    if (t==NULL){
        return;
    }
    liberarMemoria(t -> pH);
    liberarMemoria(t -> sH);

    delete t;
    t = NULL;
}


// Main function to test copiaParcial
int main() {
    // Create a sample tree
    AG root = createNode(1);
    root->pH = createNode(2);
    root->sH = createNode(3);
    root->pH->pH = createNode(4);
    root->pH->sH = createNode(5);
    root->sH->pH = createNode(6);
    root->sH->sH = createNode(7);
    root->pH->pH->pH = createNode(8);

    printf("Original Tree:\n");
    printTree(root);

    unsigned int k = 2; // Adjust this value to test different depths
    AG copiedTree = copiaParcial(k, root);

    printf("\nCopied Tree with k = %d:\n", k);
    printTree(copiedTree);

    // Clean up memory (important for real applications)
    liberarMemoria(root);
    liberarMemoria(copiedTree);

    return 0;
}

// g++ ej6.cpp -o ej6