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
            return rand_strat(prisoner, boxes, path, rand() % NUMBER, TRIES_LIMIT);
            break;
        default:
            return 0;
            break;
    }

    return 0;
}

int loopy_strat(prisoner_t prisoner, box_t boxes[], box_t path[], int searching_in, int tries_left){
    // No more tries
    tries_left--;
    if(tries_left <= 0){
        boxes[searching_in].opened = 0;
        return 0;
    }

    int paper = boxes[searching_in - OFFSET].paper;
    int num   = prisoner.num;

    // Set box as open and put that in path 
    boxes[searching_in].opened = 1;
    path[TRIES_LIMIT - tries_left - 1] = boxes[searching_in];

    // Found
    if(paper == num){
        boxes[searching_in].opened = 0;
        return 1;
    }

    // Not found
    return loopy_strat(prisoner, boxes, path, paper, tries_left);
}

int rand_strat(prisoner_t prisoner, box_t boxes[], box_t path[], int searching_in, int tries_left){
    // No more tries
    tries_left--;
    if(tries_left <= 0){
        boxes[searching_in].opened = 0;
        return 0;
    }
    
    int paper = boxes[searching_in].paper;
    int num = prisoner.num;

    // Set box as open and put that in path
    boxes[searching_in].opened = 1;
    path[TRIES_LIMIT - tries_left - 1] = boxes[searching_in];

    // Found
    if (paper == num){
        boxes[searching_in].opened = 0;
        return 1;
    }

    // Checks if next box is opened
    do{
        searching_in = rand() % NUMBER;
        paper = boxes[searching_in].paper;
        num = prisoner.num;
    }while(boxes[searching_in].opened);

    // Not found
    return rand_strat(prisoner, boxes, path, searching_in, tries_left);
}
