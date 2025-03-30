#include <stdio.h>
#include "play_game.h"

int get_dimesions_from_command_line(int argc, char** argv){
    int dimensions = 3;
    int num_args_read;
    char should_be_empty;
    if(argc != 2){
        return dimensions;
    }

    num_args_read = sscanf(argv[1], "%d %c", &dimensions, &should_be_empty);
    if(num_args_read == 1){
        return dimensions;
    }else{
        return 3;
    }

}

// Renamed from initialize_game to start_game to avoid conflict
int start_game(int argc, char** argv){
    const char blank_space = '*';
    int dimensions = get_dimesions_from_command_line(argc, argv);
    char** board;
    char* player_pieces;
    int cur_player_turn;
    setup_game(dimensions, blank_space, &board, &player_pieces, &cur_player_turn);
    play_game(board, dimensions, blank_space, player_pieces, cur_player_turn);
    clean_up(board, dimensions, player_pieces);
    return 0;
}

// This is just a stub for WebAssembly compilation
// No game functionality should be in main.c when using WebAssembly
int main(int argc, char** argv) {
    // If you want to use the game functionality without WebAssembly
    return start_game(argc, argv);
    // return 0;
}
