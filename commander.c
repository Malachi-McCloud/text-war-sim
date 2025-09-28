// commander.c - Implements commander initialization and command handling

#include <stdio.h>  //For printf
#include <string.h> // For strcmp, strncmp
#include "commander.h"

// Initiliaze Commander with default values

void initCommander(Commander *cmd, Zone *start) {

    cmd->currentZone = start;       // Set Starting Location
    cmd->troops = 10;               // Start with 10 troops
    cmd->supplies = 50;             // Initial supply level
    cmd->morale = 75;               // Initial morale level
}


// Parse and handle basic commands
void handleCommand(Commander *cmd, const char *input) {
    if(strncmp(input, "move ", 5) == 0) {
        const char *dir = input + 5;
        Zone *next = NULL;

    if (strcmp(dir, "north") == 0) next = cmd->currentZone->north;
    else if(strcmp(dir, "south") == 0) next = cmd->currentZone->south;
    else if(strcmp(dir, "east") == 0) next = cmd->currentZone->east;
    else if(strcmp(dir, "west") == 0) next = cmd->currentZone->west;

    if(next) {
        cmd->currentZone = next;
        printf("You moveed to %s.\n", next->name);
    } else {
        printf("You can't move %s from here.\n", dir);
    }
} else if(strcmp(input, "status") ==0) {
    // Display Commander Stats
    printf("Troops: %d\n", cmd->troops);
    printf("Supplies: %d\n", cmd->supplies);
    printf("Morale: %d\n", cmd->morale);
}  else if(strcmp(input, "scan") == 0) {
    printf("Zone: %s\n", cmd->currentZone->name);
    printf("%s\n", cmd->currentZone->description);
    printf("Enemies: %d\n", cmd->currentZone->enemyCount);
    printf("Resources: %d\n", cmd->currentZone->resourceLevel);
} else {
    printf("Unkown command: %s\n", input);
    }   
}