#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "move.h"
#include "player.h"
#include "win.h"
#include "input_val.h"

int main() {
    // Create a 3x3 board
    Board board = create_board(3, ' ');

    // Get player names and pieces
    Player* players = players_pick_names_pieces(2);

    // Print the initial empty board
    printf("\nInitial Board:\n");
    print_board(&board);

    // Set the starting player
    int current_player_index = pick_who_goes_first(2);

    while (true) {
        // Print the current board state
        printf("\n%s, enter a spot on the board to play (use row,col format | row starts at 0 - 2, col starts at 0 - 2): ", players[current_player_index].name);
        Move move = get_move(&board);

        // Place the piece on the board
        board.contents[move.row][move.col] = players[current_player_index].piece;

        // Print the board after the move
        print_board(&board);

        // Check if the current player has won
        if (someone_won(&board)) {
            printf("\n%s won!\n", players[current_player_index].name);
            break;
        }

        // Check if the board is full (tie)
        if (is_full(&board)) {
            printf("\nIt's a tie!\n");
            break;
        }

        // Switch to the other player
        current_player_index = (current_player_index + 1) % 2;
    }

    // Free allocated memory
    destroy_board(&board);
    for (int i = 0; i < 2; i++) {
        destroy_player(&players[i]);
    }
    free(players);

    return 0;
}
