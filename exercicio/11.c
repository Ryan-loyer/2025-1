#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == chave)
            return meio;
        else if (vetor[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int chave;

    printf("Digite o número a buscar: ");
    scanf("%d", &chave);

    int resultado = buscaBinaria(vetor, n, chave);
    if (resultado != -1)
        printf("Elemento %d encontrado no índice %d.\n", chave, resultado);
    else
        printf("Elemento %d não encontrado.\n", chave);

    return 0;
}
