/*WAP in C to implement Queue Operations Using Menudriven*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue {
    int front;
    int rear;
    int items[MAX];
};
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue.\n");
        return;
    }
    if (q->front == -1)  // If the queue is initially empty
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}
void dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", q->items[q->front]);
    q->front++;
    if (q->front > q->rear) {  // Reset the queue when empty
        q->front = -1;
        q->rear = -1;
    }
}
void display(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
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
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting the program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}