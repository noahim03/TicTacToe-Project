#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "board.h"
#include "player.h"

typedef struct Game {
    Board b;
    int current_player_turn;
    Player* players;
    int num_players;
} Game;

// Function declarations for game logic
Game setup_game(int dimensions, char blank_char);
bool is_game_over(Board* board);
Player* get_cur_player(struct Game* game);
void announce_result(Game* game);
void switch_turns(Game* game);
void play_game(Game* game);
void clean_up(Game* game);
int pick_who_goes_first(int num_players);

#endif // GAME_H
