#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPalindromo(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
    
        while (inicio < fim && !isalnum(str[inicio])) inicio++;
        while (inicio < fim && !isalnum(str[fim])) fim--;

        if (tolower(str[inicio]) != tolower(str[fim]))
            return 0;

        inicio++;
        fim--;
    }
    return 1; 
}

int main() {
    char texto[100];
    printf("Digite uma palavra ou frase: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0; 

    if (ehPalindromo(texto))
        printf("\"%s\" é um palíndromo.\n", texto);
    else
        printf("\"%s\" não é um palíndromo.\n", texto);

    return 0;
}
