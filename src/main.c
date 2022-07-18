#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

    int total_wins = 0;
    for(int i=0;i<ITERATIONS;i++){

        // Shuffle needs to be done every time
        shuffle_boxes(boxes);

        int prisoner_wins = 0;
        for(int j=0;j<PRISONERS;j++){

            box_t path[BOXES];
            memcpy(path, boxes, BOXES*sizeof(box_t));

            int found = make_choice(prisoners[j], boxes, path, &state);
            prisoner_wins += 1 ? found : 0;

            for(int k=0;k<BOXES;k++){
                boxes[k].opened = 0;
            }
        }

        if(prisoner_wins == PRISONERS){
            total_wins++;
        }

        double actual = total_wins/(i+1.0);
        printf("%s %f %s %.30f %s", "Expected: ", state.strategy == LOOPY ? 1-M_LN2 : pow(1/2, NUMBER), "Actual: ", actual, "\r");
    }

    fflush(stdout);
    printf("\n");
    return EXIT_SUCCESS;
}
