#include <stdio.h>
#include <stdlib.h>

// Queue implementation using Linked List
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

int isEmptyQueue() {
    return front == NULL;
}

void dequeue() {
    if (isEmptyQueue()) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue() {
    struct Node* temp = front;
    if (isEmptyQueue()) {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Circular Queue implementation using Linked List
struct Node* front_circular = NULL;
struct Node* rear_circular = NULL;

void enqueueCircular(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    if (rear_circular == NULL) {
        front_circular = rear_circular = new_node;
        rear_circular->next = front_circular;
        return;
    }
    rear_circular->next = new_node;
    rear_circular = new_node;
    rear_circular->next = front_circular;
}

int isEmptyCircularQueue() {
    return front_circular == NULL;
}

void dequeueCircular() {
    if (isEmptyCircularQueue()) {
        printf("Circular Queue Underflow\n");
        return;
    }
    struct Node* temp = front_circular;
    if (front_circular == rear_circular) {
        front_circular = rear_circular = NULL;
    } else {
        front_circular = front_circular->next;
        rear_circular->next = front_circular;
    }
    free(temp);
}

void displayCircularQueue() {
    if (isEmptyCircularQueue()) {
        printf("Circular Queue is empty\n");
        return;
    }
    struct Node* temp = front_circular;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front_circular);
    printf("Circular head\n");
}

// Dequeue implementation using Linked List
struct Node* front_deque = NULL;
struct Node* rear_deque = NULL;

void enqueueFront(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = front_deque;
    if (front_deque == NULL)
        rear_deque = new_node;
    front_deque = new_node;
}

void enqueueRear(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (rear_deque == NULL) {
        front_deque = rear_deque = new_node;
        return;
    }
    rear_deque->next = new_node;
    rear_deque = new_node;
}

int isEmptyDeque() {
    return front_deque == NULL;
}

void dequeueFront() {
    if (isEmptyDeque()) {
        printf("Deque Underflow\n");
        return;
    }
    struct Node* temp = front_deque;
    front_deque = front_deque->next;
    if (front_deque == NULL)
        rear_deque = NULL;
    free(temp);
}

void dequeueRear() {
    if (isEmptyDeque()) {
        printf("Deque Underflow\n");
        return;
    }
    struct Node* temp = front_deque;
    if (front_deque == rear_deque) {
        front_deque = rear_deque = NULL;
        free(temp);
        return;
    }
    while (temp->next != rear_deque)
        temp = temp->next;
    free(rear_deque);
    rear_deque = temp;
    rear_deque->next = NULL;
}

void displayDeque() {
    struct Node* temp = front_deque;
    if (isEmptyDeque()) {
        printf("Deque is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    dequeue();
    displayQueue();

    enqueueCircular(40);
    enqueueCircular(50);
    enqueueCircular(60);
    displayCircularQueue();
    dequeueCircular();
    displayCircularQueue();

    enqueueFront(70);
    enqueueRear(80);
    enqueueFront(90);
    displayDeque();
    dequeueRear();
    dequeueFront();
    displayDeque();

    return 0;
}
