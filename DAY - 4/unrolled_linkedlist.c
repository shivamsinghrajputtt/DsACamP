#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 4

struct Node {
    int numElements;
    int elements[MAX_NODES];
    struct Node* next;
};

struct UnrolledLinkedList {
    struct Node* head;
};

struct UnrolledLinkedList* createList() {
    struct UnrolledLinkedList* list = (struct UnrolledLinkedList*)malloc(sizeof(struct UnrolledLinkedList));
    list->head = NULL;
    return list;
}

void insert(struct UnrolledLinkedList* list, int value) {
    if (list->head == NULL) {
        list->head = (struct Node*)malloc(sizeof(struct Node));
        list->head->numElements = 0;
        list->head->next = NULL;
    }

    struct Node* current = list->head;
    while (current->next != NULL)
        current = current->next;

    if (current->numElements == MAX_NODES) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->numElements = 0;
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }

    current->elements[current->numElements] = value;
    current->numElements++;
}

void display(struct UnrolledLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        for (int i = 0; i < current->numElements; i++) {
            printf("%d ", current->elements[i]);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct UnrolledLinkedList* list = createList();

    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);
    insert(list, 6);

    display(list);

    return 0;
}
