#include <stdio.h>
#include <string.h>

#define MAX 5 // Número de produtos

struct Produto {
    char nome[50];
    int quantidade;
    float preco;
};

// Função para mesclar duas metades ordenadas
void merge(struct Produto arr[], int left, int mid, int right, int criterio) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Produto L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        int condicao;
        if (criterio == 1)
            condicao = (L[i].preco < R[j].preco); // Ordenar por preço
        else if (criterio == 2)
            condicao = (L[i].quantidade < R[j].quantidade); // Ordenar por quantidade
        else
            condicao = (strcmp(L[i].nome, R[j].nome) < 0); // Ordenar por nome

        if (condicao) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(struct Produto arr[], int left, int right, int criterio) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, criterio);
        mergeSort(arr, mid + 1, right, criterio);
        merge(arr, left, mid, right, criterio);
    }
}

// Função para exibir os produtos
void mostrarProdutos(struct Produto produtos[], int n) {
    printf("\n--- Lista de Produtos Ordenada ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Quantidade: %d, Preço: %.2f\n",
               produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
}

// Função principal
int main() {
    struct Produto produtos[MAX];
    int criterio;

    // Entrada de dados
    for (int i = 0; i < MAX; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %[^\n]", produtos[i].nome);

        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);

        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }

    // Escolha do critério de ordenação
    printf("\nEscolha o critério de ordenação:\n");
    printf("1 - Preço\n");
    printf("2 - Quantidade\n");
    printf("3 - Nome\n");
    printf("Opção: ");
    scanf("%d", &criterio);

    // Aplicando Merge Sort
    mergeSort(produtos, 0, MAX - 1, criterio);

    // Exibir a lista ordenada
    mostrarProdutos(produtos, MAX);

    return 0;
}
