#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int valor;
    struct Node *esq, *dir;
} Node;

Node* novoNo(int v) {
    Node *n = malloc(sizeof(Node));
    n->valor = v;
    n->esq = n->dir = NULL;
    return n;
}

void insere(Node **root, int v) {
    Node *n = novoNo(v);
    if (!*root) {
        *root = n;
        return;
    }
    // fila simples usando array circular
    Node* fila[100];
    int ini = 0, fim = 0;
    fila[fim++] = *root;
    while (ini < fim) {
        Node *at = fila[ini++];
        if (!at->esq) {
            at->esq = n;
            return;
        } else {
            fila[fim++] = at->esq;
        }
        if (!at->dir) {
            at->dir = n;
            return;
        } else {
            fila[fim++] = at->dir;
        }
    }
}

int buscaCaminho(Node *at, int alvo, char caminho[], int profundidade) {
    if (!at) return 0;
    if (at->valor == alvo) {

        printf("Raiz");
        for (int i = 0; i < profundidade; i++) {
            printf(" -> %c", caminho[i]);
        }
        printf(" -> %d\n", alvo);
        return 1;
    }
    // desce esquerda
    caminho[profundidade] = 'E';
    if (buscaCaminho(at->esq, alvo, caminho, profundidade+1))
        return 1;
    // desce direita
    caminho[profundidade] = 'D';
    if (buscaCaminho(at->dir, alvo, caminho, profundidade+1))
        return 1;
    return 0;
}

void imprimeArvore(Node *at, int nivel) {
    if (!at) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("%d\n", at->valor);
    imprimeArvore(at->esq, nivel+1);
    imprimeArvore(at->dir, nivel+1);
}

int main() {
    Node *raiz = NULL;
    int n, v, alvo;
    char caminho[100];

    printf("Quantos valores vai inserir na árvore? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &v);
        insere(&raiz, v);
    }

    printf("Digite o valor a buscar: ");
    scanf("%d", &alvo);

    printf("\nResultado da busca:\n");
    if (!buscaCaminho(raiz, alvo, caminho, 0)) {
        printf("Valor %d não encontrado. Árvore completa:\n", alvo);
        imprimeArvore(raiz, 0);
    }

    return 0;
}
