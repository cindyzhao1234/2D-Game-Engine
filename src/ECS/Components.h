#pragma once
#include <string>
#include "../TransformComponent.h"

struct SpriteComponent{
    //links an entity to a texture and draws order layer
    std::string textureKey;
    int layer;
};