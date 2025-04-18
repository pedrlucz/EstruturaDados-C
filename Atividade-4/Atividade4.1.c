#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica {
    char nome[100];
    char artista[100];
    struct Musica* proximo;
    struct Musica* anterior;
} Musica;

// só de criar nova música
Musica* criarMusica(char nome[], char artista[]) {
    Musica* nova = (Musica*)malloc(sizeof(Musica));
    strcpy(nova -> nome, nome);
    strcpy(nova -> artista, artista);
    nova -> proximo = NULL;
    nova -> anterior = NULL;
    return nova;
}

// pra inserir no final da lista
void inserirFim(Musica** inicio, Musica** fim, char nome[], char artista[]) {
    Musica* nova = criarMusica(nome, artista);
    if (*fim == NULL) {
        *inicio = *fim = nova;
    } else {
        (*fim) -> proximo = nova;
        nova -> anterior = *fim;
        *fim = nova;
    }
}

// pra inserir no início da lista
void inserirInicio(Musica** inicio, Musica** fim, char nome[], char artista[]) {
    Musica* nova = criarMusica(nome, artista);
    if (*inicio == NULL) {

        *inicio = *fim = nova;

    } else {
        nova -> proximo = *inicio;

        (*inicio) -> anterior = nova;

        *inicio = nova;
    }
}

// pra avançar para a próxima música
void avancar(Musica** tocando) {
    if (*tocando != NULL && (*tocando) -> proximo != NULL) {

        *tocando = (*tocando) -> proximo;

    } else {
        printf("Já está na última música.\n");
    }
}

// pra voltar para a música anterior
void voltar(Musica** tocando) {
    if (*tocando != NULL && (*tocando) -> anterior != NULL) {
        *tocando = (*tocando) -> anterior;
    } else {
        printf("Já está na primeira música.\n");
    }
}

// pra mostrar a música que ta tocando
void mostrarTocando(Musica* tocando) {
    if (tocando != NULL) {
        printf("Tocando agora: %s - %s\n", tocando->nome, tocando->artista);
    } else {
        printf("Nenhuma música tocando.\n");
    }
}

int main() {
    Musica *inicio = NULL, *fim = NULL, *tocando = NULL;

    inserirFim(&inicio, &fim, "Shape of You", "Ed Sheeran");
    inserirFim(&inicio, &fim, "Blinding Lights", "The Weeknd");
    inserirInicio(&inicio, &fim, "Bohemian Rhapsody", "Queen");

    tocando = inicio;
    mostrarTocando(tocando);

    avancar(&tocando);
    mostrarTocando(tocando);

    avancar(&tocando);
    mostrarTocando(tocando);

    voltar(&tocando);
    mostrarTocando(tocando);

    return 0;
}