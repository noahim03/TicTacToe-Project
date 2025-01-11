#include <stdlib.h>
#include <stdbool.h>
#include "winning.h"
#include "board.h"

bool is_game_over(char** board, int dimensions, char blank_space){
    return has_a_player_won(board, dimensions, blank_space) || 
           is_tie_game(board, dimensions, blank_space);
}

bool has_a_player_won(char** board, int dimensions, char blank_space){
    return has_a_player_won_horizontally(board, dimensions, blank_space) ||
           has_a_player_won_vertically(board, dimensions, blank_space) ||
           has_a_player_won_diagonally(board, dimensions, blank_space); 
}

bool has_a_player_won_horizontally(char** board, int dimensions, char blank_space){

    for(int i = 0; i < dimensions; ++i){

        if(contains_win(board[i], dimensions, blank_space)){
            return true;
        }
    }
    return false; 

}

bool has_a_player_won_vertically(char** board, int dimensions, char blank_space){

    for(int i = 0; i < dimensions; ++i){
        char* cur_col = get_column(board, dimensions, i);
        bool is_win = contains_win(cur_col, dimensions, blank_space);
        free(cur_col);
        if(is_win){
            return true;
        }
    }

    return false;
}

bool has_a_player_won_diagonally(char** board, int dimensions, char blank_space){
    char* left_diagonal = get_left_diagonal(board, dimensions);
    char* right_diagonal = get_right_diagonal(board, dimensions);
    bool is_win =  contains_win(left_diagonal, dimensions, blank_space) || 
                   contains_win(right_diagonal, dimensions, blank_space);
    free(left_diagonal);
    free(right_diagonal);
    return is_win;
}

bool contains_win(char* sequence, int length , char blank_space){
    return sequence[0] != blank_space && are_all_same(sequence, length);
}

bool are_all_same(char* str, int len){
    for(int i = 1; i < len; ++i){
        if(str[i] != str[0]){
            return false;
        }
    }
    return true; 
}

bool is_tie_game(char** board, int dimensions, char blank_space){
    for(int i = 0; i < dimensions; ++i){
        for(int j = 0; j < dimensions; ++j){
            if(board[i][j] == blank_space){
                return false;
            }
        }
    }
    return !has_a_player_won(board, dimensions, blank_space);
}