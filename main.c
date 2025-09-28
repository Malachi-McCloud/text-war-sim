// main.c — Entry point for the war game

#include <stdio.h>      // For input/output
#include <string.h>     // For string handling
#include "zone.h"       // Zone definitions
#include "commander.h"  // Commander definitions

int main() {
    // Create battlefield and initialize commander
    Zone *startZone = createBattlefield();
    Commander cmd;
    initCommander(&cmd, startZone);

    char input[100]; // Buffer for user input

    printf("Welcome, Commander. Type 'move <direction>', 'scan', 'status', or 'exit'.\n");

    // Main game loop
    while (1) {
        printf("\nCurrent Zone: %s\n>> ", cmd.currentZone->name);
        fgets(input, sizeof(input), stdin); // Read input from user
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            printf("Mission terminated. Exiting...\n");
            break;
        }

        handleCommand(&cmd, input); // Execute command
    }

    return 0;
}
