#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Queue structure
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create a queue and initialize front and rear
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to add an element to the queue (Enqueue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front if adding the first element
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove an element from the queue (Dequeue)
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset the queue
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

// Function to get the front item of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contains: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue* q = createQueue();

    // Sample operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);

    dequeue(q);
    displayQueue(q);

    printf("Front element is %d\n", peek(q));

    return 0;
}
