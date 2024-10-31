#define K=10

ColaImpresion crear();

void destruir(ColaImpresion &ci);

void insertar(string elem, unsigned int prio, ColaImpresion &ci);

/*precond: !esVacia(ci) */
string imprimir(ColaImpresion &ci);

bool esVacia(ColaImpresion &ci);
