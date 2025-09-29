// game_state.h - for defining the dynamic state of the game through the struct

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdbool.h>       // For using the bool type
#include "player.h"     // Uses our player struct 
#include "map.h"        // Uses our map struct


typedef struct {
    Player player;          // Struct holding our player specific data
    Map map;                // Struct representing the game world
    int turn;               // Tracks how many turns have passed
    bool game_over;         // Falgs to indiciate our end state

} GameState;

// Sets up memory for player, map, resets counters
void GameState_init(GameState* state);

// Resets gamestate to original condition
void GameState_reset(GameState* state);

#endif