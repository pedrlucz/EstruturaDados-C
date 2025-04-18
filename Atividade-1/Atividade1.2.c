#include <stdio.h>

struct Carta {
    char simbolo;
    int valor;
};

struct Carta baralho[5];

int main() {
    int i;
    
    for (i = 0; i < 5; i++) {
        printf("Digite o símbolo da carta %d: ", i + 1);
        scanf(" %c", &baralho[i].simbolo); // spaço pra ignorar espaços em branco

        printf("Digite o valor da carta %d: ", i + 1);
        scanf("%d", &baralho[i].valor);
    }

    // pra ordenar pelo menor valor
    for (int i = 0; i < 5 - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < 5; j++) {
            if (baralho[j].valor < baralho[min_idx].valor) {
                min_idx = j;
            }
        }
        // troca
        struct Carta temp = baralho[i];
        baralho[i] = baralho[min_idx];
        baralho[min_idx] = temp;
    }

    printf("\n--- Baralho ordenado pelo menor valor ---\n");
    for (i = 0; i < 5; i++) {
        printf("Carta: %c, Valor: %d\n", baralho[i].simbolo, baralho[i].valor);
    }

    return 0;
}
