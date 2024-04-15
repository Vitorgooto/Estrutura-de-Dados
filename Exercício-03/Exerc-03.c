#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TreeNode {
    char palavra[50];
    struct TreeNode* esquerda;
    struct TreeNode* direita;
} TreeNode;

TreeNode* novoNo(char palavra[]) {
    TreeNode* no = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(no->palavra, palavra);
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

TreeNode* inserir(TreeNode* raiz, char palavra[]) {
    if (raiz == NULL)
        return novoNo(palavra);

    if (strcmp(palavra, raiz->palavra) < 0)
        raiz->esquerda = inserir(raiz->esquerda, palavra);
    else if (strcmp(palavra, raiz->palavra) > 0)
        raiz->direita = inserir(raiz->direita, palavra);

    return raiz;
}

bool buscar(TreeNode* raiz, char palavra[]) {
    while (raiz != NULL) {
        if (strcmp(palavra, raiz->palavra) == 0)
            return true;
        else if (strcmp(palavra, raiz->palavra) < 0)
            raiz = raiz->esquerda;
        else
            raiz = raiz->direita;
    }
    return false;
}

void liberarArvore(TreeNode* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    TreeNode* raiz = NULL;
    char palavra[50];
    char opcao;

    // Abrindo o arquivo de entrada
    FILE* arquivo = fopen("palavras_chave.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    // Lendo as palavras-chave do arquivo e inserindo na árvore
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        raiz = inserir(raiz, palavra);
    }

    fclose(arquivo);

    do {
        // Testando se uma palavra está presente na árvore
        printf("\nDigite uma palavra para verificar se está presente no dicionario: ");
        scanf("%s", palavra);

        if (buscar(raiz, palavra))
            printf("A palavra \"%s\" esta presente no dicionario.\n", palavra);
        else
            printf("A palavra \"%s\" nao esta presente no dicionario.\n", palavra);

        printf("Deseja buscar outra palavra? (s/n): ");
        scanf(" %c", &opcao); // O espaço antes do %c ignora espaços em branco e novas linhas

    } while (opcao == 's' || opcao == 'S');

    // Liberando a memória alocada pela árvore
    liberarArvore(raiz);

    return 0;
}
