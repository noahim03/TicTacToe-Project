#include <stdio.h>
#include <stdbool.h>
#include "move.h"
#include "board.h"
#include "input_val.h"

bool is_between(int value, int start, int end){
    return value >= start && value <= end;
}

bool is_valid_move(Board* board, Move move) {
    return is_on_board(board, move.row, move.col) && is_empty(board, move.row, move.col);
}

Move get_move(Board* board) {
    Move move;
    do {
        scanf("%d %d", &move.row, &move.col);
    } while (!is_valid_move(board, move));
    return move;
}
