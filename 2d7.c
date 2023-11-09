#include <stdio.h>

#define SIZE 3

// Function to print the Tic-Tac-Toe board
void printBoard(char board[SIZE][SIZE]) {
    printf("Tic-Tac-Toe Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; // Player has won
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1; // Player has won
    }

    return 0; // No win yet
}

// Function to check if the board is full
int checkFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char currentPlayer = 'X';

    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Main game loop
    do {
        // Print the current state of the board
        printBoard(board);

        // Get the player's move
        printf("Player %c's turn. Enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the chosen cell is empty
        if (board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Check if the board is full (resulting in a tie)
            if (checkFull(board)) {
                printBoard(board);
                printf("It's a tie!\n");
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Cell already occupied. Try again.\n");
        }

    } while (1);

    return 0;
}
//Output-
Tic-Tac-Toe Board:
      
Player X's turn. Enter row and column (1-3): 5 6
Cell already occupied. Try again.
Tic-Tac-Toe Board:
      
      
      

Player X's turn. Enter row and column (1-3): 2 6
Tic-Tac-Toe Board:
      
      
    X 

Player O's turn. Enter row and column (1-3):