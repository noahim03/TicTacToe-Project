#ifndef BOARD_H
    #define BOARD_H
    char** make_grid(int dimensions, char blank_space);
    void destroy_board(char** board, int dimensions);
    void display_board(char** board, int dimensions);
    char* get_left_diagonal(char** board, int dimensions);
    char* get_right_diagonal(char** board, int dimensions);
    char* get_column(char** board, int dimensions, int column_index);

#endif