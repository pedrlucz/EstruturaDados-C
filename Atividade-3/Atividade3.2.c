#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    int quantidade;
    struct Produto *prox; // ponteiro pro prox elemento da lista
};

void inserirNoInicio(struct Produto **head, char nome[], int quantidade) {
    struct Produto *novo = (struct Produto *)malloc(sizeof(struct Produto));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->prox = *head;
    *head = novo;
}

void inserir_final(struct Produto **head, char nome[], int quantidade) {
    struct Produto *novo = (struct Produto *)malloc(sizeof(struct Produto));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->prox = NULL;

    if (*head == NULL) {
        *head = novo;
    } else {
        struct Produto *temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void imprimir_lista(struct Produto *head) {
    printf("\nLista de Compras:\n");
    while (head != NULL) {
        printf("Produto: %s, Quantidade: %d\n", head->nome, head->quantidade);
        head = head->prox;
    }
}

int main() {
    struct Produto *lista = NULL;
    int opcao, quantidade;
    char nome[50];

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir produto no início\n");
        printf("2 - Inserir produto no final\n");
        printf("3 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // tchau buffer

        switch (opcao) {
            case 1:
                printf("Digite o nome do produto: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' do final da string
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                inserirNoInicio(&lista, nome, quantidade);
                break;

            case 2:
                printf("Digite o nome do produto: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                inserir_final(&lista, nome, quantidade);
                break;

            case 3:
                imprimir_lista(lista);
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
