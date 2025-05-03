// Main Voxel Engine
// Import lybraries
#include "./include/camera.hpp"
#include "./include/chunk.hpp"
#include "./include/voxel.hpp"
#include "./include/voxel_picker.hpp"
#include "./include/render.hpp"
#include "./include/inventory.hpp"
#include "./include/crosshair.hpp"
#include <raylib.h>
#include <iostream>
#include <raymath.h>
// Main function
int main() {
    // Initialize the chunk
    Chunk chunk = {};
    // Fill the chunk with voxels
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int y = 0; y < CHUNK_SIZE; ++y) {
            for (int z = 0; z < CHUNK_SIZE; ++z) {
                chunk.voxels[x][y][z].isActive = true; // Set the voxel to active
                chunk.voxels[x][y][z].color = { static_cast<unsigned char>(x * 16), static_cast<unsigned char>(y * 16), static_cast<unsigned char>(z * 16), 255 }; // Set the color of the voxel
            }
        }
    }
    // Initialize the camera
    VoxelCamera myCam;
    // Window sizes
    int screenWidth = 800;
    int screenHeight = 600;
    bool fullscreen = false; // Fullscreen mode
    bool inventoryOpen = false; // Inventory mode
    // Title of the window
    std::string title = "Voxel Engine";
    // Initialize the window
    InitWindow(screenWidth, screenHeight, title.c_str()); // Create the window
    // Enable vsync
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor())); // Set the target FPS to the monitor refresh rate
    // cursor settings
    HideCursor(); // Hide the cursor
    DisableCursor(); // Enable the cursor
    // Vereify if the window is ready
    if (!IsWindowReady()) {
        std::cerr << "Failed to initialize window!" << std::endl;
        return -1;
    }
    // Loop until the window is closed
    while (!WindowShouldClose()) {
        // Keys shortcuts
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
        if (IsKeyPressed(KEY_I)) {
            inventoryOpen = !inventoryOpen; // Toggle inventory mode
            std::cout << (inventoryOpen ? "Opening inventory" : "Closing inventory") << std::endl;

            if (inventoryOpen) {
                ShowCursor(); // Show the cursor
                EnableCursor(); // Enable the cursor
            } else {
                HideCursor(); // Hide the cursor
                DisableCursor(); // Disable the cursor
            }
        }
        if (IsKeyPressed(KEY_F11)) {
            std::cout << "Toggling fullscreen mode" << std::endl;
            fullscreen = !fullscreen; // Toggle fullscreen mode
            ToggleFullscreen(); // Toggle fullscreen mode

            if (!fullscreen) {
                std::cout << "Exiting fullscreen mode" << std::endl;
                SetWindowSize(screenWidth, screenHeight); // Set the window size
            }
        } 

        float dt = GetFrameTime(); // Get the time between frames
        if (!inventoryOpen) {
            myCam.Update(dt); // Update the camera
        }
        // Render the scene
        BeginDrawing();
            // Clear the background
            ClearBackground(RAYWHITE);
            // Create camera
            BeginMode3D(myCam.camera);
            // Render the chunk
            RenderChunk(chunk, { 1, 0, 1 }); // Render the chunk at position (0, 0, 0)
            // End the 3D mode
            EndMode3D();
            // Draw the crosshair
            DrawCrosshair(screenWidth, screenHeight); // Draw the crosshair
            // Draw the inventory if it's open
            if (inventoryOpen) {
                DrawInventory(screenWidth, screenHeight); // Draw the inventory
            }
            HitVoxel hoveredVoxel = { Vector3Zero(), false }; // Initialize the hovered voxel
            // Draw FPS
            DrawFPS(10, 10);
        // End the drawing
        EndDrawing();
    }
    CloseWindow(); // Close the window
    return 0;
}
