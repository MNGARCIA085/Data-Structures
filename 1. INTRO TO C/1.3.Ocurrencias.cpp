#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ocurrencias(char frase[], int largo, char letra){
    int cantidad =  0;
    char letra_upper = toupper(letra);
    for (int i = 0; i < largo; i++){
        if ( toupper(frase[i]) == letra_upper){
            cantidad++;
        }
    }
    return cantidad;
}


int main(){
    char frase[100] = "Vamos con todo";
    int largo = 14; // largo de la frase anterior

    char letra = 'o';

    int cant = ocurrencias(frase, largo, letra);

    printf("La cantidad de ocurrencias de la letra %c en la frase es %d\n", letra, cant);

}


// g++ 1.3.Ocurrencias.cpp -o ocurrencias