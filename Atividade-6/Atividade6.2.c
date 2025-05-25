#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float tempo;
} Corredor;

typedef struct Node {
    Corredor corredor;
    struct Node *esq, *dir;
} Node;

Node* novoNode(Corredor c) {
    Node *n = malloc(sizeof(Node));
    if (!n) {
        perror("Erro ao alocar nó");
        exit(EXIT_FAILURE);
    }
    n->corredor = c;
    n->esq = n->dir = NULL;
    return n;
}

// insere na árvore: à direita se tempo < corte (melhor), à esquerda se >= corte (pior)
void insere(Node **root, Corredor c, float corte) {
    if (*root == NULL) {
        *root = novoNode(c);
    } else {
        if (c.tempo < corte)
            insere(&(*root)->dir, c, corte);
        else
            insere(&(*root)->esq, c, corte);
    }
}

// percorre só a subÁrvore direita (classificados) em ordem
void imprimeClassificados(Node *root) {
    if (root == NULL) return;
    imprimeClassificados(root->esq);
    // (na subÁrvore direita, todos têm tempo < corte)
    printf("%s — tempo: %.2f s\n", root->corredor.nome, root->corredor.tempo);
    imprimeClassificados(root->dir);
}

void liberaArvore(Node *root) {
    if (!root) return;
    liberaArvore(root->esq);
    liberaArvore(root->dir);
    free(root);
}

int main() {
    int n;
    float tempoCorte;
    Node *raiz = NULL;

    printf("Quantos corredores serão cadastrados? ");
    scanf("%d", &n);

    printf("Informe o tempo de corte (em segundos): ");
    scanf("%f", &tempoCorte);

    for (int i = 0; i < n; i++) {
        Corredor c;
        printf("\n--- Corredor %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", c.nome);
        printf("Tempo (s): ");
        scanf("%f", &c.tempo);
        insere(&raiz, c, tempoCorte);
    }

    printf("\n=== Corredores classificados (tempo < %.2f s) ===\n", tempoCorte);
    // passando raiz->dir para evitar checar raiz se ela for pior
    if (raiz && raiz->dir)
        imprimeClassificados(raiz->dir);
    else
        printf("Nenhum corredor alcançou o tempo de corte.\n");

    liberaArvore(raiz);
    return 0;
}
