#ifndef GAME_H
#define GAME_H

#define NUMBER      100
#define PRISONERS   NUMBER
#define BOXES       NUMBER
#define OFFSET      0

#define ITERATIONS  10E10
#define TRIES_LIMIT PRISONERS / 2 + 1

typedef enum STRATEGY_E {
    RANDOMNESS,
    LOOPY,
} strategy_t;

typedef struct GAME_STATE_S {
    strategy_t strategy;
} game_state_t;

#endif //GAME_H
