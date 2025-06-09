#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11
#define MAX_NAME   50

typedef struct {
    char nome[MAX_NAME];
    char dataNascimento[11];  
    float nota;
    int ocupado;              
} Aluno;

unsigned int hash(const char *chave) {
    unsigned int sum = 0;
    for (; *chave; chave++) {
        sum += (unsigned char)(*chave);
    }
    return sum % TABLE_SIZE;
}

int inserir(Aluno tabela[]) {
    Aluno a;
    printf("Cadastrar aluno:\n");
    printf("  Nome: ");
    scanf(" %[^\n]", a.nome);
    printf("  Data de Nasc. (DD/MM/YYYY): ");
    scanf(" %10[^\n]", a.dataNascimento);
    printf("  Nota: ");
    scanf("%f", &a.nota);
    a.ocupado = 1;

    unsigned int idx = hash(a.nome);
    unsigned int start = idx;
    do {
        if (!tabela[idx].ocupado) {
            tabela[idx] = a;
            return 1;  // inserido
        }
        // colisão — próxima posição
        idx = (idx + 1) % TABLE_SIZE;
    } while (idx != start);

    printf("Erro: tabela cheia, não foi possível inserir.\n");
    return 0;
}

void buscar(Aluno tabela[]) {
    char chave[MAX_NAME];
    printf("Buscar aluno por nome: ");
    scanf(" %[^\n]", chave);

    unsigned int idx = hash(chave);
    unsigned int start = idx;
    do {
        if (tabela[idx].ocupado && strcmp(tabela[idx].nome, chave) == 0) {
            printf("\nAluno encontrado:\n");
            printf("  Nome: %s\n", tabela[idx].nome);
            printf("  Data de Nasc.: %s\n", tabela[idx].dataNascimento);
            printf("  Nota: %.2f\n\n", tabela[idx].nota);
            return;
        }
        // se vazio, não existe
        if (!tabela[idx].ocupado) break;
        idx = (idx + 1) % TABLE_SIZE;
    } while (idx != start);

    printf("Aluno \"%s\" não encontrado na tabela.\n\n", chave);
}

int main() {
    Aluno tabela[TABLE_SIZE] = {0};
    int opc;

    do {
        printf("=== Menu Tabela Hash ===\n");
        printf("1) Inserir aluno\n");
        printf("2) Buscar aluno\n");
        printf("0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                inserir(tabela);
                break;
            case 2:
                buscar(tabela);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opc != 0);

    return 0;
}
