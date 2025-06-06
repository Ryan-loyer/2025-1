#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;


No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    else if (valor > raiz->dado)
        raiz->direito = inserir(raiz->direito, valor);
    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) return raiz;
    if (valor < raiz->dado)
        return buscar(raiz->esquerdo, valor);
    else
        return buscar(raiz->direito, valor);
}

No* minValorNo(No* no) {
    No* atual = no;
    while (atual && atual->esquerdo != NULL)
        atual = atual->esquerdo;
    return atual;
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->dado)
        raiz->esquerdo = remover(raiz->esquerdo, valor);
    else if (valor > raiz->dado)
        raiz->direito = remover(raiz->direito, valor);
    else {
        if (raiz->esquerdo == NULL) {
            No* temp = raiz->direito;
            free(raiz);
            return temp;
        } else if (raiz->direito == NULL) {
            No* temp = raiz->esquerdo;
            free(raiz);
            return temp;
        }
        No* temp = minValorNo(raiz->direito);
        raiz->dado = temp->dado;
        raiz->direito = remover(raiz->direito, temp->dado);
    }
    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direito);
    }
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int altEsq = altura(raiz->esquerdo);
    int altDir = altura(raiz->direito);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

int profundidade(No* raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado)
        return profundidade(raiz->esquerdo, valor, prof + 1);
    else
        return profundidade(raiz->direito, valor, prof + 1);
}

int soma(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + soma(raiz->esquerdo) + soma(raiz->direito);
}

int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerdo) + contarNos(raiz->direito);
}

int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL) return 1;
    return contarFolhas(raiz->esquerdo) + contarFolhas(raiz->direito);
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Em ordem: "); emOrdem(raiz); printf("\n");
    printf("Pre ordem: "); preOrdem(raiz); printf("\n");
    printf("Pos ordem: "); posOrdem(raiz); printf("\n");
    printf("Altura: %d\n", altura(raiz));
    printf("Profundidade do 40: %d\n", profundidade(raiz, 40, 0));
    printf("Soma dos valores: %d\n", soma(raiz));
    printf("Numero de nos: %d\n", contarNos(raiz));
    printf("Numero de folhas: %d\n", contarFolhas(raiz));

    raiz = remover(raiz, 70);
    printf("Em ordem apos remover 70: "); emOrdem(raiz); printf("\n");

    return 0;
}