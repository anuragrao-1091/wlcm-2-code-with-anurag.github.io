#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define a structure for the double stack
struct DoubleStack {
    int arr[MAX_SIZE];
    int top1; // Top of the first stack
    int top2; // Top of the second stack
};

// Initialize the double stack
void initialize(struct DoubleStack *ds) {
    ds->top1 = -1;
    ds->top2 = MAX_SIZE;
}

// Check if the first stack is empty
bool isEmpty1(struct DoubleStack *ds) {
    return (ds->top1 == -1);
}

// Check if the second stack is empty
bool isEmpty2(struct DoubleStack *ds) {
    return (ds->top2 == MAX_SIZE);
}

// Check if the first stack is full
bool isFull1(struct DoubleStack *ds) {
    return (ds->top1 + 1 == ds->top2);
}

// Check if the second stack is full
bool isFull2(struct DoubleStack *ds) {
    return (ds->top2 - 1 == ds->top1);
}

// Push an element onto the first stack
void push1(struct DoubleStack *ds, int value) {
    if (isFull1(ds)) {
        printf("Stack 1 is full. Cannot push.\n");
    } else {
        ds->arr[++ds->top1] = value;
    }
}

// Push an element onto the second stack
void push2(struct DoubleStack *ds, int value) {
    if (isFull2(ds)) {
        printf("Stack 2 is full. Cannot push.\n");
    } else {
        ds->arr[--ds->top2] = value;
    }
}

// Pop an element from the first stack
int pop1(struct DoubleStack *ds) {
    if (isEmpty1(ds)) {
        printf("Stack 1 is empty. Cannot pop.\n");
        return -1; // Return a special value to indicate an error
    } else {
        return ds->arr[ds->top1--];
    }
}

// Pop an element from the second stack
int pop2(struct DoubleStack *ds) {
    if (isEmpty2(ds)) {
        printf("Stack 2 is empty. Cannot pop.\n");
        return -1; // Return a special value to indicate an error
    } else {
        return ds->arr[ds->top2++];
    }
}

int main() {
    struct DoubleStack dStack;
    initialize(&dStack);

    int choice, value;

    while (1) {
        printf("Double Stack Operations:\n");
        printf("1. Push into Stack 1\n");
        printf("2. Pop from Stack 1\n");
        printf("3. Push into Stack 2\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push into Stack 1: ");
                scanf("%d", &value);
                push1(&dStack, value);
                break;
            case 2:
                value = pop1(&dStack);
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 3:
                printf("Enter the value to push into Stack 2: ");
                scanf("%d", &value);
                push2(&dStack, value);
                break;
            case 4:
                value = pop2(&dStack);
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
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
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 1
Enter the value to push into Stack 1: 30
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 2
Popped from Stack 1: 30
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 3
Enter the value to push into Stack 2: 60
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 2
Stack 1 is empty. Cannot pop.
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 1
Enter the value to push into Stack 1: 40
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 4
Popped from Stack 2: 60
Double Stack Operations:
1. Push into Stack 1
2. Pop from Stack 1
3. Push into Stack 2
4. Pop from Stack 2
5. Exit
Enter your choice: 5
Exiting the program.