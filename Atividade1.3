#include <stdio.h>

struct Senha {
    int prioridade;
    int numero;
};

struct Senha fila[5];

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite a prioridade da senha %d (1 = prioritário, 0 = normal): ", i + 1);
        scanf("%d", &fila[i].prioridade);

        printf("Digite o número da senha %d: ", i + 1);
        scanf("%d", &fila[i].numero);
    }

    for (int i = 1; i < 5; i++) {
        struct Senha temp = fila[i];
        int j = i - 1;

        // considerando prioridade primeiro e número depois
        while (j >= 0 && 
              (fila[j].prioridade < temp.prioridade || 
              (fila[j].prioridade == temp.prioridade && fila[j].numero > temp.numero))) {
            fila[j + 1] = fila[j];
            j--;
        }
        fila[j + 1] = temp;
    }

    printf("\n--- Lista de senhas ordenada ---\n");
    for (i = 0; i < 5; i++) {
        printf("Prioridade: %d, Número: %d\n", fila[i].prioridade, fila[i].numero);
    }

    return 0;
}
