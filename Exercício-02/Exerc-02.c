#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

// Estrutura para representar um contato
typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

// Variáveis globais
Contato listaTelefonica[MAX_CONTATOS];
int numContatos = 0;

// Protótipos das funções
void adicionarContato();
void removerContato();
void buscarContato();

int main() {
    int opcao;

    do {
        // Menu de opções
        printf("\nSelecione uma opcao:\n");
        printf("1. Adicionar contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar contato\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                removerContato();
                break;
            case 3:
                buscarContato();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para adicionar um novo contato
void adicionarContato() {
    if (numContatos < MAX_CONTATOS) {
        printf("\nDigite o nome do contato: ");
        scanf("%s", listaTelefonica[numContatos].nome);
        printf("Digite o telefone do contato: ");
        scanf("%s", listaTelefonica[numContatos].telefone);
        numContatos++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A lista telefônica está cheia. Não é possível adicionar mais contatos.\n");
    }
}

// Função para remover um contato existente
void removerContato() {
    char nomeRemover[50];
    int i, encontrado = 0;

    printf("\nDigite o nome do contato a ser removido: ");
    scanf("%s", nomeRemover);

    for (i = 0; i < numContatos; i++) {
        if (strcmp(listaTelefonica[i].nome, nomeRemover) == 0) {
            encontrado = 1;
            // Movendo os contatos restantes para ocupar o espaço liberado
            for (int j = i; j < numContatos - 1; j++) {
                strcpy(listaTelefonica[j].nome, listaTelefonica[j + 1].nome);
                strcpy(listaTelefonica[j].telefone, listaTelefonica[j + 1].telefone);
            }
            numContatos--;
            printf("Contato removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado na lista telefônica.\n");
    }
}

// Função para buscar por um contato específico
void buscarContato() {
    char nomeBuscar[50];
    int i, encontrado = 0;

    printf("\nDigite o nome do contato a ser buscado: ");
    scanf("%s", nomeBuscar);

    for (i = 0; i < numContatos; i++) {
        if (strcmp(listaTelefonica[i].nome, nomeBuscar) == 0) {
            encontrado = 1;
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", listaTelefonica[i].nome);
            printf("Telefone: %s\n", listaTelefonica[i].telefone);
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado na lista telefônica.\n");
    }
}
