// test_commander.c — Test harness for movement logic

#include <assert.h>
#include <string.h>
#include "commander.h"
#include "zone.h"
#include <stdio.h>
// Test movement across linked zones
void testMovement() {
    Zone *start = createBattlefield();
    Commander cmd;
    initCommander(&cmd, start);

    handleCommand(&cmd, "move north");
    assert(strcmp(cmd.currentZone->name, "Forest") == 0);

    handleCommand(&cmd, "move east");
    assert(strcmp(cmd.currentZone->name, "Outpost") == 0);

    handleCommand(&cmd, "move west");
    assert(strcmp(cmd.currentZone->name, "Forest") == 0);

    handleCommand(&cmd, "move south");
    assert(strcmp(cmd.currentZone->name, "Base Camp") == 0);

    printf("✅ testMovement passed.\n");
}

// Entry point for test execution
int main() {
    testMovement();
    // Add more tests here later
    return 0;
}
