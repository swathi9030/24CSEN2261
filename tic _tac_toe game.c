#include <stdio.h>

char board[3][3]; 
char currentPlayer; 

void initializeBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return 1; 
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || 
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return 1; 
    }

    return 0; 
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; 
            }
        }
    }
    return 1; 
}

void playerMove() {
    int choice;
    printf("Player %c, enter your move (1-9): ", currentPlayer);
    scanf("%d", &choice);

    if (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O') {
        printf("Invalid move! Try again.\n");
        playerMove();
    } else {
        board[(choice - 1) / 3][(choice - 1) % 3] = currentPlayer;
    }
}

int main() {
    int gameOver = 0;
    currentPlayer = 'X';

    initializeBoard();

    while (!gameOver) {
        printBoard();  
        playerMove();  

        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        }
        else if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        }
        else {
            switchPlayer();
        }
    }

    return 0;
}



OUTPUT :

 1 | 2 | 3 
---|---|---
 4 | 5 | 6 
---|---|---
 7 | 8 | 9 

Player X, enter your move (1-9): 5

 1 | 2 | 3 
---|---|---
 4 | X | 6 
---|---|---
 7 | 8 | 9 

Player O, enter your move (1-9): 1

 O | 2 | 3 
---|---|---
 4 | X | 6 
---|---|---
 7 | 8 | 9 

Player X, enter your move (1-9): 8

 O | 2 | 3 
---|---|---
 4 | X | 6 
---|---|---
 7 | X | 9 

Player O, enter your move (1-9): 3

 O | 2 | O 
---|---|---
 4 | X | 6 
---|---|---
 7 | X | 9 

Player X, enter your move (1-9): 9

 O | 2 | O 
---|---|---
 4 | X | 6 
---|---|---
 7 | X | X 

Player O, enter your move (1-9): 4

 O | 2 | O 
---|---|---
 O | X | 6 
---|---|---
 7 | X | X 

Player X, enter your move (1-9): 7

 O | 2 | O 
---|---|---
 O | X | 6 
---|---|---
 X | X | X 

Player X wins!
