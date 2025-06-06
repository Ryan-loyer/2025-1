#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

Aluno* criarAluno(char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->nota = nota;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

Aluno* inserir(Aluno* raiz, char* nome, int matricula, float nota) {
    if (raiz == NULL) return criarAluno(nome, matricula, nota);

    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0)
        raiz->esquerdo = inserir(raiz->esquerdo, nome, matricula, nota);
    else if (cmp > 0)
        raiz->direito = inserir(raiz->direito, nome, matricula, nota);
    else
        printf("Aluno com nome '%s' ja existe na arvore.\n", nome);

    return raiz;
}

Aluno* buscarPorNome(Aluno* raiz, char* nome) {
    if (raiz == NULL) return NULL;

    int cmp = strcmp(nome, raiz->nome);
    if (cmp == 0)
        return raiz;
    else if (cmp < 0)
        return buscarPorNome(raiz->esquerdo, nome);
    else
        return buscarPorNome(raiz->direito, nome);
}

void somaNotasEContar(Aluno* raiz, float* soma, int* contador) {
    if (raiz != NULL) {
        *soma += raiz->nota;
        (*contador)++;
        somaNotasEContar(raiz->esquerdo, soma, contador);
        somaNotasEContar(raiz->direito, soma, contador);
    }
}

float calcularMedia(Aluno* raiz) {
    float soma = 0.0;
    int contador = 0;
    somaNotasEContar(raiz, &soma, &contador);
    if (contador == 0) return 0.0;
    return soma / contador;
}

void liberarArvore(Aluno* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}

int main() {
    Aluno* raiz = NULL;

    raiz = inserir(raiz, "Matheus", 123, 8.5);
    raiz = inserir(raiz, "Ediana", 456, 7.0);
    raiz = inserir(raiz, "Joao", 789, 9.2);
    raiz = inserir(raiz, "Ysis", 101, 6.8);

    char nomeBusca[50];
    printf("Digite o nome do aluno para buscar: ");
    scanf("%49s", nomeBusca);

    Aluno* alunoEncontrado = buscarPorNome(raiz, nomeBusca);
    if (alunoEncontrado != NULL) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", alunoEncontrado->nome);
        printf("Matricula: %d\n", alunoEncontrado->matricula);
        printf("Nota: %.2f\n", alunoEncontrado->nota);
    } else {
        printf("Aluno com nome '%s' nao encontrado.\n", nomeBusca);
    }

    float media = calcularMedia(raiz);
    printf("Media das notas dos alunos: %.2f\n", media);

    liberarArvore(raiz);

    return 0;
}