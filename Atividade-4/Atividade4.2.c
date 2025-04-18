#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_CARRINHOS 10

typedef struct Carrinho {
    int pessoas;
    char cor[20];
    struct Carrinho* proximo;
    struct Carrinho* anterior;
} Carrinho;

Carrinho* criarCarrinho(char cor[]) {
    Carrinho* novo = (Carrinho*)malloc(sizeof(Carrinho));
    novo -> pessoas = 0;
    strcpy(novo -> cor, cor);
    novo -> proximo = NULL;
    novo -> anterior = NULL;
    return novo;
}

Carrinho* criarRodaGigante() {
    char cores[TOTAL_CARRINHOS][20] = {
                                            "Vermelho", "Azul", "Verde", "Amarelo", "Roxo", "Laranja", "Rosa", "Branco", "Preto", "Cinza"
                                                                                                                                            };

    Carrinho* primeiro = NULL;
    Carrinho* anterior = NULL;

    for (int i = 0; i < TOTAL_CARRINHOS; i++) {
        Carrinho* novo = criarCarrinho(cores[i]);

        if (primeiro == NULL) {
            primeiro = novo;
        } else {
                    anterior -> proximo = novo;
                        novo -> anterior = anterior;
                                                        }

        anterior = novo;

    }

    // fechando a lista circular
    primeiro -> anterior = anterior;
    anterior -> proximo = primeiro;

    return primeiro;
}

void mostrarCarrinho(Carrinho* atual) {
                                            printf("\nCarrinho atual: Cor %s | Pessoas: %d\n", atual -> cor, atual -> pessoas);
                                                                                                                                }

void embarcar(Carrinho* atual) {
                                    atual -> pessoas++;
                                        printf("Pessoa embarcou no carrinho %s. Total agora: %d\n", atual -> cor, atual -> pessoas);
                                                                                                                                    }

void desembarcar(Carrinho* atual) {
    if (atual -> pessoas > 0) {
        atual -> pessoas--;

        printf("Pessoa desembarcou do carrinho %s. Total agora: %d\n", atual -> cor, atual -> pessoas);

    } else {
        printf("Carrinho %s já está vazio!\n", atual -> cor);
    }
}

int main() {
    Carrinho* atual = criarRodaGigante();
    int opcao;

    do {
        mostrarCarrinho(atual);
        printf("\nMenu:\n");
        printf("1 - Girar horário\n");
        printf("2 - Girar anti-horário\n");
        printf("3 - Embarcar pessoa\n");
        printf("4 - Desembarcar pessoa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                atual = atual -> proximo;
                break;
            case 2:
                atual = atual -> anterior;
                break;
            case 3:
                embarcar(atual);
                break;
            case 4:
                desembarcar(atual);
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
