#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the stack node
struct Node {
    int data;
    struct Node *next;
};

// Define a structure for the stack
struct Stack {
    struct Node *top;
};

// Initialize the stack
void initialize(struct Stack *s) {
    s->top = NULL;
}

// Check if the stack is empty
bool isEmpty(struct Stack *s) {
    return (s->top == NULL);
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a special value to indicate an error
    }

    struct Node *temp = s->top;
    int poppedValue = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedValue;
}

// Peek at the top element of the stack without removing it
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a special value to indicate an error
    }

    return s->top->data;
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, value;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Peek: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

//Output-
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Exit
Enter your choice: 1
Enter the value to push: 56
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Exit
Enter your choice: 2
Popped: 56
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Exit
Enter your choice: 3
Stack is empty. Cannot peek.
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Exit
Enter your choice: 5
Exiting the program.