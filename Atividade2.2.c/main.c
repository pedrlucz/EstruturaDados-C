#include "carros.h"

// if __name__ = "__main__"
int main() {
    Carro carros[TAM];

    preencherCarros(carros);

    int criterio;
    printf("Escolha o criterio de ordenacao:\n");
    printf("1 - Potencia\n2 - Nome\n3 - Marca\n");
    scanf("%d", &criterio);

    quickSort(carros, 0, TAM - 1, criterio);

    exibirCarros(carros);

    return 0;
}
