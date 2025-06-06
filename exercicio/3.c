#include <stdio.h>

int inverterNumero(int n) {
    int invertido = 0;
    int negativo = 0;

    if (n < 0) {
        negativo = 1;
        n = -n; 
    }

    while (n > 0) {
        int digito = n % 10;
        invertido = invertido * 10 + digito;
        n /= 10;                
    }

    if (negativo) {
        invertido = -invertido;  
    }

    return invertido;
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    int resultado = inverterNumero(numero);
    printf("Número invertido: %d\n", resultado);

    return 0;
}
