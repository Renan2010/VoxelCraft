#include "./include/crosshair.hpp"
#include <raylib.h>


void DrawCrosshair(int screenWidth, int screenHeight) {
    // Crosshair size
    const int crosshairSize = 10;
    // Crosshair color
    Color crosshairColor = BLACK;
    // Draw the crosshair
    DrawLine(screenWidth / 2 - crosshairSize, screenHeight / 2, screenWidth / 2 + crosshairSize, screenHeight / 2, crosshairColor);
    DrawLine(screenWidth / 2, screenHeight / 2 - crosshairSize, screenWidth / 2, screenHeight / 2 + crosshairSize, crosshairColor);
}
