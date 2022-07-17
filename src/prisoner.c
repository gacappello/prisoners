#include <stddef.h>

#include "../includes/prisoner.h"
#include "../includes/game.h"

void fill_prisoners(prisoner_t *prisoners){
    size_t len = NUMBER;
    for(int i=0;i<len;i++){
        prisoners[i].num = i + OFFSET;
    }
}
