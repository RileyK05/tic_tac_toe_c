#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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
    printf("\n");
    printf("    1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf(" %d  ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("    ---|---|---\n");
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
    int score = evaluate(gameState);
 
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (!isMovesLeft(gameState)) return 0;

    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameState[i][j] == 0) {
                    gameState[i][j] = 2;
                    int val = minimax(gameState, depth + 1, false);
                    if (val > best) best = val;
                    gameState[i][j] = 0;
                }
            }
        }
        return best;
    }
    else {
        int best = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameState[i][j] == 0) {
                    gameState[i][j] = 1;
                    int val = minimax(gameState, depth+1, true);
                    if (val < best) best = val;
                    gameState[i][j] = 0;
                }
            }
        }
        return best;
    }
}

Move findBestMove(int gameState[3][3]) {
    int bestVal = INT_MIN;
    Move bestMove;
    bestMove.x = -1;
    bestMove.y = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameState[i][j] == 0) {
                gameState[i][j] = 2;
                int moveVal = minimax(gameState, 0, false);
                gameState[i][j] = 0;
                if (moveVal > bestVal) {
                    bestMove.x = i;
                    bestMove.y = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main(int argc, char *argv[]) {
    int usrStart;
    bool runGame;
    char board[3][3];
    initBoard(board);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            gameState[i][j] = 0;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("You are 'X' and the bot is 'O'.\n");
    printf("To start the game, press 1\n");
    printf("To quit, press 2\n");
    printf("Enter: ");
    if (scanf("%d", &usrStart) != 1) {
        printf("Invalid input. Exiting...\n");
        return -1;
    }

    if (usrStart == 2) {
        runGame = false;
        printf("Goodbye!\n");
        return 0;
    }
    else if (usrStart == 1) {
        runGame = true;
    }
    else {
        printf("Error, incorrect input. Exiting...\n");
        return -1;
    }
    printBoard(board);

    while (runGame) {
        int inputX, inputY;

        printf("Enter your move (row and column numbers from 1 to 3, separated by space): ");
        if (scanf("%d %d", &inputX, &inputY) != 2) {
            printf("Invalid input. Please enter two numbers separated by space.\n");
            while (getchar() != '\n');
            continue;
        }

        inputX -= 1;
        inputY -= 1;

        if (inputX < 0 || inputX >= 3 || inputY < 0 || inputY >= 3 || gameState[inputX][inputY] != 0) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        gameStateTrack(gameState, inputX, inputY, true);
        updateBoard(board, inputX, inputY, true);
        printBoard(board);

        int score = evaluate(gameState);
        if (score == -10) {
            printf("Congratulations! You win!\n");
            break;
        }

        if (!isMovesLeft(gameState)) {
            printf("It's a draw!\n");
            break;
        }

        printf("Bot is making a move...\n");
        Move botMove = findBestMove(gameState);
        if (botMove.x != -1 && botMove.y != -1) {
            gameStateTrack(gameState, botMove.x, botMove.y, false);
            updateBoard(board, botMove.x, botMove.y, false);
            printBoard(board);

            score = evaluate(gameState);
            if (score == 10) {
                printf("Bot wins! Better luck next time.\n");
                break;
            }

            if (!isMovesLeft(gameState)) {
                printf("It's a draw!\n");
                break;
            }
        } else {
            printf("No moves left. It's a draw!\n");
            break;
        }
    }

    printf("Game over.\n");
    return 0;
}
