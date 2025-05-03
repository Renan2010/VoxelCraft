// Inventory (like minecraft) for a game
#include "./include/inventory.hpp"
#include <raylib.h>

Item inventory[9]; // Array of items in the inventory
bool inventoryOpen = false; // Flag to check if the inventory is open

void   DrawInventory(int screenWidth, int screenHeight) {
    // Draw the inventory background
    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(DARKGRAY, 0.8f));
    // Draw the inventory slots
    for (int i = 0; i < 9; i++) {
        int x = (screenWidth / 2) - (4 * 50) + (i * 50);
        int y = screenHeight - 100;
        DrawRectangle(x, y, 50, 50, Fade(LIGHTGRAY, 0.8f));
        DrawRectangleLines(x, y, 50, 50, BLACK);
    }
}