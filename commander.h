// commander.h - Defines the commander struct and command line handling

#ifndef COMMANDER_H
#define COMMANDER_H

#include "zone.h" // include zone definitions

// Commander represents the player and their strategic state in the game

typedef struct {
    Zone *currentZone;      // Pointer to current location on field
    int troops;             // Number of troops under command
    int supplies;           // Supplies available for operations
    int morale;             // Troop morale (0-100)

} Commander;

// Initialize commander with starting zone and default stats
void initCommander(Commander *cmd, Zone *start);

// Parse and execute player commands (move status attack)
void handleCommand(Commander *cmd, const char *input);


#endif