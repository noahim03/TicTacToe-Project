#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "win.h"

Board create_board(int dimensions, char blank_char) {
    Board board = {NULL, dimensions, blank_char};
    board.contents = (char**)malloc(dimensions * sizeof(char*));
    for(int i = 0; i < dimensions; i++){
        board.contents[i] = (char*)malloc(dimensions * sizeof(char));
        for(int j = 0; j < dimensions; j++){
            board.contents[i][j] = blank_char;
        }
    }
    return board;
}

bool is_full(Board* board){
    for(int i = 0; i < board->dimensions; i++){
        for(int j = 0; j < board->dimensions; j++){
            if(board->contents[i][j] == board->blank_char){
                return false;
            }
        }
    }
    return true;
}

bool tie(Board* board) {
    return is_full(board) && !someone_won(board);
}

bool is_on_board(Board* board, int row, int col){
    return row >= 0 && row < board->dimensions && col >= 0 && col < board->dimensions;
}

bool is_empty(Board* board, int row, int col){
    return board->contents[row][col] == board->blank_char;
}   

void destroy_board(Board* board){
    for(int i = 0; i < board->dimensions; i++){
        free(board->contents[i]);
    }
    free(board->contents);
    board->contents = NULL;
    board->dimensions = 0;
}

void print_board(Board* board) {
    for (int i = 0; i < board->dimensions; i++) {
        for (int j = 0; j < board->dimensions; j++) {
            printf("%c ", board->contents[i][j]);
        }
        printf("\n");
    }
}