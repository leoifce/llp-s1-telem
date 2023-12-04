#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack) {
    int value;
    printf("Digite o valor a ser inserido na pilha: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia. Não é possível remover elementos.\n");
    } else {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

void displayTop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Topo da pilha: %d\n", stack->top->data);
    }
}

void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Conteúdo da pilha a partir do Topo: ");
        Node* current = stack->top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Verificar o Topo da Pilha\n");
        printf("2. Push (Inserir elemento na Pilha)\n");
        printf("3. Pop (Retirar elemento da Pilha)\n");
        printf("4. Mostrar conteúdo da Pilha a partir do Topo\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTop(&myStack);
                break;
            case 2:
                push(&myStack);
                break;
            case 3:
                pop(&myStack);
                break;
            case 4:
                displayStack(&myStack);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice != 5);

    return 0;
}
