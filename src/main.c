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
    
    // This can be done only one time
    fill_prisoners(prisoners);
    fill_boxes(boxes);

    for(int i=0;i<PRISONERS;i++){
       printf("Prisoner: %d Box: %d Paper: %d\n", prisoners[i].num, boxes[i].num, boxes[i].paper);
    }
    printf("\n");

    for(int i=0;i<ITERATIONS;i++){

        // Shuffle needs to be done every time
        shuffle_boxes(boxes);

        for(int j=0;j<PRISONERS;j++){

            box_t path [TRIES_LIMIT];

            int found = make_choice(prisoners[j], boxes, path, &state);
            if(found)
                printf("PRISONER NUMBER %d HAS FOUND: ", prisoners[j].num);
            else printf("PRISONER NUMBER %d HAS NOT FOUND: ", prisoners[j].num);

            for(int k=0;k<TRIES_LIMIT;k++){
                if(path[k]. != 0){
                    printf("%d ", path[k].paper);
                }
            }
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
