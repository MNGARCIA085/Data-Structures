#include <stdio.h>

struct nodoDir {
    char * nombre ;
    nodoDir *pH , * sH;
};
typedef nodoDir * Directorios;

/*Se quiere representar una estructura simplificada de directorios (carpetas) de un sistema operativo, donde
cada directorio tiene un nombre único que lo identfica. Cada directorio puede contener un número finito
de subdirectorios. No se contemplan archivos en esta versión simplficada del sistema.
Considere el tipo Directorios, definido como árboles generales de strings (char *) e implementado como
árboles binarios con la semántica primer hijo (pH) - siguiente hermano (sH):*/


/*Defina un procedimiento borrar que, dados un Directorios D sin elementos repetidos y el nombre
nom_dir de un directorio, elimine a nom_dir de D si nom_dir está en D y no tiene subdirectorios.
En caso contrario, el procedimiento no tendrá efecto. En particular, si D es el directorio vacío (NULL) el
procedimiento no tendrá efecto. Al eliminar un directorio deberá liberarse la memoria asociada a este.
Utilice la función strEq (que se asume implementada) para comparar strings; strEq retorna true si y
sólo si dos strings son iguales. No defina funciones o procedimientos auxiliares.*/


bool strEq(char* s1, char* s2);


void borrar(Directorios & D, char * nom_dir){
    if (D != NULL){
        if (strEq(D->nombre, nom_dir)){
            if (D -> pH == NULL){ // si esta vacío
                // borro
                Directorios aBorrar = D;
                D = D -> sH;
                delete[] aBorrar->nombre;
                delete aBorrar;
            }
        }
        else { // busco en el primer hijo y siguiente hermano
            borrar(D -> pH, nom_dir);
            borrar(D -> sH, nom_dir);

        }
    }
}