#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

int main() {
    int n;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    Aluno alunos[n];

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        getchar();
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0; // remove \n

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Média: ");
        scanf("%f", &alunos[i].media);
    }

    printf("\nAlunos aprovados (média >= 7.0):\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i].media >= 7.0) {
            printf("Nome: %s, Matrícula: %d, Média: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
        }
    }

    return 0;
}
