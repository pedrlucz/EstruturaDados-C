#ifndef CARROS_H
#define CARROS_H
    //pra 5 msm
#define TAM 5 
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char marca[50];
    int potencia;
} Carro;

void preencherCarros(Carro carros[]);
void exibirCarros(Carro carros[]);
void quickSort(Carro carros[], int low, int high, int criterio);

#endif
