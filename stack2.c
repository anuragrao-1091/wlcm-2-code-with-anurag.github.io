#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct CharStack {
    char arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct CharStack *s) {
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct CharStack *s) {
    return (s->top == -1);
}

// Check if the stack is full
bool isFull(struct CharStack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push a character onto the stack
void push(struct CharStack *s, char value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push.\n");
    } else {
        s->arr[++s->top] = value;
    }
}

// Pop a character from the stack
char pop(struct CharStack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0'; // Return a null character to indicate an error
    } else {
        return s->arr[s->top--];
    }
}

// Peek at the top character of the stack without removing it
char peek(struct CharStack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return '\0'; // Return a null character to indicate an error
    } else {
        return s->arr[s->top];
    }
}

int main() {
    struct CharStack stack;
    initialize(&stack);

    int choice;
    char value;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the character to push: ");
                scanf(" %c", &value); // Read a single character
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != '\0') {
                    printf("Popped: %c\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != '\0') {
                    printf("Peek: %c\n", value);
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
                if (isFull(&stack)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 6:
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
5. Is Full
6. Exit
Enter your choice: 1
Enter the character to push: a
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Is Full
6. Exit
Enter your choice: 2
Popped: a
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Is Full
6. Exit
Enter your choice: 3
Stack is empty. Cannot peek.
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Is Full
6. Exit
Enter your choice: 4
Stack is empty.
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Is Full
6. Exit
Enter your choice: 5
Stack is not full.
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Is Full
6. Exit
Enter your choice: 6
Exiting the program.
