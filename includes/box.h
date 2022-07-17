#ifndef BOX_H
#define BOX_H

typedef struct BOX_S {
    int num;
    int paper;
} box_t;

void fill_boxes(box_t *boxes);
void shuffle_boxes(box_t *boxes);

#endif  //BOX_H
