// game_state.h — Defines the dynamic state of the game

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "force_unit.h"  // For ForceUnit and enums

typedef struct {
    ForceUnit player_forces[FORCE_TYPE_COUNT];
    ForceUnit enemy_forces[FORCE_TYPE_COUNT];
    int player_support_flags;
    int enemy_support_flags;
    int terrain;
    int weather;
    int turn_number;
} GameState;

void init_game_state(GameState *state);
void simulate_turn(GameState *state);
void log_game_state(GameState *state);

#endif
