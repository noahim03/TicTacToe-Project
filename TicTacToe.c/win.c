#include <stdbool.h>
#include <stdlib.h>
#include "board.h"

bool all_same(char* array, int length) {
    char first = array[0];
    if (first == ' ') {
        return false; // Ensure that an empty row/column/diagonal does not count as a win
    }
    for (int i = 1; i < length; i++) {
        if (array[i] != first) {
            return false;
        }
    }
    return true;
}

char* get_column_i(Board* board, int col) {
    char* column = (char*)malloc(board->dimensions * sizeof(char));
    for (int i = 0; i < board->dimensions; i++) {
        column[i] = board->contents[i][col];
    }
    return column;
}

bool someone_won_horizontally(Board* board) {
    for (int i = 0; i < board->dimensions; i++) {
        if (all_same(board->contents[i], board->dimensions)) {
            return true;
        }
    }
    return false;
}

bool someone_won_vertically(Board* board) {
    for (int i = 0; i < board->dimensions; i++) {
        char* column = get_column_i(board, i);
        if (all_same(column, board->dimensions)) {
            free(column);
            return true;
        }
        free(column);
    }
    return false;
}

bool someone_won_diagonally_left(Board* board) {
    char upper_left = board->contents[0][0];
    if (upper_left == ' ') {
        return false; // Ensure that an empty diagonal does not count as a win
    }
    for (int i = 1; i < board->dimensions; i++) {
        if (board->contents[i][i] != upper_left) {
            return false;
        }
    }
    return true;
}

bool someone_won_diagonally_right(Board* board) {
    char upper_right = board->contents[0][board->dimensions - 1];
    if (upper_right == ' ') {
        return false; // Ensure that an empty diagonal does not count as a win
    }
    for (int i = 1; i < board->dimensions; i++) {
        if (board->contents[i][board->dimensions - 1 - i] != upper_right) {
            return false;
        }
    }
    return true;
}

bool someone_won(Board* board) {
    return someone_won_horizontally(board) || someone_won_vertically(board) || 
           someone_won_diagonally_left(board) || someone_won_diagonally_right(board);
}