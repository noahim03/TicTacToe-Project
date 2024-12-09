#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "player.h"
#include "game.h"

bool is_piece_already_chosen(char piece, Player* players, int len) {
    for (int i = 0; i < len; i++) {
        if (players[i].piece == piece) {
            return true;
        }
    }
    return false;
}

char* get_player_name() {
    char* name = (char*)malloc(50 * sizeof(char));
    printf("Enter player name: ");
    scanf("%s", name);
    return name;
}

char get_player_piece(Player* players, int len) {
    char piece;
    while (true) {
        printf("Enter a piece character: ");
        scanf(" %c", &piece);
        if (is_piece_already_chosen(piece, players, len)) {
            printf("%c already chosen. Please choose a different piece.\n", piece);
        } else {
            return piece;
        }
    }
}

Player* players_pick_names_pieces(int num_players) {
    Player* players = (Player*)calloc(num_players, sizeof(Player));
    for (int i = 0; i < num_players; i++) {
        players[i].name = get_player_name();
        players[i].piece = get_player_piece(players, i);
    }
    return players;
}

void take_turn(struct Game* game) {
    Player* cur_player = get_cur_player(game);
    Move move;
    do {
        printf("%s, enter a spot on the board to play (use row,col format): ", cur_player->name);
        int result = scanf("%d %d", &move.row, &move.col);
        if (result != 2) {
            printf("Invalid input format. Please enter row and column as two integers.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
    } while (!is_valid_move(&game->b, move));
    game->b.contents[move.row][move.col] = cur_player->piece; // Update the board with the current player's piece
}


void destroy_player(Player* player){
    free(player->name);
    player->name = NULL;
    player->piece = '\0';
}