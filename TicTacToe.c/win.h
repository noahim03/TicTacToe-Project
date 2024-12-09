#ifndef WIN_H
    #define WIN_H

    #include "board.h"
    #include <stdbool.h>

    bool someone_won(Board* board);
    bool someone_won_row(Board* board, int row);
    bool someone_won_column(Board* board, int col);
    bool someone_won_diagonally_left(Board* board);
    bool someone_won_diagonally_right(Board* board);

#endif
