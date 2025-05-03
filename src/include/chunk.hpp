// chunk.hpp
#pragma once
#include "voxel.hpp"
#include <raylib.h>

const int CHUNK_SIZE = 16; // Size of the chunk in voxels

struct Chunk {
    Voxel voxels[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE]; // 3D array of voxels
};