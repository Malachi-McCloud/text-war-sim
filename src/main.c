// main.c — Entry point for the war game

#include <stdio.h>      // For input/output
#include <string.h>     // For string handling
#include "game_state.h"


int main() {
    GameState state;
    init_game_state(&state);

    // Example: enable logisitics and anti-air for player
    state.player_support_flags |= (1 << LOGISTICS);
    state.player_support_flags |= (1 << ANTI_AIR); 

    // Set terrain and weather for testing
    state.terrain = FOREST;
    state.weather = RAIN;
    
    // Run 3 turns
    for(int i = 0; i < 3; i++) {
        simulate_turn(&state);
    }

    return 0;

}

