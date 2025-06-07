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

c) O tempo de execução cresce exponencialmente com o valor de n, como previsto por 
O(2 n).A execução se torna inviável rapidamente, evidenciando o alto custo computacional da recursão ingênua.
Isso justifica a necessidade de algoritmos otimizados (memoização, iterativos ou fórmula fechada)
para calcular Fibonacci em aplicações práticas.
*/
