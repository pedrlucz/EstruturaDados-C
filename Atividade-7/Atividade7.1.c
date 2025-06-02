#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int quantidade;
    float valor;
} Produto;

typedef struct Node {
    Produto prod;
    struct Node *esq, *dir;
} Node;

Node* novoNode(Produto p) {
    Node *n = (Node*) malloc(sizeof(Node));
    if (!n) {
        perror("Erro ao alocar nó");
        exit(EXIT_FAILURE);
    }
    n->prod = p;
    n->esq = n->dir = NULL;
    return n;
}

Node* insere(Node *root, Produto p) {
    if (root == NULL) {
        return novoNode(p);
    }
    // compara nomes
    int cmp = strcmp(p.nome, root->prod.nome);
    if (cmp < 0) {
        root->esq = insere(root->esq, p);
    } else if (cmp > 0) {
        root->dir = insere(root->dir, p);
    } else {
        // se já existe um produto com esse nome, podemos atualizar quantidade e valor
        root->prod.quantidade = p.quantidade;
        root->prod.valor = p.valor;
    }
    return root;
}

void buscaProduto(Node *root, const char *nome) {
    if (root == NULL) {
        printf("Produto \"%s\" não encontrado no estoque.\n", nome);
        return;
    }
    int cmp = strcmp(nome, root->prod.nome);
    if (cmp == 0) {
        printf("Produto: %s\nQuantidade em estoque: %d\n", 
               root->prod.nome, root->prod.quantidade);
    } else if (cmp < 0) {
        buscaProduto(root->esq, nome);
    } else {
        buscaProduto(root->dir, nome);
    }
}

void liberaArvore(Node *root) {
    if (!root) return;
    liberaArvore(root->esq);
    liberaArvore(root->dir);
    free(root);
}

int main() {
    Node *raiz = NULL;
    int n;

    printf("Quantos produtos serão cadastrados? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Produto p;
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", p.nome);
        printf("Quantidade: ");
        scanf("%d", &p.quantidade);
        printf("Valor (R$): ");
        scanf("%f", &p.valor);

        raiz = insere(raiz, p);
    }

    // qual produto buscar
    char busca[50];
    printf("\nDigite o nome do produto a buscar: ");
    scanf(" %[^\n]", busca);

    printf("\nResultado da busca:\n");
    buscaProduto(raiz, busca);

    liberaArvore(raiz);
    return 0;
}
