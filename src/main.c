#include <stdio.h>
#include <stdlib.h>

#include "../includes/game.h"
#include "../includes/box.h"
#include "../includes/logic.h"
#include "../includes/prisoner.h"

int main(void){
    game_state_t state;
    state.strategy = LOOPY; 
     
    prisoner_t prisoners [PRISONERS];
    box_t      boxes     [BOXES];
 
    fill_prisoners(prisoners);
    fill_boxes(boxes);
    shuffle_boxes(boxes);

    for(int i=0;i<PRISONERS;i++){
       printf("Prisoner: %d Box: %d Paper: %d\n", prisoners[i].num, boxes[i].num, boxes[i].paper);
    }

    for(int i=0;i<ITERATIONS;i++){
        printf("-----");
        for(int j=0;j<PRISONERS;j++){
            int found = make_choice(prisoners[j], boxes, &state);
            if(found) {
                printf("%d FOUND\n", prisoners[j].num);
            }
            else {
                printf("%d FAILED", prisoners[j].num);
            }
        }
    }

    return EXIT_SUCCESS;
}
