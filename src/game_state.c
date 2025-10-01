#include <stdio.h>      // For logging simulation output
#include <string.h>     // For memory initialization
#include "game_state.h" // Core game state struct and function declarations

// Initializes the game state to a clean starting point.
// Resets all counters and zeroes out unit arrays.
void init_game_state(GameState *state) {
    memset(state, 0, sizeof(GameState));
    state->turn_number = 0;
}

// Runs a single turn of the simulation.
// Applies terrain, weather, and support modifiers to both sides,
// then logs the updated state and advances the turn counter.
void simulate_turn(GameState *state) {
    printf("\n--- Simulating Turn %d ---\n", state->turn_number);

    // Apply modifiers to each force type (INFANTRY, ARMOR, etc.)
    for (int i = 0; i < FORCE_TYPE_COUNT; i++) {
        // Player forces receive terrain/weather/support adjustments
        apply_modifiers(&state->player_forces[i],
                        state->player_support_flags,
                        state->terrain,
                        state->weather);

        // Enemy forces receive their own adjustments
        apply_modifiers(&state->enemy_forces[i],
                        state->enemy_support_flags,
                        state->terrain,
                        state->weather);
    }

    // Log the updated state after modifiers are applied
    log_game_state(state);

    // Advance the turn counter for the next simulation cycle
    state->turn_number++;
}

// Outputs the current state of the game to the console.
// Useful for debugging, testing, and visualizing force effectiveness.
void log_game_state(GameState *state) {
    printf("Turn %d | Terrain: %d | Weather: %d\n",
           state->turn_number, state->terrain, state->weather);

    for (int i = 0; i < FORCE_TYPE_COUNT; i++) {
        printf("Player %d: Qty %d, Eff %d\n",
               i,
               state->player_forces[i].quantity,
               state->player_forces[i].effectiveness);

        printf("Enemy  %d: Qty %d, Eff %d\n",
               i,
               state->enemy_forces[i].quantity,
               state->enemy_forces[i].effectiveness);
    }
}
