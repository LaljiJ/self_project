//////////////////////////////////////////////////////////
// Name: Lalji J
// Organization : Vector India Pvt Ltd
// File: tic tac toe game
// Description: tic tac toe game using c programming
//////////////////////////////////////////////////////////


/* Standard header file */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* macro define */
#define SIZE 3

/* Global variable */
char board[SIZE][SIZE];
char player1[50], player2[50];
char symbol1, symbol2;

/* Function defination */
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '1' + (i * SIZE + j);
        }
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("-----------\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') return 0;
        }
    }
    return 1;
}

void makeMove(char player, char *playerName) {
    int choice;
    while (1) {
        printf("%s (%c), enter your move (1-9): ", playerName, player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move! Choose a number between 1 and 9.\n");
            continue;
        }

        int row = (choice - 1) / SIZE;
        int col = (choice - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Spot already taken! Try again.\n");
        } else {
            board[row][col] = player;
            break;
        }
    }
}


/* Main function */
int main() {
    printf("Enter name of Player 1: ");
    scanf("%s", player1);
    printf("Enter name of Player 2: ");
    scanf("%s", player2);

    while (1) {
        printf("%s, choose your symbol (X or O): ", player1);
        scanf(" %c", &symbol1);
        symbol1 = toupper(symbol1); // Convert input to uppercase
        if (symbol1 == 'X' || symbol1 == 'O') break;
        printf("Invalid symbol! Choose either X or O.\n");
    }

    symbol2 = (symbol1 == 'X') ? 'O' : 'X';
    printf("%s will play as %c\n", player1, symbol1);
    printf("%s will play as %c\n", player2, symbol2);

    char currentPlayer = symbol1;
    char *currentPlayerName = player1;
    initializeBoard();
    displayBoard();

    while (1) {
        makeMove(currentPlayer, currentPlayerName);
        displayBoard();

        if (checkWin()) {
            printf("%s wins! Congratulations!\n", currentPlayerName);
            break;
        }
        if (isDraw()) {
            printf("It's a draw!\n");
            break;
        }
        
        if (currentPlayer == symbol1) {
            currentPlayer = symbol2;
            currentPlayerName = player2;
        } else {
            currentPlayer = symbol1;
            currentPlayerName = player1;
        }
    }
    return 0;
}

