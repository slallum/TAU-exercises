/*
 * interpreter.c
 *
 *  Created on: Dec 17, 2013
 *      Author: shir
 */
#include <stdlib.h>
#include <stdio.h>

#include "io.h"
#include "interpreter.h"
#include "game.h"
#include "tree.h"
#include "board.h"

static int get_depth(char *command_line);
static int is_set_depth_command(char* command_line);

void run_interpreter() {
    char command_line[MAX_COMMAND_LENGTH + 2];
    int depth;
    game *current_game;

    current_game = new_game(-1);
    if (current_game == NULL) {
        return;
    }

    print_board(&(current_game->current_board));

    get_command_line(command_line);
    depth = get_first_depth(command_line);
    // error
    if (depth == 0) {
        return;
    }
    current_game->depth = depth;
    return;
}


/*
/ gets the depth from the first command
/ keeps running until an error is accured or we got a good depth (between 1 and MAX_STEPS_NUMBER)
*/
int get_first_depth(char *command_line) {
    int depth = -1;
    int result;
    while (1) {
        result = get_command_line(command_line);
        // error in get_command_line - exit
        if (result == 0) {
            return 0;
        }
        // got cmd - checking that the first command line is `set number of steps`
        if (!is_set_depth_command(command_line)) {
            printf(ERROR_MESSAGE_FIRST_COMMAND_SET_NUMBER_STEPS);            
        }
        // cmd is indeed `set number of steps`
        else {
            depth = get_depth(command_line);
            if (depth == 0) {
                printf(ERROR_MESSAGE_STEPS_NON_ZERO);
            }
            else if (depth > MAX_STEPS_NUMBER) {
                printf(ERROR_MESSAGE_STEPS_OVER_LIMIT);
            }
            // alright - the depth if ok!
            else {
                return depth;
            }
        }
    }
        
}



void run_command(char *command){

}

void set_number_steps(game current_game, int steps) {
    current_game.depth = steps;
}

void suggest_move(game current_game){

}

void add_disc(game current_game, int column_num){
    current_game.current_board.make_move(current_game.current_board.cells, current_game.current_board.n, column_num, 1);
    update_tree(current_game.tree, &current_game.current_board, column_num, current_game.depth);
}

void restart_game(game *current_game){
    free(current_game->current_board.cells);
    free(current_game->tree);
    current_game = new_game(current_game->depth);
}

void quit() {

}


static int is_set_depth_command(char* command_line) {
    // TODO: implement
    return 1;
}


/* 
* assumes that command_line is a valid command line of `set number of steps`
*/
static int get_depth(char *command_line) {
    // TODO: implement
    return 1;
}