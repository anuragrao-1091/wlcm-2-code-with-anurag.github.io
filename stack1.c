#include <stdio.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Check if the stack is full
int isFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push.\n");
    } else {
        s->arr[++s->top] = value;
    }
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a special value to indicate an error
    } else {
        return s->arr[s->top--];
    }
}

// Peek at the top element of the stack without removing it
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a special value to indicate an error
    } else {
        return s->arr[s->top];
    }
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
        printf("5. Is Full\n");
        printf("6. Exit\n");
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
Enter the value to push: 40
Stack Operations:
1. Push
2. Pop
3. Peek
4. Is Empty
5. Is Full
6. Exit
Enter your choice: 2
Popped: 40
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
Stack is empty.Stack Operations:
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

