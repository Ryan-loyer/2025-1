#include <stdio.h>
#include <stdbool.h>

int main() {
    int numeros[10];
    int frequencia[10] = {0};
    bool jaContado[10] = {false};

    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < 10; i++) {
        int count = 1;
        for (int j = i + 1; j < 10; j++) {
            if (numeros[i] == numeros[j]) {
                count++;
            }
        }
        frequencia[i] = count;
    }

    printf("\nFrequência dos números digitados:\n");
    for (int i = 0; i < 10; i++) {
        if (!jaContado[i]) {
            printf("Número %d aparece %d vez(es)\n", numeros[i], frequencia[i]);

            for (int j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    jaContado[j] = true;
                }
            }
        }
    }

    return 0;
}
