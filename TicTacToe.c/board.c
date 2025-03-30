#include <stdlib.h>
#include <stdio.h>
#include "board.h"

char** make_grid(int dimensions, char blank_space){
    char** board = (char**)malloc(dimensions * sizeof(char*));
    for(int i = 0; i < dimensions; ++i){
        board[i] = (char*) malloc(dimensions * sizeof(char));
        for(int j = 0; j < dimensions; ++j){
            board[i][j] = blank_space;
        }
    }
    return board;
}

void destroy_board(char** board, int dimensions){
    for(int i = 0; i < dimensions; ++i){
        free(board[i]);
    }
    free(board);
}

#include "board.h"
#include <stdio.h>

void display_board(char** board, int dimensions) {
    int i, j;
    
    printf("\n");
    // Print column numbers
    printf("  ");
    for (j = 0; j < dimensions; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");
    
    for (i = 0; i < dimensions; i++) {
        printf("%d ", i + 1); // Row numbers
        for (j = 0; j < dimensions; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char* get_column(char** board, int dimensions, int column_index){
    char* cur_col = (char*)malloc(dimensions * sizeof(char));
    for(int i = 0; i < dimensions; ++i){
        cur_col[i] = board[i][column_index]; 
    }
    return cur_col;
}

char* get_left_diagonal(char** board, int dimensions){
    char* diagonal = (char*)malloc(dimensions * sizeof(char));
    for(int i = 0; i < dimensions; ++i){
        diagonal[i] = board[i][i];
    }
    return diagonal;
}

char* get_right_diagonal(char** board, int dimensions){
    char* diagonal = (char*)malloc(dimensions * sizeof(char));
    for(int row = 0, col = dimensions - 1; row < dimensions; ++row, --col){
        diagonal[row] = board[row][col];
    }
    return diagonal;
}