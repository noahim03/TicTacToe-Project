#ifndef BOARD_UTILS_H
#define BOARD_UTILS_H

// Function to get a column from the board as a string
char* get_column(char** board, int dimensions, int col);

// Function to get the main (left-to-right) diagonal
char* get_left_diagonal(char** board, int dimensions);

// Function to get the other (right-to-left) diagonal
char* get_right_diagonal(char** board, int dimensions);

#endif