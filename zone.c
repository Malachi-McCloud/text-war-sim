// zone.c - Implements zone creation and linking logic

#include <stdlib.h>
#include <string.h>
#include "zone.h"

// Helper function to allocate and initialize a zone
Zone * createZone(const char *name, const char *desc, int enemies, int resources) {
    Zone *z = malloc(sizeof(Zone));       // Dynamically allocate memory for a zone
    strcpy(z->name, name);              // Copy name into zone struct
    strcpy(z->description, desc);       // Copy Desc
    z->enemyCount = enemies;            // Set enemy count
    z->resourceLevel = resources;        // Set resource level
    z->north = z->south = z->east = z->west = NULL;  // Initialize links
    return z;
}

// Create and link a small battlefield map
Zone* createBattlefield() { 
    // Create zones with name, desciription, enemy count and resource level
    Zone *base = createZone("Base Camp", "Your fortified starting position.", 0, 100);
    Zone *forest = createZone("Forest", "Dense woods with enemy scouts", 3, 40);
    Zone *outpost = createZone("Outpost", "A captured enemy outpost.", 5, 60);

    // Now we link the zones together
    base->north = forest;
    forest->south = base;
    forest->east = outpost;
    outpost->west = forest;

    return base; // Return to starting zone
}