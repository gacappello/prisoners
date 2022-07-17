#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "../includes/box.h"
#include "../includes/game.h"

void fill_boxes(box_t *boxes){
    size_t len = NUMBER;
    for(int i=0;i<len;i++){
        boxes[i].opened = 0;
        boxes[i].num = i + OFFSET;
        boxes[i].paper = i + OFFSET;
    }
}

void shuffle_boxes(box_t *boxes){
    size_t len = NUMBER;
    srand(time(0));
    for (int i=0;i<len;i++) {
        int j = rand() % len;
        int tmp = boxes[i].paper;
        boxes[i].paper = boxes[j].paper;
        boxes[j].paper = tmp;
        boxes[j].opened = 0;
    }
}
