#include <iostream>
#include <cstring>


// nota -> debería convertir todo a minúscula por ejemplo
bool es_palindrome(char *frase){
    int largo = strlen(frase);
    int i = 0;
    while ( (frase[i] == frase[largo - 1 - i]) && (i < largo/2) ){
        i++;
    }
    return i >= largo/2;
}

int main() {
    char frase[100];
    printf("Ingrese frase: ");
    scanf("%[^\n]", frase);
    if (es_palindrome(frase))
        printf("La frase es Palindrome\n");
    else
        printf("La frase NO es Palindrome\n");
    return 0;
}


// g++ 1.5.Palindrome.cpp -o palindrome