#include <stdio.h>
#include <stdlib.h>
typedef struct Queue {
    int *items;   
    int front;    
    int rear;     
    int capacity; 
    int size;     
} Queue;

Queue* createQueue(int initialCapacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = initialCapacity;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    q->items = (int*)malloc(q->capacity * sizeof(int));
    return q;
}
int isFull(Queue* q) {
    return q->size == q->capacity;
}
int isEmpty(Queue* q) {
    return q->size == 0;
}
void resizeQueue(Queue* q) {
    q->capacity *= 2; // Double the capacity
    q->items = (int*)realloc(q->items, q->capacity * sizeof(int));
    if (q->items == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity; 
    q->size--;
    printf("Dequeued: %d\n", item);
    return item;
}
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->items[(q->front + i) % q->capacity]);
    }
    printf("\n");
}
int main() {
    Queue* q = createQueue(2);
    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                free(q->items);
                free(q);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}