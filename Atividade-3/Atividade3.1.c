#include <stdio.h>
#include <string.h>

#define MAX 100

struct Aluno {
    char nome[50];
    int idade;
    int serie;
    int matricula;
};

// usando bubble sort
void ordenar_por_matricula(struct Aluno alunos[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (alunos[j].matricula > alunos[j + 1].matricula) {
                struct Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

void exibir_alunos(struct Aluno alunos[], int n) {
    printf("\nLista de alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("Matrícula: %d, Nome: %s, Idade: %d, Série: %d\n",
               alunos[i].matricula, alunos[i].nome, alunos[i].idade, alunos[i].serie);
    }
}

int main() {
    int n;
    struct Aluno alunos[MAX];

    // cadastro dos alunos
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Digite a matrícula: ");
        scanf("%d", &alunos[i].matricula);
        
        // " %[^\n]" para ler nomes com espaços
        printf("Digite o nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        
        printf("Digite a idade: ");
        scanf("%d", &alunos[i].idade);
        
        printf("Digite a série: ");
        scanf("%d", &alunos[i].serie);
    }

    ordenar_por_matricula(alunos, n);
    printf("\nLista de alunos ordenada por matrícula:\n");
    exibir_alunos(alunos, n);

    // remover os elementos
    char opcao;
    do {
        int mat;
        printf("\nDigite a matrícula do aluno a ser removido: ");
        scanf("%d", &mat);
        
        int indice = -1;
        for (int i = 0; i < n; i++) {
            if (alunos[i].matricula == mat) {
                indice = i;
                break;
            }
        }
        
        if (indice == -1) {
            printf("Aluno com matrícula %d não encontrado.\n", mat);
        } else {

            // desloca os elementos à esquerda 
            for (int i = indice; i < n - 1; i++) {
                alunos[i] = alunos[i + 1];
            }
            n--; // pra ir tirando o número de alunos
            printf("Aluno removido. Lista atualizada:\n");
            exibir_alunos(alunos, n);
        }
        
        printf("Deseja remover outro aluno? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
