#define MAX_BOARD_SIZE 40
#define NBR_PIECES_TO_WIN 5
#define FIRST_PLAYER_ID 1
#define SECOND_PLAYER_ID 2

#include <stdio.h>
#include <stdbool.h>

void displayBoard(int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] , int size){
     for(int i = 0 ; i < size ; i ++){
        for(int j = 0 ; j < size ; j ++) printf("%d" , board[i][j]);
        printf("\n");
      }
}

bool isInsideBoard(int row , int column , int size){
    // Corrigido para >= 0 para incluir a primeira linha/coluna
    return (row >= 0 && row < size) && (column >= 0 && column < size);
}

bool checkHorizontally(int startRow , int startColumn , int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE]  , int size){
    int piece = board[startRow][startColumn];
    for(int column = startColumn + 1 ; column < startColumn + NBR_PIECES_TO_WIN ; column ++){
        if(! isInsideBoard(startRow , column , size) || piece != board[startRow][column] ) 
            return false;
    }
    return true;
}

bool checkVerticaly(int startRow , int startColumn , int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] , int size){
    int piece = board[startRow][startColumn];
    for(int row = startRow + 1 ; row < startRow + NBR_PIECES_TO_WIN ; row ++){
       if(! isInsideBoard(row , startColumn , size) || piece != board[row][startColumn])
           return false;
    }
    return true;
}

bool checkDiagonally(int startRow , int startColumn , int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size) {
    int piece = board[startRow][startColumn];
    bool isValidDiagonal1 = true;  // Check top-left to bottom-right
    bool isValidDiagonal2 = true;  // Check top-right to bottom-left
    
    // Check diagonal from top-left to bottom-right
    for (int i = 1; i < NBR_PIECES_TO_WIN; i++) {
        if (!isInsideBoard(startRow + i, startColumn + i, size) || piece != board[startRow + i][startColumn + i]) {
            isValidDiagonal1 = false;
        }
    }
    // Check diagonal from top-right to bottom-left
    for (int i = 1; i < NBR_PIECES_TO_WIN ; i ++) {
        if (!isInsideBoard(startRow + i , startColumn - i , size) || 
            piece != board[startRow + i][startColumn - i]
        ) 
            isValidDiagonal2 = false;
    }
    return isValidDiagonal1 || isValidDiagonal2;
}

int getWinner(int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] , int size){
    int winnerId = 0;
    for(int row = 0 ; row < size ; row ++){
        for(int column = 0 ; column < size ; column ++){
            int piece = board[row][column];
            if(piece != 0){
                 if(
                      checkHorizontally(row , column , board , size)
                   || checkVerticaly(row , column , board , size )
                   || checkDiagonally(row , column , board , size)
                  ) 
                 return piece;
            }
        }
     }
    return winnerId;
}

int main() {
    int boardSize;
    if (scanf("%d" , &boardSize) != 1) return 1;
    
    int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = { { 0 } };
    for(int i = 0 ; i < boardSize ; i ++)
        for(int j = 0 ; j < boardSize ; j ++) {
            if (scanf("%d" , &board[i][j]) != 1) return 1;
        }
        
    printf("%d" , getWinner(board , boardSize));
    return 0;
}
