#include "input_validation.h"
#include <stdio.h>

bool isValidFormat(int num_args_read, int expected_args) {
    return num_args_read == expected_args;
}

bool is_between(int value, int min_value, int max_value) {
    return value >= min_value && value <= max_value;
}

bool is_on_board(int row, int col, int dimensions) {
    return is_between(row, 0, dimensions - 1) && is_between(col, 0, dimensions - 1);
}

bool is_valid_spot_to_play(char** board, int dimensions, char blank_space, int row, int col, int num_args_read) {
    return isValidFormat(num_args_read, 2) && 
           is_on_board(row, col, dimensions) && 
           board[row][col] == blank_space;
}

void get_valid_player_spot_to_play(char** board, int dimensions, char blank_space, int cur_player_turn, int *row, int *col) {
    int num_args_read;
    do {
        printf("Player %d enter a spot to play in the form row col: ", cur_player_turn + 1);
        num_args_read = scanf("%d %d", row, col);
        
        // Adjust for 0-based indexing
        (*row)--;
        (*col)--;
        
        // Clear input buffer if input was invalid
        if (num_args_read != 2) {
            while (getchar() != '\n');
            printf("Invalid input! Please enter two numbers.\n");
        } else if (!is_on_board(*row, *col, dimensions)) {
            printf("Position is off the board! Try again.\n");
        } else if (board[*row][*col] != blank_space) {
            printf("That position is already taken! Try again.\n");
        }
    } while (!is_valid_spot_to_play(board, dimensions, blank_space, *row, *col, num_args_read));
}


