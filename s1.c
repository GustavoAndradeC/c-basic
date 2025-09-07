//ALGORITMOS E ESTRUTURA DE DADOS SEMANA 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista
typedef struct Node {
    int id;
    char descricao[100];
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* criarTarefa(int id, char descricao[]) {
    Node* nova = (Node*) malloc(sizeof(Node));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    nova->id = id;
    strcpy(nova->descricao, descricao);
    nova->next = NULL;
    return nova;
}

// Inserção no final da lista
void inserirTarefa(Node** head, int id, char descricao[]) {
    Node* nova = criarTarefa(id, descricao);
    if (*head == NULL) {
        *head = nova;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nova;
    }
    printf("Tarefa %d inserida com sucesso!\n", id);
}

// Percorrer e exibir tarefas
void listarTarefas(Node* head) {
    if (head == NULL) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    printf("\n--- Lista de Tarefas ---\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("ID: %d | Descricao: %s\n", temp->id, temp->descricao);
        temp = temp->next;
    }
    printf("------------------------\n");
}

// Remover tarefa pelo ID
void removerTarefa(Node** head, int id) {
    if (*head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node* temp = *head;
    Node* anterior = NULL;

    while (temp != NULL && temp->id != id) {
        anterior = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Tarefa com ID %d não encontrada.\n", id);
        return;
    }

    if (anterior == NULL) { // removendo o primeiro nó
        *head = temp->next;
    } else {
        anterior->next = temp->next;
    }
    free(temp);
    printf("Tarefa %d removida com sucesso!\n", id);
}

// Liberar toda a lista ao final
void liberarLista(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* prox = temp->next;
        free(temp);
        temp = prox;
    }
    *head = NULL;
}

int main() {
    Node* lista = NULL;
    int opcao, id;
    char descricao[100];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Remover tarefa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                printf("Digite o ID da tarefa: ");
                scanf("%d", &id);
                getchar();
                printf("Digite a descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = 0; // remover \n
                inserirTarefa(&lista, id, descricao);
                break;
            case 2:
                listarTarefas(lista);
                break;
            case 3:
                printf("Digite o ID da tarefa a remover: ");
                scanf("%d", &id);
                removerTarefa(&lista, id);
                break;
            case 0:
                printf("Saindo...\n");
                liberarLista(&lista);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
