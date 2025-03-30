#include "carros.h"

void trocar(Carro *a, Carro *b) {
    Carro temp = *a;
    *a = *b;
    *b = temp;
}

int partition_qs(Carro arr[], int low, int high, int criterio) {
    Carro pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        int comparar = 0;
        if (criterio == 1) { // potência
            comparar = (arr[j].potencia < pivot.potencia);
        } else if (criterio == 2) { // nome
            comparar = (strcmp(arr[j].nome, pivot.nome) < 0);
        } else if (criterio == 3) { // marca
            comparar = (strcmp(arr[j].marca, pivot.marca) < 0);
        }

        if (comparar) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Carro arr[], int low, int high, int criterio) {
    if (low < high) {
        int pi = partition_qs(arr, low, high, criterio);

        quickSort(arr, low, pi - 1, criterio);
        quickSort(arr, pi + 1, high, criterio);
    }
}

void preencherCarros(Carro carros[]) {
    Carro lista[TAM] = {
        {"Civic", "Honda", 158},
        {"Gol", "Volkswagen", 100},
        {"Supra", "Toyota", 450},
        {"Corolla", "Toyota", 168},
        {"Uno", "Fiat", 75}
    };
    
    for (int i = 0; i < TAM; i++) {
        carros[i] = lista[i];
    }
}

void exibirCarros(Carro carros[]) {
    printf("\nLista de carros:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Nome: %s, Marca: %s, Potencia: %d\n", carros[i].nome, carros[i].marca, carros[i].potencia);
    }
}
