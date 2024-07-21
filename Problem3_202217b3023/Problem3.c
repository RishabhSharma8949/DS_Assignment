#include<stdio.h>

int stack[100];  // Array to hold stack elements
int top = -1;    // Variable to track the top of the stack
int n;           // Size of the stack
int choice;      // User choice for stack operation
int x;           // Element to be pushed or popped
int i;           // Iterator for display operation

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main() {
    printf("\n Enter the size of STACK [MAX = 100]: ");
    scanf("%d", &n);
    
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1. PUSH");
    printf("\n\t 2. POP");
    printf("\n\t 3. DISPLAY");
    printf("\n\t 4. EXIT");

    do {
        printf("\n\n Enter the Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT");
                break;
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    } while(choice != 4);

    return 0;
}

void push() {
    if(top >= n - 1) {
        printf("\n\t STACK is Overflow");
    } else {
        printf("\n Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if(top <= -1) {
        printf("\n\t STACK is Underflow");
    } else {
        printf("\n\t The popped element is %d", stack[top]);
        top--;
    }
}

void display() {
    if(top >= 0) {
        printf("\n\t Elements in STACK are: ");
        for(i = top; i >= 0; i--) {
            printf("\n\t %d", stack[i]);
        }
        printf("\n\t Press Next Choice");
    } else {
        printf("\n\t The STACK is empty");
    }
}
