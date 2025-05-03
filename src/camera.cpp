// camera.cpp
#include "./include/camera.hpp"
#include <raylib.h>

VoxelCamera::VoxelCamera() {
    camera.position = { 0.0f, 0.0f, 0.0f }; // Camera position
    camera.target = { 0.0f, 0.0f, 1.0f }; // Camera target
    camera.up = { 0.0f, 1.0f, 0.0f }; // Up vector
    camera.fovy = 45.0f; // Field of view
    camera.projection = CAMERA_PERSPECTIVE; // Camera type
}

void VoxelCamera::Update(float deltaTime) {
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
}