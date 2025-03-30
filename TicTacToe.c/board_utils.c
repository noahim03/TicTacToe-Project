#include "board_utils.h"
#include <stdlib.h>

char* get_column(char** board, int dimensions, int col) {
    char* column = (char*)malloc((dimensions + 1) * sizeof(char));
    
    for (int i = 0; i < dimensions; i++) {
        column[i] = board[i][col];
    }
    column[dimensions] = '\0'; // Null-terminate the string
    
    return column;
}

char* get_left_diagonal(char** board, int dimensions) {
    char* diagonal = (char*)malloc((dimensions + 1) * sizeof(char));
    
    for (int i = 0; i < dimensions; i++) {
        diagonal[i] = board[i][i];
    }
    diagonal[dimensions] = '\0'; // Null-terminate the string
    
    return diagonal;
}

char* get_right_diagonal(char** board, int dimensions) {
    char* diagonal = (char*)malloc((dimensions + 1) * sizeof(char));
    
    for (int i = 0; i < dimensions; i++) {
        diagonal[i] = board[i][dimensions - 1 - i];
    }
    diagonal[dimensions] = '\0'; // Null-terminate the string
    
    return diagonal;
}