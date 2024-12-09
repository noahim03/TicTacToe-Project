#ifndef PLAYER_H
#define PLAYER_H

#include "move.h"
#include "board.h"

typedef struct {
    char piece;
    char* name;
} Player;

struct Game; // Forward declaration of Game

int pick_who_goes_first(int num_players);
char* get_player_name();
char get_player_piece(Player* players_in_game, int len);
Player* players_pick_names_pieces(int num_players);
void take_turn(struct Game* game); 
void destroy_player(Player* player);

#endif
