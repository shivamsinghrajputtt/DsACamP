#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

int stack[MAX];
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to add an element to the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to remove and return the top element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

// Function to return the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display the stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();  // Display stack

    printf("Top element is %d\n", peek());

    printf("Popped element is %d\n", pop());
    printf("Popped element is %d\n", pop());

    display();  // Display stack after popping

    return 0;
}
