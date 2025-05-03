#pragma once
#include <raylib.h>
#include <string>

struct Item {
    int id;
    std::string name;
    Texture2D texture;
};
extern Item inventory[9]; // Array of items in the inventory
extern bool inventoryOpen; // Flag to check if the inventory is open
void DrawInventory(int screenWidth, int screenHeight);

