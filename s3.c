//ALGORITMOS E ESTRUTURA DE DADOS SEMANA 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct No {
    char usuario[50];
    char senha[50];
    struct No* prox;
} No;

No* tabela[TAM];

int hash(char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAM;
}

void initialize() {
    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }
}

void push(char* usuario, char* senha) {
    int indice = hash(usuario);
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->usuario, usuario);
    strcpy(novo->senha, senha);
    novo->prox = tabela[indice];
    tabela[indice] = novo;
    printf("Usuario '%s' inserido com sucesso!\n", usuario);
}

char* seek(char* usuario) {
    int indice = hash(usuario);
    No* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->usuario, usuario) == 0) {
            return atual->senha;
        }
        atual = atual->prox;
    }
    return NULL;
}

void imprimir() {
    for (int i = 0; i < TAM; i++) {
        printf("[%d] -> ", i);
        No* atual = tabela[i];
        while (atual != NULL) {
            printf("(%s | %s) -> ", atual->usuario, atual->senha);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}

void liberar() {
    for (int i = 0; i < TAM; i++) {
        No* atual = tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
}

int main() {
    initialize();

    push("gustavo", "12345");
    push("joao", "senha123");
    push("maria", "abcde");
    push("carlos", "qwerty");

    printf("\n--- Tabela de Espalhamento ---\n");
    imprimir();

    char* senha = seek("joao");
    if (senha != NULL) {
        printf("\nSenha do usuario 'joao': %s\n", senha);
    } else {
        printf("\nUsuario 'joao' nao encontrado.\n");
    }

    liberar();
    return 0;
}
