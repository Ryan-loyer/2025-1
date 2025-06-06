#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *cont) {
    printf("Nome do produto: ");
    getchar();
    fgets(produtos[*cont].nome, 50, stdin);
    produtos[*cont].nome[strcspn(produtos[*cont].nome, "\n")] = 0;

    printf("Código: ");
    scanf("%d", &produtos[*cont].codigo);

    printf("Quantidade: ");
    scanf("%d", &produtos[*cont].quantidade);

    printf("Preço: ");
    scanf("%f", &produtos[*cont].preco);

    (*cont)++;
}

void listarProdutos(Produto produtos[], int cont) {
    printf("\nLista de produtos:\n");
    for (int i = 0; i < cont; i++) {
        printf("Código: %d, Nome: %s, Quantidade: %d, Preço: %.2f\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
}

void buscarProduto(Produto produtos[], int cont, int codigo) {
    bool encontrado = false;
    for (int i = 0; i < cont; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d, Nome: %s, Quantidade: %d, Preço: %.2f\n",
                   produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com código %d não encontrado.\n", codigo);
    }
}

int main() {
    Produto produtos[100];
    int cont = 0;
    int opcao;

    do {
        printf("\nMenu:\n1 - Cadastrar produto\n2 - Buscar produto\n3 - Listar produtos\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &cont);
                break;
            case 2: {
                int codigo;
                printf("Digite o código do produto para buscar: ");
                scanf("%d", &codigo);
                buscarProduto(produtos, cont, codigo);
                break;
            }
            case 3:
                listarProdutos(produtos, cont);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
