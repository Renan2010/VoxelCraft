#include "./include/voxel_picker.hpp"
#include "./include/chunk.hpp"
#include <raylib.h>
#include <iostream>
#include <algorithm>
#include <raymath.h>

struct Vec3 {
    float x, y, z; // Coordinates of the box
};

struct Box {
    Vec3 min; // Minimum coordinates of the box
    Vec3 max; // Maximum coordinates of the box
};


bool CheckCollisionRayBox(const Vec3& rayOrigin, const Vec3& rayDirection, const Box& box, float& t) {
    Vec3 invDir = {1.0f / rayDirection.x, 1.0f / rayDirection.y, 1.0f / rayDirection.z};

    float tmin = (box.min.x - rayOrigin.x) * invDir.x;
    float tmax = (box.max.x - rayOrigin.x) * invDir.x;

    if (tmin > tmax) std::swap(tmin, tmax);

    float tymin = (box.min.y - rayOrigin.y) * invDir.y;
    float tymax = (box.max.y - rayOrigin.y) * invDir.y;

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (box.min.z - rayOrigin.z) * invDir.z;
    float tzmax = (box.max.z - rayOrigin.z) * invDir.z;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    t = tmin;
    if (t < 0) t = tmax;

    return true;
}



HitVoxel GetHoveredVoxel(Camera3D camera, int screenWidth, int screenHeight, Chunk &chunk) {
    Ray ray = GetMouseRay({ (float)screenWidth / 2, (float)screenHeight / 2}, camera); // Get the ray from the camera
    HitVoxel result = { Vector3Zero(), false }; // Initialize the result

    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int y = 0; y < CHUNK_SIZE; ++y) {
            for (int z = 0; z < CHUNK_SIZE; ++z) {
                Voxel &voxel = chunk.voxels[x][y][z]; // Get the voxel
                if (voxel.isActive) { // Check if the voxel is active
                    Vector3 voxelPos = { (float)x, (float)y, (float)z }; // Get the position of the voxel
                    
                    Box box = {
                        { voxelPos.x, voxelPos.y, voxelPos.z },
                        { voxelPos.x, voxelPos.y, voxelPos.z }
                    };

                    Vec3 rayOrigin = { ray.position.x, ray.position.y, ray.position.z };
                    Vec3 rayDir = { ray.direction.x, ray.direction.y, ray.direction.z };

                    float t;

                    if (CheckCollisionRayBox(rayOrigin, rayDir, box, t)) { // Check if the ray intersects with the voxel
                        std::cout << "Hit voxel at: " << voxelPos.x << ", " << voxelPos.y << ", " << voxelPos.z << std::endl;
                        if (t < result.hit) { // Check if the hit is closer than the previous hit
                            result.position = voxelPos; // Set the position of the hit voxel
                            result.hit = true; // Set the hit flag to true
                            std::cout << "Hit voxel at: " << result.position.x << ", " << result.position.y << ", " << result.position.z << std::endl;
                            return result; // Return the result
                        }
                    }

                    

                    
                    
                }
            }
        }
    }
}