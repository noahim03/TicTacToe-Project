#ifndef PLAY_GAME_H
#define PLAY_GAME_H

// Expose these functions to the frontend
void initialize_game(int dimensions, char blank_space);
int make_move(int row, int col, int player);
int check_game_status(); // 0 = ongoing, 1 = player 1 wins, 2 = player 2 wins, 3 = tie

void setup_game(int dimensions, char blank_space, char*** board, char** player_pieces, int* cur_player_turn);
void clean_up(char** board, int dimensions, char* player_pieces);

// Main game loop
void play_game(char** board, int dimensions, char blank_space, char* player_pieces, int cur_player_turn);

#endif