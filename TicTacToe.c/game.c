#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "win.h"

Game setup_game(int dimensions, char blank_char){
    Game game;
    game.num_players = 2;   
    game.b = create_board(dimensions, blank_char);
    game.current_player_turn = pick_who_goes_first(game.num_players);
    game.players = players_pick_names_pieces(game.num_players);
    return game;
}

bool is_game_over(Board* board){
    return someone_won(board) || tie(board);
}

Player* get_cur_player(struct Game* game){
    return &game->players[game->current_player_turn];
}

void announce_result(Game* game){
    if(someone_won(&game->b)){
        Player* winner = get_cur_player(game);
        printf("%s won!\n", winner->name);
    }
    else{
        printf("It's a tie!\n");
    }
}

void switch_turns(Game* game){
    game->current_player_turn = (game->current_player_turn + 1) % game->num_players;
}

void play_game(Game* game) {
    printf("%s goes first!\n", game->players[game->current_player_turn].name);
    while (!is_game_over(&game->b)) {
        print_board(&game->b);  // Print the board before each move
        take_turn(game);       // Prompt the current player for their move
        if (is_game_over(&game->b)) {
            break;  // Exit the loop if the game is over after the move
        }
        switch_turns(game);    // Switch to the next player
    }
    print_board(&game->b);     // Print the board after the game ends
    announce_result(game);
}



void clean_up(Game* game) {
    destroy_board(&game->b);
    for (int i = 0; i < game->num_players; i++) {
        destroy_player(&game->players[i]);
    }
    free(game->players);
}

int pick_who_goes_first(int num_players) {
    return rand() % num_players;
}