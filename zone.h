// zone.h - This file defines the Zone struct for creating the battlefield

#ifndef ZONE_H
#define ZONE_H


/* Zone represents a battlefield area the commander can move in
Each zone has a name, description, directional links and strategic properties. */
typedef struct Zone {

    char name[50]; // Name of the zone
    char description[256]; // Text description to be shown to player
    struct Zone *north; // Pointer adjacent to zone to north
    struct Zone *south; // Pointer adjacent to zone to south
    struct Zone *east; // Pointer adjacent to zone to east
    struct Zone *west; // Pointer adjacent to zone in west
    int enemyCount; // Number of enemies present in this zone
    int resourceLevel; // Supplie or strategic value in the zone

} Zone;

// Function to create and link different zones into a battlefield map
Zone* createBattlefield();

#endif