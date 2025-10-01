#include "force_unit.h"
#include <stdio.h>

// 2025-09-03 Numbers / Game theory needs a definite review

// Applies terrain, weather and support modifiers to a unit's effectiveness
// strategic impacts like movement penalties visibility and support advantages
void apply_modifiers(ForceUnit *unit, int support_flags, int terrain, int weather) {
    int base = unit->effectiveness;

    //Terrain impact : example

    switch (terrain) {
        case 0: // Plains
            if(unit->type == ARMOR) base +=2;
            if(unit->type == INFANTRY) base +=1;
            break;
        case 1: // Forest
            if(unit->type == INFANTRY) base +=2;
            if(unit->type == ARMOR) base -=1;
            break;
        case 2: // Urban
            if(unit->type == INFANTRY) base +=3;
            break;
        case 3: // Mountain
            if(unit->type == INFANTRY) base +=1;
            if(unit->type == ARMOR) base -= 2;
            break;   
    } // End Case

    switch (weather) {
        case 1: // Rain
            if(unit->type == AIR_SUPPORT) base -=2;
            break;
        case 2: // Snow
            base -=1;
            break;
    } // End Case 2
    
    // Support Impact
    if ((support_flags & ( 1 << ANTI_AIR)) & unit->type == AIR_SUPPORT) {
        base -=3; // Anti-air suppresses air support
    }
    if ((support_flags & (1 << LOGISTICS)) && unit->type != AIR_SUPPORT) {
        base +=1; // Logistics boost ground units
    }

    unit->effectiveness = base;

}