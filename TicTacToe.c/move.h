#ifndef MOVE_H
#define MOVE_H

#include "board.h"

typedef struct {
    int row;
    int col;
} Move;

bool is_valid_move(Board* board, Move move);
Move get_move(Board* board);

#endif // MOVE_H
