#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setup.h"
#include "input_validation.h"
#include "board.h"

// Function prototypes
bool is_in(char letter, const char* str, int len);
bool is_valid_piece(int num_args_read, char player_piece, char blank_space, char* player_pieces, int num_player_pieces);
char pick_piece(char blank_space, char* player_pieces, int num_player_pieces);

char* pick_player_pieces(char blank_space){
    const int num_players = 2;
    char* player_pieces = (char*)malloc(num_players * sizeof(char));
    for(int i = 0; i < num_players; ++i){
        player_pieces[i] = pick_piece(blank_space, player_pieces, i);
    }
    return player_pieces;
}

char pick_piece(char blank_space, char* player_pieces, int num_player_pieces){
    char player_piece;
    int num_args_read;
    
    do {
        printf("Player %d, pick your piece: ", num_player_pieces + 1);
        num_args_read = scanf(" %c", &player_piece);
        
        // Clear input buffer if input was invalid
        if (num_args_read != 1) {
            while (getchar() != '\n');
        }
    } while(!is_valid_piece(num_args_read, player_piece, blank_space, player_pieces, num_player_pieces));
    
    return player_piece;
}

bool is_valid_piece(int num_args_read, char player_piece, char blank_space, char* player_pieces, int num_player_pieces){
    return num_args_read == 1 && 
           player_piece != blank_space && 
           !is_in(player_piece, player_pieces, num_player_pieces);
}

bool is_in(char letter, const char* str, int len){
    for(int i = 0; i < len; ++i){
        if(str[i] == letter){
            return true;
        }
    }
    return false;
}

#include "setup.h"
#include <stdio.h>
#include <stdlib.h>

void setup_game(int dimensions, char blank_space, char*** board, char** player_pieces, int* cur_player_turn) {
    int i, j;
    
    // Allocate memory for the board
    *board = (char**)malloc(dimensions * sizeof(char*));
    for (i = 0; i < dimensions; i++) {
        (*board)[i] = (char*)malloc(dimensions * sizeof(char));
        for (j = 0; j < dimensions; j++) {
            (*board)[i][j] = blank_space;
        }
    }
    
    // Allocate memory for player pieces (X and O)
    *player_pieces = (char*)malloc(2 * sizeof(char));
    (*player_pieces)[0] = 'X';
    (*player_pieces)[1] = 'O';
    
    // Set first player's turn
    *cur_player_turn = 0; // Player X goes first
    
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: %c, Player 2: %c\n", (*player_pieces)[0], (*player_pieces)[1]);
    printf("Board size: %d x %d\n", dimensions, dimensions);
    printf("Enter row and column (1-%d) separated by space to make a move.\n\n", dimensions);
}

void clean_up(char** board, int dimensions, char* player_pieces) {
    int i;
    
    // Free the board memory
    for (i = 0; i < dimensions; i++) {
        free(board[i]);
    }
    free(board);
    
    // Free player pieces memory
    free(player_pieces);
}