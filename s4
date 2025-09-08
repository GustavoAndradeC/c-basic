// //ALGORITMOS E ESTRUTURA DE DADOS SEMANA 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct Cliente {
    char nome[50];
    char telefone[20];
    struct Cliente *prox;
} Cliente;

Cliente* tabela[TAM];

int hash(char *nome) {
    int soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += nome[i];
    }
    return soma % TAM;
}

void inserir(char *nome, char *telefone) {
    int indice = hash(nome);
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->prox = tabela[indice];
    tabela[indice] = novo;
    printf("Cliente %s inserido com sucesso!\n", nome);
}

void buscar(char *nome) {
    int indice = hash(nome);
    Cliente *atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Telefone de %s: %s\n", nome, atual->telefone);
            return;
        }
        atual = atual->prox;
    }
    printf("Cliente %s nao encontrado.\n", nome);
}

void exibir() {
    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < TAM; i++) {
        Cliente *atual = tabela[i];
        while (atual != NULL) {
            printf("Nome: %s | Telefone: %s\n", atual->nome, atual->telefone);
            atual = atual->prox;
        }
    }
}

void liberar() {
    for (int i = 0; i < TAM; i++) {
        Cliente *atual = tabela[i];
        while (atual != NULL) {
            Cliente *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
}

int main() {
    int opcao;
    char nome[50], telefone[20];

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Inserir cliente\n");
        printf("2 - Buscar cliente\n");
        printf("3 - Exibir todos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Digite o nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                printf("Digite o telefone: ");
                fgets(telefone, 20, stdin);
                telefone[strcspn(telefone, "\n")] = '\0';
                inserir(nome, telefone);
                break;

            case 2:
                printf("Digite o nome para buscar: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscar(nome);
                break;

            case 3:
                exibir();
                break;

            case 0:
                printf("Encerrando programa...\n");
                liberar();
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
