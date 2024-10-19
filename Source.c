#include <stdio.h>
#include <stdbool.h>

int gameState[3][3] = {0};

typedef struct {
    int x; 
    int y;
} Move;

void initBoard(char board[3][3]);
void printBoard(char board[3][3]);
void gameStateTrack(int gameState[3][3], int inputX, int inputY, bool isPlayer);
void updateBoard(char board[3][3], int inputX, int inputY, bool isPlayer);
int evaluate(int gameState[3][3]);
bool isMovesLeft(int gameState[3][3]);
int minimax(int gameState[3][3], int depth, bool isMax);
Move findBestMove(int gameState[3][3]);


void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[3][3]) {
    printf('\n');
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c ", i+1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("  ---|---|---\n");
    }
    printf("\n");
}

void gameStateTrack(int gameState[3][3], int inputX, int inputY, bool isPlayer) {
    if (isPlayer) {
        gameState[inputX][inputY] = 1;
    }
    else {
        gameState[inputX][inputY] = 2;
    }
}

void updateBoard(char board[3][3], int inputX, int inputY, bool isPlayer) {
    if (isPlayer) {
        board[inputX][inputY] = 'X';
    }
    else {
        board[inputX][inputY] = 'O';
    }
}

int evaluate(int gameState[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (gameState[i][0] == gameState[i][1] &&
            gameState[i][1] == gameState[i][2]) { 
                if (gameState[i][0] == 1) return -10;
                else if (gameState[i][0] == 2) return +10;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (gameState[0][j] == gameState[1][j] &&
            gameState[1][j] == gameState[2][j]) {
                if (gameState[0][j] == 1) return -10;
                else if (gameState[0][j] == 2) return +10;
        }
    }
    if (gameState[0][2] == gameState[1][1] &&
        gameState[1][1] == gameState[2][0]) {
            if (gameState[0][2] == 1) return -10;
            else if (gameState[0][2] == 2) return +10;
    }
    if (gameState[0][0] == gameState[1][1] &&
        gameState[1][1] == gameState[2][2]) {
            if (gameState[0][0] == 1) return -10;
            else if (gameState[0][0] == 2) return +10;
    }
    return 0;
}

bool isMovesLeft(int gameState[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(gameState[i][j] == 0) return true;
        }
    }
    return false;
}

int minimax(int gameState[3][3], int depth, bool isMax) {
    
}

Move findBestMove(int gameState[3][3]) {

}

int main(int arcv, char *argc[]) {
    int usrStart;
    bool runGame;
    printf("To start game, press 1\n");
    printf("To quit, press 2\n");
    printf("Enter: ");
    scanf("%d", &usrStart);

    if (usrStart == 2) {
        runGame = false;
    }
    else if (usrStart == 1) {
        runGame = true;
    }
    else {
        printf("Error, incorrect input\n");
        return -1;
    }

    while (runGame) {

    }



    return 0;
}

