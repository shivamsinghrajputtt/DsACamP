#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of requests

// Queue structure to hold floor requests
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue *q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Add a floor request to the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more requests.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Floor %d added to the queue.\n", value);
    }
}

// Remove and return the first floor request from the queue
int dequeue(struct Queue *q) {
    int floor;
    if (isEmpty(q)) {
        printf("No floors in queue. Please request a floor.\n");
        return -1;
    } else {
        floor = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset queue after all requests are served
        }
        return floor;
    }
}

// Function to simulate the lift operation
void operateLift(struct Queue *q, int *currentFloor) {
    if (isEmpty(q)) {
        printf("No floors in the queue. Lift is idle.\n");
        return;
    }

    int nextFloor = dequeue(q);
    if (nextFloor == -1) {
        return;
    }

    printf("Moving from floor %d to floor %d\n", *currentFloor, nextFloor);

    if (nextFloor > *currentFloor) {
        for (int i = *currentFloor + 1; i <= nextFloor; i++) {
            printf("Lift moving up to floor %d\n", i);
        }
    } else if (nextFloor < *currentFloor) {
        for (int i = *currentFloor - 1; i >= nextFloor; i--) {
            printf("Lift moving down to floor %d\n", i);
        }
    }

    *currentFloor = nextFloor;
    printf("Lift has reached floor %d\n", *currentFloor);
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    int currentFloor = 0;  // Lift starts at ground floor
    int choice, floorRequest;

    while (1) {
        printf("\nCurrent floor: %d\n", currentFloor);
        printf("1. Request a floor\n");
        printf("2. Operate the lift\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the floor number to request: ");
                scanf("%d", &floorRequest);
                if (floorRequest == currentFloor) {
                    printf("You are already on floor %d\n", currentFloor);
                } else {
                    enqueue(&q, floorRequest);
                }
                break;
            case 2:
                operateLift(&q, &currentFloor);
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
