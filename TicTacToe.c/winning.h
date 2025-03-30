#ifndef WINNING_H
    #define WINNING_H
    #include <stdbool.h>
    bool is_game_over(char** board, int dimensions, char blank_space);
    bool has_a_player_won(char** board, int dimensions, char blank_space);
    bool has_a_player_won_horizontally(char** board, int dimensions, char blank_space);
    bool has_a_player_won_vertically(char** board, int dimensions, char blank_space);
    bool has_a_player_won_diagonally(char** board, int dimensions, char blank_space);
    bool contains_win(char* sequence, int length , char blank_space);
    bool are_all_same(char* str, int len);
    bool is_tie_game(char** board, int dimensions, char blank_space);

#endif 