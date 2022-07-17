#include "../includes/logic.h"
#include "../includes/game.h"
#include "../includes/prisoner.h"
#include "../includes/box.h"
#include <stdlib.h>

int make_choice(prisoner_t prisoner, box_t boxes[], game_state_t *state){
    switch(state->strategy){
        case LOOPY:
            return loopy_strat(prisoner, boxes, prisoner.num - OFFSET, TRIES_LIMIT);
            break;
        case RANDOMNESS:
            return rand_strat(prisoner, boxes, TRIES_LIMIT);
            break;
        default:
            return 0;
            break;
    }

    return 0;
}

int loopy_strat(prisoner_t prisoner, box_t boxes[], int searching_in, int tries_left){
    // TODO: List all opened boxes
    tries_left--;
    if(tries_left == 0){
        return 0;
    }

    int paper = boxes[searching_in - OFFSET].paper;
    int num   = prisoner.num; 
    if(paper == num){
        return 1;
    }

    return loopy_strat(prisoner, boxes, paper, tries_left);
}

int rand_strat(prisoner_t prisoner, box_t *boxes, int tries_left){
    // TODO: List all opened boxes
    tries_left--;
    if(tries_left == 0){
        return 0;
    }
    
    // TODO: Filter opened boxes
    int rand_index = rand() % NUMBER;
    int paper = boxes[rand_index].paper;
    int num = prisoner.num;
    if (paper == num){
        return 1;
    }

    return rand_strat(prisoner, boxes, tries_left);
}
