#include <stdio.h>
#include <time.h>
#include <math.h>

long long fibonacci_binet(int n) {
    const double sqrt5 = sqrt(5.0);
    const double phi = (1.0 + sqrt5) / 2.0;
    const double psi = (1.0 - sqrt5) / 2.0;

    double result = (pow(phi, n) - pow(psi, n)) / sqrt5;

    return (long long)(result + 0.5); // Arredondamento correto
}

int main() {
    int n;
    int N_Max = 1000;
    double total_time = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        fibonacci_binet(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos\n", total_time / N_Max);
    return 0;
}
