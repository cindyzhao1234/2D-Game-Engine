#pragma once
#include <raylib.h>

//struct members are public by default while class members are private by default
struct TransformComponent{
    Vector2 pos = {0.0f, 0.0f};
    float rot = 0.0f;
    Vector2 scale = {1.0f, 1.0f};
};