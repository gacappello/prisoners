#ifndef LOGIC_H
#define LOGIC_H

#include "../includes/game.h"
#include "../includes/prisoner.h"
#include "../includes/box.h"

int make_choice (prisoner_t prisoner, box_t boxes[], game_state_t *state);
int loopy_strat (prisoner_t prisoner, box_t boxes[], int searching_in, int tries_left);
int rand_strat  (prisoner_t prisoner, box_t boxes[], int tries_left);

#endif //LOGIC_H
