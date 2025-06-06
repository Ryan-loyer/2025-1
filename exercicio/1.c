#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int n) {
    if (n <= 1) return false; 
    if (n == 2) return true;  
    if (n % 2 == 0) return false; 

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int inicio, fim;

  
    printf("Digite o intervalo (inicio e fim): ");
    scanf("%d %d", &inicio, &fim);

    if (inicio > fim) {
        int temp = inicio;
        inicio = fim;
        fim = temp;
    }

    printf("Números primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
