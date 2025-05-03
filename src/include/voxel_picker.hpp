#ifndef VOXEL_PICKER_HPP
#define VOXEL_PICKER_HPP
#pragma once
#include <raylib.h>
#include "chunk.hpp"

struct HitVoxel {
    Vector3 position; // Position of the voxel in world space
    bool hit; // Coordinates of the voxel
};

HitVoxel GetHoveredVoxel(Camera3D camera, int screenWidth, int screenHeight, Chunk& chunk);

#endif // VOXEL_PICKER_HPP