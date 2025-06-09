#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 23   
#define MAX_NAME   50

typedef struct {
    char nome[MAX_NAME];
    char dataNascimento[11];  
    float nota;
} Aluno;

typedef struct Node {
    Aluno aluno;
    struct Node *next;
} Node;

Node *tabela[TABLE_SIZE];

unsigned int hash(const char *chave) {
    unsigned int sum = 0;
    for (; *chave; chave++) {
        sum += (unsigned char)(*chave);
    }
    return sum % TABLE_SIZE;
}

Node* novoNode(Aluno a) {
    Node *n = malloc(sizeof(Node));
    if (!n) {
        perror("Erro ao alocar nó");
        exit(EXIT_FAILURE);
    }
    n->aluno = a;
    n->next = NULL;
    return n;
}

void inserir(Aluno a) {
    unsigned int idx = hash(a.nome);
    Node *n = novoNode(a);
    n->next = tabela[idx];
    tabela[idx] = n;
    printf("Aluno \"%s\" inserido no bucket %u.\n", a.nome, idx);
}

void buscar(const char *chave) {
    unsigned int idx = hash(chave);
    Node *p = tabela[idx];
    while (p) {
        if (strcmp(p->aluno.nome, chave) == 0) {
            printf("\nAluno encontrado:\n");
            printf("  Nome: %s\n", p->aluno.nome);
            printf("  Data de Nasc.: %s\n", p->aluno.dataNascimento);
            printf("  Nota: %.2f\n\n", p->aluno.nota);
            return;
        }
        p = p->next;
    }
    printf("Aluno \"%s\" não encontrado no bucket %u.\n\n", chave, idx);
}

void liberaTabela() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *p = tabela[i];
        while (p) {
            Node *tmp = p;
            p = p->next;
            free(tmp);
        }
        tabela[i] = NULL;
    }
}

int main() {
    int n;
    printf("Quantos estudantes (até 20)? ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Número inválido. Encerrando.\n");
        return 1;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
        tabela[i] = NULL;

    for (int i = 0; i < n; i++) {
        Aluno a;
        printf("\n--- Cadastro do aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", a.nome);
        printf("Data de Nasc. (DD/MM/YYYY): ");
        scanf(" %10[^\n]", a.dataNascimento);
        printf("Nota: ");
        scanf("%f", &a.nota);
        inserir(a);
    }

    char chave[MAX_NAME];
    do {
        printf("Digite o nome para busca (ou \"sair\"): ");
        scanf(" %[^\n]", chave);
        if (strcmp(chave, "sair") == 0) break;
        buscar(chave);
    } while (1);

    liberaTabela();
    printf("Encerrando...\n");
    return 0;
}
