//ALGORITMOS E ESTRUTURA DE DADOS SEMANA 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char *operation; 
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

static char *my_strdup(const char *s) {
    if (!s) return NULL;
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (!copy) return NULL;
    memcpy(copy, s, len);
    return copy;
}

static Node *create_node(const char *operation) {
    Node *n = malloc(sizeof(Node));
    if (!n) return NULL;
    n->operation = my_strdup(operation);
    n->next = NULL;
    if (!n->operation) {
        free(n);
        return NULL;
    }
    return n;
}

void init_stack(Stack *s) {
    s->top = NULL;
}

bool is_empty(const Stack *s) {
    return s->top == NULL;
}

bool push(Stack *s, const char *operation) {
    Node *n = create_node(operation);
    if (!n) return false;
    n->next = s->top;
    s->top = n;
    return true;
}

char *pop(Stack *s) {
    if (is_empty(s)) return NULL;
    Node *n = s->top;
    char *op = n->operation;
    s->top = n->next;
    free(n); 
    return op;
}

void free_stack(Stack *s) {
    while (!is_empty(s)) {
        char *op = pop(s);
        if (op) free(op);
    }
}

void print_stack(const Stack *s) {
    printf("Pilha (topo -> base):\n");
    Node *cur = s->top;
    if (!cur) {
        printf("  <vazia>\n");
        return;
    }
    while (cur) {
        printf("  %s\n", cur->operation);
        cur = cur->next;
    }
}

int main(void) {
    Stack history;
    init_stack(&history);

    push(&history, "5 + 3 = 8");
    push(&history, "8 * 2 = 16");
    push(&history, "16 - 7 = 9");
    push(&history, "sqrt(9) = 3");

    print_stack(&history);

    printf("\nDesfazendo operacoes:\n");
    char *op;
    op = pop(&history);
    if (op) { printf("Desfeito: %s\n", op); free(op); }

    op = pop(&history);
    if (op) { printf("Desfeito: %s\n", op); free(op); }

    printf("\nEstado atual apos 2 desfazes:\n");
    print_stack(&history);

    printf("\nRemovendo o restante das operacoes:\n");
    while ((op = pop(&history)) != NULL) {
        printf("Desfeito: %s\n", op);
        free(op);
    }

    op = pop(&history);
    if (!op) {
        printf("\nPop em pilha vazia retornou NULL.\n");
    }

    free_stack(&history);

    return 0;
}
