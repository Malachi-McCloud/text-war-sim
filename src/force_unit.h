#ifndef FORCE_UNIT_H
#define FORCE_UNIT_H

// Enumerates all support force types in the simulation.
// These are used to model strategic capabilities, not individual soldiers
typedef enum {
    INFANTRY,           // Ground troops, basic combat units pos 0 1 
    ARMOR,              // Tanks and armored vehicles pos 1 2
    ARTILLERY,          // Longe-range bombardment pos 2 4
    AIR_SUPPORT,        // Air superiority and strike capability pos 3 8 
    ANTI_AIR,           // Defensive counter to air units pos 4 16
    RECON,              // Intelligence gathering and visibility pos 5 32
    LOGISTICS,          // Supply lines and movement efficiency pos 6 64
    FORCE_TYPE_COUNT    // Sentinel value for array sizing 
} ForceType;


// Represents a single force unit type and its strategic attributes
typedef struct {
    ForceType type;     // What kind of unit is this
    int quantity;       // Number of units available
    int effectiveness;  // Base strength, modified by terrain/support
    int has_support;    // Boolean or bitmask for support precense
} ForceUnit;

typedef enum {
    CLEAR,
    FOREST,
    URBAN
} TerrainType;

typedef enum {
    SUNNY,
    RAIN,
    SNOW
} WeatherType;


// Applies terrain weather and support modifiers to a unit's effectiveness
// This function is called during combat evaluations or scenario updates
void apply_modifiers(ForceUnit *unit, int support_flags, int terrain, int weather);

#endif