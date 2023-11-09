#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Evaluate a prefix expression
int evaluatePrefixExpression(char expression[]) {
    struct Stack stack;
    initialize(&stack);

    int result;

    // Process the expression from right to left
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // If it's a digit, convert to integer and push onto the stack
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            // Ignore spaces
            continue;
        } else {
            // If it's an operator, pop two operands from the stack, perform the operation, and push the result back
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return -1;
            }
        }
    }

    // The final result will be at the top of the stack
    result = pop(&stack);

    if (!isEmpty(&stack)) {
        // If the stack is not empty, the expression is invalid
        printf("Invalid expression.\n");
        return -1;
    }

    return result;
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter the prefix expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePrefixExpression(expression);

    if (result != -1) {
        printf("Result of the prefix expression: %d\n", result);
    }

    return 0;
}
//Output-
Enter the prefix expression: +ab
Stack is empty. Cannot pop.
Stack is empty. Cannot pop.
Stack is empty. Cannot pop.
Invalid operator: a