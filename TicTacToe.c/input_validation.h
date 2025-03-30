#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <stdbool.h>

// Function to validate input format
bool isValidFormat(int num_args_read, int expected_args);

// Function to validate a position input
bool is_between(int value, int min_value, int max_value);

// Function to check if coordinates are on the board
bool is_on_board(int row, int col, int dimensions);

// Function to check if a spot is valid to play (empty and on board)
bool is_valid_spot_to_play(char** board, int dimensions, char blank_space, int row, int col, int num_args_read);

// Get valid player input for board position
void get_valid_player_spot_to_play(char** board, int dimensions, char blank_space, int cur_player_turn, int *row, int *col);

#endif