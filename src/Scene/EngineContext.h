#pragma once
#include "../MyRenderer2D.h"
#include "../Input.h"
#include "../MyAssetManager.h"
#include "../ECS/World.h"

//engine owns systems, scenes uses systems

//EngineContext gives access to the real copy of each engine system, without copying them

struct EngineContext{
    Input& input;
    MyRenderer2D& myRenderer;
    World& myWorld;
    MyAssetManager& assetManager;
};