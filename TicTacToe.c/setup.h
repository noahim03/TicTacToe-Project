#ifndef SETUP_H
#define SETUP_H

// Initialize the game board and players
void setup_game(int dimensions, char blank_space, char*** board, char** player_pieces, int* cur_player_turn);

// Clean up allocated memory
void clean_up(char** board, int dimensions, char* player_pieces);

#endif