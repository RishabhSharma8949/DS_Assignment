#include <stdio.h>
#include <stdlib.h>  // For exit() function

#define MAX_SIZE 5

void insert(int queue[], int *rear, int *item);
void delete(int queue[], int *front, int rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[MAX_SIZE];
    int front = 0, rear = 0;
    int choice, item;

    printf("Queue using Array");
    printf("\n1. Insertion");
    printf("\n2. Deletion");
    printf("\n3. Display");
    printf("\n4. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &item);
                insert(queue, &rear, &item);
                break;
            case 2:
                delete(queue, &front, rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("\nExiting from the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid menu option.");
        }
    }

    return 0;
}

// Function to insert an element into the queue
void insert(int queue[], int *rear, int *item) {
    if (*rear == MAX_SIZE) {
        printf("\nQueue is Full. Cannot insert element.\n");
    } else {
        queue[*rear] = *item;
        (*rear)++;
        printf("\nElement inserted successfully.\n");
    }
}

// Function to delete an element from the queue
void delete(int queue[], int *front, int rear) {
    if (*front == rear) {
        printf("\nQueue is Empty. Cannot delete element.\n");
    } else {
        printf("\nDeleted Element: %d\n", queue[*front]);
        (*front)++;
    }
}

// Function to display elements of the queue
void display(int queue[], int front, int rear) {
    int i;
    if (front == rear) {
        printf("\nQueue is Empty.\n");
    } else {
        printf("\nQueue Elements are:\n");
        for (i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
