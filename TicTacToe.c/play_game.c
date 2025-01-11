#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "play_game.h"
#include "winning.h"
#include "input_validation.h"

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

void play_game(char** board, int dimensions, char blank_space, char* player_pieces, int cur_player_turn){
    while(true){
        current_player_take_turn(board, dimensions, blank_space, cur_player_turn, player_pieces[cur_player_turn]);
        if(is_game_over(board, dimensions, blank_space)){
            break;
        }
        cur_player_turn = switch_to_next_player(cur_player_turn);
    }
    announce_results(board, dimensions, blank_space, cur_player_turn);
}



void current_player_take_turn(char** board, int dimensions, char blank_space, int cur_player_turn, char cur_players_piece){
    int row, col;
    display_board(board, dimensions);
    get_valid_player_spot_to_play(board, dimensions, blank_space, cur_player_turn, &row, &col);
    board[row][col] = cur_players_piece; 

}

void  get_valid_player_spot_to_play(char** board, int dimensions, char blank_space, int cur_player_turn, int *row, int *col){
    int num_args_read;
    do{
        printf("Player %d enter a spot to play in the form row col: ", cur_player_turn + 1);
        num_args_read = scanf("%d %d", row, col);
    }while(!is_valid_spot_to_play(board, dimensions, blank_space, *row, *col, num_args_read));
}

bool is_valid_spot_to_play(char** board, int dimensions, char blank_space, int row, int col, int num_args_read){
    return isValidFormat(num_args_read, 2) && 
           is_on_board(row, col, dimensions) && board[row][col] == blank_space;
}

bool is_on_board(int row, int col, int dimensions){
    return is_between(row, 0, dimensions - 1) && is_between(col, 0, dimensions -1);
}

bool is_between(int value, int min_value, int max_value){
    return value >= min_value && value <= max_value;
}