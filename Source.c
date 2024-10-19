#include <stdio.h>
#include <stdbool.h>

int gameState[3][3] = {0};

void gameStateTrack(int gameState[3][3], int inputX, int inputY, bool isPlayer) {
    if (isPlayer) {
        gameState[inputX][inputY] = 1;
    }
    else {
        gameState[inputX][inputY] = 2;
    }
}

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

void updateBoard(char board[3][3], int inputX, int inputY, bool isPlayer) {
    if (isPlayer) {
        board[inputX][inputY] = " X ";
    }
    else {
        board[inputX][inputY] = " O ";
    }
}

int botX(int x) {
    
}

int botY(int y) {

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

