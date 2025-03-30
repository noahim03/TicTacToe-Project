#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "board.h"
#include "play_game.h"
#include "winning.h"
#include "input_validation.h"
#include <string.h>

// Keep only function prototypes that are not already in input_validation.h
int check_win(char** board, int dimensions, char player_piece);
int check_draw(char** board, int dimensions, char blank_space);
int make_player_move(char** board, int dimensions, char blank_space, char player_piece);
void current_player_take_turn(char** board, int dimensions, char blank_space, int cur_player_turn, char cur_players_piece);

int switch_to_next_player(int cur_player_turn){
    if(cur_player_turn == 0){
        return 1;
    }else{
        return 0;
    }
}

void announce_results(char** board, int dimensions, char blank_space, int cur_player_turn){
    display_board(board, dimensions);
    if(has_a_player_won(board, dimensions, blank_space)){
        if(cur_player_turn == 0){
            printf("Player 1 won!");
        }else{
            printf("Player 2 won!");
        }
    }else{
        printf("Tie Game.");
    }
}

void play_game(char** board, int dimensions, char blank_space, char* player_pieces, int cur_player_turn) {
    int row, col;
    
    while (!is_game_over(board, dimensions, blank_space)) {
        display_board(board, dimensions);
        
        printf("Player %d's turn (%c)\n", cur_player_turn + 1, player_pieces[cur_player_turn]);
        
        // Get valid move from player
        get_valid_player_spot_to_play(board, dimensions, blank_space, cur_player_turn, &row, &col);
        
        // Make the move
        board[row][col] = player_pieces[cur_player_turn];
        
        // Check if current player won
        if (has_a_player_won(board, dimensions, blank_space)) {
            display_board(board, dimensions);
            printf("Player %d (%c) wins!\n", cur_player_turn + 1, player_pieces[cur_player_turn]);
            return;
        }
        
        // Check for tie game
        if (is_tie_game(board, dimensions, blank_space)) {
            display_board(board, dimensions);
            printf("Game ends in a tie!\n");
            return;
        }
        
        // Switch player turn
        cur_player_turn = (cur_player_turn + 1) % 2;
    }
}

int check_win(char** board, int dimensions, char player_piece) {
    int i, j;
    int win;
    
    // Check rows
    for (i = 0; i < dimensions; i++) {
        win = 1;
        for (j = 0; j < dimensions; j++) {
            if (board[i][j] != player_piece) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    
    // Check columns
    for (j = 0; j < dimensions; j++) {
        win = 1;
        for (i = 0; i < dimensions; i++) {
            if (board[i][j] != player_piece) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    
    // Check main diagonal
    win = 1;
    for (i = 0; i < dimensions; i++) {
        if (board[i][i] != player_piece) {
            win = 0;
            break;
        }
    }
    if (win) return 1;
    
    // Check other diagonal
    win = 1;
    for (i = 0; i < dimensions; i++) {
        if (board[i][dimensions - 1 - i] != player_piece) {
            win = 0;
            break;
        }
    }
    return win;
}

int check_draw(char** board, int dimensions, char blank_space) {
    int i, j;
    
    for (i = 0; i < dimensions; i++) {
        for (j = 0; j < dimensions; j++) {
            if (board[i][j] == blank_space) {
                return 0; // Not a draw, empty space exists
            }
        }
    }
    return 1; // Draw, no empty spaces
}

int make_player_move(char** board, int dimensions, char blank_space, char player_piece) {
    int row, col;
    
    get_valid_player_spot_to_play(board, dimensions, blank_space, 0, &row, &col);
    board[row][col] = player_piece;
    return 1;
}

void current_player_take_turn(char** board, int dimensions, char blank_space, int cur_player_turn, char cur_players_piece){
    int row, col;
    display_board(board, dimensions);
    get_valid_player_spot_to_play(board, dimensions, blank_space, cur_player_turn, &row, &col);
    board[row][col] = cur_players_piece; 
}

static char** board;
static char* player_pieces;
static int cur_player_turn;
static int dimensions;
static char blank_space;

void initialize_game(int dim, char blank) {
    dimensions = dim;
    blank_space = blank;
    cur_player_turn = 0;

    // Allocate memory for the board
    board = (char**)malloc(dimensions * sizeof(char*));
    for (int i = 0; i < dimensions; i++) {
        board[i] = (char*)malloc(dimensions * sizeof(char));
        for (int j = 0; j < dimensions; j++) {
            board[i][j] = blank_space;
        }
    }

    // Allocate memory for player pieces
    player_pieces = (char*)malloc(2 * sizeof(char));
    player_pieces[0] = 'X';
    player_pieces[1] = 'O';
}

int make_move(int row, int col, int player) {
    if (row < 0 || row >= dimensions || col < 0 || col >= dimensions || board[row][col] != blank_space) {
        return -1; // Invalid move
    }

    board[row][col] = player_pieces[player];
    cur_player_turn = (cur_player_turn + 1) % 2;
    return 0; // Move successful
}

int check_game_status() {
    if (has_a_player_won(board, dimensions, blank_space)) {
        return cur_player_turn == 0 ? 2 : 1; // Return the winner (1 or 2)
    }
    if (is_tie_game(board, dimensions, blank_space)) {
        return 3; // Tie
    }
    return 0; // Game ongoing
}