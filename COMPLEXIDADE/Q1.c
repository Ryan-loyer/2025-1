/* O algoritmo apresentado calcula o tempo médio de execução de uma função recursiva x(n) 
para um valor fixo n0  , executando-a repetidamente até atingir um número máximo de repetições NMax.
A complexidade do processo é proporcional ao tempo de execução da função multiplicado por NMaxNMax.
Assim, o algoritmo mede empiricamente o desempenho médio da função, mas não determina sua complexidade teórica, que depende
  da própria definição recursiva de x(n)x(n). */
/*
Algorithm 1: Calculo da função ao recursiva x(n)
input: Algoritmo para x(n) avaliado para n = n₀
Output: Tempo medio do algoritmo x(n) para n = n₀, N_Max
N = 0;
T = 0;
if N ≤ N_Max then
    return T / N_Max
end
else
    N = N + 1;
    T = T + tempo_execucao(x(n₀));
    Execute Algoritmo para calcular x(n₀);
end
*/