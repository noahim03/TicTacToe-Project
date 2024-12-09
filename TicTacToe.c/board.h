#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

typedef struct {
    char** contents;
    int dimensions;
    char blank_char;
} Board;

Board create_board(int dimensions, char blank_char);
bool is_full(Board* board);
bool tie(Board* board);
bool is_on_board(Board* board, int row, int col);
bool is_empty(Board* board, int row, int col);
void destroy_board(Board* board);
void print_board(Board* board); // Declaration only

#endif // BOARD_H
