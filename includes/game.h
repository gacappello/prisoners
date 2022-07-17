#ifndef GAME_H
#define GAME_H

#define NUMBER      100
#define PRISONERS   NUMBER
#define BOXES       NUMBER
#define OFFSET      1

#define ITERATIONS  0
#define TRIES_LIMIT PRISONERS / 2

typedef enum STRATEGY_E {
    RANDOMNESS,
    LOOPY,
} strategy_t;

typedef struct GAME_STATE_S {
    strategy_t strategy;
} game_state_t;

#endif //GAME_H
