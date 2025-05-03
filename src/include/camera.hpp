#pragma once
#include <raylib.h>

class VoxelCamera {
public:
    Camera3D camera; // Camera object

    VoxelCamera();
    void Update(float deltaTime);
};