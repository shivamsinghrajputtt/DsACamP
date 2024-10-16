#include <stdio.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

int isFull(CircularQueue* q) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->rear == (q->front - 1) % (SIZE - 1))) {
        return 1;
    }
    return 0;
}

int isEmpty(CircularQueue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enQueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

int deQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Deleted %d\n", element);
    return element;
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front -> %d\n", q->front);
    printf("Items -> ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]);
    printf("Rear -> %d\n", q->rear);
}

int main() {
    CircularQueue q;
    q.front = q.rear = -1;

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);
    enQueue(&q, 50);
    display(&q);
    
    deQueue(&q);
    display(&q);
    
    enQueue(&q, 60);
    display(&q);
    
    return 0;
}