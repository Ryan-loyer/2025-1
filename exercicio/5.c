#include <stdio.h>
#include <stdbool.h>

int main() {
    int vet1[5], vet2[8];
    int intersecao[5];
    int k = 0;
    bool jaAdicionado[5] = {false};

    printf("Digite 5 números do primeiro vetor:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vet1[i]);
    }

    printf("Digite 8 números do segundo vetor:\n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &vet2[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (vet1[i] == vet2[j]) {
                
                bool repetido = false;
                for (int x = 0; x < k; x++) {
                    if (intersecao[x] == vet1[i]) {
                        repetido = true;
                        break;
                    }
                }
                if (!repetido) {
                    intersecao[k++] = vet1[i];
                }
                break;
            }
        }
    }

    printf("Elementos comuns entre os vetores:\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", intersecao[i]);
    }
    printf("\n");

    return 0;
}
