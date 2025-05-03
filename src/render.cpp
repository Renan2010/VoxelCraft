#include <raylib.h>
#include "./include/chunk.hpp"

void RenderChunk(const Chunk& chunk, Vector3 chunkpos) {
    // Loop through each voxel in the chunk
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int y = 0; y < CHUNK_SIZE; ++y) {
            for (int z = 0; z < CHUNK_SIZE; ++z) {
                const Voxel& voxel = chunk.voxels[x][y][z];
                if (voxel.isActive) {
                    // Calculate the position of the voxel
                    Vector3 position = { chunkpos.x + x, chunkpos.y + y, chunkpos.z + z };
                    DrawCube(position, 1.0f, 1.0f, 1.0f, voxel.color);
                }
            }
        }
    }
}