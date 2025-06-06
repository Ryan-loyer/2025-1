#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void adicionarContato(Contato contatos[], int *cont) {
    printf("Nome: ");
    getchar(); 
    fgets(contatos[*cont].nome, 50, stdin);
    contatos[*cont].nome[strcspn(contatos[*cont].nome, "\n")] = 0;

    printf("Telefone: ");
    fgets(contatos[*cont].telefone, 20, stdin);
    contatos[*cont].telefone[strcspn(contatos[*cont].telefone, "\n")] = 0;

    printf("Email: ");
    fgets(contatos[*cont].email, 50, stdin);
    contatos[*cont].email[strcspn(contatos[*cont].email, "\n")] = 0;

    (*cont)++;
}

void buscarContato(Contato contatos[], int cont, char nomeBusca[]) {
    int encontrados = 0;
    for (int i = 0; i < cont; i++) {
        if (strstr(contatos[i].nome, nomeBusca) != NULL) {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum contato encontrado com o nome \"%s\".\n", nomeBusca);
    }
}

void listarContatos(Contato contatos[], int cont) {
    printf("\nLista de contatos:\n");
    for (int i = 0; i < cont; i++) {
        printf("Nome: %s, Telefone: %s, Email: %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
    }
}

int main() {
    Contato contatos[100];
    int cont = 0;
    int opcao;

    do {
        printf("\nMenu:\n1 - Adicionar contato\n2 - Buscar contato por nome\n3 - Listar todos os contatos\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &cont);
                break;
            case 2: {
                char nomeBusca[50];
                printf("Digite o nome para buscar: ");
                getchar();
                fgets(nomeBusca, 50, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0;
                buscarContato(contatos, cont, nomeBusca);
                break;
            }
            case 3:
                listarContatos(contatos, cont);
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
