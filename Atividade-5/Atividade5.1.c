#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100

typedef struct {
    char nome[50];
    char cpf[15];
    int gravidade;  
} Paciente;

int main() {
    Paciente emergencia[MAX_PACIENTES];
    Paciente uti[MAX_PACIENTES];
    Paciente triagem[MAX_PACIENTES];
    int ne = 0, nu = 0, nt = 0;  // contadores de cada fila
    int total;

    printf("Quantos pacientes serão cadastrados? ");
    scanf("%d", &total);

    // cadastrar
    for (int i = 0; i < total; i++) {
        printf("\n--- Cadastro do paciente %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", emergencia[ne].nome);
        printf("CPF: ");
        scanf(" %[^\n]", emergencia[ne].cpf);
        printf("Gravidade (1-10): ");
        scanf("%d", &emergencia[ne].gravidade);
        ne++;
    }

    //    Se gravidade >= 7 -> UTI; senão -> triagem
    for (int i = 0; i < ne; i++) {
        if (emergencia[i].gravidade >= 7) {
            uti[nu++] = emergencia[i];
        } else {
            triagem[nt++] = emergencia[i];
        }
    }

    // exibir as três filas
    printf("\n=== Fila de Emergência (inicial) ===\n");
    for (int i = 0; i < ne; i++) {
        printf("%d) %s | CPF: %s | Gravidade: %d\n",
               i+1,
               emergencia[i].nome,
               emergencia[i].cpf,
               emergencia[i].gravidade);
    }

    printf("\n=== Fila da UTI (gravidade >= 7) ===\n");
    for (int i = 0; i < nu; i++) {
        printf("%d) %s | CPF: %s | Gravidade: %d\n",
               i+1,
               uti[i].nome,
               uti[i].cpf,
               uti[i].gravidade);
    }

    printf("\n=== Fila de Triagem (gravidade < 7) ===\n");
    for (int i = 0; i < nt; i++) {
        printf("%d) %s | CPF: %s | Gravidade: %d\n",
               i+1,
               triagem[i].nome,
               triagem[i].cpf,
               triagem[i].gravidade);
    }

    return 0;
}
