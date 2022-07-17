#include <stdlib.h>

#include "../includes/logic.h"
#include "../includes/game.h"
#include "../includes/prisoner.h"
#include "../includes/box.h"

int make_choice(prisoner_t prisoner, box_t boxes[], box_t path[], game_state_t *state){
    switch(state->strategy){
        case LOOPY:
            return loopy_strat(prisoner, boxes, path, prisoner.num, TRIES_LIMIT);
            break;
        case RANDOMNESS:
            return rand_strat(prisoner, boxes, path, TRIES_LIMIT);
            break;
        default:
            return 0;
            break;
    }

    return 0;
}

int loopy_strat(prisoner_t prisoner, box_t boxes[], box_t path[], int searching_in, int tries_left){
    tries_left--;
    if(tries_left == 0){
        return 0;
    }

    int paper = boxes[searching_in - OFFSET].paper;
    int num   = prisoner.num;

    boxes[searching_in].opened = 1;
    path[TRIES_LIMIT - tries_left - 1] = boxes[searching_in];

    // Found
    if(paper == num){
        return 1;
    }

    // Not found
    return loopy_strat(prisoner, boxes, path, paper, tries_left);
}

int rand_strat(prisoner_t prisoner, box_t boxes[], box_t path[], int tries_left){
    tries_left--;
    if(tries_left == 0){
        return 0;
    }
    
    // Checks if box is opened
    do{
        int rand_index = rand() % NUMBER;
        int paper = boxes[rand_index].paper;
        int num = prisoner.num;
    }while(boxes[rand_index].opened);

    boxes[searching_in].opened = 1;
    path[TRIES_LIMIT - tries_left - 1] = boxes[rand_index];

    // Found
    if (paper == num){
        return 1;
    }

    // Not found
    return rand_strat(prisoner, boxes, path, tries_left);
}
