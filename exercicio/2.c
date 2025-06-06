#include <stdio.h>


int potencia(int base, int expoente) {
    if (expoente < 0) {
      
        return 0;
    }
    if (expoente == 0) {
        return 1;
    }

    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

int main() {
    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    int resultado = potencia(base, expoente);
    printf("%d elevado a %d = %d\n", base, expoente, resultado);

    return 0;
}
