#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue) {
    int value;
    printf("Digite o valor a ser inserido na fila: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia. Não é possível remover elementos.\n");
    } else {
        Node* temp = queue->front;
        queue->front = queue->front->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);
    }
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Elementos na fila: ");
        Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento na fila\n");
        printf("2. Retirar elemento da fila\n");
        printf("3. Mostrar elementos da fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&myQueue);
                break;
            case 2:
                dequeue(&myQueue);
                break;
            case 3:
                displayQueue(&myQueue);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice != 4);

    destroyQueue(&myQueue);

    return 0;
}
