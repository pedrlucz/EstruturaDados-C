#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct {
    char nome[50];
    float nota;
    int matricula;
} Aluno;

void troca(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void reorganizar_heap(Aluno arr[], int n, int i, int criterio) {
    int maior = i; 
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2; 

    if (esq < n) {
        int comparar = 0;
        if (criterio == 1) comparar = (arr[esq].nota > arr[maior].nota);
        else if (criterio == 2) comparar = (arr[esq].matricula > arr[maior].matricula);
        else if (criterio == 3) comparar = (strcmp(arr[esq].nome, arr[maior].nome) > 0);
        
        if (comparar) maior = esq;
    }

    if (dir < n) {
        int comparar = 0;
        if (criterio == 1) comparar = (arr[dir].nota > arr[maior].nota);
        else if (criterio == 2) comparar = (arr[dir].matricula > arr[maior].matricula);
        else if (criterio == 3) comparar = (strcmp(arr[dir].nome, arr[maior].nome) > 0);
        
        if (comparar) maior = dir;
    }

    if (maior != i) {
        troca(&arr[i], &arr[maior]);
        reorganizar_heap(arr, n, maior, criterio);
    }
}

void heapSort(Aluno arr[], int n, int criterio) {
    for (int i = n / 2 - 1; i >= 0; i--)
        reorganizar_heap(arr, n, i, criterio);

    for (int i = n - 1; i > 0; i--) {
        troca(&arr[0], &arr[i]);
        reorganizar_heap(arr, i, 0, criterio);
    }
}

void exibirAlunos(Aluno alunos[]) {
    printf("\nLista de alunos ordenada:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Nome: %s, Nota: %.2f, Matrícula: %d\n", alunos[i].nome, alunos[i].nota, alunos[i].matricula);
    }
}

int main() {
    Aluno alunos[TAM] = {
        {"Carlos", 8.5, 102},
        {"Bruna", 9.2, 101},
        {"Fernando", 7.8, 103},
        {"Ana", 9.5, 100},
        {"Eduardo", 8.0, 104}
    };

    //qual ordenação
    int criterio;
    printf("Escolha o critério de ordenação:\n");
    printf("1 - Nota\n2 - Matrícula\n3 - Nome\n");
    scanf("%d", &criterio);

    heapSort(alunos, TAM, criterio);

    exibirAlunos(alunos);

    return 0;
}
