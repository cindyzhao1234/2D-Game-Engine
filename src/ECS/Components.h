#pragma once
#include <string>
#include <raylib.h>

struct SpriteComponent{
    //links an entity to a texture and draws order layer
    std::string textureKey;
    int layer;
};

//struct members are public by default while class members are private by default
struct TransformComponent{
    Vector2 pos = {0.0f, 0.0f};
    float rot = 0.0f;
    Vector2 scale = {1.0f, 1.0f};
};