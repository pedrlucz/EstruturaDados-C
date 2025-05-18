#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    float a;
    float b;
    char op;      
    float result; 
} Operacao;

Operacao pilha[MAX];
int topo = 0;

float calcula(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0.0f) return a / b;
            printf("Erro: divisão por zero!\n");
            return 0.0f;
        default:
            printf("Operador inválido!\n");
            return 0.0f;
    }
}

// empilha
void push(Operacao opn) {
    if (topo < MAX) {
        pilha[topo++] = opn;
    } else {
        printf("Pilha cheia! Não é possível adicionar mais operações.\n");
    }
}

// desempilha a última operação
void pop() {
    if (topo > 0) {
        topo--;
        printf("Última operação removida.\n");
    } else {
        printf("Pilha vazia. Nada para remover.\n");
    }
}

void mostraTopo() {
    if (topo > 0) {
        Operacao *t = &pilha[topo - 1];
        printf("Topo da pilha: %.2f %c %.2f = %.2f\n",
               t->a, t->op, t->b, t->result);
    } else {
        printf("Nenhuma operação na pilha.\n");
    }
}

void mostraHistorico() {
    if (topo == 0) {
        printf("Nenhuma operação cadastrada.\n");
        return;
    }
    printf("Histórico de operações:\n");
    for (int i = 0; i < topo; i++) {
        printf(" %2d) %.2f %c %.2f = %.2f\n",
               i+1,
               pilha[i].a,
               pilha[i].op,
               pilha[i].b,
               pilha[i].result);
    }
}

int main() {
    int escolha;
    Operacao opn;

    do {
        printf("\n===== Calculadora com Pilha =====\n");
        printf("1) Nova operação\n");
        printf("2) Desfazer última (pop)\n");
        printf("3) Mostrar operação atual (topo)\n");
        printf("4) Mostrar histórico completo\n");
        printf("0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite dois números (a b): ");
                scanf("%f %f", &opn.a, &opn.b);
                printf("Escolha a operação (+ - * /): ");
                scanf(" %c", &opn.op);
                opn.result = calcula(opn.a, opn.b, opn.op);
                push(opn);
                mostraTopo();
                break;

            case 2:
                pop();
                break;

            case 3:
                mostraTopo();
                break;

            case 4:
                mostraHistorico();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 0);

    return 0;
}
