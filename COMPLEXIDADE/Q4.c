#include <stdio.h>
#include <time.h>

int x(int n) {
    if (n <= 1) return 1;
    return x(n - 1) + x(n - 2);
}

int main() {
    int n;              
    int N_Max = 1000;    
    double total_time = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos\n", total_time / N_Max);
    return 0;
}
/*
b) Tabela:
| n  | Tempo Médio (segundos) |
|----|------------------------| 
| 10 | 0.00001                |
| 20 | 0.001                  |
| 25 | 0.01                   |
| 30 | 0.12                   |
| 35 | 1.4                    |
| 40 | 15.8                   |
-------------------------------

c) A versão recursiva simples da sequência de Fibonacci faz muitas chamadas repetidas, pois para cada valor de n>1, a função chama a si mesma duas vezes. 
Isso gera uma árvore de chamadas que cresce de forma exponencial
, resultando em uma complexidade de tempo aproximada de O(2 n).
Em outras palavras, o número de chamadas de função dobra a cada incremento em n, tornando o algoritmo ineficiente para valores grandes.
*/
